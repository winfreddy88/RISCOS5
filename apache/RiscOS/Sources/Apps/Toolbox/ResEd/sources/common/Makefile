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
# ResEd common Makefile

OFILES = dbmalloc.o dbox.o debug.o dragdrop.o error.o interactor.o menu.o\
	message.o registry.o saveas.o wimp.o toolbox.o focus.o swicall.o

install export: commonlib.o
        @echo *** Commonlib build complete

commonlib.o: $(OFILES)
        libfile -c -o $@ $(OFILES)

.c.o:
        cc -c -depend !Depend $(CFLAGS) $(THROWBACK) $(INCLUDES) -o $@ $<

.s.o:
        objasm -quit -CloseExec $(AFLAGS) -from $< -to $@

clean:
       x wipe o.* ~CRF~V
       @echo *** Common cleaned


# Dynamic dependencies:
