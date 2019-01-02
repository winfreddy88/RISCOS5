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
MKDIR   = cdir
CC      = cc
CP      = copy
LD      = link
RM      = remove
SQUEEZE = squeeze
WIPE    = x wipe

CFLAGS  = ${THROWBACK} -c -depend !Depend -fah -fussy ${INCLUDES} ${DFLAGS}
CPFLAGS = ~cfr~v
SQFLAGS = -nolist
WFLAGS  = ~c~v
LINKFLAGS =

#
# Libraries
#
CLIB       = CLib:o.stubs
WIMPLIB    = tbox:o.wimplib


#
# Include files
#
INCLUDES = -Itbox:,C:

DFLAGS   =

#
# Rule patterns
#
.c.o:;      ${CC} ${CFLAGS} -o $@ $<

#
# GENERIC RULES
#
all: ^.TTextTest ^.TTextKill
     @echo all built

clean:
        ${RM} o.TTextTest
        ${RM} o.TTextKill
        ${RM} ^.TTextTest
        ${RM} ^.TTextKill
        @echo cleaned

#
# Static dependencies:
#
^.TTextTest: o.TTextTest ${CLIB} ${WIMPLIB}
        ${LD} ${LINKFLAGS} -o $@ o.TTextTest ${CLIB} ${WIMPLIB}
#        ${SQUEEZE} $@

^.TTextKill: o.TTextKill ${CLIB} ${WIMPLIB}
        ${LD} ${LINKFLAGS} -o $@ o.TTextKill ${CLIB} ${WIMPLIB}
#        ${SQUEEZE} $@

#---------------------------------------------------------------------------
# Dynamic dependencies:
