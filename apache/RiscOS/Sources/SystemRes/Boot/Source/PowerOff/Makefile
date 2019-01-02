# Copyright 2002 Tematic Ltd
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
#
# Paths
#
EXP_HDR =       <export$dir>
LIBDIR          = <Lib$Dir>

#
# Generic options:
#
MKDIR =         cdir
AS =            objasm
CP =            copy
LD =            ${MEMCHECKLD} link
RM =            remove
WIPE =          wipe
STRIPDEPEND =   stripdepnd

ASMFLAGS =      -depend !Depend ${THROWBACK} 
CPFLAGS =       ~cfr~v
WFLAGS =        ~c~v

#
# Program specific options:
#
COMPONENT =     PowerOff
RAMTARGET =     bin.PowerOff

#
# Main rules:
#
all: local_dirs
     ${AS} poweroff.s poweroff.o
     ${LD} -bin -o ${RAMTARGET} poweroff.o
     settype ${RAMTARGET} FFC
     @echo ${COMPONENT}: all complete

clean:  
        ${WIPE} o ${WFLAGS}
        ${WIPE} bin ${WFLAGS}
        ${RM} ${RAMTARGET}
        @echo ${COMPONENT}: cleaned

local_dirs:
        ${MKDIR} o
        ${MKDIR} bin

# Dynamic dependencies:
