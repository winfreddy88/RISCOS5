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
# Makefile for Dversions (ReadMe etc)
# 
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date       Name   Description
# ----       ----   -----------
# 30-Jan-95  AMcC   Created
#

#
# Program specific options:
#
COMPONENT  = Diversions
DDIR       = DataFiles
LDIR       = ${LOCALE}
INSTAPP    = ${INSTDIR}

# Generic options:
#
MKDIR   = do mkdir -p
CP      = copy
RM      = remove
WIPE    = x wipe

CPFLAGS = ~cfr~v
WFLAGS  = ~c~v

FILES =\
 ${LDIR}.ReadMe\
 ${DDIR}.Desktop

#
# Main rules:
#
all: ${FILES}
        @echo ${COMPONENT}: All built (Disc)

install: ${FILES}
        ${MKDIR} ${INSTAPP}
        ${CP} ${LDIR}.ReadMe  ${INSTAPP}.ReadMe  ${CPFLAGS}
        ${CP} ${DDIR}.Desktop ${INSTAPP}.Desktop ${CPFLAGS}
        Access ${INSTAPP}.ReadMe WR/r
        Access ${INSTAPP}.Desktop WR/r
        @echo ${COMPONENT}: All installed (HardDisc)

clean:
        @echo ${COMPONENT}: cleaned

#---------------------------------------------------------------------------
# Dynamic dependencies:
