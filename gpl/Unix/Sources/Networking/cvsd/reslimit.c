/*
   reslimit.c - resource limit functions

   Copyright (C) 2002, 2003 Arthur de Jong.

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

#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <errno.h>

#include "reslimit.h"
#include "xmalloc.h"
#include "log.h"


/* workaround for old BSD systems */
#ifndef RLIMIT_NOFILE
#define RLIMIT_NOFILE RLIMIT_OFILE
#endif


/* definition of all settable resources */
static struct resource {
  int resource;    /* the id of the resource for setrlimit() */
  char *name;      /* symbolic name of resource, see below */
  int type;        /* the type of the resource, see reslimit.h defines */
} knownresources[]= {
  { RLIMIT_CORE,    "coredumpsize", RESTYPE_SIZE },
  { RLIMIT_CORE,    "core",         RESTYPE_SIZE },
  { RLIMIT_CPU,     "cputime",      RESTYPE_TIME },
  { RLIMIT_CPU,     "cpu",          RESTYPE_TIME },
  { RLIMIT_DATA,    "datasize",     RESTYPE_SIZE },
  { RLIMIT_DATA,    "data",         RESTYPE_SIZE },
  { RLIMIT_FSIZE,   "filesize",     RESTYPE_SIZE },
  { RLIMIT_FSIZE,   "fsize",        RESTYPE_SIZE },
#ifdef RLIMIT_MEMLOCK
  { RLIMIT_MEMLOCK, "memorylocked", RESTYPE_SIZE },
  { RLIMIT_MEMLOCK, "memlock",      RESTYPE_SIZE },
#endif /* RLIMIT_MEMLOCK */
  { RLIMIT_NOFILE,  "openfiles",    RESTYPE_NUM  },
  { RLIMIT_NOFILE,  "nofile",       RESTYPE_NUM  },
#ifdef RLIMIT_NPROC
  { RLIMIT_NPROC,   "maxproc",      RESTYPE_NUM  },
  { RLIMIT_NPROC,   "nproc",        RESTYPE_NUM  },
#endif /* RLIMIT_NPROC */
#ifdef RLIMIT_RSS
  { RLIMIT_RSS,     "memoryuse",    RESTYPE_SIZE },
  { RLIMIT_RSS,     "rss",          RESTYPE_SIZE },
#endif /* RLIMIT_RSS */
  { RLIMIT_STACK,   "stacksize",    RESTYPE_SIZE },
  { RLIMIT_STACK,   "stack",        RESTYPE_SIZE },
#ifdef RLIMIT_AS
  { RLIMIT_AS,      "virtmem",      RESTYPE_SIZE },
  { RLIMIT_AS,      "as",           RESTYPE_SIZE },
#endif /* RLIMIT_AS */
#ifdef RLIMIT_VMEM
  { RLIMIT_VMEM,    "virtmem",      RESTYPE_SIZE },
#endif /* RLIMIT_VMEM */
#ifdef RLIMIT_PTHREAD
  { RLIMIT_PTHREAD, "pthreads",     RESTYPE_NUM  },
#endif /* RLIMIT_PTHREAD */
  { -1, NULL, -1 }
};


/* the list of resource limitations configured */
static struct reslimit
{
  struct resource *resource;
  struct rlimit limit;
  struct reslimit *next;
} *savedlimits=NULL;


/* find the resource record for the given name */
static struct resource *getresourcebyname(const char *name)
{
  struct resource *tmp;
  for (tmp=knownresources;tmp->name!=NULL;tmp++)
  {
    if (strcmp(name,tmp->name)==0)
    {
      return tmp;
    }
  }
  return NULL;
}


/* return the type of the resource defined by name */
int getresourcetype(const char *name)
{
  struct resource *res;
  res=getresourcebyname(name);
  if (res==NULL)
    return RESTYPE_UNKNOWN;
  return res->type;
}


/* save the limit to the specified values
   note: limit will be set only when setreslimits() is called */
void savereslimit(const char *name,rlim_t soft,rlim_t hard)
{
  struct resource *res;
  struct reslimit *lim;
  res=getresourcebyname(name);
  if (res==NULL)
  {
    log_log(LOG_ERR,"cannot find resource %s",name);
    exit(1);
  }
  lim=(struct reslimit *)xmalloc(sizeof(struct reslimit));
  lim->resource=res;
  lim->limit.rlim_cur=soft;
  lim->limit.rlim_max=hard;
  lim->next=savedlimits;
  savedlimits=lim;
}


/* set all the resources defined */
void setreslimits(void)
{
  struct reslimit *tmp;
  for (tmp=savedlimits;tmp!=NULL;tmp=tmp->next)
  {
    log_log(LOG_DEBUG,"debug: limit %s to %d(soft) and %d(hard)",
                  tmp->resource->name,
                  (int)(tmp->limit.rlim_cur),
                  (int)(tmp->limit.rlim_max));
    if (setrlimit(tmp->resource->resource,&(tmp->limit)))
    {
      log_log(LOG_ERR,"cannot limit %s: %s",tmp->resource->name,strerror(errno));
      exit(1);
    }
  }
}
