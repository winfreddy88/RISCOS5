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
# Makefile for BootApps / BootBoot / BootRun
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date           Name   Description
# ----           ----   -----------
# 29-May-98      BJGA   Derived from BootMerge/FontMerge/SysMerge makefile
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

CFLAGS  = -c -depend !Depend -ffa -gflv ${INCLUDES} -throwback
PFLAGS  = -c -depend !Depend -E -C ${INCLUDES} -throwback
CPFLAGS = ~cfr~v
WFLAGS  = ~c~v

include AppLibs

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

ROBJS = oR.List oR.Main oR.ToolboxE oR.WimpE oR.WimpM
BOBJS = oB.List oB.Main oB.ToolboxE oB.WimpE oB.WimpM
AOBJS = oA.List oA.Main oA.ToolboxE oA.WimpE oA.WimpM

#
# Rule patterns
#
.SUFFIXES: .c .oA .oB .oR
.c.oA:;  ${CC} ${CFLAGS} -DAPP=1 -o $@ $<
.c.oB:;  ${CC} ${CFLAGS} -DAPP=2 -o $@ $<
.c.oR:;  ${CC} ${CFLAGS} -DAPP=3 -o $@ $<

#
# Main rules:
#
all:        Resources.BootRun.!RunImage \
            Resources.BootBoot.!RunImage \
            Resources.BootApps.!RunImage
        @echo All built (Disc)

install:    Resources.BootRun.!RunImage \
            Resources.BootBoot.!RunImage \
            Resources.BootApps.!RunImage
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
        ${XWIPE} oA.* ${WFLAGS}
        ${XWIPE} oB.* ${WFLAGS}
        ${XWIPE} oR.* ${WFLAGS}
        ${RM} Resources.BootApps.!RunImage
        ${RM} Resources.BootBoot.!RunImage
        ${RM} Resources.BootRun.!RunImage
        @echo All cleaned

#
# Static dependencies:
#
Resources.BootApps.!RunImage: ${AOBJS} ${CONLIB} ${EVENTLIB} ${TBOXLIB} ${WIMPLIB} ${CLIB}
        ${LD} ${LDFLAGS} -o $@ ${AOBJS} ${CONLIB} ${EVENTLIB} ${TBOXLIB} ${WIMPLIB} ${CLIB}
        ${SQUEEZE} $@

Resources.BootBoot.!RunImage: ${BOBJS} ${CONLIB} ${EVENTLIB} ${TBOXLIB} ${WIMPLIB} ${CLIB}
        ${LD} ${LDFLAGS} -o $@ ${BOBJS} ${CONLIB} ${EVENTLIB} ${TBOXLIB} ${WIMPLIB} ${CLIB}
        ${SQUEEZE} $@

Resources.BootRun.!RunImage:  ${ROBJS} ${CONLIB} ${EVENTLIB} ${TBOXLIB} ${WIMPLIB} ${CLIB}
        ${LD} ${LDFLAGS} -o $@ ${ROBJS} ${CONLIB} ${EVENTLIB} ${TBOXLIB} ${WIMPLIB} ${CLIB}
        ${SQUEEZE} $@

# Dynamic dependencies:
