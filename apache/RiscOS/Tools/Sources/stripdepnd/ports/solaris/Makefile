# Copyright 2000 Pace Micro Technology plc
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
# Makefile for stripdepnd
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date       Name         Description
# ----       ----         -----------
# 28-Sep-00  SNB          Created
#

#
# Generic options:
#
MKDIR   = mkdir -p
CC      = gcc
LD      = gcc
RM      = -rm -f
WIPE    = -rm 
CD      = cd
TOUCH   = touch
SQZ     = strip

COMPONENT = stripdepnd

#
# Internet version compatibility
#

DEFINES = ${OPTIONS}
CFLAGS  = -c -g ${DEFINES} ${INCLUDES} ${DEPENDS}
WFLAGS  = -rf
LDFLAGS = -g

#
# Libraries
#
CLIB      =

#
# Include files
#
INCLUDES  =

#
# Program specific options:
#
TARGET    = ${COMPONENT}

OBJS      = stripdepnd.o


#
# Rule patterns
#
.SUFFIXES:  .o .c
.c.o:;      ${CC} ${CFLAGS} -o $@ $<


#
# build the application
#
all: ${TARGET}
	@echo ${COMPONENT}: all complete

clean:
	${WIPE} ${WFLAGS} *.o
	${RM} ${TARGET}
	@echo ${COMPONENT}: cleaned

realclean: clean
	find . -type l -exec rm {} \;

#
# Target 
#
${TARGET}: ${OBJS} ${CLIB}
	${LD} -o $@ ${LDFLAGS} ${OBJS} ${CLIB}
	${SQZ} $@

# Dynamic dependencies:
