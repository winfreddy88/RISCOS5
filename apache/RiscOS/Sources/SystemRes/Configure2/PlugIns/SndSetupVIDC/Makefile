# Copyright 2003 Tematic Ltd
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
# Makefile for Sound plug-in (VIDC)
#

COMPONENT  = SndSetup
TARGET     = !RunImage
INSTTYPE   = app
APP_OBJS   = main common sound
LIBS       = ${EVENTLIB} ${TBOXLIB} ${WIMPLIB}
CINCLUDES  = -Itbox:,C:
INSTAPP_FILES = !Boot !Run !RunImage Res \
                !Sprites !Sprites22 CoSprite CoSprite22
INSTAPP_VERSION = Messages

include CApp

C_WARNINGS = -fa

# Dynamic dependencies:
