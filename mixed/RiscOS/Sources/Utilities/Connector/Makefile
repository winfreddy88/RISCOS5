#
# Copyright (c) 2015, RISC OS Open Ltd
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
# Makefile for Connector
#

COMPONENT  = Connector
TARGET     = !RunImage
INSTTYPE   = app
OBJS       = Ansi ascii Chat Connector Console CRCTAB display driver event global\
             import inout layer6 LRZ LSZ misc rawfont serialbuff Script spool Text\
             TIMING vt100 xfont ZM ZMISC ibmfonts isofonts
LIBS       = ${DESKLIB} ${OSLIB}
CINCLUDES  = -IDesk:,OS:,C:
CDEFINES   = -DDesk_COMPATABILITY
INSTAPP_DEPENDS = datafiles
INSTAPP_FILES = !Boot !Help !Run !RunImage !Sprites !Sprites22 Templates\
                Sprites Sprites22 config
INSTAPP_VERSION = Messages

include CApp

C_WARNINGS = -fa

#
# Static dependencies:
#
datafiles:
        ${MKDIR} ${INSTAPP}${SEP}Scripts
        ${MKDIR} ${INSTAPP}${SEP}Fonts
        ${CP} Resources${SEP}scripts ${INSTAPP}${SEP}Scripts ${CPFLAGS}
        ${CP} Resources${SEP}fonts   ${INSTAPP}${SEP}Fonts   ${CPFLAGS}

# Dynamic dependencies:
