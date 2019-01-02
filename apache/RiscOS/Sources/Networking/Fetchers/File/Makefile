# Copyright 1998 Acorn Computers Ltd
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# Makefile for File
#
# ***********************************
# ***	 C h a n g e   L i s t	  ***
# ***********************************
# Date	     Name   Description
# ----	     ----   -----------
# 10-Feb-98  SNB    Created
#

#
# Component specific options:
#
COMPONENT  = File
ROM_MODULE = aof.${COMPONENT}
RAM_MODULE = rm.${COMPONENT}
INSTDIR   ?= <Install$Dir>
TARGET    ?= ${COMPONENT}

RESFSDIR   = Resources.URL.${COMPONENT}

#
# Export Paths for Messages module
#
RESDIR = <resource$dir>.Resources2.URL

#
# Generic options:
#
MKDIR	= do mkdir -p
CC	= cc
CMHG	= cmhg
CP	= copy
LD	= link
RM	= remove
WIPE	= -wipe
XWIPE   = x wipe

CPFLAGS = ~cfr~v
WFLAGS  = ~c~v

CFLAGS	 = -c -depend !Depend ${INCLUDES} -zM -ffah -zps1 ${DFLAGS}
DFLAGS	 = -D${SYSTEM} -DCOMPAT_INET4 -UTML -UTRACE
ROMFLAGS = -DROM
INCLUDES = -IC:

#
# Libraries
#
ANSILIB	  = CLib:o.ansilib
CLIB	  = CLIB:o.stubs
RLIB	  = RISCOSLIB:o.risc_oslib
ROMCSTUBS = RISCOSLIB:o.romcstubs
ABSSYM	  = RISC_OSLib:o.abssym

OBJS =\
 o.module\
 o.processdir\
 o.readdata\
 o.ses_ctrl\
 o.start\
 o.status\
 o.stop\
 o.utils\
 o.FileHdr

RAM_OBJS =\
 o.moduleRAM\
 o.processdir\
 o.readdata\
 o.ses_ctrl\
 o.start\
 o.status\
 o.stop\
 o.utils\
 o.FileHdr

MSGSF=o.msgs

#
# Rule patterns
#
.c.o:;	  ${CC} ${CFLAGS} ${ROMFLAGS} -o $@ $<
.cmhg.o:; ${CMHG} -p -o $@ $< -d $*.h

FileHdr.h: FileHdr.o
	@|
#
# Main rules:
#
#
all: ${RAM_MODULE}
	@echo ${COMPONENT}: Module built (RAM)

rom: ${ROM_MODULE}
	@echo ${COMPONENT}: Module built (ROM)

install: ${RAM_MODULE}
	${MKDIR} ${INSTDIR}
	${CP} ${RAM_MODULE} ${INSTDIR}.${TARGET} ${CPFLAGS}
	@echo ${COMPONENT}: Module install (disc)

install_rom: ${ROM_MODULE}
	${CP} ${ROM_MODULE} ${INSTDIR}.${COMPONENT} ${CPFLAGS}
	@echo ${COMPONENT}: Module installed (ROM)

resources: Resources.${LOCALE}.Messages
	${MKDIR} ${RESDIR}
	${MKDIR} ${RESDIR}.${COMPONENT}
	${CP} Resources.${LOCALE}.* ${RESDIR}.${COMPONENT}.* ${CPFLAGS}
	@echo ${COMPONENT}: resource files copied to Messages module

clean:
	${XWIPE} o.* ${WFLAGS}
	${XWIPE} aof ${WFLAGS}
	${XWIPE} rm ${WFLAGS}
	${XWIPE} h.${COMPONENT}Hdr ${WFLAGS}
	${XWIPE} linked ${WFLAGS}
	${XWIPE} map ${WFLAGS}
	@echo ${COMPONENT}: cleaned

${ROM_MODULE}: ${OBJS} ${ROMCSTUBS}
	${MKDIR} aof
	${LD} -o $@ -aof ${OBJS} ${ROMCSTUBS}

# final link for ROM Image (using given base address)
rom_link:
	${MKDIR} linked
	${MKDIR} map
	${LD} -o linked.${COMPONENT} -bin -base ${ADDRESS} ${ROM_MODULE} ${ABSSYM} \
	      -map > map.${COMPONENT}
	truncate map.${COMPONENT} linked.${COMPONENT}
	${CP} linked.${COMPONENT} ${LINKDIR}.${COMPONENT} ${CPFLAGS}
	@echo ${COMPONENT}: rom_link complete

${MSGSF}: @.Resources.${LOCALE}.Messages
	resgen messages_file ${MSGSF} Resources.${LOCALE}.Messages ${RESFSDIR}.Messages

${RAM_MODULE}: ${RAM_OBJS} ${MSGSF} ${CLIB}
	${mkdir} rm
	${LD} -o $@ -module ${RAM_OBJS} ${MSGSF} ${CLIB}
	Access $@ RW/R

o.moduleRAM: module.c
	$(CC) ${CFLAGS} -o $@ module.c


#---------------------------------------------------------------------------
# Dynamic dependencies:
