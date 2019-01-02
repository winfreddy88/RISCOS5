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
# Makefile for BootMerge / FontMerge / SysMerge
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date           Name   Description
# ----           ----   -----------
# 29-May-98      BJGA   Derived from FontSetup makefile
# 10-Jun-98      BJGA   Added preprocess-only option
#

#
# Program specific options:
#
APP        = !${COMPONENT}
RDIR       = Resources.${COMPONENT}
LDIR       = ${RDIR}.${LOCALE}
INSTAPP    = ${INSTDIR}.${APP}

#
# Generic options:
#
MKDIR   = do mkdir -p
CC      = cc
ATTR    = -attr
CP      = copy
LD      = link
RM      = remove
SQUEEZE = squeeze
WIPE    = x wipe
XWIPE   = x wipe

CFLAGS  = -c -depend !Depend -ffa -gflv ${INCLUDES} ${THROWBACK}
PFLAGS  = -c -depend !Depend -E -C ${INCLUDES} ${THROWBACK}
CPFLAGS = ~cfr~v
WFLAGS  = ~c~v

#
# Libraries
#
CLIB = C:o.stubs
ELIB = Tbox:o.eventlib
TLIB = Tbox:o.toolboxlib
WLIB = Tbox:o.wimplib
CONLIB = <Lib$Dir>.ConfigLib.o.ConfigLib

#
# Include files
#
INCLUDES = -ITbox:,C:,<Lib$Dir>.ConfigLib.

FILES=\
 ${LDIR}.!Help\
 ${RDIR}.!Boot\
 ${LDIR}.!Run\
 ${RDIR}.!RunImage\
 ${RDIR}.!Sprites\
 ${RDIR}.!Sprites11\
 ${RDIR}.!Sprites22\
 ${RDIR}.CoSprite\
 ${RDIR}.CoSprite11\
 ${RDIR}.CoSprite22\
 ${LDIR}.Messages\
 ${LDIR}.Res\

SOBJS = oS.Main oS.Merge oS.ToolboxE oS.WimpE oS.WimpM
FOBJS = oF.Main oF.Merge oF.ToolboxE oF.WimpE oF.WimpM
BOBJS = oB.Main oB.Merge oB.ToolboxE oB.WimpE oB.WimpM
POBJS = pS.Main pS.Merge pS.ToolboxE pS.WimpE pS.WimpM \
        pF.Main pF.Merge pF.ToolboxE pF.WimpE pF.WimpM \
        pB.Main pB.Merge pB.ToolboxE pB.WimpE pB.WimpM \


#
# Rule patterns
#
.SUFFIXES: .c .oB .oF .oS .pB .pF .pS
.c.oB:;  ${CC} ${CFLAGS} -DAPP=1 -o $@ $<
.c.oF:;  ${CC} ${CFLAGS} -DAPP=2 -o $@ $<
.c.oS:;  ${CC} ${CFLAGS} -DAPP=3 -o $@ $<
.c.pB:;  ${CC} ${PFLAGS} -DAPP=1 $< > $@
.c.pF:;  ${CC} ${PFLAGS} -DAPP=2 $< > $@
.c.pS:;  ${CC} ${PFLAGS} -DAPP=3 $< > $@

#
# Main rules:
#
# Application
#
all:        Resources.SysMerge.!RunImage \
            Resources.FontMerge.!RunImage \
            Resources.BootMerge.!RunImage
        @echo All built (Disc)

preprocess: ${POBJS}
        @echo
        @echo Preprocessing complete

install:    Resources.SysMerge.!RunImage \
            Resources.FontMerge.!RunImage \
            Resources.BootMerge.!RunImage
        ${MKDIR} ${INSTAPP}
        |
        ${CP} ${RDIR}.!Boot      ${INSTAPP}.!Boot      ${CPFLAGS}
        ${CP} ${LDIR}.!Help      ${INSTAPP}.!Help      ${CPFLAGS}
        ${CP} ${LDIR}.!Run       ${INSTAPP}.!Run       ${CPFLAGS}
        ${CP} ${RDIR}.!RunImage  ${INSTAPP}.!RunImage  ${CPFLAGS}
        ${CP} ${RDIR}.!Sprites   ${INSTAPP}.!Sprites   ${CPFLAGS}
        ${CP} ${RDIR}.!Sprites11 ${INSTAPP}.!Sprites11 ${CPFLAGS}
        ${CP} ${RDIR}.!Sprites22 ${INSTAPP}.!Sprites22 ${CPFLAGS}
        ${CP} ${RDIR}.CoSprite   ${INSTAPP}.CoSprite   ${CPFLAGS}
        ${CP} ${RDIR}.CoSprite11 ${INSTAPP}.CoSprite11 ${CPFLAGS}
        ${CP} ${RDIR}.CoSprite22 ${INSTAPP}.CoSprite22 ${CPFLAGS}
        ${CP} ${LDIR}.Messages   ${INSTAPP}.Messages   ${CPFLAGS}
        ${CP} ${LDIR}.Res        ${INSTAPP}.Res        ${CPFLAGS}
        |
        ${ATTR} -directories +wr -ww ${INSTAPP}
        ${ATTR} -files +or +ow +wr -ww ${INSTAPP}
        |
        @echo ${COMPONENT}: All installed (Disc)

clean:
        ${XWIPE} oB.* ${WFLAGS}
        ${XWIPE} oF.* ${WFLAGS}
        ${XWIPE} oS.* ${WFLAGS}
        ${XWIPE} pB ${WFLAGS}
        ${XWIPE} pF ${WFLAGS}
        ${XWIPE} pS ${WFLAGS}
        ${RM} Resources.BootMerge.!RunImage
        ${RM} Resources.FontMerge.!RunImage
        ${RM} Resources.SysMerge.!RunImage
        @echo All cleaned

#
# Static dependencies:
#
Resources.BootMerge.!RunImage: ${BOBJS} ${CONLIB} ${ELIB} ${TLIB} ${WLIB} ${CLIB}
        ${LD} ${LDFLAGS} -o $@ ${BOBJS} ${CONLIB} ${ELIB} ${TLIB} ${WLIB} ${CLIB}
        ${SQUEEZE} $@

Resources.FontMerge.!RunImage: ${FOBJS} ${CONLIB} ${ELIB} ${TLIB} ${WLIB} ${CLIB}
        ${LD} ${LDFLAGS} -o $@ ${FOBJS} ${CONLIB} ${ELIB} ${TLIB} ${WLIB} ${CLIB}
        ${SQUEEZE} $@

Resources.SysMerge.!RunImage:  ${SOBJS} ${CONLIB} ${ELIB} ${TLIB} ${WLIB} ${CLIB}
        ${LD} ${LDFLAGS} -o $@ ${SOBJS} ${CONLIB} ${ELIB} ${TLIB} ${WLIB} ${CLIB}
        ${SQUEEZE} $@

#---------------------------------------------------------------------------
# Dynamic dependencies:
