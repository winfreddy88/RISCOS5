# Copyright 1996 Acorn Computers Ltd
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
# Makefile for Fake Portable
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date       Name         Description
# ----       ----         -----------
# 09-Aug-94  AMcC         Created.
#

#
# Generic options:
#
MKDIR   = cdir
AS      = aasm
CP      = copy
RM      = remove
CCFLAGS = -c -depend !Depend -IC:
ASFLAGS = -depend !Depend -Stamp -quit -module -To $@ -From
CPFLAGS = ~cfr~v

#
# Program specific options:
#
COMPONENT = FakePort
SOURCE    = s.Portable
TARGET    = rm.Portable

#
# Generic rules:
#
all: ${TARGET}
        @echo ${COMPONENT}: all built

clean:
        ${RM} ${TARGET}
        @echo ${COMPONENT}: cleaned

${TARGET}: ${SOURCE}
        ${AS} ${ASFLAGS} ${SOURCE}

# Dynamic dependencies:
rm.Portable: Hdr:ListOpts
rm.Portable: Hdr:Macros
rm.Portable: Hdr:System
rm.Portable: Hdr:SWIs
rm.Portable: Hdr:CPU.Generic26
rm.Portable: Hdr:IO.GenericIO
rm.Portable: Hdr:RISCOS
rm.Portable: Hdr:ModHand
rm.Portable: Hdr:Services
rm.Portable: Hdr:FSNumbers
rm.Portable: Hdr:NewErrors
rm.Portable: Hdr:Portable
rm.Portable: s.date/time
