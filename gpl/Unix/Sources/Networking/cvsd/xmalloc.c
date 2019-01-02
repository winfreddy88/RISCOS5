/*
   xmalloc.c - malloc wrapper

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

#include <stdlib.h>
#include <string.h>

#include "xmalloc.h"
#include "log.h"


/* malloc wrapper */
void *xmalloc(size_t size)
{
  void *tmp;
  if ((tmp=malloc(size))==NULL)
  {
    log_log(LOG_CRIT,"malloc() failed");
    exit(1);
  }
  return tmp;
}

/* strdup wrapper */
char *xstrdup(const char *s)
{
  char *tmp;
  int l;
  if (s==NULL)
  {
    log_log(LOG_CRIT,"xstrdup() called with NULL");
    exit(1);
  }
  l=strlen(s);
  tmp=(char *)xmalloc((l+1)*sizeof(char));
  strncpy(tmp,s,l);
  tmp[l]='\0';
  return tmp;
}
