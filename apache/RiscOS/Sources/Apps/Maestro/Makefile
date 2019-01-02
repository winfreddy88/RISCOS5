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
# Makefile for Maestro
#

COMPONENT  = Maestro
APP        = !${COMPONENT}
RDIR       = Resources
LDIR       = ${RDIR}.${LOCALE}
INSTAPP    = ${INSTDIR}.${APP}

include StdTools

FILES =\
 $(RDIR).!Boot\
 $(LDIR).!Help\
 $(LDIR).!Run\
 $(RDIR).!RunImage\
 $(RDIR).!Sprites\
 $(RDIR).!Sprites11\
 $(RDIR).!Sprites22\
 $(RDIR).EnsureRMA\
 $(RDIR).GenMessage\
 $(RDIR).Sprites\
 $(RDIR).Sprites11\
 $(RDIR).Sprites22\
 $(LDIR).Templates

#
# Main rules:
#
all: ${FILES}
        @${ECHO} ${COMPONENT}: application built

install: install_${TARGET}

install_Examples:
        ${MKDIR} ${INSTDIR}
        ${CP} Examples ${INSTDIR} ${CPFLAGS}
        ${CHMOD} -R a+r ${INSTAPP}
        @${ECHO} ${COMPONENT}: example files installed

install_ install_Maestro: ${FILES}
        ${MKDIR} ${INSTAPP}
        ${CP} ${RDIR}.!Boot      ${INSTAPP}.!Boot      ${CPFLAGS}
        ${CP} ${LDIR}.!Help      ${INSTAPP}.!Help      ${CPFLAGS}
        ${CP} ${LDIR}.!Run       ${INSTAPP}.!Run       ${CPFLAGS}
        ${CP} ${RDIR}.!RunImage  ${INSTAPP}.!RunImage  ${CPFLAGS}
        ${CP} ${RDIR}.EnsureRMA  ${INSTAPP}.EnsureRMA  ${CPFLAGS}
        ${CP} ${RDIR}.GenMessage ${INSTAPP}.Messages   ${CPFLAGS}
        ${CP} ${RDIR}.Sprites    ${INSTAPP}.Sprites    ${CPFLAGS}
        ${CP} ${RDIR}.Sprites11  ${INSTAPP}.Sprites11  ${CPFLAGS}
        ${CP} ${RDIR}.Sprites22  ${INSTAPP}.Sprites22  ${CPFLAGS}
        ${CP} ${LDIR}.Templates  ${INSTAPP}.Templates  ${CPFLAGS}
        ${MKDIR} ${INSTAPP}.Themes.Ursula
        ${MKDIR} ${INSTAPP}.Themes.Morris4
        ${CP} ${RDIR}.!Sprites           ${INSTAPP}.Themes.!Sprites   ${CPFLAGS}
        ${CP} ${RDIR}.!Sprites11         ${INSTAPP}.Themes.!Sprites11 ${CPFLAGS}
        ${CP} ${RDIR}.!Sprites22         ${INSTAPP}.Themes.!Sprites22 ${CPFLAGS}
        ${CP} ${RDIR}.Ursula.!Sprites    ${INSTAPP}.Themes.Ursula.!Sprites   ${CPFLAGS}
        ${CP} ${RDIR}.Ursula.!Sprites22  ${INSTAPP}.Themes.Ursula.!Sprites22 ${CPFLAGS}
        ${CP} ${RDIR}.Morris4.!Sprites   ${INSTAPP}.Themes.Morris4.!Sprites   ${CPFLAGS}
        ${CP} ${RDIR}.Morris4.!Sprites22 ${INSTAPP}.Themes.Morris4.!Sprites22 ${CPFLAGS}
        ${CHMOD} -R a+rx ${INSTAPP}
        @${ECHO} ${COMPONENT}: application installation complete

clean:
        ${RM} ${RDIR}.!RunImage
        ${RM} ${RDIR}.EnsureRMA
        ${RM} ${RDIR}.GenMessage
        ${WIPE} crunched.* ${WFLAGS}
        ${WIPE} o ${WFLAGS}
        @${ECHO} ${COMPONENT}: cleaned

#
# Static dependencies:
#
${RDIR}.!RunImage: crunched.!RunImage
        ${SQUISH} ${SQUISHFLAGS} -from crunched.!RunImage -to $@

crunched.!RunImage: bas.!RunImage
        ${RUN}BasCrunch -1 bas.!RunImage $@

o.EnsureRMA: s.EnsureRMA
        ${MKDIR} o
        ${AS} ${AFLAGS} -o $@ s.EnsureRMA

$(RDIR).EnsureRMA: o.EnsureRMA
        ${LD} -bin -o $@ o.EnsureRMA
        ${SETTYPE} $@ Utility

$(RDIR).GenMessage: $(LDIR).Messages
        ${INSERTVERSION} $(LDIR).Messages > $(RDIR).GenMessage

#---------------------------------------------------------------------------
# Dynamic dependencies:
