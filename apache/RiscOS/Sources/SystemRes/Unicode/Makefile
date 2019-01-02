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
# Makefile for Unicode Resources
#

include StdTools

#
# Program specific options:
#
COMPONENT = Unicode
APP       = !${COMPONENT}
INSTAPP   = ${INSTDIR}.${APP}
RESMOD    = rm.${COMPONENT}Res
VIAFILE   = LocalRes:ViaFile
TARGET    =

#
# Export Paths for Messages module
#
RESAPP = <resource$dir>.Apps.${APP}
RESDIR = <resource$dir>.Resources.${COMPONENT}

#
# Generic rules:
#
rom: ${TARGET}
        @echo ${COMPONENT}: rom module built

export: ${EXPORTS}
        @echo ${COMPONENT}: export complete

install_rom: ${TARGET}
        @echo ${COMPONENT}: rom module installed

clean:
        ${XWIPE} rm ${WFLAGS}
        ${MAKE} -f makealiases/mk clean
        ${STRIPDEPEND} makealiases/mk
        ${RM} Aliases
        @echo ${COMPONENT}: cleaned

resources: resources-${SUBSET}
        @echo ${COMPONENT}: resource files copied

resources-Japan: resources-
        ${XWIPE} ${RESDIR}.Encodings.ISO2022.G94x94.*CNS* ${WFLAGS}
        ${XWIPE} ${RESDIR}.Encodings.ISO2022.G94x94.*KS*  ${WFLAGS}
        ${XWIPE} ${RESDIR}.Encodings.ISO2022.G94x94.*GB*  ${WFLAGS}
        ${XWIPE} ${RESDIR}.Encodings.BigFive              ${WFLAGS}

resources-NoCJK: resources-
        ${XWIPE} ${RESDIR}.Encodings.ISO2022.G94x94.* ${WFLAGS}
        ${XWIPE} ${RESDIR}.Encodings.BigFive          ${WFLAGS}
        ${XWIPE} ${RESDIR}.Encodings.Microsoft.CP932  ${WFLAGS}

resources-:
        ${MKDIR} ${RESAPP}
        ${MKDIR} ${RESDIR}
        ${CP} Resources.Encodings ${RESDIR}.Encodings  ${CPFLAGS}
        ${CP} LocalRes:!Boot      ${RESAPP}.!Boot      ${CPFLAGS}
        ${CP} LocalRes:!Run       ${RESAPP}.!Run       ${CPFLAGS}
        ${CP} LocalRes:!Help      ${RESAPP}.!Help      ${CPFLAGS}
        ${CP} LocalRes:!Sprites   ${RESAPP}.!Sprites   ${CPFLAGS}
        ${CP} LocalRes:!Sprites11 ${RESAPP}.!Sprites11 ${CPFLAGS}
        ${CP} LocalRes:!Sprites22 ${RESAPP}.!Sprites22 ${CPFLAGS}

install_STB:
        ${CP} LocalUserIFRes:!Boot      ${INSTAPP}.!Boot      ${CPFLAGS}
        ${CP} LocalUserIFRes:!Run       ${INSTAPP}.!Run       ${CPFLAGS}

install_:
        ${CP} LocalRes:!Boot      ${INSTAPP}.!Boot      ${CPFLAGS}
        ${CP} LocalRes:!Run       ${INSTAPP}.!Run       ${CPFLAGS}
        ${CP} LocalRes:!Help      ${INSTAPP}.!Help      ${CPFLAGS}
        ${CP} LocalRes:!Sprites   ${INSTAPP}.Themes.!Sprites   ${CPFLAGS}
        ${CP} LocalRes:!Sprites11 ${INSTAPP}.Themes.!Sprites11 ${CPFLAGS}
        ${CP} LocalRes:!Sprites22 ${INSTAPP}.Themes.!Sprites22 ${CPFLAGS}
        ${CP} LocalRes:Morris4    ${INSTAPP}.Themes.Morris4    ${CPFLAGS}
        ${CP} LocalRes:Ursula     ${INSTAPP}.Themes.Ursula     ${CPFLAGS}

install_dirs:
        ${MKDIR} ${INSTAPP}.Themes
        ${MKDIR} ${INSTAPP}.Files

install: install_${OPTIONS} install_dirs Aliases
        ${CP} Resources.Encodings ${INSTAPP}.Encodings       ${CPFLAGS}
        ${CP} Aliases             ${INSTAPP}.Files.Aliases   ${CPFLAGS}
        ${CP} data.CharNames      ${INSTAPP}.Files.CharNames ${CPFLAGS}
        ${CHMOD} -R 755 ${INSTAPP}
        @${ECHO} ${COMPONENT}: application installation complete

Aliases: makealiases data.aliases-top data.character-sets data.aliases-bottom
        makealiases data.aliases-top data.character-sets data.aliases-bottom $@

makealiases:
        ${MAKE} -f makealiases/mk

module: ${VIAFILE}
        ${MKDIR} rm
        ${GETVERSION} Unicode$BuildV Unicode$FullV Unicode$Date
        ${DO} ${MODGEN} -date "<Unicode$Date>" ${RESMOD} ${RESMOD} ${RESMOD} <Unicode$BuildV> -via ${VIAFILE}
        @${ECHO} built softload UnicodeRes 

# Dynamic dependencies:
