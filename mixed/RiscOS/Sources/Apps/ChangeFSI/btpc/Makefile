# Copyright 2003 Tematic Ltd
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
# Makefile for btpc

CC      = cc
CPP     = c++
CPPFLAGS= -DRISCOS_TWEAK -Xcc -ffa
RM      = x wipe
RMFLAGS = ~C~VF
MV      = rename
SQUEEZE = squeeze
MKDIR   = cdir 

# source files to get to BTPC
SRC=    dbtpc compact declevel colmap

# Make C into O
.c.o:
        $(CC) $(CFLAGS) -c $*.c

btpc:   
        ${MKDIR} bin
        ${CPP} ${SRC} ${CPPFLAGS}
        ${MV} dbtpc bin.btpc
        ${SQUEEZE} bin.btpc

clean:
        $(RM) o.* ${RMFLAGS}
        ${RM} dbtpc
        $(RM) bin.btpc ${RMFLAGS}
        $(RM) bin ${RMFLAGS}


