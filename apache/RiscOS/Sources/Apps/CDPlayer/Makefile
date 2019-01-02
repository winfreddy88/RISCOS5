# Copyright 1996 Acorn Computers Ltd
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
# Makefile for CDPlayer
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date       Name   Description
# ----       ----   -----------
# 12-Dec-94  AMcC   Created
# 08-Nar-95  AMcC   Added !Help file installation
#                   Commented out rules that would clean & rebuild cdplayer
#

#
# Program specific options:
#
COMPONENT  = CDPlayer
APP        = !${COMPONENT}
RDIR       = Resources
LDIR       = ${RDIR}.${LOCALE}
APPDIR     = ${INSTDIR}.${APP}

# Generic options:
#
MKDIR   = do mkdir -p
CC      = cc
CP      = copy
LD      = link
RM      = remove
SQUEEZE = squeeze
WIPE    = -wipe

CFLAGS  = ${THROWBACK} -c -depend !Depend -fah -Wp ${INCLUDES} ${DFLAGS}
CPFLAGS = ~cfr~v
SQFLAGS = -nolist
WFLAGS  = ~c~v

#
# Libraries
#
CLIB = CLIB:o.stubs
RLIB = RISC_OSLib:o.risc_oslib

#
# Include files
#
INCLUDES = -IC:

DFLAGS   = 

FILES  =\
 $(RDIR).!Boot\
 $(LDIR).!Help\
 $(LDIR).!Run\
 $(RDIR).!sprites\
 $(RDIR).cdplayer\
 $(RDIR).config\
 $(RDIR).sprites\
 $(LDIR).Templates

OBJS = cdplayer.o

#
# Rule patterns
#
.c.o:;      ${CC} ${CFLAGS} -o $@ $<

#
# GENERIC RULES
#
all: $(FILES)
     @echo $(COMPONENT): all built

install: $(FILES)
         $(MKDIR) ${APPDIR}
         Access ${APPDIR} /r
         $(CP) $(RDIR).!Boot      $(APPDIR).!Boot       $(CPFLAGS)
         $(CP) $(LDIR).!Help      $(APPDIR).!Help       $(CPFLAGS)
         $(CP) $(LDIR).!Run       $(APPDIR).!Run        $(CPFLAGS)
         $(CP) $(RDIR).!sprites   $(APPDIR).!sprites    $(CPFLAGS)
         $(CP) $(RDIR).cdplayer   $(APPDIR).cdplayer    $(CPFLAGS)
         $(CP) $(RDIR).config     $(APPDIR).config      $(CPFLAGS)
         $(CP) $(RDIR).sprites    $(APPDIR).sprites     $(CPFLAGS)
         $(CP) $(LDIR).Templates  $(APPDIR).Templates   $(CPFLAGS)
         Access ${APPDIR}.* LR/r
         Access ${APPDIR}.config WR/r
         @echo $(COMPONENT): installed

clean:
        ${RM} o.cdplayer
        ${RM} ${RDIR}.cdplayer
        @echo $(COMPONENT): cleaned

#
# Static dependencies:
#
${RDIR}.cdplayer: ${OBJS}
        ${LD} -o $@ ${OBJS} ${CLIB} ${RLIB}
        ${SQUEEZE} $@

#---------------------------------------------------------------------------
# Dynamic dependencies:
o.cdplayer:	c.cdplayer
o.cdplayer:	C:h.kernel
o.cdplayer:	C:h.swis
o.cdplayer:	C:h.trace
o.cdplayer:	h.cd_swis
o.cdplayer:	C:h.os
o.cdplayer:	C:h.wimp
o.cdplayer:	C:h.sprite
o.cdplayer:	C:h.wimpt
o.cdplayer:	C:h.win
o.cdplayer:	C:h.event
o.cdplayer:	C:h.menu
o.cdplayer:	C:h.baricon
o.cdplayer:	C:h.res
o.cdplayer:	C:h.resspr
o.cdplayer:	C:h.menu
o.cdplayer:	C:h.template
o.cdplayer:	C:h.dbox
o.cdplayer:	C:h.werr
