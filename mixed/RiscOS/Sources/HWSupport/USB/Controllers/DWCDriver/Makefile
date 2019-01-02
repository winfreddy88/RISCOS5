# Copyright 2012 Castle Technology Ltd
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
# Makefile for Synopsys DWC driver
#
# $Id: Makefile,v 1.14 2017/09/19 20:28:38 rool Exp $

COMPONENT       = DWCDriver
RES_AREA        = resource_files
OBJS            = cmodule call_veneer triggercbs dwc_common_riscos dwc_otg_riscos softc_root softc_device port regaccess
LIBS            = ${CALLXLIB} ${ASMUTILS} ${TBOXINTLIB}
CMHGFILE        = modhead
HDRS            =

#
# Debug switch
#
DEBUG ?= FALSE
ifeq (${DEBUG},TRUE)
CFLAGS         += -DDEBUGLIB -DDWCDRIVER_DEBUG -DDEBUG -DUSB_DEBUG
CMHGDEFINES    += -DDWCDRIVER_DEBUG
LIBS           += ${DEBUGLIBS} ${NET5LIBS}
endif

CFLAGS          += -wp -wc
CDEFINES        += -DKERNEL -D_KERNEL -Dpaddr_t=int -D__P(A)=A -DKLD_MODULE -DDISABLE_PACKED
ROMCDEFINES     = -DROM
CINCLUDES       = -ITCPIPLibs:,C:USB,OS:
CMHGDEPENDS     = cmodule dwc_otg_riscos softc_root softc_device

VPATH = dwc.driver dwc.dwc_common_port

# DWC bits
CFLAGS += -DDWC_EN_ISOC -Idwc.dwc_common_port -DDWC_HOST_ONLY
CFLAGS += -Dnotrace= -Dnoinline=
OBJS += dwc_otg_cil dwc_otg_cil_intr dwc_otg_hcd dwc_otg_hcd_intr dwc_otg_hcd_queue dwc_otg_hcd_ddma dwc_otg_adp dwc_otg_fiq_fsm
# OBJS += dwc_cc dwc_modpow dwc_notifier dwc_mem

# Use this flag to enable Broadcom SoC/BCM2835-specific changes
CFLAGS += -DBCM2835

include CModule

# Dynamic dependencies:
