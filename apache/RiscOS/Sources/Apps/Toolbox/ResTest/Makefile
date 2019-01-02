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
# Makefile for ResTest
#

COMPONENT = ResTest
TARGET    = !RunImage
INSTTYPE  = app
OBJS      = linklist main messages tbox_tools txt wimplib wimpmess
CINCLUDES = -IC:tboxlibint,Tbox:,C:
LIBS      = ${TBOXLIBS}
INSTAPP_FILES = !Help !Run !RunImage TBlockMess Templates !Sprites !Sprites22 [!Sprites11]
INSTAPP_VERSION = Messages

include CApp

# Dynamic dependencies:
