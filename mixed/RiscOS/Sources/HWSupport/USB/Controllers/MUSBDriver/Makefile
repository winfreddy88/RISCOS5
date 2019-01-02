# Copyright 2009 Castle Technology Ltd
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
# Makefile for MUSB driver
#
# $Id: Makefile,v 1.18 2017/11/18 10:26:24 rool Exp $

COMPONENT       = MUSBDriver
RES_AREA        = resource_files
OBJS            = cmodule call_veneer musb musb_debug musb_peri musb_root musb_usb musb_util bsd_fns triggercbs tps
LIBS            = ${CALLXLIB} ${ASMUTILS} ${TBOXINTLIB}
CMHGFILE        = modhead
HDRS            =
CMHGDEPENDS     = cmodule musb tps
ROMCDEFINES     = -DROM
CINCLUDES       = -ITCPIPLibs:,C:USB,OS:
CFLAGS         += -wp -wc
CDEFINES       += -DKERNEL -D_KERNEL -Dpaddr_t=int -D__P(A)=A -DKLD_MODULE -DDISABLE_PACKED

#
# Debug switch
#
DEBUG          ?= FALSE
ifeq (${DEBUG},TRUE)
CFLAGS         += -DDEBUGLIB -DMUSB_DEBUG -DUSB_DEBUG
CMHGDEFINES    += -DMUSB_DEBUG
LIBS           += ${NET5LIBS}
endif

include CModule

# Dynamic dependencies:
