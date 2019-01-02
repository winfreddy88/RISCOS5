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
# Makefile for squeeze
#

COMPONENT ?= squeeze
INSTAPP    = ${INSTDIR}${SEP}!Squeeze
OBJS       = squeeze unsqueeze1 unsqrm1
LIBS       = ${CLXLIB}
CDEFINES   = -DDEBUGGING=0
INSTAPP_FILES = !Boot !Help !Run !Setup !Sprites [!Sprites11] !Sprites22 Desc Messages Templates
INSTAPP_VERSION = Desc

include CApp

unsqueeze1.h unsqueeze1.c: unsqueeze.o
	aoftoc unsqueeze.o $*

unsqrm1.h unsqrm1.c: unsqrm.o
	aoftoc unsqrm.o $*

unsqueeze.o: unsqueeze.s
	${AOFASM} -o $@ unsqueeze.s

unsqrm.o: unsqrm.s
	${AOFASM} -o $@ unsqrm.s

clean::
	${RM} h.unsqueeze1
	${RM} c.unsqueeze1
	${RM} h.unsqrm1
	${RM} c.unsqrm1

o.unsqueeze1: c.unsqueeze1
	${CC} ${CFLAGS} -o $@ c.unsqueeze1

o.unsqrm1: c.unsqrm1
	${CC} ${CFLAGS} -o $@ c.unsqrm1

# Static dependencies:
squeeze.o o.squeeze squeeze.od od.squeeze: unsqueeze1.h unsqrm1.h

# Dynamic dependencies:
