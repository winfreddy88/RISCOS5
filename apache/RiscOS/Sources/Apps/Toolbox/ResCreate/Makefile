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
# Makefile for ResCreate
#

COMPONENT = ResCreate
TARGET    = !RunImage
INSTTYPE  = app
OBJS      = alloc debug error main message dbox
CINCLUDES = -ITbox:,C:
LIBS      = ${TBOXLIBS}
INSTAPP_FILES = !Help !Run !RunImage !Sprites !Sprites22 [!Sprites11] Res
INSTAPP_VERSION = Messages

include CApp

# Dynamic dependencies:
