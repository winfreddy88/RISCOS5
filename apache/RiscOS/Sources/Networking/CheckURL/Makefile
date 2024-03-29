# Copyright 2000 Pace Micro Technology plc
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
# Makefile for CheckURL
# =====================
#

# -----------------------------------------------------------------------------
# Change List
#

# Date		Name	Description
# ====		====	===========
# 08-Mar-2000	ADH	Created from VideoControl Makefile

# -----------------------------------------------------------------------------
# Component specific options
#

COMPONENT	= CheckURL
CMHG_HDR	= CUHdr
SWI_PREFIX	= CheckURL
ROM_MODULE	= aof.${COMPONENT}
RAM_MODULE	= rm.${COMPONENT}
DBG_MODULE	= rm.${COMPONENT}-tr
EXPORTS		= <CExport$Dir>.h.${COMPONENT}

# -----------------------------------------------------------------------------
# Export Paths for Messages module
#

RESDIR		= <resource$dir>.Resources2.CheckURL

# -----------------------------------------------------------------------------
# Generic options
#

MKDIR		= cdir
CC		= cc
CMHG		= cmhg
CP		= copy
LD		= link
RM		= remove
WIPE		= x wipe
XWIPE		= x wipe
MODSQZ		= modsqz
AWK		= GNU.gawk

CPFLAGS		= ~cfr~v
WFLAGS		= ~c~v

CFLAGS		= -c -depend !Depend ${INCLUDES} -zM -Wpc -ffah -zps1 ${DFLAGS}
DFLAGS		= -D${SYSTEM} -DCOMPAT_INET4 -UDIRECTSWI
ROMFLAGS	= -DROM
RAMFLAGS	= -UROM
INCLUDES	= -ITCPIPLibs:,C:

DIRS		= o._dirs_

# -----------------------------------------------------------------------------
# Libraries and objects lists
#

ANSILIB		= CLib:o.ansilib
CLIB		= CLIB:o.stubs
RLIB		= RISCOSLIB:o.risc_oslib
ROMCSTUBS	= RISCOSLIB:o.romcstubs
ABSSYM		= RISC_OSLib:o.abssym
TCPIPLIBS	= TCPIPLibs:o.inetlibzm TCPIPLIBS:o.socklibzm
ASMUTILS	= <Lib$Dir>.AsmUtils.o.AsmUtilszm

LIBS = ${DEBUGLIB} \
       ${TCPIPLIBS} \
       ${ASMUTILS}

ROM_OBJS =	\
 o.Area		\
 o.Check	\
 o.File		\
 o.Generic	\
 o.Module	\
 o.URLutils	\
 o.Utils	\
 o.${CMHG_HDR}

# oSL -> Soft Load

RAM_OBJS =	\
 oSL.Area	\
 oSL.Check	\
 oSL.File	\
 oSL.Generic	\
 oSL.Module	\
 oSL.URLutils	\
 oSL.Utils	\
 o.${CMHG_HDR}

# oSLd -> Soft Load deug

DBG_OBJS =	\
 oSLd.Area	\
 oSLd.Check	\
 oSLd.File	\
 oSLd.Generic	\
 oSLd.Module	\
 oSLd.URLutils	\
 oSLd.Utils	\
 o.${CMHG_HDR}

# Defining TRACE enable debuglib based message outputting. Defining
# TRACE2 defines TRACE for you and also enables various extra bits and
# pieces in some builds (i.e. possibly not this module...).

MSGSF		= o.msgs
DBGFLAGS	= -DTRACE2

# -----------------------------------------------------------------------------
# Rule patterns
#

.SUFFIXES:
.SUFFIXES: .o .oSL .oSLd .i .s .c .h .cmhg

.c.o:;		@echo
		@echo Compiling $<
		@echo ${DFLAGS} ${ROMFLAGS}
		@${CC} ${CFLAGS} ${DFLAGS} ${ROMFLAGS} -o $@ $<

.c.oSL:;	@echo
		@echo Compiling $<
		@echo ${DFLAGS} ${RAMFLAGS}
		@${CC} ${CFLAGS} ${DFLAGS} ${RAMFLAGS} -o $@ $<

.c.oSLd:;	@echo
		@echo Compiling $<
		@echo ${DFLAGS} ${RAMFLAGS} ${DBGFLAGS}
		@${CC} ${CFLAGS} ${DFLAGS} ${RAMFLAGS} ${DBGFLAGS} -o $@ $<

.c.i:;		@echo
		@echo Creating $<
		@echo ${DFLAGS} ${RAMFLAGS} -C -E
		@${CC} ${CFLAGS} ${DFLAGS} ${RAMFLAGS} -C -E $< >$@

.s.o .s.oSL .s.oSLd:; \
		@echo
		@echo Assembling $<
		@echo -depend !Depend -throwback
		@objasm -depend !Depend -throwback -o $@ $<

.cmhg.o .cmhg.oSL .cmhg.oSLd:; \
		@echo
		@echo CMHG generating $@
		@echo -p -o
		@${CMHG} -p -o $@ $<

.cmhg.h:;	@echo
		@echo CMHG generating $@
		@echo -p -d
		@${CMHG} -p -d $@ $<

# -----------------------------------------------------------------------------
# Main rules
#

all: ${RAM_MODULE} ${DIRS}
	@echo
	@echo ${COMPONENT}: Module built (RAM)

install: ${RAM_MODULE}
	${MKDIR} ${INSTDIR}
	${CP} ${RAM_MODULE} ${INSTDIR}.${COMPONENT} ${CPFLAGS}
	@echo
	@echo ${COMPONENT}: Module installed (Disc)

ramtrace: ${DBG_MODULE} ${DIRS}
	@echo
	@echo ${COMPONENT}: Module built (RAM debug)

rom: ${ROM_MODULE} ${DIRS}
	@echo
	@echo ${COMPONENT}: Module built (ROM)

export: ${EXPORTS}
	@echo
	@echo ${COMPONENT}: Export complete

install_rom: ${ROM_MODULE}
	${CP} ${ROM_MODULE} ${INSTDIR}.${COMPONENT} ${CPFLAGS}
	@echo
	@echo ${COMPONENT}: Module installed (ROM)

resources: LocalRes:Messages
	@echo
	${MKDIR} ${RESDIR}
	TokenCheck LocalRes:Messages
	${CP} LocalRes:Messages ${RESDIR}.Messages ${CPFLAGS}
	@echo
	@echo ${COMPONENT}: resource files copied to Messages module

${DIRS}:
	@echo
	${MKDIR} o
	${MKDIR} oSL
	${MKDIR} oSLd
	${MKDIR} i
	${MKDIR} linked
	create ${DIRS}

clean:
	${XWIPE} o		${WFLAGS}
	${XWIPE} oSL		${WFLAGS}
	${XWIPE} oSLd		${WFLAGS}
	${XWIPE} i		${WFLAGS}
	${XWIPE} linked		${WFLAGS}
	${XWIPE} aof		${WFLAGS}
	${XWIPE} rm		${WFLAGS}
	${XWIPE} h.${CMHG_HDR}	${WFLAGS}
	@echo
	@echo ${COMPONENT}: cleaned

${ROM_MODULE}: ${ROM_OBJS} ${ROMCSTUBS} ${DIRS}
	@echo
	${MKDIR} aof
	${LD} -o $@ -aof ${ROM_OBJS} ${LIBS} ${ROMCSTUBS}

# -----------------------------------------------------------------------------
# Final link for ROM Image (using given base address)
#

rom_link: ${DIRS} ${ROM_MODULE}
	@echo
	${MKDIR} aof
	${LD} -o linked.${COMPONENT} -rmf -base ${ADDRESS} ${ROM_MODULE} ${ABSSYM}
	${CP} linked.${COMPONENT} ${LINKDIR}.${COMPONENT} ${CPFLAGS}
	@echo ${COMPONENT}: rom_link complete

${EXPORTS}: h.${CMHG_HDR} h.CheckURL
        # The >> operator seems to be broken with the current gawk binary
        ${MKDIR} o
        Do ${AWK} -- "/.define ${SWI_PREFIX}\_00/,/endif/" h.${CMHG_HDR} > o._h_${TARGET}
        FAppend $@ h.CheckURL o._h_${TARGET}
	# ${CP} h.CheckURL $@ ${CPFLAGS}
	# Do ${AWK} -- "/.define ${SWI_PREFIX}\_00/,/endif/" h.${CMHG_HDR} >>$@

${MSGSF}: LocalRes:Messages
	TokenCheck LocalRes:Messages
	resgen messages_file ${MSGSF} LocalRes:Messages Resources.${COMPONENT}.Messages

${RAM_MODULE}: ${RAM_OBJS} ${MSGSF} ${LIBS} ${CLIB} ${DIRS}
	@echo
	${MKDIR} rm
	${LD} -o $@ -module ${RAM_OBJS} ${MSGSF} ${LIBS} ${CLIB}
	${MODSQZ} $@
	Access $@ RW/R

${DBG_MODULE}: ${DBG_OBJS} ${MSGSF} ${LIBS} ${CLIB}
	@echo
	${MKDIR} rm
	${LD} -o $@ -module ${DBG_OBJS} ${MSGSF} ${LIBS} ${CLIB}
	Access $@ RW/R

# -----------------------------------------------------------------------------
# Specialised static dependencies
#

o.CUHdr h.CUHdr: VersionNum

o.Module oSL.Module oSLd.Module: CUHdr.h

# -----------------------------------------------------------------------------
# Dynamic dependencies:
