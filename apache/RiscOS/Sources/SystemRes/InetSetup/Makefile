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
# Makefile for InetSetup plug-in
#

COMPONENT  = InetSetup
TARGET     = !RunImage
INSTTYPE   = app
APP_OBJS   = AUN Detect Diagnose event FileUtils IfsDbox Load \
             Main ModUtils Save SmallDrag swis tbevent wimpevent \
             wimpmsg xtry
LIBS       = ${OSLIB} ${INETLIB} ${SOCK5LIB}
CDEFINES  += -DPlugIn
CINCLUDES  = -IOS:,C:,TCPIPLibs:
INSTAPP_FILES = !Boot !Help !Run !RunImage Res \
                !Sprites !Sprites11 !Sprites22 CoSprite CoSprite11 CoSprite22 Sprites Sprites11 Sprites22
INSTAPP_DEPENDS = Blanks
INSTAPP_VERSION = Messages

include CApp

C_WARNINGS = -Wp

#
# Static dependencies:
#
Blanks: LocalRes:Blanks.SetUpNet LocalRes:Blanks.Routes LocalRes:Blanks.User
        ${MKDIR} ${INSTAPP}.Blanks
        ${MKDIR} ${INSTAPP}.AutoSense
        ${CP} LocalRes:Blanks.SetUpNet ${INSTAPP}.Blanks.SetUpNet ${CPFLAGS}
        ${CP} LocalRes:Blanks.Routes   ${INSTAPP}.Blanks.Routes   ${CPFLAGS}
        ${CP} LocalRes:Blanks.User     ${INSTAPP}.Blanks.User     ${CPFLAGS}

# Dynamic dependencies:
