/*
   cvsd - chroot wrapper to run `cvs pserver' more securely.

   cvsd was originally written by Chris Black <cblack@mokey.com>,
   http://cblack.mokey.com/. That was until release 0.6

   cvsd versions up till 0.8b3 were maintained by Philippe Kehl
   <phkehl@gmx.net>, http://guv.ethz.ch/~flip/cvsd/,
   http://www.oinkzwurgl.org/software/cvsd/.

   after that Arthur de Jong <arthur@ch.tudelft.nl>
   took up the work and did a complete rewrite,
   http://ch.tudelft.nl/~arthur/cvsd.

   Copyright (C) 1999 Chris Black.
   Copyright (C) 2000 Philippe Kehl.
   Copyright (C) 2001, 2002, 2003, 2004, 2005, 2006 Arthur de Jong.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
*/


#include "config.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

#ifdef HAVE_GETOPT_H
#include <getopt.h>
#endif /* HAVE_GETOPT_H */
#ifndef HAVE_GETOPT_LONG
#include "getopt_long.h"
#endif /* not HAVE_GETOPT_LONG */
#ifndef HAVE_DAEMON
#include "daemon.h"
#endif /* not HAVE_DAEMON */
#ifndef HAVE_GETADDRINFO
#include "getinfos.h"
#endif /* not HAVE_GETADDRINFO */

#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#ifdef HAVE_NETDB_H
#include <netdb.h>
#endif /* HAVE_NETDB_H */
#ifdef HAVE_FCNTL_H
#include <fcntl.h>
#endif /* HAVE_FCNTL_H */
#ifdef USE_LIBWRAP
#ifdef HAVE_TCPD_H
#include <tcpd.h>
#endif /* HAVE_TCPD_H */
#endif /* USE_LIBWRAP */
#ifdef HAVE_GRP_H
#include <grp.h>
#endif /* HAVE_GRP_H */
#ifdef USE_CAPABILITIES
#include <sys/capability.h>
#include <sys/prctl.h>
#endif /* USE_CAPABILITIES */

#include "xmalloc.h"
#ifdef HAVE_SETRLIMIT
#include "reslimit.h"
#endif /* HAVE_SETRLIMIT */
#include "cfg.h"
#include "cfgfile.h"
#include "log.h"


/* the definition of the environment */
extern char **environ;


/* the number of children spawned */
static volatile int cvsd_numchildren=0;


/* the exit flag to indicate that a signal was received */
static volatile int cvsd_exitsignal=0;

/* the server sockets */
#define MAXSERVERSOCKETS 16
static int cvsd_serversockets[MAXSERVERSOCKETS];
static int cvsd_serversocketnum=0;


/* the number of seconds to sleep when no more
   connections can be listened for */
#define SLEEPSECS 5


/* libwrap logging settings */
#ifdef USE_LIBWRAP
int allow_severity=LOG_INFO;
int deny_severity=LOG_NOTICE;
#endif /* USE_LIBWRAP */


/* display version information */
static void display_version(FILE *fp)
{
  fprintf(fp,"%s\n",PACKAGE_STRING);
  fprintf(fp,"Written by Chris Black, Philippe Kehl and Arthur de Jong.\n\n");
  fprintf(fp,"Copyright (C) 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006 Chris Black,\n"
             "Philippe Kehl and Arthur de Jong.\n"
             "This is free software; see the source for copying conditions.  There is NO\n"
             "warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n");
}


/* display usage information to stdout and exit(status) */
static void display_usage(FILE *fp, const char *program_name)
{
  fprintf(fp,"Usage: %s [OPTION]...\n",program_name);
  fprintf(fp,"chroot wrapper to run `cvs pserver' more securely.\n");
  fprintf(fp,"  -f, --config=FILE  use FILE as configfile (default %s)\n",DEFAULT_CONFIGFILE);
  fprintf(fp,"  -d, --debug        don't fork and print debugging to stderr\n");
  fprintf(fp,"      --help         display this help and exit\n");
  fprintf(fp,"      --version      output version information and exit\n");
  fprintf(fp,"\n"
             "Report bugs to <%s>.\n",PACKAGE_BUGREPORT);
}


/* the definition of options for getopt(). see getopt(2) */
static struct option const cvsd_options[] =
{
  { "config",      required_argument, NULL, 'f' },
  { "debug",       no_argument,       NULL, 'd' },
  { "help",        no_argument,       NULL, 'h' },
  { "version",     no_argument,       NULL, 'V' },
  { NULL, 0, NULL, 0 }
};
#define CVSD_OPTIONSTRING "f:dhV"


/* parse command line options and save settings in struct  */
static void parse_cmdline(int argc,char *argv[],struct cvsd_cfg *cfg)
{
  int optc;
  while ((optc=getopt_long(argc,argv,CVSD_OPTIONSTRING,cvsd_options,NULL))!=-1)
  {
    switch (optc)
    {
    case 'f': /* -f, --config=FILE  use FILE as configfile */
      if (optarg[0]!='/')
      {
        fprintf(stderr,"%s: configfile '%s' must be an absolute path\n",
                argv[0],optarg);
        exit(1);
      }
      cfg->configfile=xstrdup(optarg);
      break;
    case 'd': /* -d, --debug        don't fork and print debugging to stderr */
      cfg->debugging=1;
      log_setdefaultloglevel(LOG_DEBUG);
      break;
    case 'h': /*     --help         display this help and exit */
      display_usage(stdout,argv[0]);
      exit(0);
    case 'V': /*     --version      output version information and exit */
      display_version(stdout);
      exit(0);
    case ':': /* missing required parameter */
    case '?': /* unknown option character or extraneous parameter */
    default:
      fprintf(stderr,"Try `%s --help' for more information.\n",
              argv[0]);
      exit(1);
    }
  }
  /* check for remaining arguments */
  if (optind<argc)
  {
    fprintf(stderr,"%s: unrecognized option `%s'\n",
            argv[0],argv[optind]);
    fprintf(stderr,"Try `%s --help' for more information.\n",
            argv[0]);
    exit(1);
  }
}


/* get a name of a signal with a given signal number */
static const char *signame(int signum)
{
  switch (signum)
  {
  case SIGHUP:  return "SIGHUP";  /* Hangup detected */
  case SIGINT:  return "SIGINT";  /* Interrupt from keyboard */
  case SIGQUIT: return "SIGQUIT"; /* Quit from keyboard */
  case SIGILL:  return "SIGILL";  /* Illegal Instruction */
  case SIGABRT: return "SIGABRT"; /* Abort signal from abort(3) */
  case SIGFPE:  return "SIGFPE";  /* Floating point exception */
  case SIGKILL: return "SIGKILL"; /* Kill signal */
  case SIGSEGV: return "SIGSEGV"; /* Invalid memory reference */
  case SIGPIPE: return "SIGPIPE"; /* Broken pipe */
  case SIGALRM: return "SIGALRM"; /* Timer signal from alarm(2) */
  case SIGTERM: return "SIGTERM"; /* Termination signal */
  case SIGUSR1: return "SIGUSR1"; /* User-defined signal 1 */
  case SIGUSR2: return "SIGUSR2"; /* User-defined signal 2 */
  case SIGCHLD: return "SIGCHLD"; /* Child stopped or terminated */
  case SIGCONT: return "SIGCONT"; /* Continue if stopped */
  case SIGSTOP: return "SIGSTOP"; /* Stop process */
  case SIGTSTP: return "SIGTSTP"; /* Stop typed at tty */
  case SIGTTIN: return "SIGTTIN"; /* tty input for background process */
  case SIGTTOU: return "SIGTTOU"; /* tty output for background process */
#ifdef SIGBUS
  case SIGBUS:  return "SIGBUS";  /* Bus error */
#endif
#ifdef SIGPOLL
  case SIGPOLL: return "SIGPOLL"; /* Pollable event */
#endif
#ifdef SIGPROF
  case SIGPROF: return "SIGPROF"; /* Profiling timer expired */
#endif
#ifdef SIGSYS
  case SIGSYS:  return "SIGSYS";  /* Bad argument to routine */
#endif
#ifdef SIGTRAP
  case SIGTRAP: return "SIGTRAP"; /* Trace/breakpoint trap */
#endif
#ifdef SIGURG
  case SIGURG:  return "SIGURG";  /* Urgent condition on socket */
#endif
#ifdef SIGVTALRM
  case SIGVTALRM: return "SIGVTALRM"; /* Virtual alarm clock */
#endif
#ifdef SIGXCPU
  case SIGXCPU: return "SIGXCPU"; /* CPU time limit exceeded */
#endif
#ifdef SIGXFSZ
  case SIGXFSZ: return "SIGXFSZ"; /* File size limit exceeded */
#endif
  default:      return "UNKNOWN";
  }
}


/* check for and handle dying child processes */
static void reap_deadchildren(void)
{
  int status;
  pid_t cpid;
  /* loop until all pending child processes have finished
     (kill all the zombies) */
  while ((cpid=waitpid(-1,&status,WNOHANG))>0)
  {
    /* shouldn't have a race here because we don't have threads */
    cvsd_numchildren--;
    if (WIFSIGNALED(status))
    {
      log_log(LOG_INFO,"cvs command exited on signal %s (%d) with exit-status %d",
                   signame((int)WTERMSIG(status)),
                   (int)WTERMSIG(status),
                   (int)WEXITSTATUS(status));
    }
    else
    {
      log_log(LOG_INFO,"cvs command exited%s with exit-status %d",
                   WIFEXITED(status)?"":" abnormally",
                   (int)WEXITSTATUS(status));
    }
  }
}

/* signal handler for dying children */
static RETSIGTYPE sigchld_handler(int signum)
{
}


/* signal handler for closing down */
static RETSIGTYPE sigexit_handler(int signum)
{
  cvsd_exitsignal=signum;
}


/* do cleaning up before terminating */
static void exithandler(void)
{
  int i;
  for (i=0;i<=cvsd_serversocketnum;i++)
    if (close(cvsd_serversockets[i]))
      log_log(LOG_WARNING,"problem closing server socket (ignored): %s",strerror(errno));
  log_log(LOG_INFO,"version %s bailing out",VERSION);
}


/* handle a connection by doing fork() and stuff */
static void handleconnection(int csock,const struct cvsd_cfg *cfg)
{
  pid_t cpid;
  int i,m;

  /* we have a possible race here? (probably atomic) */
  cvsd_numchildren++;

  /* fork off a child to handle the connection */
  switch (cpid=fork())
  {
  case 0: /* we are the child */
    /* set limits */
    setreslimits();
    /* connect socket to stdin/stdout/stderr */
    if ( (dup2(csock,0)<0) || /* stdin */
         (dup2(csock,1)<0) || /* stdout */
         (dup2(csock,2)<0) )  /* stderr */
    {
      log_log(LOG_ERR,"dup failed: %s",strerror(errno));
      _exit(1);
    }
    /* close all other file descriptors */
    m=sysconf(_SC_OPEN_MAX);
    for (i=3;i<m;i++)
      close(i);
    /* execute cvs */
    execve(cfg->cvscmd,cfg->cvsargs,cfg->cvsenv);
    /* if we are here there has been an error */
    /* we can't log since we don't have any useful file descriptors */
    close(0);
    close(1);
    close(2);
    _exit(1);
    break;
  case -1: /* we are the parent, but have an error */
    log_log(LOG_ERR,"fork() failed: %s",strerror(errno));
    exit(1);
    break;
  }

  /* we are the parent and have a cpid */
  log_log(LOG_DEBUG,"debug: fork() succeeded (child pid=%d)",(int)cpid);

  /* close the socket to prevent confusion */
  if (close(csock))
    log_log(LOG_WARNING,"problem closing connection socket in parent (ignored): %s",strerror(errno));
}


/* create socket, bind and listen on the specified address */
static void listenonaddresses(const struct cvsd_addrs *addrs)
{
  int flag;
  int sock;
  char host[80],serv[40];
  int i;
  struct addrinfo *last=NULL;
  struct addrinfo *addr;
  int count=0;

  for (addr=addrs->addrs;addr!=NULL;addr=addr->ai_next)
  {

    switch (i=getnameinfo(addr->ai_addr,addr->ai_addrlen,
                          host,80,serv,40,
                          NI_NUMERICHOST|NI_NUMERICSERV)<0)
    {
      case 0:
        log_log(LOG_DEBUG,"debug: binding %s %s family=%d socktype=%d protocol=%d",host,serv,
                      addr->ai_family,addr->ai_socktype,addr->ai_protocol);
        break;
      case EAI_SYSTEM:
        log_log(LOG_DEBUG,"debug: getnameinfo() failed: %s",strerror(errno));
        break;
      default:
        log_log(LOG_DEBUG,"debug: getnameinfo() failed: %s",gai_strerror(i));
        break;
    }

    /* ignore unix domain sockets (i.e. named sockets) */
    if (addr->ai_family==PF_UNIX)
    {
      log_log(LOG_DEBUG,"debug: do not try unix domain socket (family %d)",addr->ai_family);
      continue;
    }

    /* create socket */
    if ((sock=socket(addr->ai_family,addr->ai_socktype,addr->ai_protocol))<0)
    {
      if ((errno==EAFNOSUPPORT)||(errno==EINVAL))
      {
        log_log(LOG_DEBUG,"debug: socket() failed (ignored): %s",strerror(errno));
        continue;
      }
      log_log(LOG_ERR,"cannot create socket: %s",strerror(errno));
      exit(1);
    }

    /* bind socket even if port is in close wait state */
    flag=1;
    if (setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,&flag,sizeof(int))!=0)
    {
      log_log(LOG_ERR,"setsockopt(SO_REUSEADDR) failed: %s",strerror(errno));
      if (close(sock))
        log_log(LOG_WARNING,"problem closing socket: %s",strerror(errno));
      exit(1);
    }

#ifdef TODO
    /* close the socket fast (SO_LINGER) */
    struct linger {
                    int   l_onoff;    /* linger active */
                    int   l_linger;   /* how many seconds to linger for */
                };
    if (setsockopt(sock,SOL_SOCKET,SO_LINGER,&**,sizeof(**))!=0)
    {
      log_log(LOG_ERR,"setsockopt(SO_LINGER) failed: %s",strerror(errno));
      if (close(sock))
        log_log(LOG_WARNING,"problem closing socket: %s",strerror(errno));
      exit(1);
    }
#endif /* TODO */

    /* do not block on accept() */
    if ((i=fcntl(sock,F_GETFL,0))<0)
    {
      log_log(LOG_ERR,"fctnl(F_GETFL) failed: %s",strerror(errno));
      if (close(sock))
        log_log(LOG_WARNING,"problem closing socket: %s",strerror(errno));
      exit(1);
    }
    if (fcntl(sock,F_SETFL,i|O_NONBLOCK)<0)
    {
      log_log(LOG_ERR,"fctnl(F_SETFL,O_NONBLOCK) failed: %s",strerror(errno));
      if (close(sock))
        log_log(LOG_WARNING,"problem closing socket: %s",strerror(errno));
      exit(1);
    }

    /* bind the socket to the specified port */
    if (bind(sock,addr->ai_addr,addr->ai_addrlen)<0)
    {
      if ((errno==EADDRINUSE)&&(last!=NULL)&&
          (last->ai_family==AF_INET6)&&
          (addr->ai_family==AF_INET))
      {
        log_log(LOG_DEBUG,"debug: bind() failed (ignored): %s",strerror(errno));
        if (close(sock))
          log_log(LOG_WARNING,"problem closing socket (ignored): %s",strerror(errno));
        continue;
      }
      log_log(LOG_ERR,"bind() failed: %s",strerror(errno));
      if (close(sock))
        log_log(LOG_WARNING,"problem closing socket: %s",strerror(errno));
      exit(1);
    }

    /* start listening for connections */
    if (listen(sock,1)<0)
    {
      log_log(LOG_ERR,"listen() failed: %s",strerror(errno));
      if (close(sock))
        log_log(LOG_WARNING,"problem closing socket: %s",strerror(errno));
      exit(1);
    }

    /* add the allocated socket to the list of ok sockets */
    if (cvsd_serversocketnum>=MAXSERVERSOCKETS)
    {
      log_log(LOG_ERR,"maximum number of listening serversockets reached: edit MAXSERVERSOCKETS in cvsd.c and recompile!");
      if (close(sock))
        log_log(LOG_WARNING,"problem closing socket: %s",strerror(errno));
      exit(1);
    }
    cvsd_serversockets[cvsd_serversocketnum++]=sock;

    /* log stuff */
    switch (i=getnameinfo(addr->ai_addr,addr->ai_addrlen,
                          host,80,serv,40,
                          NI_NUMERICHOST|NI_NUMERICSERV)<0)
    {
      case 0:
        log_log(LOG_INFO,"listening on %s %s",host,serv);
        break;
      case EAI_SYSTEM:
        log_log(LOG_ERR,"getnameinfo() failed (ignored): %s",strerror(errno));
        break;
      default:
        log_log(LOG_ERR,"getnameinfo() failed (ignored): %s",gai_strerror(i));
        break;
    }

    last=addr;
    count++;
  } /* next addr */

  if (count<=0)
  {
    log_log(LOG_ERR,"failed binding any address for %s %s: %s",
                addrs->node,addrs->service,strerror(errno));
    exit(1);
  }

}


/* accept a connection on the socket and spawn a child cvs */
static void acceptconnection(const struct cvsd_cfg *cfg)
{
  int csock;
  fd_set fds;
  int i;
  int j;
  int max=0;
  struct sockaddr_storage addr;
  socklen_t alen;
  char hostbuf[80],serv[40];
  char *host;
#ifdef USE_LIBWRAP
  struct request_info rinfo;
#endif /* USE_LIBWRAP */

  /* clear the set */
  FD_ZERO(&fds);
  for (i=0;i<cvsd_serversocketnum;i++)
  {
    FD_SET(cvsd_serversockets[i],&fds);
    if (cvsd_serversockets[i]+1>max)
      max=cvsd_serversockets[i]+1;
  }

  /* wait for something to change */
  if (select(max,&fds,NULL,NULL,NULL)<0)
  {
    if (errno==EINTR)
    {
      log_log(LOG_DEBUG,"debug: select() failed (ignored): %s",strerror(errno));
      return;
    }
    log_log(LOG_ERR,"select() failed: %s",strerror(errno));
    exit(1);
  }

  for (i=0;i<cvsd_serversocketnum;i++)
  {
    if (FD_ISSET(cvsd_serversockets[i],&fds))
    {

      /* accept a new connection */
      alen=(socklen_t)sizeof(struct sockaddr_storage);
      csock=accept(cvsd_serversockets[i],(struct sockaddr *)&addr,&alen);
      if (csock<0)
      {
        if ((errno==EINTR)||(errno==EAGAIN)||(errno==EWOULDBLOCK))
        {
          log_log(LOG_DEBUG,"debug: accept() failed (ignored): %s",strerror(errno));
          continue; /* this is 'normal' */
        }
        log_log(LOG_ERR,"accept() failed: %s",strerror(errno));
        continue;
      }

      /* look up other side of connection and log it */
      host=hostbuf;
      switch (j=getnameinfo((struct sockaddr *)&addr,alen,
                            host,80,serv,40,
                            NI_NUMERICHOST|NI_NUMERICSERV)<0)
      {
        case 0: break;
        case EAI_SYSTEM:
          log_log(LOG_ERR,"getnameinfo() failed: %s",strerror(errno));
          if (close(csock))
            log_log(LOG_WARNING,"problem closing socket: %s",strerror(errno));
          continue;
        default:
          log_log(LOG_ERR,"getnameinfo() failed: %s",gai_strerror(j));
          if (close(csock))
            log_log(LOG_WARNING,"problem closing socket: %s",strerror(errno));
          continue;
      }
      /* convert IPv4-mapped-IPv6 address to an IPv4 one */
      if ((strncmp(host,"::ffff:",7)==0)&&
          (strchr(host+7,':')==NULL))
        host+=7;

#ifdef USE_LIBWRAP
      /* find out what hosts.{allow,deny} think about this */
      request_init(&rinfo,RQ_FILE,csock,RQ_DAEMON,PACKAGE,0);
      fromhost(&rinfo); /* not documented, but needed somehow */
      if(!hosts_access(&rinfo))
      {
        log_log(LOG_INFO,"connection from %s %s refused by tcp wrappers",host,serv);
        if (close(csock))
          log_log(LOG_WARNING,"problem closing socket: %s",strerror(errno));
        continue;
      }
#endif /* USE_LIBWRAP */

      /* log connection */
      log_log(LOG_INFO,"connection from %s %s",host,serv);

      /* make sure O_NONBLOCK is not inherited */
      if ((j=fcntl(csock,F_GETFL,0))<0)
      {
        log_log(LOG_ERR,"fctnl(F_GETFL) failed: %s",strerror(errno));
        if (close(csock))
          log_log(LOG_WARNING,"problem closing socket: %s",strerror(errno));
        exit(1);
      }
      if (fcntl(csock,F_SETFL,j&~O_NONBLOCK)<0)
      {
        log_log(LOG_ERR,"fctnl(F_SETFL,~O_NONBLOCK) failed: %s",strerror(errno));
        if (close(csock))
          log_log(LOG_WARNING,"problem closing socket: %s",strerror(errno));
        exit(1);
      }

      /* handle the connection */
      handleconnection(csock,cfg);

    }
  }
}


/* write the current process id to the specified file */
static void write_pidfile(const char *filename)
{
  FILE *fp;
  if (filename!=NULL)
  {
    umask(0022);
    if ((fp=fopen(filename,"w"))==NULL)
    {
      log_log(LOG_ERR,"cannot open pid file (%s): %s",filename,strerror(errno));
      exit(1);
    }
    if (fprintf(fp,"%d\n",(int)getpid())<=0)
    {
      log_log(LOG_ERR,"error writing pid file (%s)",filename);
      exit(1);
    }
    if (fclose(fp))
    {
      log_log(LOG_ERR,"error writing pid file (%s): %s",filename,strerror(errno));
      exit(1);
    }
  }
}


/* try to install signal handler and check result */
static void install_sighandler(int signum,RETSIGTYPE (*handler) (int))
{
  struct sigaction act;
  memset(&act,0,sizeof(struct sigaction));
  act.sa_handler=handler;
  sigemptyset(&act.sa_mask);
  act.sa_flags=SA_RESTART|SA_NOCLDSTOP;
  if (sigaction(signum,&act,NULL)!=0)
  {
    log_log(LOG_ERR,"error installing signal handler for '%s': %s",signame(signum),strerror(errno));
    exit(1);
  }
}


/* the main program... */
int main(int argc,char *argv[])
{
  int i;
  int j;
  char *cvs_cmdline=NULL;
  struct cvsd_addrs *tmp,*nxt;
  struct cvsd_cfg *cfg;
#ifdef USE_CAPABILITIES
  cap_t caps;
#endif /* USE_CAPABILITIES */

  /* load the default configuration */
  cfg=cfg_new();

  /* clear the environment */
  environ=cfg->cvsenv;

  /* parse the command line */
  parse_cmdline(argc,argv,cfg);

  /* begin building command line */
  cfg_addcvsarg(cfg,"cvs");
  cfg_addcvsarg(cfg,"-f"); /* do not read ~/.cvsrc */
#ifdef DEBUG
  cfg_addcvsarg(cfg,"-t"); /* verbose */
#endif /* DEBUG */

  /* read the configuration file */
  read_configfile(cfg->configfile,cfg);

  /* specify cvs_command if not set earlier */
  if (cfg->cvscmd==NULL)
  {
    cfg->cvscmd=( (cfg->rootjail!=NULL) &&
                 (strcmp(cfg->rootjail,"none")!=0) )?"/bin/cvs":CVS_LOCATION;
  }
  log_log(LOG_DEBUG,"debug: cvscmd: %s",cfg->cvscmd);

  /* add cvs action */
  cfg_addcvsarg(cfg,"pserver"); /* run cvs as pserver */

  /* dump all arguments */
  for (i=0;cfg->cvsargs[i]!=NULL;i++)
    log_log(LOG_DEBUG,"debug: cvsargs[%d]: %s",i,cfg->cvsargs[i]);

  /* complete environment for cvs */
  cfg->cvsenv[CVSUMASK_IDX]=(char *)xmalloc(13*sizeof(char));
  i=snprintf(cfg->cvsenv[CVSUMASK_IDX],13,"CVSUMASK=%03o",cfg->umask);
  if ( (i<0) || (i>12) )
  {
    log_log(LOG_ERR,"fatal error saving umask in environment (probably a bug)");
    exit(1);
  }

  /* dump environment */
  for (i=0;cfg->cvsenv[i]!=NULL;i++)
    log_log(LOG_DEBUG,"debug: cvsenv[%d]: %s",i,cfg->cvsenv[i]);

  /* default address */
  if (cfg->addresses==NULL)
    cfg_addaddress(cfg,NULL,0,DEFAULT_ADDR,DEFAULT_PORT);

  /* daemonize */
  if ((!cfg->debugging)&&(daemon(0,0)<0))
  {
    log_log(LOG_ERR,"unable to daemonize: %s",strerror(errno));
    exit(1);
  }

  /* intilialize logging */
  if (!cfg->debugging)
    log_startlogging();
#ifdef DEBUG
  log_log(LOG_INFO,"version %s starting (debugging enabled)",VERSION);
#else /* DEBUG */
  log_log(LOG_INFO,"version %s starting",VERSION);
#endif /* not DEBUG */

  /* install handler to close stuff off on exit and log notice */
  atexit(exithandler);

  /* write pidfile */
  write_pidfile(cfg->pidfile);

  /* set the umask */
  umask(cfg->umask);

  /* start listening on addresses from configfile */
  for (tmp=cfg->addresses;tmp!=NULL;tmp=nxt)
  {
    listenonaddresses(tmp);
    nxt=tmp->next;
    freeaddrinfo(tmp->addrs);
    free(tmp->node);
    free(tmp->service);
    free(tmp);
  }
  cfg->addresses=NULL;

  /* do the chroot stuff */
  if ( (cfg->rootjail!=NULL) &&
       (strcmp(cfg->rootjail,"none")!=0) )
  {
    if (chdir(cfg->rootjail)!=0)
    {
      log_log(LOG_ERR,"cannot chdir(%s): %s",cfg->rootjail,strerror(errno));
      exit(1);
    }
    if (chroot(cfg->rootjail)!=0)
    {
      log_log(LOG_ERR,"cannot chroot(%s): %s",cfg->rootjail,strerror(errno));
      exit(1);
    }
    log_log(LOG_DEBUG,"debug: chroot(%s) done",cfg->rootjail);
  }
  /* just to be sure */
  chdir("/");

  /* renice */
  errno=0; /* for strange nice implementations */
  nice(cfg->nice);
  if (errno!=0)
  {
    log_log(LOG_ERR,"cannot nice(%d): %s",(int)cfg->nice,strerror(errno));
    exit(1);
  }
  log_log(LOG_DEBUG,"debug: nice(%d) done",(int)cfg->nice);

#ifdef HAVE_SETGROUPS
  /* drop all supplemental groups */
  if (setgroups(0,NULL)<0)
  {
    log_log(LOG_WARNING,"cannot setgroups(0,NULL) (ignored): %s",strerror(errno));
  }
  else
  {
    log_log(LOG_DEBUG,"debug: setgroups(0,NULL) done");
  }
#else /* HAVE_SETGROUPS */
  log_log(LOG_DEBUG,"debug: setgroups() not available");
#endif /* not HAVE_SETGROUPS */

#ifdef USE_CAPABILITIES
  /* if there are any capabilities defined, set them to be kept
     across setuid() calls so we can limit them later on */
  if (cfg->capabilities!=NULL)
  {
    if (prctl(PR_SET_KEEPCAPS,1))
    {
      log_log(LOG_ERR,"cannot prctl(PR_SET_KEEPCAPS,1): %s",strerror(errno));
      exit(1);
    }
    log_log(LOG_DEBUG,"debug: prctl(PR_SET_KEEPCAPS,1) done");
    /* dump the current capabilities */
    caps=cap_get_proc();
    log_log(LOG_DEBUG,"debug: current capabilities: %s",cap_to_text(caps,NULL));
    cap_free(caps);
  }
#endif /* USE_CAPABILITIES */

  /* change to cvs gid */
  if (cfg->gid!=NOGID)
  {
    if (setgid(cfg->gid)!=0)
    {
      log_log(LOG_ERR,"cannot setgid(%d): %s",(int)cfg->gid,strerror(errno));
      exit(1);
    }
    log_log(LOG_DEBUG,"debug: setgid(%d) done",cfg->gid);
  }

  /* change to cvs uid */
  if (cfg->uid!=NOUID)
  {
    if (setuid(cfg->uid)!=0)
    {
      log_log(LOG_ERR,"cannot setuid(%d): %s",(int)cfg->uid,strerror(errno));
      exit(1);
    }
    log_log(LOG_DEBUG,"debug: setuid(%d) done",cfg->uid);
  }

#ifdef USE_CAPABILITIES
  /* if there are any capabilities defined, limit them now */
  if (cfg->capabilities!=NULL)
  {
    /* dump the current capabilities */
    caps=cap_get_proc();
    log_log(LOG_DEBUG,"debug: current capabilities: %s",cap_to_text(caps,NULL));
    cap_free(caps);
    /* limit the capabilities */
    if (cap_set_proc(cfg->capabilities)!=0)
    {
      log_log(LOG_ERR,"cannot cap_set_proc(%s): %s",cap_to_text(cfg->capabilities,NULL),strerror(errno));
      exit(1);
    }
    log_log(LOG_DEBUG,"debug: cap_set_proc(%2) done",cap_to_text(cfg->capabilities,NULL));
    /* we no longer need this so we should free it */
    cap_free(cfg->capabilities);
    /* dump the current capabilities */
    caps=cap_get_proc();
    log_log(LOG_DEBUG,"debug: current capabilities: %s",cap_to_text(caps,NULL));
    cap_free(caps);
  }
#endif /* USE_CAPABILITIES */

  /* build cvs command line */
  j=strlen(cfg->cvscmd)+1;
  for (i=1;cfg->cvsargs[i]!=NULL;i++)
    j+=strlen(cfg->cvsargs[i])+1;
  cvs_cmdline=(char *)xmalloc(j*sizeof(char));
  strcpy(cvs_cmdline,cfg->cvscmd);
  for (i=1;cfg->cvsargs[i]!=NULL;i++)
  {
    strcat(cvs_cmdline," ");
    strcat(cvs_cmdline,cfg->cvsargs[i]);
  }
  log_log(LOG_DEBUG,"debug: cvs command to execute: '%s'",cvs_cmdline);

  /* install signalhandler for terminating children */
  install_sighandler(SIGCHLD,sigchld_handler);

  /* install signalhandlers for some other signals */
  install_sighandler(SIGHUP, sigexit_handler);
  install_sighandler(SIGINT, sigexit_handler);
  install_sighandler(SIGQUIT,sigexit_handler);
  install_sighandler(SIGILL, sigexit_handler);
  install_sighandler(SIGABRT,sigexit_handler);
  install_sighandler(SIGSEGV,sigexit_handler);
  install_sighandler(SIGPIPE,sigexit_handler);
  install_sighandler(SIGALRM,sigexit_handler);
  install_sighandler(SIGTERM,sigexit_handler);
  install_sighandler(SIGUSR1,sigexit_handler);
  install_sighandler(SIGUSR2,sigexit_handler);

  log_log(LOG_INFO,"accepting connections");

  /* start waiting for incoming connections */
  while (cvsd_exitsignal==0)
  {
    /* if we are ready to handle a connection do so */
    if ((cfg->maxconnections==0)||(cvsd_numchildren<cfg->maxconnections))
    {
      /* wait for a new connection */
      acceptconnection(cfg);
      /* handle exiting child processes */
      reap_deadchildren();
    }
    else /* not ready for connection */
    {
      /* log that the connections are full */
      log_log(LOG_INFO,"too many connections (%d), not accepting new connections",cvsd_numchildren);
      /* wait until children have died */
      while (cvsd_numchildren>=cfg->maxconnections)
      {
        /* sleep unblocks on a signal */
        sleep(SLEEPSECS);
        /* handle exiting child processes */
        reap_deadchildren();
      }
      /* log that the connections are full */
      log_log(LOG_INFO,"resuming accepting new connections");
    }
  }

  /* print something about received signals */
  if (cvsd_exitsignal!=0)
  {
    log_log(LOG_INFO,"caught signal %s (%d), shutting down",
                 signame(cvsd_exitsignal),cvsd_exitsignal);
  }

  return 1;
}
