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
# Makefile for OHCIDriver
#

COMPONENT    = OHCIDriver
OBJS         = call_veneer bsd_fns ohcimodule ohci
HDRS         =
CMHGDEPENDS  = ohcimodule
LIBS         = ${CALLXLIB} ${ASMUTILS}
CDEFINES    += ${CDEBUG} -DKERNEL -D_KERNEL -Dpaddr_t=int -D__P(A)=A -DKLD_MODULE -DDISABLE_PACKED
ROMCDEFINES  = -DROM
RES_AREA     = resource_files
CINCLUDES    = -IC:USB,TCPIPLibs:,C:,tbox:
CFLAGS       = -Wp

ifeq (${DEBUG},TRUE)
CFLAGS      += -DDEBUGLIB -DOHCI_DEBUG -DUSB_DEBUG
CMHGFLAGS   += -DDEBUGLIB -DOHCI_DEBUG
LIBS        += ${DEBUGLIBS} ${SOCK5LIB} ${INETLIB}
endif

include CModule

# Dynamic dependencies:
