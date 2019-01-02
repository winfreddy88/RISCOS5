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
# Makefile for Patch
#

#
# Program specific options:
#
COMPONENT  = Patch
APP        = !${COMPONENT}
RDIR       = Resources
LDIR       = ${RDIR}.${LOCALE}
INSTAPP    = ${INSTDIR}.${APP}
MSGVERSION = ${AWK} -f Build:AwkVers
MSGS       = Resources.GenMessage

include StdTools

#
# Libraries
#
CLIB      = CLib:o.stubs
RLIB      = RISC_OSLib:o.risc_oslib

OBJS      = Main.o MsgCode.o PatchApply.o PatchParse.o Subroutins.o

FILES   =\
 $(RDIR).!Boot\
 $(LDIR).!Help\
 $(LDIR).!Run\
 $(RDIR).!RunImage\
 $(RDIR).!Sprites\
 $(RDIR).!Sprites22\
 $(RDIR).!Sprites11\
 $(RDIR).BootStrap\
 Library.squeeze\
 Modules.UnSqueeze\
 ${MSGS}\
 $(LDIR).ReadMe\
 $(LDIR).Templates\
 $(RDIR).Transforms


#
# Rule patterns
#
.c.o:;  ${CC} ${CFLAGS} -o $@ $<

#
# Generic rules:
#
all: $(FILES)
        @echo $(COMPONENT): all build complete

install: $(FILES)
         $(MKDIR) $(INSTAPP); Access $(INSTAPP) /r
         Set Alias$CPFD $(CP) %0.%1 $(INSTAPP).%1 $(CPFLAGS)
         Set Alias$CPFDL CPFD %*0|MAccess $(INSTAPP).%1 LR/r
         |
         CPFDL $(RDIR) !Boot
         CPFDL $(LDIR) !Help
         CPFDL $(LDIR) !Run
         CPFDL $(RDIR) !RunImage
         CPFDL $(RDIR) BootStrap
         ${CP} ${MSGS} $(INSTAPP).Messages   ${CPFLAGS}
         |
         $(MKDIR) $(INSTAPP).Themes.Ursula;  Access $(INSTAPP).Themes.Ursula /r
         $(MKDIR) $(INSTAPP).Themes.Morris4; Access $(INSTAPP).Themes.Morris4 /r
         $(CP) $(RDIR).!Sprites           $(INSTAPP).Themes.!Sprites           ${CPFLAGS}
         $(CP) $(RDIR).!Sprites22         $(INSTAPP).Themes.!Sprites22         ${CPFLAGS}
         $(CP) $(RDIR).!Sprites11         $(INSTAPP).Themes.!Sprites11         ${CPFLAGS}
         $(CP) $(RDIR).Morris4.!Sprites   $(INSTAPP).Themes.Morris4.!Sprites   ${CPFLAGS}
         $(CP) $(RDIR).Morris4.!Sprites22 $(INSTAPP).Themes.Morris4.!Sprites22 ${CPFLAGS}
         $(CP) $(RDIR).Ursula.!Sprites    $(INSTAPP).Themes.Ursula.!Sprites    ${CPFLAGS}
         $(CP) $(RDIR).Ursula.!Sprites22  $(INSTAPP).Themes.Ursula.!Sprites22  ${CPFLAGS}
         |
         $(MKDIR) $(INSTAPP).Library; Access $(INSTAPP).Library /r
         CPFDL @ Library.squeeze
         $(MKDIR) $(INSTAPP).Modules; Access $(INSTAPP).Modules /r
         CPFDL @ Modules.UnSqueeze
         |
         $(MKDIR) $(INSTAPP).Patches; Access $(INSTAPP).Patches /r
         CPFDL @ Patches
         |
         CPFDL $(LDIR) ReadMe
         CPFDL $(LDIR) Templates
         CPFDL $(RDIR) Transforms
         |
         Unset Alias$CPFDL
         Unset Alias$CPFD
         |
         @echo $(COMPONENT): installed

clean:
        ${XWIPE} o.* ${WFLAGS}
        $(RM) ${RDIR}.!RunImage
        $(RM) s.TokHelpSrc
        $(RM) Modules.UnSqueeze
        $(RM) ${MSGS}
        @echo $(COMPONENT): cleaned

#
# Static dependencies:
#
s.TokHelpSrc: s.HelpSrc Hdr:Tokens
        Tokenise Hdr:Tokens s.HelpSrc s.TokHelpSrc

Modules.UnSqueeze: s.UnSqueeze s.TokHelpSrc
        $(AS) $(AFLAGS) -o o.UnSqueeze s.UnSqueeze
        $(LD) -rmf -o $@ o.UnSqueeze

$(RDIR).!RunImage: $(OBJS) $(CLIB) $(RLIB)
        $(LD) -o $@ $(OBJS) $(CLIB) $(RLIB)
        $(SQZ) $@

${MSGS}: ${LDIR}.Messages VersionNum
        ${MSGVERSION} ${LDIR}.Messages > $@

#---------------------------------------------------------------------------
# Dynamic dependencies:
