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
# Makefile for FontSetup
#

COMPONENT  = FontSetup
TARGET     = !RunImage
INSTTYPE   = app
APP_OBJS   = Main Settings ToolboxE WimpE WimpM
LIBS       = ${CONLIB} ${EVENTLIB} ${TBOXLIB} ${WIMPLIB} ${RMVSN}
CINCLUDES  = -ITbox:,C:,C:ConfigLib.
INSTAPP_FILES = !Boot !Run !RunImage Res \
                !Sprites !Sprites11 !Sprites22 CoSprite CoSprite11 CoSprite22
INSTAPP_VERSION = Messages

include CApp

C_WARNINGS = -fa

# Dynamic dependencies:
