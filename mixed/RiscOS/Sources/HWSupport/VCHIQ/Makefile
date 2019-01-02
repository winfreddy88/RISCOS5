# 
# Copyright (c) 2012, RISC OS Open Ltd
# All rights reserved.
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met: 
#     * Redistributions of source code must retain the above copyright
#       notice, this list of conditions and the following disclaimer.
#     * Redistributions in binary form must reproduce the above copyright
#       notice, this list of conditions and the following disclaimer in the
#       documentation and/or other materials provided with the distribution.
#     * Neither the name of RISC OS Open Ltd nor the names of its contributors
#       may be used to endorse or promote products derived from this software
#       without specific prior written permission.
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
# 
# Makefile for Broadcom VCHIQ driver
#

DEBUG ?= FALSE

ifeq ($(DEBUG),TRUE)
CFLAGS += -DDEBUGLIB
CMHGFLAGS += -DDEBUGLIB
LIBS = ${DEBUGLIBS} ${NET5LIBS}
endif

COMPONENT       = VCHIQ
ASMHDRS         = VCHIQ
ASMCHDRS        = VCHIQ
OBJS            = cmodule vchiq_riscos asm swis errors
HDRS            = VCHIQWrap
LIBS           += ${ASMUTILS}

CINCLUDES       = -Itbox:
CFLAGS          += -ff -wp -wc
CMHGDEFINES     = -DCOMPONENT=${COMPONENT}
CMHGDEPENDS     = cmodule swis
RAMCDEFINES     = -DSTANDALONE

RES_OBJ         = messages

# VCHIQ bits
VPATH = vc04_services.interface.vchiq_arm
# vc04_services.interface.vcos.generic vc04_services.interface.vcos.riscos
OBJS += vchiq_core vchiq_shim vchiq_util vchiq_kern_lib
#OBJS += vcos_generic_event_flags vcos_logcat vcos_mem_from_malloc vcos_cmd
CFLAGS += -DUSE_VCHIQ_ARM -D__VCCOREVER__=0x04000000 -Ivc04_services
# -Ivc04_services.interface.vcos.riscos

include CModule

# Dynamic dependencies:
