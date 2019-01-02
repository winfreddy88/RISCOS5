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
# Makefile for Prototype OHCI driver
#

COMPONENT   = ProtoOHCI
TARGET      = ${COMPONENT}
OBJS        = controller memory usbd cmodule bufman
RES_AREA    = resource_files
CMHGFILE    = modhead
CMHGDEPENDS = cmodule
CINCLUDES   = -Itbox:,OS:,C:

include CModule

CFLAGS     += ${COPTIONS}
LIBS       += ${CALLXLIB} ${ASMUTILS}
DBG_LIBS   += ${NET5LIBS} 

# Dynamic dependencies:
