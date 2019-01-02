# Copyright 1998 Acorn Computers Ltd
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
# ResEd shell Makefile


INCLUDES = -I^.common,C:

CPFLAGS = A~C~DF~L~N~P~Q~R~S~T~V

LIBS = ^.common.o.commonlib C:o.Stubs

CFILES = main.c document.c dragdrop.c protocol.c class.c fileinfo.c objflags.c rename.c copy.c genmsgs.c help.c

OFILES = main.o document.o dragdrop.o protocol.o class.o fileinfo.o objflags.o rename.o copy.o genmsgs.o help.o

install export: ${OUTPUT}
        @echo *** ${OUTPUT} build complete

${OUTPUT}: ${OFILES} ${LIBS}
	link ${LDFLAGS} -o $@ ${OFILES} ${LIBS}

${CFILES}: h.icondefs
	stamp $@
	
h.icondefs: ${TEMPLATES}
        ${WINEDIT} -h ${TEMPLATES} > $@

.c.o:
        cc -c $(CFLAGS) $(THROWBACK) $(INCLUDES) -o $@ $<

.s.o:
        objasm -quit -CloseExec $(AFLAGS) -from $< -to $@

clean:
	remove h.icondefs
        x wipe o.* ~CRF~V
       	@echo *** Misc cleaned


# Dynamic dependencies:
