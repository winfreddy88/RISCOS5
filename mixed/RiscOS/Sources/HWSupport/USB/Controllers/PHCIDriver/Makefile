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
# Makefile for PHCIDriver

COMPONENT  = PHCIDriver
TARGET     = PHCIDriver
ROM_SOURCE = init.s

AIFDBG     ?= aif.${MACHINE}.${TARGET}
GPADBG     ?= gpa.${MACHINE}.${TARGET}
ASFLAGS    += -G

include StdTools
include AAsmModule

${AIFDBG}: ${DBG_OBJECT}
        ${MKDIR} aif.${MACHINE}
        ${LD} -aif -bin -d -o ${AIFDBG} ${DBG_OBJECT}

${GPADBG}: ${AIFDBG}
        ${MKDIR} gpa.${MACHINE}
        ToGPA -s ${AIFDBG} ${GPADBG}

exception: ${GPADBG}
        find_error ${TARGET}

# Dynamic dependencies:
