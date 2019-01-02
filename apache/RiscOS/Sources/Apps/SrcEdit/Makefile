# Copyright 2007 Castle Technology Ltd
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
# Makefile for SrcEdit
#

COMPONENT = SrcEdit
TARGET    = !RunImage
INSTTYPE  = app
APP_OBJS  = editv canonise langhelp languages main message \
            multiedit options saveall selectload slist srcedmenus \
            throwback upcalls winevent utils
CINCLUDES = -IC:
CDEFINES  = -DSRCEDIT
LIBS      = ${RLIB}
INSTAPP_FILES = !Boot !Run !RunImage !Sprites !Sprites22 [!Sprites11] Messages Templates \
                Export help.ASM:help help.C:help help.C\+\+:help \
                choices.languages:choices choices.liboptions:choices choices.options:choices
INSTAPP_VERSION = Messages

include CApp

# Dynamic dependencies:
