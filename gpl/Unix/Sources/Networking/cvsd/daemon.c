/*
   daemon.c - implementation of daemon() for systems that lack it

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


#include "daemon.h"

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int daemon(int nochdir,int noclose)
{
  /* change directory */
  if (!nochdir)
    if (chdir("/")!=0)
      return -1;
  /* fork() and exit() to detach from the parent process */
  switch (fork())
  {
  case 0: /* we are the child */
    break;
  case -1: /* we are the parent, but have an error */
    return -1;
  default: /* we are the parent and we're done*/
    _exit(0);
  }
  /* become process leader */
  if (setsid()<0)
  {
    return -1;
  }
  /* fork again so we cannot allocate a pty */
  switch (fork())
  {
  case 0: /* we are the child */
    break;
  case -1: /* we are the parent, but have an error */
    return -1;
  default: /* we are the parent and we're done*/
    _exit(0);
  }
  /* close stdin, stdout and stderr and reconnect to /dev/null */
  if (!noclose)
  {
    close(0); /* stdin */
    close(1); /* stdout */
    close(2); /* stderr */
    open("/dev/null",O_RDWR); /* stdin, fd=0 */
    dup(0); /* stdout, fd=1 */
    dup(0); /* stderr, fd=2 */
  }
  return 0;
}
