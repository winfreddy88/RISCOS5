# Copyright 1997 Acorn Computers Ltd
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
# Makefile for HTMLLib
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date       Name         Description
# ----       ----         -----------
# 12-Dec-96  KJB          Created.
# 08-Jul-97  BAL          Added build suitable for modules.
# 17-Mar-99  ADH          Modified to work in current build structure.
#

#
# Paths
#
EXP_HDR = <export$dir>
LIBDIR = <Lib$Dir>

#
# Generic options:
#
MKDIR   = cdir
AS      = objasm
CP      = copy
CC      = cc
CM      = cmhg
RM      = remove
LD      = link
LB      = libfile
TOUCH   = create
WIPE    = x wipe

CCFLAGS = -c -depend !Depend -ffah -throwback ${INCLUDES} ${DFLAGS}
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
INCLUDES  = -Itbox:,C:,TCPIPLibs:
#DFLAGS    = -DLIBRARY -DNDEBUG -DNEWSPACING -DTonyTables -DUSE_NSPRLIB_MALLOC_REGISTRATION
DFLAGS    = -DLIBRARY -DNDEBUG -DNEWSPACING -DTonyTables

#
# Program specific options:
#
COMPONENT   = HTMLLib
COMPONENTZ  = HTMLLibzm
COMPONENTU  = HTMLLibU
COMPONENTUZ = HTMLLibUzm
TARGET      = ${COMPONENT}
TARGETZ     = ${COMPONENTZ}
TARGETU     = ${COMPONENTU}
TARGETUZ    = ${COMPONENTUZ}
SOURCE      = ...
EXPORTS     = ${EXP_HDR}.${COMPONENT}

OBJS =\
 o.display\
 o.malloc\
 o.rules\
 o.veneers\
 o.new_stream\
 o.HTTPSuport\
 o.font\
 o.HTMLTables\
 o.attributes\
 o.attrvenrs\
 o.object\
 o.ol\
 o.URLModule

OBJSZ =\
 oz.display\
 oz.malloc\
 oz.rules\
 oz.veneers\
 oz.new_stream\
 oz.HTTPSuport\
 oz.font\
 oz.HTMLTables\
 oz.attributes\
 oz.attrvenrs\
 oz.object\
 oz.ol\
 oz.URLModule

OBJSU =\
 ou.display\
 ou.malloc\
 ou.rules\
 ou.veneers\
 ou.new_stream\
 ou.HTTPSuport\
 ou.font\
 ou.HTMLTables\
 ou.attributes\
 ou.attrvenrs\
 ou.object\
 ou.ol\
 ou.URLModule

OBJSUZ =\
 ouz.display\
 ouz.malloc\
 ouz.rules\
 ouz.veneers\
 ouz.new_stream\
 ouz.HTTPSuport\
 ouz.font\
 ouz.HTMLTables\
 ouz.attributes\
 ouz.attrvenrs\
 ouz.object\
 ouz.ol\
 ouz.URLModule

#
# Rule patterns
#
.SUFFIXES: .o .s .h .cmhg .c .oz .ou .ouz
.c.o:;     ${CC} ${CCFLAGS} -o $@ $<
.c.oz:;    ${CC} ${CCFLAGS} -zM -o $@ $<
.c.ou:;    ${CC} ${CCFLAGS} -DUNIFONT -o $@ $<
.c.ouz:;   ${CC} ${CCFLAGS} -DUNIFONT -zM -o $@ $<
.s.o:;     ${AS} ${ASFLAGS} -o $@ $<
.cmhg.o:;  ${CM} ${CMFLAGS} -o $@ $<
.cmhg.h:;  ${CM} ${CMFLAGS} -d $@ $<

#
# build a the library:
#
all:	${COMPONENT} #${COMPONENTZ}

#
# build a test program:
#
html_riscos2: ${COMPONENT} o.main o.svcprint o.irqs ${CLIB}
	${LD} -aif -o html_riscos2 ${COMPONENT} o.main o.svcprint o.irqs ${CLIB}

#
# RISC OS ROM build rules:
#
rom: ${TARGET} ${TARGETZ}
        @echo ${COMPONENT}: rom module built

export: export_${PHASE}

install_rom: ${TARGET} ${TARGETZM}
        ${CP} ${TARGET} ${INSTDIR}.${COMPONENT} ${CPFLAGS}
        @echo ${COMPONENT}: rom module installed

clean:
        ${WIPE} o   ${WFLAGS}
        ${WIPE} oz  ${WFLAGS}
        ${WIPE} ou  ${WFLAGS}
        ${WIPE} ouz ${WFLAGS}
        ${RM} ${TARGET}
        ${RM} ${TARGETZ}
        ${RM} ${TARGETU}
        ${RM} ${TARGETUZ}
        ${RM} html_riscos2
        ${RM} local_dirs
        @echo ${COMPONENT}: cleaned

export_hdrs: h.html2_ext h.api h.struct h.tags dirs
	Copy h.html2_ext                ${LIBDIR}.HTMLLib.h.html2_ext                ~CFLNR~V
	Copy h.api                      ${LIBDIR}.HTMLLib.h.HTMLLib                  ~CFLNR~V
	Copy h.struct                   ${LIBDIR}.HTMLLib.h.struct                   ~CFLNR~V
	Copy h.tags                     ${LIBDIR}.HTMLLib.h.tags                     ~CFLNR~V
	Copy h.tablestruc               ${LIBDIR}.HTMLLib.h.tablestruc               ~CFLNR~V
	@echo ${COMPONENT}: export complete (hdrs)

export_libs: ${TARGET} ${TARGETZ} ${TARGETU} ${TARGETUZ} dirs
	Copy ${TARGET}      ${LIBDIR}.HTMLLib.o.${TARGET}      ~CFLNR~V
	Copy ${TARGETZ}    ${LIBDIR}.HTMLLib.o.${TARGETZ}    ~CFLNR~V
	Copy ${TARGETU}     ${LIBDIR}.HTMLLib.o.${TARGETU}     ~CFLNR~V
	Copy ${TARGETUZ}   ${LIBDIR}.HTMLLib.o.${TARGETUZ}   ~CFLNR~V
        @echo ${COMPONENT}: export complete (libs)

local_dirs:
	${MKDIR} o
	${MKDIR} oz
	${MKDIR} ou
	${MKDIR} ouz
	${TOUCH} local_dirs

dirs:
        ${MKDIR} ${LIBDIR}
        ${MKDIR} ${LIBDIR}.HTMLLib
        ${MKDIR} ${LIBDIR}.HTMLLib.h
        ${MKDIR} ${LIBDIR}.HTMLLib.o

#
# Final link
#
${TARGET}: ${OBJS} local_dirs
        ${LB} ${LBFLAGS} -o ${COMPONENT} ${OBJS}

${TARGETZ}: ${OBJSZ} local_dirs
	${LB} ${LBFLAGS} -o ${COMPONENTZ} ${OBJSZ}

${TARGETU}: ${OBJSU} local_dirs
        ${LB} ${LBFLAGS} -o ${COMPONENTU} ${OBJSU}

${TARGETUZ}: ${OBJSUZ} local_dirs
	${LB} ${LBFLAGS} -o ${COMPONENTUZ} ${OBJSUZ}

${EXP_HDR}.${COMPONENT}: hdr.${COMPONENT}
        ${CP} hdr.${COMPONENT} $@ ${CPFLAGS}

# Dynamic dependencies:
