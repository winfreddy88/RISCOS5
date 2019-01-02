/*
   getinfos.h - definition of getaddrinfo(), getnameinfo() and related
                functions for systems that lack it
                note that these functions are implemented only for use
                in cvsd and are probably incomplete for other purposes

   Copyright (C) 2002 Arthur de Jong

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


#ifndef _GETINFOS_H
#define _GETINFOS_H 1


#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>


/* errors for both getaddrinfo() and getnameinfo() */
#define EAI_OK         0
#define EAI_SYSTEM   -11
#define EAI_WRONGNODE  2
#define EAI_WRONSERVC  3
#define EAI_WRONGSOCK  4
#define EAI_HERR       5

/* macros for the ai_flags field  */
#define AI_PASSIVE 0x0001

/* macros for the getnameinf() flags parameter */
#define NI_NUMERICHOST 0x0001
#define NI_NUMERICSERV 0x0002

/* macros for systems that don't have them */
#ifndef AF_INET6
#define AF_INET6 -1
#endif /* not AF_INET6 */

/* the structure used by getaddrinfo() for passing address information */
struct addrinfo
{
  int     ai_flags;
  int     ai_family;
  int     ai_socktype;
  int     ai_protocol;
  size_t  ai_addrlen;
  struct sockaddr *ai_addr;
  char   *ai_canonname; /* used nowhere */
  struct addrinfo *ai_next;
};


/* very poor implementation, see getaddrinfo.c for details */
int getaddrinfo(const char *node,const char *service,
                const struct addrinfo *hints,
                struct addrinfo **res);


/* poor implementation of getnameinfo() doing no name lookups */
int getnameinfo(const struct sockaddr *sa,socklen_t salen,
                char *host,size_t hostlen,
                char *serv,size_t servlen,int flags);


/* free address information allocated by getaddrinfo */
void freeaddrinfo(struct addrinfo *res);


/* translate an error codes returned by getaddrinfo() and
   getnameinfo() to printable error strings */
const char *gai_strerror(int errcode);


#endif /* not _GETINFOS_H */
