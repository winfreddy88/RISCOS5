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
# Makefile for SCSISoftUSB
#

COMPONENT   = SCSISoftUSB
TARGET     ?= SCSISoftUSB
OBJS        = global glue module umass umass_quirks asm
HDRS        =
CINCLUDES   = -ITCPIPLibs:,C:USB
CFLAGS     += -wp -wc -we -DDISABLE_PACKED -D_KERNEL
CMHGFILE    = modhdr
CMHGDEPENDS = glue module
RAMCDEFINES = -DSTANDALONE
CDFLAGS    += -DDEBUGLIB -DUMASS_DEBUG -DUSB_DEBUG
CMHGDFLAGS += -DDEBUGLIB -DUMASS_DEBUG -DUSB_DEBUG
RES_OBJ     = resmess
RES_AREA    = resmess_ResourcesFiles

include CModule

DBG_LIBS   += ${SOCK5LIB} ${INETLIB}

# Dynamic dependencies:
