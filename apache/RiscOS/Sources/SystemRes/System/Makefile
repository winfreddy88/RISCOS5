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
# Makefile for System
#

COMPONENT  = System
APP        = !${COMPONENT}
RDIR       = Resources
INSTAPP    = ${INSTDIR}.${APP}

include StdTools

#
# Static dependencies
#
MODULES =                             \
      310.Modules.310Support.icons    \
      310.Modules.310Support.icons22  \
      310.Modules.310Support.ThreeTen \
      310.Modules.Network.MManager    \
      310.Modules.ABCLib              \
      310.Modules.SerialUtil          \
      350.Modules.Fonts               \

FILES =                       \
      LocalRes:!Help          \
      ${RDIR}.!Boot           \
      ${RDIR}.!Run            \
      ${RDIR}.SysPaths        \

#
# Main rules:
#
install: ${FILES} ${MODULES} install_sprites
        ${MKDIR} ${INSTAPP}
        ${CP} LocalRes:!Help            ${INSTAPP}.!Help      ${CPFLAGS}
        ${RM} ${INSTAPP}.!Run
        ${AWK} -f Build:AwkVers obeymode=1 < ${RDIR}.!Run > ${INSTAPP}.!Run
        ${SETTYPE} ${INSTAPP}.!Run Obey
        ${CP} ${RDIR}.SysPaths          ${INSTAPP}.SysPaths   ${CPFLAGS}
        ${CP} ${RDIR}.!Boot             ${INSTAPP}.!Boot      ${CPFLAGS}
        |
        ${MKDIR} ${INSTAPP}.310.Modules.310Support
        ${CP} 310.Modules.310Support.icons    ${INSTAPP}.310.Modules.310Support.* ${CPFLAGS}
        ${CP} 310.Modules.310Support.icons22  ${INSTAPP}.310.Modules.310Support.* ${CPFLAGS}
        ${CP} 310.Modules.310Support.ThreeTen ${INSTAPP}.310.Modules.310Support.* ${CPFLAGS}
        |
        ${CP} 310.Modules.ABCLib              ${INSTAPP}.310.Modules.* ${CPFLAGS}
        ${CP} 310.Modules.SerialUtil          ${INSTAPP}.310.Modules.* ${CPFLAGS}
        ${MKDIR} ${INSTAPP}.310.Modules.Network
        ${CP} 310.Modules.Network.MManager    ${INSTAPP}.310.Modules.Network.* ${CPFLAGS}
        |
        ${MKDIR} ${INSTAPP}.350.Modules
        ${CP} 350.Modules.Fonts               ${INSTAPP}.350.Modules.* ${CPFLAGS}
        |
        ${CHMOD} -R 755 ${INSTAPP}
        |
        @${ECHO} ${COMPONENT}: All installed (Disc)

ifeq (${USERIF},None)
install_sprites:
        ${NOP}
else
install_sprites:
        ${MKDIR} ${INSTAPP}.Themes
        ${CP} LocalUserIFRes:!Sprites   ${INSTAPP}.Themes.!Sprites   ${CPFLAGS}
        ${CP} LocalUserIFRes:!Sprites11 ${INSTAPP}.Themes.!Sprites11 ${CPFLAGS}
        ${CP} LocalUserIFRes:!Sprites22 ${INSTAPP}.Themes.!Sprites22 ${CPFLAGS}
        ${CP} ${RDIR}.Ursula.${LOCALE}  ${INSTAPP}.Themes.Ursula     ${CPFLAGS}
        ${CP} ${RDIR}.Morris4.${LOCALE} ${INSTAPP}.Themes.Morris4    ${CPFLAGS}
endif

clean:
        @${ECHO} ${COMPONENT}: cleaned

#---------------------------------------------------------------------------
# Dynamic dependencies:
