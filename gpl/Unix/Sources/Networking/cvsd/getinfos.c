/*
   getinfos.c - implementation of getaddrinfo(), getnameinfo() and related
                functions for systems that lack it
                note that these functions are implemented only for use
                in cvsd and are probably incomplete for other purposes

   Copyright (C) 2002, 2003 Arthur de Jong

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

#include "getinfos.h"
#include "xmalloc.h"

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#ifdef HAVE_NETDB_H
#include <netdb.h>
#endif /* HAVE_NETDB_H */


/* this is a very poor implementation of the getaddrinfo() function
   it only returns IPv4 stream addresses, regardless of the input
   only numericly specified services (port numbers) are supported
   hints are completely ignored */
int getaddrinfo(const char *node, const char *service,
                const struct addrinfo *hints,
                struct addrinfo **res)
{
  char *tmp;
  struct sockaddr_in *addr;
  struct hostent *hent;
  *res=NULL;
  /* allocate address */
  addr=(struct sockaddr_in *)xmalloc(sizeof(struct sockaddr_in));
  addr->sin_family=AF_INET;
  /* check node */
  if ((node==NULL)||
      (strcmp(node,"*")==0)||
      (strcmp(node,"0.0.0.0")==0))
    addr->sin_addr.s_addr=INADDR_ANY;
  else if ((hent=gethostbyname(node))!=NULL)
    memcpy(&addr->sin_addr.s_addr,hent->h_addr,4);
  else
  {
    free(addr);
    return EAI_HERR;
  }
  /* check service */
  /* TODO: maybe use getservbyname() */
  addr->sin_port=htons((int)strtol(service,&tmp,0));
  if (*tmp!='\0')
  {
    free(addr);
    return EAI_WRONSERVC;
  }
  /* build result */
  *res=(struct addrinfo *)xmalloc(sizeof(struct addrinfo));
  (*res)->ai_flags=0;
  (*res)->ai_family=AF_INET;
  (*res)->ai_socktype=SOCK_STREAM;
  (*res)->ai_protocol=0;
  (*res)->ai_addrlen=(socklen_t)sizeof(struct sockaddr_in);
  (*res)->ai_addr=(struct sockaddr *)addr;
  (*res)->ai_canonname=NULL;
  (*res)->ai_next=NULL;
  /* and we're done */
  return EAI_OK;
}


/* this is a poor implementation of getnameinfo()
   it lacks name lookups and only returns numeric values */
int getnameinfo(const struct sockaddr *sa,socklen_t salen,
                char *host,size_t hostlen,
                char *serv,size_t servlen,int flags)
{
  const struct sockaddr_in *caddr;
  caddr=(const struct sockaddr_in *)sa;
  if (salen!=(socklen_t)sizeof(struct sockaddr_in))
    return EAI_WRONGSOCK;
  /* save ip */
  if ((host!=NULL)&&(hostlen>0))
  {
    /* TODO: use gethostbyaddr() or getipnodebyaddr() */
    snprintf(host,hostlen,"%s",inet_ntoa(caddr->sin_addr));
    host[hostlen-1]='\0';
  }
  /* save port */
  if ((serv!=NULL)&&(servlen>0))
  {
    /* TODO: use getservbyport() */
    snprintf(serv,servlen,"%d",(int)ntohs(caddr->sin_port));
    serv[servlen-1]='\0';
  }
  return EAI_OK;
}


/* free address information allocated by getaddrinfo */
void freeaddrinfo(struct addrinfo *res)
{
  /* do recursively */
  if (res==NULL) return;
  freeaddrinfo(res->ai_next);
  /* free memory */
  free(res->ai_addr);
  free(res);
}


/* translate an error codes returned by getaddrinfo() and
   getnameinfo() to printable error strings */
const char *gai_strerror(int errcode)
{
  switch (errcode)
  {
    case EAI_OK:             return "nothing wrong";
    case EAI_SYSTEM:         return "see errno";
    case EAI_WRONGNODE:      return "currently only '*' is supported";
    case EAI_WRONSERVC:      return "only support for numeric services";
    case EAI_WRONGSOCK:      return "wrong socket type returned";
#ifdef HAVE_HSTRERROR
    case EAI_HERR:           return hstrerror(h_errno);
#else /* HAVE_HSTRERROR */
    case EAI_HERR:
      switch(h_errno)
      {
#ifdef HOST_NOT_FOUND
        case HOST_NOT_FOUND: return "host not found";
#endif /* HOST_NOT_FOUND */
#ifdef NO_ADDRESS
        case NO_ADDRESS:     return "no address associated with that name";
#else /* NO_ADDRESS */
#ifdef NO_DATA
        case NO_DATA:        return "no address associated with that name";
#endif /* NO_DATA */
#endif /* not NO_ADDRESS */
#ifdef NO_RECOVERY
        case NO_RECOVERY:    return "unrecoverable error";
#endif /* NO_RECOVERY */
#ifdef TRY_AGAIN
        case TRY_AGAIN:      return "temporary error";
#endif /* TRY_AGAIN */
        default:             return "unknown";
      }
#endif /* not HAVE_HSTRERROR */
    default:                 return "unknown";
  }
}
