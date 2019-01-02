/*
   cfg.c - all the configurable options in cvsd

   Copyright (C) 2003, 2004, 2006 Arthur de Jong.

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

#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#ifdef HAVE_NETDB_H
#include <netdb.h>
#endif /* HAVE_NETDB_H */
#ifndef HAVE_GETADDRINFO
#include "getinfos.h"
#endif /* not HAVE_GETADDRINFO */

#include "xmalloc.h"
#include "cfg.h"
#include "log.h"


/* note: if you change this, be sure to also change CVSUMASK_IDX in cfg.h */
static char *default_environment[] = {
  "HOME=/",
  "PATH=/bin",
  "SHELL=/bin/sh",
  "TMPDIR=/tmp",
  NULL, /* this will be set to CVSUMASK=<cvs_umask> */
  NULL
};


/* initialize the configuration with some reasonable default values */
struct cvsd_cfg *cfg_new()
{
  struct cvsd_cfg *cfg;
  cfg=(struct cvsd_cfg *)xmalloc(sizeof(struct cvsd_cfg));
  cfg->configfile = DEFAULT_CONFIGFILE;
  cfg->pidfile    = NULL;
  cfg->debugging  = 0;
  cfg->rootjail   = NULL;
  cfg->uid        = NOUID;
  cfg->gid        = NOGID;
  cfg->nice       = 0;
  cfg->umask      = 0027;
#ifdef USE_CAPABILITIES
  cfg->capabilities = NULL;
#endif /* USE_CAPABILITIES */
  cfg->addresses  = NULL;
  cfg->maxconnections = 0;
  cfg->cvscmd     = NULL; /* default is set according to configured rootjail */
  cfg->cvsargs    = NULL; /* autom. allocated by add_cvsarg() */
  cfg->cvsenv     = default_environment;
  return cfg;
}


/* add a string as a command line argument to the cvs command */
void cfg_addcvsarg(struct cvsd_cfg *cfg,const char *arg)
{
  static int sz=0; /* size of array */
  static int cn=0; /* number of elements */
  char **tmp;
  int nsz;
  /* first ensure array is large enough */
  if ((cn+2)>sz)
  {
    if (sz==0)
      nsz=10;
    else
      nsz=sz*2;
    tmp=(char **)xmalloc(nsz*sizeof(char *));
    if (cfg->cvsargs!=NULL)
      memcpy(tmp,cfg->cvsargs,sz*sizeof(char *));
    cfg->cvsargs=tmp;
    sz=nsz;
  }
  /* add string to end of array */
  cfg->cvsargs[cn++]=(char *)arg;
  cfg->cvsargs[cn]=NULL;
}


/* add the given node and service to the list of addresses that
   will be listened on */
void cfg_addaddress(struct cvsd_cfg *cfg,
                    const char *filename,int lnr,
                    const char *node,const char *service)
{
  struct cvsd_addrs *addr,*tmp;
  struct addrinfo hints;
  int i;

  /* create space to store address */
  addr=(struct cvsd_addrs *)xmalloc(sizeof(struct cvsd_addrs));
  addr->node=xstrdup(node);
  addr->service=xstrdup(service);
  addr->addrs=NULL;
  addr->next=NULL;

  /* some aliases for the unspecified address */
  if ((strcmp(node,"*")==0)||(strcmp(node,"")==0))
    node=NULL;

  /* create the name for the socket */
  memset(&hints,0,sizeof(struct addrinfo));
  hints.ai_flags=AI_PASSIVE;
  hints.ai_family=PF_UNSPEC;
  hints.ai_socktype=SOCK_STREAM;
  switch (i=getaddrinfo(node,service,&hints,&(addr->addrs)))
  {
    case 0: break;
    case EAI_SYSTEM:
      if (filename==NULL)
        log_log(LOG_ERR,"getaddrinfo() failed: %s",strerror(errno));
      else
        log_log(LOG_ERR,"%s:%d: getaddrinfo() failed: %s",
                    filename,lnr,strerror(errno));
      exit(1);
    default:
      if (filename==NULL)
        log_log(LOG_ERR,"getaddrinfo() failed: %s",gai_strerror(i));
      else
        log_log(LOG_ERR,"%s:%d: getaddrinfo() failed: %s",
                    filename,lnr,gai_strerror(i));
      exit(1);
  }
  if (addr->addrs==NULL)
  {
    log_log(LOG_ERR,"%s:%d: getaddrinfo() returned no usable addresses",filename,lnr);
    exit(1);
  }

  /* save the address */
  if (cfg->addresses==NULL)
    cfg->addresses=addr;
  else
  {
    for (tmp=cfg->addresses;tmp->next!=NULL;tmp=tmp->next);
    tmp->next=addr;
  }
}


