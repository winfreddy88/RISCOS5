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
# Makefile for !ROMxxx
# Run this after you have completed a successful build
# Note that various customisations are required for each build

COMPONENT = !ROM<Build$KernelVersion>
INSTDIR := ${INSTDIR}.${COMPONENT}

include StdTools

all:    install

install:
        ${AWK} '/^Version/ { VERSION=$3 } END { system("set Build$KernelVersion " VERSION) }' <Build$Dir>.castle.RiscOS.Sources.Kernel.Version
        ${AWK} '/^VString SETS    / { VSTRING=$3 } END { system("set Build$KernelVString " VSTRING) }' <Build$Dir>.castle.RiscOS.Sources.Kernel.Version
        ${AWK} '/^Date    SETS    / { VDATE=$3 " " $4 " " $5 } END { system("set Build$KernelVDate " VDATE) }' <Build$Dir>.castle.RiscOS.Sources.Kernel.Version
        ${MKDIR} ${INSTDIR}
	echo RISC OS <Build$KernelVString> (<Build$KernelVDate>) { > ${INSTDIR}.Release }
        ${CP} LocalRes:!Help                       ${INSTDIR}.!Help       ${CPFLAGS}
        ${CP} Resources.!Run                       ${INSTDIR}.!Run        ${CPFLAGS}
        ${CP} LocalRes:!RunTestBed                 ${INSTDIR}.!RunTestBed ${CPFLAGS}
        ${CP} LocalRes:!RunRestore                 ${INSTDIR}.!RunRestore ${CPFLAGS}
        ${CP} LocalRes:FlashICP                    ${INSTDIR}.FlashICP    ${CPFLAGS}
        rompress -vZps 4M <Build$Dir>.Images.<Build$ImageName> ${INSTDIR}.trom
        ${CP} Resources.Update                     ${INSTDIR}.Update      ${CPFLAGS}
        ${CP} LocalRes:Warning                     ${INSTDIR}.Warning     ${CPFLAGS}
        @echo ${COMPONENT}: installed

# Dynamic dependencies:
