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
# Makefile for Battery Manager
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date       Name         Description
# ----       ----         -----------
# 07-Mar-01  SNB          Recreated.
#

#
# Program specific options:
#
COMPONENT  = BatMgr
APP        = !${COMPONENT}

# Pass OPTIONS as batmgr_app to include !BatMgr in ResourceFS
RESOURCEEXTRA = batmgr_resources ${OPTIONS}

include StdTools
include AAsmModule

# Note: !Run and !Sprites NOT in Messages module (only required on portables)
batmgr_resources:
        ${MKDIR} ${RESFSDIR}
        ${CP} LocalRes:Templates ${RESFSDIR}.Templates ${CPFLAGS}
        ${CP} Resources.Sprites  ${RESFSDIR}.Sprites   ${CPFLAGS}
        @echo ${COMPONENT}: extra resource files copied to Messages module

batmgr_app:
        ${MKDIR} ${RESAPPDIR}
        ${CP} LocalRes:!Run      ${RESAPPDIR}.!Run ${CPFLAGS}
        ${CP} Resources.!Sprites ${RESAPPDIR}.!Sprites ${CPFLAGS}
        @echo ${COMPONENT}: application frontend copied to Messages module

# Dynamic dependencies:
