/*
   reslimit.h - resource limit functions

   Copyright (C) 2002 Arthur de Jong.

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


#ifndef _RESLIMIT_H
#define _RESLIMIT_H 1


#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>


/* the types resources can be */
#define RESTYPE_UNKNOWN -1
#define RESTYPE_SIZE     1
#define RESTYPE_TIME     2
#define RESTYPE_NUM      3


/* return the type of the resource defined by name */
int getresourcetype(const char *name);


/* save the limit to the specified values
   note: limit will be set only when setreslimits() is called */
void savereslimit(const char *name,rlim_t soft,rlim_t hard);


/* set all the resources defined */
void setreslimits(void);


#endif /* not _RESLIMIT_H */
