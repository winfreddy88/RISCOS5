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
# Makefile for WebServe
#
# ***********************************
# ***	 C h a n g e   L i s t	  ***
# ***********************************
# Date	     Name   Description
# ----	     ----   -----------
# 11-Feb-98  SNB    Created
# 30-Apr-98  SNB    Added trace build option
#
.SUFFIXES: .c .o .od

#
# Component specific options:
#
COMPONENT = WebServe

INSTDIR ?= <Install$Dir>
EXPDIR = Export
TARGET = aif.!RunImage

#
# Generic options:
#
CHMOD	= access
MKDIR	= do mkdir -p
CC	= cc
CMHG	= cmhg
CP	= copy
LD	= link
RM	= remove
SQZ	= squeeze
WIPE	= x wipe

CPFLAGS = ~cfr~v
WFLAGS  = ~c~vr

SQZFLAGS =
CFLAGS	 = -c -depend !Depend ${INCLUDES} -ffah -Wp ${DFLAGS}
DFLAGS	 = -D${SYSTEM} -DCOMPAT_INET4 -UTML
INCLUDES = -ITbox:,TCPIPLibs:,C:

#
# Libraries
#
CLIB	  = CLIB:o.stubs
TBOXLIBS  = TBox:o.eventlib TBox:o.wimplib TBox:o.toolboxlib
TCPIPLIBS = TCPIPLIBS:o.inetlib TCPIPLIBS:o.socklib TCPIPLIBS:o.unixlib


OBJS =\
 o.cache\
 o.checkloop\
 o.config\
 o.debug\
 o.dialler\
 o.filemanage\
 o.generic\
 o.headers\
 o.italkmsg\
 o.main\
 o.messages\
 o.network\
 o.process\
 o.quit\
 o.serve\
 o.URLclient


DEBOBJS =\
 od.cache\
 od.checkloop\
 od.config\
 od.debug\
 od.dialler\
 od.filemanage\
 od.generic\
 od.headers\
 od.italkmsg\
 od.main\
 od.messages\
 od.network\
 od.process\
 od.quit\
 od.serve\
 od.URLclient


#
# Rule patterns
#
.c.o:;	  ${CC} ${CFLAGS} -o $@ $<
.c.od:;	  ${CC} ${CFLAGS} -DTRACE -DUSE_SYSLOG -fn -o $@ $<

#
# Main rules:
#
#
all: ${TARGET}
	@echo ${COMPONENT}: !RunImage built

trace: ${TARGET}T

install: all
	${MKDIR} ${EXPDIR}
	${CP} CommonBase.* ${EXPDIR}.* ${CPFLAGS}
	${CP} Resources.${LOCALE}.* ${EXPDIR}.* ${CPFLAGS}
	${SQZ} ${TARGET} ${EXPDIR}.!${COMPONENT}.!RunImage ${SQZFLAGS}
	${MKDIR} ${INSTDIR}
	${CP} ${EXPDIR}.!${COMPONENT} ${INSTDIR}.!${COMPONENT} ${CPFLAGS}
	@echo ${COMPONENT}: installed (disc)

clean:
	${WIPE} o.* ${WFLAGS}
	${WIPE} aif ${WFLAGS}
	${WIPE} ${EXPDIR} ${WFLAGS}
	${WIPE} od.* ${WFLAGS}
	@echo ${COMPONENT}: cleaned

${TARGET}: ${OBJS} ${CLIB} ${TBOXLIBS} ${TCPIPLIBS}
	${mkdir} aif
	${LD} -aif -o $@ ${OBJS} ${TBOXLIBS} ${TCPIPLIBS} ${CLIB}
	Access $@ RW/R

${TARGET}T: ${DEBOBJS} ${CLIB} ${TBOXLIBS} ${TCPIPLIBS}
        ${mkdir} aif
	${LD} -aif -o $@ ${DEBOBJS} ${TBOXLIBS} ${TCPIPLIBS} ${CLIB} -Symbols symtab
	Access $@ RW/R


#---------------------------------------------------------------------------
# Dynamic dependencies:
