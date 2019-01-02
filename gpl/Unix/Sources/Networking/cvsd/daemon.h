/*
   daemon.h - definition of daemon() for systems that lack it

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


#ifndef _DAEMON_H
#define _DAEMON_H 1


#include <unistd.h>


/* deamonize process, optionally chdir to / and optionally close stdin,
   strdout and stderr and redirect them to /dev/null */
int daemon(int nochdir,int noclose);


#endif /* not _DAEMON_H */
