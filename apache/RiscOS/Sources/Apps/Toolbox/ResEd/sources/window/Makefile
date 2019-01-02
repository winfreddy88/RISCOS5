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
# ResEd Window CSE Makefile


INCLUDES = -I^.common,C:

CPFLAGS = A~C~DF~L~N~P~Q~R~S~T~V

LIBS = ^.common.o.commonlib C:o.Stubs

CFILES = main.c protocol.c relocate.c windowedit.c windinfo.c grid.c coords.c align.c\
         gadget.c props.c colours.c extent.c gui.c keycuts.c lassoo.c drag.c move.c\
         resize.c gadgdefs.c winddrag.c toolbars.c help.c

OFILES = main.o protocol.o relocate.o windowedit.o windinfo.o grid.o coords.o align.o\
         gadget.o props.o colours.o extent.o gui.o keycuts.o lassoo.o drag.o move.o\
         resize.o gadgdefs.o winddrag.o toolbars.o help.o

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
