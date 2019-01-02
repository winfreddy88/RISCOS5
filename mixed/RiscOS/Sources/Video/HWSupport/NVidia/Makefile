# Copyright 2008 Castle Technology Ltd
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
# Makefile for NVidia
#

COMPONENT = NVidia
OBJS      = nv_globals nv_dac nv_dac2 nv_crtc nv_crtc2 \
            nv_general _nv_info_ GetAll NewPost CLib CLibAsm
CMHGFILE  =
HDRS      =
RAMASMDEFINES += -PD "standalone SETL {TRUE}" -PD "MergedMsgs SETS \"${MERGEDMSGS}\""

include CModule

#
# Ensure that the SharedCLibrary is not used
#
ROM_LIBS  =
SA_LIBS   =
ROM_SYMS  =

#
# Ensure v5TE processor instruction set
#
ASFLAGS  += ${OPTIONS} -cpu 5TE
CFLAGS   += ${DFLAGS} ${C_NO_STKCHK} -cpu 5TE -apcs /nofp

#
# Static dependency to ensure no unaligned loads
#
_nv_info_.c: nv_info.c
        ${SED} -f scripts.RomOffsets < c.nv_info > $@

_nv_info_.o: _nv_info_.c
        ${CC} ${CFLAGS} -o $@ _nv_info_.c

clean::
        ${WIPE} c._nv_info_ ${WFLAGS}

# Dynamic dependencies:
