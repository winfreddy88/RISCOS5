# Copyright 2012 Castle Technology Ltd
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
COMPONENT = rompress
OBJS = rompress unsqueeze1 squeeze algorithms zlib zinflate asm romcrc patchable1 uimage
LIBS = ${CLXLIB} C:zlib.o.zlib

include AppLibs
include CApp

unsqueeze1.h unsqueeze1.c: unsqueeze.o
	aoftoc unsqueeze.o $*

unsqueeze.o: unsqueeze.s
	${AOFASM} -o $@ unsqueeze.s

o.unsqueeze1: c.unsqueeze1
	${CC} ${CFLAGS} -o $@ c.unsqueeze1

patchable1.h patchable1.c: patchable.o
	aoftoc patchable.o $*

patchable.o: patchable.s
	${AOFASM} -o $@ patchable.s

o.patchable1: c.patchable1
	${CC} ${CFLAGS} -o $@ c.patchable1

o.zinflate: zinflate.zinflate
	binaof zinflate.zinflate $@ BinAofData rompress_zinflate

zinflate.zinflate: zinflate.s.zinflate
	${CD} zinflate
	${MAKE}
	${CD} ^

clean::
	${RM} h.unsqueeze1
	${RM} c.unsqueeze1
	${RM} h.patchable1
	${RM} c.patchable1
	${CD} zinflate
	${MAKE} clean
	${CD} ^

# Static dependencies:
o.squeeze od.squeeze: unsqueeze1.h

# Dynamic dependencies:
