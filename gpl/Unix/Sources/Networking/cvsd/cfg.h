/*
   cfg.h - all the configurable options in cvsd

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


#ifndef _CVSDCFG_H
#define _CVSDCFG_H 1


#include <unistd.h>
#include <sys/types.h>
#ifdef USE_CAPABILITIES
#include <sys/capability.h>
#endif /* USE_CAPABILITIES */

/* values for uid and gid */
#define NOUID ((gid_t)-1)
#define NOGID ((gid_t)-1)


/* the index where to set CVSUMASK=<cvs_umask> in cfg->cvsenv
   see also the static char *default_environment in cfg.c */
#define CVSUMASK_IDX 4


/* the addresses to listen on */
struct cvsd_addrs
{
  char *node;              /* supplied node(address) name in config */
  char *service;           /* supplied service(port) name in config */
  struct addrinfo *addrs;  /* addresses asiciated with node+service */
  struct cvsd_addrs *next; /* next configured node+service */
};


/* default address/port combination to listen on
   if nothing is supplied in the config file */
#define DEFAULT_ADDR "*"
#define DEFAULT_PORT "2401"


/* struct to hold all configuration information
   initial values are set in cfg_new() */
struct cvsd_cfg
{

  /* the configuration file
     DEFAULT_CONFIGFILE is set in config.h */
  char *configfile;

  /* the pid file
     default is no pidfile (NULL) */
  char *pidfile;

  /* whether debugging mode is enabled */
  int debugging;

  /* the location of the rootjail
     NULL or "none": no chroot */
  char *rootjail;

  /* the user id cvs should be run as
     NOUID: don't change */
  uid_t uid;

  /* the group id cvs should be run as
     NOGID: don't change */
  gid_t gid;

  /* the nice value the daemon should run as
     0: don't change */
  int nice;

  /* the umask that should be used to create files */
  mode_t umask;

  /* TODO: limits (are currently stored in structures in reslimit.c)*/

#ifdef USE_CAPABILITIES
  /* the capabilities for cvs */
  cap_t capabilities;
#endif /* USE_CAPABILITIES */

  /* the addresses/ports that should be listened on */
  struct cvsd_addrs *addresses;

  /* the maximum number of connections to handle
     0: unlimited */
  int maxconnections;

  /* TODO: repositories (currently only added to cvsargs below) */

  /* the command that will be run (location of the binary) */
  char *cvscmd;

  /* the arguments that will be passed */
  char **cvsargs;

  /* the environment that should be used */
  char **cvsenv;

};


/* initialize the configuration with some reasonable default values */
struct cvsd_cfg *cfg_new(void);


/* add a string as a command line argument to the cvs command */
void cfg_addcvsarg(struct cvsd_cfg *cfg,const char *arg);


/* add the given node and service to the list of addresses that
   will be listened on */
void cfg_addaddress(struct cvsd_cfg *cfg,
                    const char *filename,int lnr,
                    const char *node,const char *service);

#endif /* not _CVSDCFG_H */
