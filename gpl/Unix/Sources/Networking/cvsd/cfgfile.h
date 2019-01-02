/*
   cfgfile.h - handle configuration files

   Copyright (C) 2003 Arthur de Jong.

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


#ifndef _CFGFILE_H
#define _CFGFILE_H 1


#include "cfg.h"


/* read the configuration file and save settings in struct */
void read_configfile(const char *filename,struct cvsd_cfg *cfg);


#endif /* not _CFGFILE_H */
