# 
# Copyright (c) 2014, RISC OS Open Ltd
# All rights reserved.
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
# Makefile for Hopper
#

COMPONENT  = Hopper
TARGET     = !RunImage
INSTTYPE   = app
APP_OBJS   = water timer templates sync score scenery qtm menu main keys \
             iconbar icon hopper graphics frog data cars snake \
             memory messages exit
LIBS       = ${OSLIB}
CINCLUDES  = -IOS:,C:
INSTAPP_DEPENDS = datafiles
INSTAPP_FILES = !Help !Run !Sprites !Sprites22 !Sprites11 Templates !RunImage \
                Keys
INSTAPP_VERSION = Messages

include CApp

C_WARNINGS = -fa

#
# Static dependencies:
#
datafiles:
        ${MKDIR} ${INSTAPP}${SEP}Levels
        ${MKDIR} ${INSTAPP}${SEP}Music
        ${MKDIR} ${INSTAPP}${SEP}Graphics
        ${MKDIR} ${INSTAPP}${SEP}Sounds
        ${CP} DataFiles${SEP}Levels   ${INSTAPP}${SEP}Levels   ${CPFLAGS}
        ${CP} DataFiles${SEP}Music    ${INSTAPP}${SEP}Music    ${CPFLAGS}
        ${CP} DataFiles${SEP}Graphics ${INSTAPP}${SEP}Graphics ${CPFLAGS}
        ${CP} DataFiles${SEP}Sounds   ${INSTAPP}${SEP}Sounds   ${CPFLAGS}

# Dynamic dependencies:
