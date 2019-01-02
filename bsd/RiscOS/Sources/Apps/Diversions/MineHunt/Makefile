#
# Copyright (c) 2002-2011 Paul LeBeau
# All rights reserved.
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
# 
#    1. Redistributions of source code must retain the above copyright
#       notice, this list of conditions and the following disclaimer.
# 
#    2. Redistributions in binary form must reproduce the above copyright
#       notice, this list of conditions and the following disclaimer in the
#       documentation and/or other materials provided with the distribution.
# 
# THIS SOFTWARE IS PROVIDED BY PAUL LEBEAU "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL PAUL LEBEAU OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
# 
# The views and conclusions contained in the software and documentation
# are those of the authors and should not be interpreted as representing
# official policies, either expressed or implied, of Paul LeBeau.
#
# Makefile for MineHunt
#

COMPONENT  = MineHunt
TARGET     = !RunImage
INSTTYPE   = app
APP_OBJS   = main tools game
LIBS       = ${RLIB}
INSTAPP_FILES = !Help !Run !Sprites !Sprites22 Templates Parts Parts22 Sprites \
                !RunImage \
                Applause:Sounds RealMine:Sounds Shame:Sounds \
                Spiffing:Sounds TryAgain:Sounds YouDidIt:Sounds
INSTAPP_DEPENDS = Voices
INSTAPP_VERSION = Messages

include CApp

C_WARNINGS = -fa

#
# Static dependencies:
#
Voices: VoiceMod.s
        ${AS} VoiceMod.s ${ASFLAGS} -pd "VoiceName SETS \"Applause\"" -o Applause.o
        ${AS} VoiceMod.s ${ASFLAGS} -pd "VoiceName SETS \"RealMine\"" -o RealMine.o
        ${AS} VoiceMod.s ${ASFLAGS} -pd "VoiceName SETS \"Shame\""    -o Shame.o
        ${AS} VoiceMod.s ${ASFLAGS} -pd "VoiceName SETS \"Spiffing\"" -o Spiffing.o
        ${AS} VoiceMod.s ${ASFLAGS} -pd "VoiceName SETS \"TryAgain\"" -o TryAgain.o
        ${AS} VoiceMod.s ${ASFLAGS} -pd "VoiceName SETS \"YouDidIt\"" -o YouDidIt.o
        ${LD} -rmf -o Resources.Applause Applause.o
        ${LD} -rmf -o Resources.RealMine RealMine.o
        ${LD} -rmf -o Resources.Shame    Shame.o
        ${LD} -rmf -o Resources.Spiffing Spiffing.o
        ${LD} -rmf -o Resources.TryAgain TryAgain.o
        ${LD} -rmf -o Resources.YouDidIt YouDidIt.o

clean::
        ${RM} Resources.Applause
        ${RM} Resources.RealMine
        ${RM} Resources.Shame
        ${RM} Resources.Spiffing
        ${RM} Resources.TryAgain
        ${RM} Resources.YouDidIt

# Dynamic dependencies:
