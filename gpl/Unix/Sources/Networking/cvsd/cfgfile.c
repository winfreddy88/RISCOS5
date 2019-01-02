/*
   cfgfile.c - handle configuration files

   Copyright (C) 2002, 2003, 2004 Arthur de Jong.

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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>

#include "cfgfile.h"
#include "xmalloc.h"
#ifdef HAVE_SETRLIMIT
#include "reslimit.h"
#endif /* HAVE_SETRLIMIT */
#include "cfg.h"
#include "log.h"


/* maximum linelength in the configuration file */
#define MAX_LINE_LENGTH 1024


/* the maximum number of options on a line */
#define MAX_LINE_OPTIONS 10


/* find out the uid this string describes
   returns 1 on success, 0 on failure */
static int get_uid(const char *str,uid_t *val)
{
  struct passwd *pwent;
  char *tmp;
  /* check if it is a valid numerical uid */
  *val=(uid_t)strtol(str,&tmp,0);
  if ((*str!='\0')&&(*tmp=='\0'))
    return 1;
  /* find by name */
  pwent=getpwnam(str);
  if (pwent!=NULL)
  {
    *val=pwent->pw_uid;
    return 1;
  }
  return 0;
}


/* find the group id this string represents
   returns 1 on success, 0 on failure */
static int get_gid(const char *str,gid_t *val)
{
  struct group *grent;
  char *tmp;
  /* check if it is a valid numerical uid */
  *val=(gid_t)strtol(str,&tmp,0);
  if ((*str!='\0')&&(*tmp=='\0'))
    return 1;
  /* find by name */
  grent=getgrnam(str);
  if (grent!=NULL)
  {
    *val=grent->gr_gid;
    return 1;
  }
  return 0;
}


/* split a line from the configuration file
   note that this code is not thread safe!
   the line value will be rewritten! */
static char **parse_configline(char *line,int *nopt)
{
  static char *retv[MAX_LINE_OPTIONS];
  int opt;
  for (opt=0;opt<MAX_LINE_OPTIONS;opt++)
  {
    /* skip beginning spaces */
    while ((*line==' ')||(*line=='\t'))
      line++;
    /* check for end of line or comment */
    if ((*line=='\0')||(*line=='#'))
      break; /* we're done */
    /* we have a new keyword */
    retv[opt]=line;
    /* find the end of the token */
    while ((*line!=' ')&&(*line!='\t')&&(*line!='\0'))
      line++;
    /* mark the end of the token */
    if (*line!='\0')
      *line++='\0';
  }
  *nopt=opt;
  return retv;
}


/* parse a log statement from the configfile */
static void parse_option_log(const char *filename,int lnr,
                             char * const opts[],int nopts)
{
  int level;
  if ((nopts<=1)||(nopts>3))
  {
    log_log(LOG_ERR,"%s:%d: Log: wrong number of arguments",filename,lnr);
    exit(1);
  }
  /* get the loglevel */
  level=LOG_INFO;
  if (nopts==3)
  {
    if ((level=log_getloglevel(opts[2]))<0)
    {
      log_log(LOG_ERR,"%s:%d: Log: wrong loglevel '%s'",filename,lnr,opts[2]);
      exit(1);
    }
  }
  /* find the method */
  if ( strcmp(opts[1],"none")==0 )
    log_addlogging_none();
  else if ( strcmp(opts[1],"syslog")==0 )
    log_addlogging_syslog(level);
  else if ( opts[1][0]=='/' )
    log_addlogging_file(opts[1],level);
  else
  {
    log_log(LOG_ERR,"%s:%d: Log: wrong argument '%s'",filename,lnr,opts[1]);
    exit(1);
  }
}


/* read the configuration file and save settings in struct */
void read_configfile(const char *filename,struct cvsd_cfg *cfg)
{
  FILE *fp;
  int lnr=0;
  char line[MAX_LINE_LENGTH];
  char *tmp;
  char **opts;
  int nopts;
  int i;
  int numrepos=0;
#ifdef HAVE_SETRLIMIT
  rlim_t resval;
#endif /* HAVE_SETRLIMIT */
  /* open configuration file */
  if ((fp=fopen(filename,"r"))==NULL)
  {
    log_log(LOG_ERR,"cannot open config file (%s): %s",filename,strerror(errno));
    exit(1);
  }
  log_log(LOG_DEBUG,"debug: reading config file (%s)",filename);
  /* read all lines in the file */
  while (fgets(line,MAX_LINE_LENGTH,fp)!=NULL)
  {
    lnr++;
    /* strip newline */
    i=(int)strlen(line);
    if ((i<=0)||(line[i-1]!='\n'))
    {
      log_log(LOG_ERR,"%s:%d: line too long or last line missing newline",filename,lnr);
      exit(1);
    }
    line[i-1]='\0';
    /* split the line in tokens */
    opts=parse_configline(line,&nopts);
    /* find identifier */
    if (nopts==0)
    {} /* ignore empty lines */
    else if (strcmp(opts[0],"RootJail")==0)
    {
      if (nopts!=2)
      {
        log_log(LOG_ERR,"%s:%d: RootJail: wrong number of arguments",filename,lnr);
        exit(1);
      }
      /* only accept absolute paths. abort otherwise.*/
      if ((*opts[1]!='/')&&(strcmp(opts[1],"none")!=0))
      {
        log_log(LOG_ERR,"%s:%d: RootJail: '%s' must be an absolute path or 'none'",filename,lnr,opts[1]);
        exit(1);
      }
      /* save value */
      if (cfg->rootjail!=NULL)
      {
        log_log(LOG_ERR,"%s:%d: RootJail: can only be specified once",filename,lnr);
      }
      else
      {
        cfg->rootjail=xstrdup(opts[1]);
      }
    }
    else if (strcmp(opts[0],"Nice")==0)
    {
      if (nopts!=2)
      {
        log_log(LOG_ERR,"%s:%d: Nice: wrong number of arguments",filename,lnr);
        exit(1);
      }
      /* check if it is a valid numerical uid */
      cfg->nice=(int)strtol(opts[1],&tmp,0);
      if (*tmp!='\0')
      {
        log_log(LOG_ERR,"%s:%d: Nice: wrong argument '%s'",filename,lnr,opts[1]);
        exit(1);
      }
    }
    else if (strcmp(opts[0],"Uid")==0)
    {
      if (nopts!=2)
      {
        log_log(LOG_ERR,"%s:%d: Uid: wrong number of arguments",filename,lnr);
        exit(1);
      }
      if (!get_uid(opts[1],&cfg->uid))
      {
        log_log(LOG_ERR,"%s:%d: Uid: wrong argument '%s'",filename,lnr,opts[1]);
        exit(1);
      }
    }
    else if (strcmp(opts[0],"Gid")==0)
    {
      if (nopts!=2)
      {
        log_log(LOG_ERR,"%s:%d: Gid: wrong number of arguments",filename,lnr);
        exit(1);
      }
      if (!get_gid(opts[1],&cfg->gid))
      {
        log_log(LOG_ERR,"%s:%d: Gid: wrong argument '%s'",filename,lnr,opts[1]);
        exit(1);
      }
    }
    else if (strcmp(opts[0],"Listen")==0)
    {
      if (nopts==2)
      {
        /* accept [node]:service and [node].service */
        if (tmp=strrchr(opts[1],']'),(tmp!=NULL)&&(opts[1][0]=='[')&&((tmp[1]=='.')||(tmp[1]==':')))
        {
          *tmp='\0';
          cfg_addaddress(cfg,filename,lnr,opts[1]+1,tmp+2);
        }
        /* accept nodewithoutcolons:service */
        else if ((tmp=strchr(opts[1],':'),(tmp!=NULL)&&(tmp==strrchr(opts[1],':'))))
        {
          *tmp='\0';
          cfg_addaddress(cfg,filename,lnr,opts[1],tmp+1);
        }
        /* accept nodewithoutdots.service */
        else if ((tmp=strchr(opts[1],'.'),(tmp!=NULL)&&(tmp==strrchr(opts[1],'.'))))
        {
          *tmp='\0';
          cfg_addaddress(cfg,filename,lnr,opts[1],tmp+1);
        }
        else
        {
          log_log(LOG_ERR,"%s:%d: Listen: wrong argument '%s'",filename,lnr,opts[1]);
          exit(1);
        }
      }
      else if (nopts==3)
      {
        cfg_addaddress(cfg,filename,lnr,opts[1],opts[2]);
      }
      else
      {
        log_log(LOG_ERR,"%s:%d: Listen: wrong number of arguments",filename,lnr);
        exit(1);
      }
    }
    else if (strcmp(opts[0],"MaxConnections")==0)
    {
      if (nopts!=2)
      {
        log_log(LOG_ERR,"%s:%d: MaxConnections: wrong number of arguments",filename,lnr);
        exit(1);
      }
      cfg->maxconnections=(int)strtol(opts[1],&tmp,0);
      if (*tmp!='\0')
      {
        log_log(LOG_ERR,"%s:%d: MaxConnections: wrong argument '%s'",filename,lnr,opts[1]);
        exit(1);
      }
    }
    else if (strcmp(opts[0],"Repos")==0)
    {
      if (nopts!=2)
      {
        log_log(LOG_ERR,"%s:%d: Repos: wrong number of arguments",filename,lnr);
        exit(1);
      }
      /* only accept absolute paths. abort otherwise.*/
      if (*opts[1]!='/')
      {
        log_log(LOG_ERR,"%s:%d: Repos: '%s' must be an absolute path",filename,lnr,opts[1]);
        exit(1);
      }
      /* add --allow-root=path to cvs parameters */
      tmp=(char *)xmalloc((13+strlen(opts[1])+1)*sizeof(char));
      strcpy(tmp,"--allow-root=");
      strcat(tmp,opts[1]);
      cfg_addcvsarg(cfg,tmp);
      numrepos++;
    }
    else if (strcmp(opts[0],"PidFile")==0)
    {
      if (nopts!=2)
      {
        log_log(LOG_ERR,"%s:%d: PidFile: wrong number of arguments",filename,lnr);
        exit(1);
      }
      /* only accept absolute paths. abort otherwise.*/
      if (*opts[1]!='/')
      {
        log_log(LOG_ERR,"%s:%d: PidFile: '%s' must be an absolute path",filename,lnr,opts[1]);
        exit(1);
      }
      if (cfg->pidfile!=NULL)
      {
        log_log(LOG_ERR,"%s:%d: PidFile: can only be specified once",filename,lnr);
        exit(1);
      }
      else
      {
        cfg->pidfile=xstrdup(opts[1]);
      }
    }
    else if (strcmp(opts[0],"CvsCommand")==0)
    {
      if (nopts!=2)
      {
        log_log(LOG_ERR,"%s:%d: CvsCommand: wrong number of arguments",filename,lnr);
        exit(1);
      }
      /* only accept absolute paths, abort otherwise */
      if (*opts[1]!='/')
      {
        log_log(LOG_ERR,"%s:%d: CvsCommand: '%s' must be an absolute path",filename,lnr,opts[1]);
        exit(1);
      }
      /* save value */
      if (cfg->cvscmd!=NULL)
      {
        log_log(LOG_ERR,"%s:%d: CvsCommand: can only be specified once",filename,lnr);
        exit(1);
      }
      else
      {
        cfg->cvscmd=xstrdup(opts[1]);
      }
    }
    else if (strcmp(opts[0],"CvsArgs")==0)
    {
      if (nopts<2)
      {
        log_log(LOG_ERR,"%s:%d: CvsArgs: wrong number of arguments",filename,lnr);
        exit(1);
      }
      for (i=1;i<nopts;i++)
      {
        /* TODO: check if arguments look like valid cvs parameters and issue warning otherwise */
        tmp=(char *)xmalloc((strlen(opts[i])+1)*sizeof(char));
        strcpy(tmp,opts[i]);
        cfg_addcvsarg(cfg,tmp);
      }
    }
    else if (strcmp(opts[0],"Limit")==0)
    {
#ifdef HAVE_SETRLIMIT
      if (nopts!=3)
      {
        log_log(LOG_ERR,"%s:%d: Limit: wrong number of arguments",filename,lnr);
        exit(1);
      }
      /* read value */
      if ( (strcmp(opts[2],"none")==0) ||
           (strcmp(opts[2],"inf")==0) ||
           (strcmp(opts[2],"unlimited")==0) )
        resval=RLIM_INFINITY;
      else
        resval=0;
      switch (getresourcetype(opts[1]))
      {
      case RESTYPE_NUM:  /* numeric value */
      case RESTYPE_SIZE: /* size value */
        if (resval==RLIM_INFINITY) break;
        resval=(rlim_t)strtol(opts[2],&tmp,0);
        if ((tmp[0]=='k')&&(tmp[1]=='\0'))
          resval*=(rlim_t)1024;
        else if ((tmp[0]=='m')&&(tmp[1]=='\0'))
          resval*=(rlim_t)(1024*1024);
        else if ((tmp[0]!='\0')&&(tmp[0]!='b'))
        {
          log_log(LOG_ERR,"%s:%d: Limit: wrong value '%s'",filename,lnr,opts[2]);
          exit(1);
        }
        break;
      case RESTYPE_TIME: /* time value */
        if (resval==RLIM_INFINITY) break;
        resval=(rlim_t)strtol(opts[2],&tmp,0);
        if ((tmp[0]=='m')&&(tmp[1]=='\0'))
          resval*=(rlim_t)60;
        else if ((tmp[0]==':')&&(tmp[1]!='\0'))
        {
          tmp++;
          resval*=(rlim_t)60;
          resval+=(rlim_t)strtol(tmp,&tmp,0);
          if (tmp[0]!='\0')
          {
            log_log(LOG_ERR,"%s:%d: Limit: wrong value '%s'",filename,lnr,opts[2]);
            exit(1);
          }
        }
        else if ((tmp[0]!='\0')&&(tmp[0]!='s'))
        {
          log_log(LOG_ERR,"%s:%d: Limit: wrong value '%s'",filename,lnr,opts[2]);
          exit(1);
        }
        break;
      default:
        log_log(LOG_ERR,"%s:%d: Limit: unknown or unsupported resource '%s'",filename,lnr,opts[1]);
        exit(1);
      }
      /* save the limit, execute with setreslimits() */
      savereslimit(opts[1],resval,resval);
#else /* HAVE_SETRLIMIT */
      log_log(LOG_ERR,"%s:%d: Limit: not supported on this system",filename,lnr);
      exit(1);
#endif /* not HAVE_SETRLIMIT */
    }
#ifdef USE_CAPABILITIES
    else if (strcmp(opts[0],"Capabilities")==0)
    {
      /* TODO: fix this because capabilities may be space separated */
      if (nopts!=2)
      {
        log_log(LOG_ERR,"%s:%d: Capabilities: wrong number of arguments",filename,lnr);
        exit(1);
      }
      /* save value */
      if (cfg->capabilities!=NULL)
      {
        log_log(LOG_ERR,"%s:%d: Capabilities: can only be specified once",filename,lnr);
      }
      else if ((cfg->capabilities=cap_from_text(opts[1]))==NULL)
      {
        log_log(LOG_ERR,"%s:%d: Capabilities: wrong value '%s': %s",filename,lnr,opts[1],strerror(errno));
        exit(1);
      }
    }
#endif /* USE_CAPABILITIES */
    else if (strcmp(opts[0],"Umask")==0)
    {
      if (nopts!=2)
      {
        log_log(LOG_ERR,"%s:%d: Umask: wrong number of arguments",filename,lnr);
        exit(1);
      }
      /* check if it is a valid numerical uid */
      cfg->umask=(mode_t)strtol(opts[1],&tmp,8);
      if ((*tmp!='\0')||(cfg->umask<0000)||(cfg->umask>0777))
      {
        log_log(LOG_ERR,"%s:%d: Umask: wrong argument '%s'",filename,lnr,opts[1]);
        exit(1);
      }
    }
    else if (strcmp(opts[0],"Log")==0)
      parse_option_log(filename,lnr,opts,nopts);
    else
    {
      log_log(LOG_ERR,"%s:%d: unrecognized line",filename,lnr);
      exit(1);
    }
  }
  fclose(fp);
  if (numrepos==0)
  {
    log_log(LOG_ERR,"%s: contains no 'Repos' statements",filename);
    exit(1);
  }
  log_log(LOG_DEBUG,"debug: done reading config file");
}
