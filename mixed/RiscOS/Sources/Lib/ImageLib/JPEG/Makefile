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
# Makefile for libjpeg
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date       Name         Description
# ----       ----         -----------
# 1998-03-16 KJB          Created.
# 2001-06-13 ADH          Wipes o and z directories as well as contents.
#

#
# Paths
#
EXP_HDR = <export$dir>
LIBDIR = <Lib$Dir>

#
# Generic options:
#
MKDIR   = do mkdir -p
AS      = objasm
CP      = copy
CC      = cc
CM      = cmhg
RM      = remove
LD      = link
LB      = libfile
WIPE    = x wipe

CCFLAGS = -c -depend !Depend -ff -throwback ${INCLUDES} ${DFLAGS}
ASFLAGS = -depend !Depend -Stamp -quit
CPFLAGS = ~cfr~v
LBFLAGS = -c
WFLAGS  = ~CFR~V

#
# Libraries
#
CLIB      = CLIB:o.stubs
RLIB      = RISCOSLIB:o.risc_oslib
RSTUBS    = RISCOSLIB:o.rstubs
ROMSTUBS  = RISCOSLIB:o.romstubs
ROMCSTUBS = RISCOSLIB:o.romcstubs
ABSSYM    = RISC_OSLib:o.AbsSym

#
# Include files
#
INCLUDES  = -IC:

#
# Symbols to predefine
#
DFLAGS    =

#
# Program specific options:
#
COMPONENT  = o.libjpeg
COMPONENTZ = o.libjpeg-zm
SOURCE     = ...
TARGET     = ${COMPONENT}
TARGETZ    = ${COMPONENTZ}
EXPORTS    = ${EXP_HDR}.${COMPONENT}

OBJS =\
 o.jdapimin\
 o.jdapistd\
 o.jdtrans\
 o.jdmaster\
 o.jdinput\
 o.jdmarker\
 o.jdhuff\
 o.jdphuff\
 o.jdmainct\
 o.jdcoefct\
 o.jdpostct\
 o.jddctmgr\
 o.jidctint\
 o.jdsample\
 o.jdcolor\
 o.jquant2\
 o.jdmerge\
 o.jcomapi\
 o.jutils\
 o.jerror\
 o.jmemmgr\
 o.jmemflex

OBJSZ =\
 z.jdapimin\
 z.jdapistd\
 z.jdtrans\
 z.jdmaster\
 z.jdinput\
 z.jdmarker\
 z.jdhuff\
 z.jdphuff\
 z.jdmainct\
 z.jdcoefct\
 z.jdpostct\
 z.jddctmgr\
 z.jidctint\
 z.jdsample\
 z.jdcolor\
 z.jquant2\
 z.jdmerge\
 z.jcomapi\
 z.jutils\
 z.jerror\
 z.jmemmgr\
 z.jmemflex

#
# Rule patterns
#
# Need to clear the built-in suffixes first before setting our own.
.SUFFIXES:
.SUFFIXES: .o .s .h .cmhg .c .z
.c.o:;     ${CC} ${CCFLAGS} -o $@ $<
.c.z:;     ${CC} ${CCFLAGS} -zM -o $@ $<
.s.o:;     ${AS} ${ASFLAGS} -o $@ $<
.s.z:;     ${AS} ${ASFLAGS} -o $@ $<
.cmhg.o:;  ${CM} ${CMFLAGS} -o $@ $<
.cmhg.h:;  ${CM} ${CMFLAGS} -d $@ $<

#
# build a the library:
#
all install export_libs:	${COMPONENT} ${COMPONENTZ}

export: export_libs export_hdrs

export_hdrs:
	@| Nothing to do

#
# RISC OS ROM build rules:
#
clean:
        ${WIPE} o ${WFLAGS}
        ${WIPE} z ${WFLAGS}
        @echo ${COMPONENT}: cleaned

o.local_dirs:
	${MKDIR} o
	${MKDIR} z
        Create o.local_dirs

#
# Final link
#
${TARGET}: ${OBJS} o.local_dirs
        ${LB} ${LBFLAGS} -o ${COMPONENT} ${OBJS}

${TARGETZ}: ${OBJSZ} o.local_dirs
	${LB} ${LBFLAGS} -o ${COMPONENTZ} ${OBJSZ}


# Dynamic dependencies:
