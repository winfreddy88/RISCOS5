# Copyright 2001 Pace Micro Technology plc
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
# Makefile for Prototype USB mouse driver
#

COMPONENT   = PrototypeUMouse
TARGET      = ProtoUMouse
OBJS        = cmodule
RES_OBJ     =
CMHGFILE    = modhead
CMHGDEPENDS = cmodule
CINCLUDES   = -IC:USB,OS:,C:

include CModule

CFLAGS     += ${OPTIONS}
LIBS       += ${CALLXLIB} ${ASMUTILS}
DBG_LIBS   += ${NET5LIBS} 

# Dynamic dependencies:
