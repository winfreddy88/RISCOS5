# Copyright 1999 Element 14 Ltd
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
# Translate Makefile
#
# Neil Bingham (99-02-17).
#
# 99-02-17	Created.
#
COMPONENT       = Translate
TARGET 		= Target.Translate

CC 		= cc
CP 		= copy
CPFLAGS		= ~cfr~v
LD 		= Link
ASM 		= ObjAsm
CMHG	 	= CMHG
LB  		= LibFile
RM  		= Remove
WIPE 		= -Wipe
MKDIR 		= do mkdir -p

LIBDIR 		= <Lib$Dir>
LIBRARYDIR 	= <Build$Dir>.Library
CFLAGS 		= -c -depend !Depend -IC: -fah $(THROWBACK)
CPPFLAGS 	= -c -depend !Depend -IC: $(THROWBACK)
LDFLAGS		= -aif -c++
ASMFLAGS 	= -NoCache -depend !Depend
CMHGFLAGS 	= -depend !Depend $(THROWBACK)
WIPEFLAGS 	= ~CFR~V

#Libraries
CLIB		= CLib:o.stubs
C++LIB          = $(LIBDIR).C++Lib.o.c++lib
EVENTLIB	= $(LIBDIR).tboxlibs.o.eventlib
TOOLBOXLIB	= $(LIBDIR).tboxlibs.o.toolboxlib
WIMPLIB		= $(LIBDIR).tboxlibs.o.wimplib

EMAILCOMMONLIB	= $(LIBDIR).Email.Common.o.Common
SOCKLIB		= $(LIBDIR).TCPIPLibs.o.socklib5
DEBUGLIB	= $(LIBDIR).DebugLib.o.debuglib
INETLIB		= $(LIBDIR).TCPIPLibs.o.inetlib
UNIXLIB		= $(LIBDIR).TCPIPLibs.o.unixlib
NBLIB	        = $(LIBDIR).NBLib.o.nblib
ERRORLIB	= $(LIBDIR).ErrorLib.o.ErrorLib

DFLAGS 		= $(EXTRADFLAGS)


OBJS = 		\
 o.main 	\
 o.translate 	\
 o.htmlescape	\

LIBS = 		\
 C:o.stubs	\
 $(EXTRALIBS)	\
 $(NBLIB)	\

.SUFFIXES:	.o .c
.c.o:;		$(CC) $(CFLAGS) $(DFLAGS) -o $@ $<

all:    $(TARGET)

install: ${TARGET}
	${MKDIR} ${INSTDIR}.Docs
	${CP} ${TARGET} ${INSTDIR}.${COMPONENT} ${CPFLAGS}
	@echo ${COMPONENT}: installed

clean:
	$(RM)		$(TARGET)
	$(WIPE)	o	$(WIPEFLAGS)
	$(WIPE)	Target	$(WIPEFLAGS)

o.dirs:
	$(MKDIR) o
	$(MKDIR) Target
	create o.dirs
	stamp  o.dirs

$(TARGET): $(OBJS) $(LIBS) o.dirs
	$(LD) $(LDFLAGS) -o $@ $(OBJS) $(LIBS)

# Dynamic dependencies:
