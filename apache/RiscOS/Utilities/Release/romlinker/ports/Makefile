# Copyright 2001 Pace Micro Technology plc
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
# ROM linker.

TARGET=romlinker

CLX=${CLXPATH}/clx.a

CFLAGS=-c -I${CLXPATH}
CC=gcc
TOLOCAL=cp
OBJALL=filereader.o filewriter.o romlinker.o memory.o makerom.o makeexprom.o

EXTDIR1=${CLXPATH}
EXTLIB1=${CLX}

noarg: ${TARGET}
	@echo "Made ${TARGET} (the default target)"

${TARGET}: $(OBJALL)
	$(CC) -o ${TARGET} $(OBJALL) $(EXTLIB1)
	@echo "Made ${TARGET}"

install: ${TARGET}
	install ${TARGET} ${RISCOS_BUILD_TOOLS}/${TARGET}
	strip ${RISCOS_BUILD_TOOLS}/${TARGET}

clean:
	-rm -f ${OBJALL}
	-rm -f ${TARGET}
	@echo cleaned ${TARGET}

realclean: clean
	-find . -type l -print | xargs rm
	@echo cleaned ${TARGET} links

links:
	./mklinks
	@echo made ${TARGET} links
