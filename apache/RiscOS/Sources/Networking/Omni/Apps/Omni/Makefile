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
# File:    Makefile
# Purpose: Makefile for Omni
# Author:  Ben Laughton
#
# History:
#
# 2000-03-02: BAL
# Created.




# ------------------------------------------------------------------------------
# Paths
#

# Export path for Messages module
RESDIR          = <resource$dir>.Resources2.$(COMPONENT)



# ------------------------------------------------------------------------------
# Generic options
#

MKDIR           = do mkdir -p
CP              = copy
RM              = remove
WIPE            = x wipe
MAKE            = @amu -f MainMake
AWK             = GNU.gawk 
INSERTVERSION   = ${AWK} -f Build:AwkVers

# ------------------------------------------------------------------------------
# Flags
#

CPFLAGS         = ~cfr~v
WFLAGS          = ~c~vr




# ------------------------------------------------------------------------------
# Program specific options
#

COMPONENT       = Omni
NORMAL_TARGET   = Omni
HIERPROF_TARGET = Omnihp
DEBUG_TARGET    = Omnid

HDR = h.OmniClient

A_DEBUG_ON      = "-pd \"DEBUG SETL {TRUE}\""
A_DEBUG_OFF     = "-pd \"DEBUG SETL {FALSE}\""

# C debugging and DebugLib do not map 1<->1 since DebugLib is used for other
# stuff as well
C_DEBUG_ON      = -DDEBUG -DNDEBUG
C_DEBUG_OFF     = -DNDEBUG




# ------------------------------------------------------------------------------
# Build rules
#

# Local

all:
        $(MAKE) $(MFLAGS) $(MAKECMDGOALS) TARGET=$(NORMAL_TARGET) ASMDEFINES=$(A_DEBUG_OFF) CDEFINES=$(C_DEBUG_OFF) EXT=o
        @echo $(COMPONENT): build complete

debug:
        $(MAKE) $(MFLAGS) $(MAKECMDGOALS) TARGET=$(DEBUG_TARGET) ASMDEFINES=$(A_DEBUG_ON) CDEFINES="$(C_DEBUG_ON) -DDEBUGLIB" EXT=od
        @echo $(COMPONENT): debug build complete

preprocess:
        $(MAKE) $(MFLAGS) $(MAKECMDGOALS)  ASMDEFINES=$(A_DEBUG_OFF) CDEFINES=$(C_DEBUG_OFF) EXT=i
        @echo $(COMPONENT): preprocessing complete


# RISC OS ROM build rules

rom:
        $(MAKE) $(MFLAGS) $(MAKECMDGOALS) TARGET=$(NORMAL_TARGET) ASMDEFINES=$(A_DEBUG_OFF) CDEFINES=$(C_DEBUG_OFF) EXT=o
        @echo $(COMPONENT): build complete

export:
        $(MAKE) $(MFLAGS) $(MAKECMDGOALS) EXT=o

install:
        $(MAKE) $(MFLAGS) $(MAKECMDGOALS) TARGET=$(NORMAL_TARGET) EXT=o

install_rom:
        $(MAKE) $(MFLAGS) $(MAKECMDGOALS) TARGET=$(NORMAL_TARGET) EXT=o

rom_link:
        $(MAKE) $(MFLAGS) $(MAKECMDGOALS) TARGET=$(NORMAL_TARGET) EXT=o

resources: LocalRes:Messages
        $(MKDIR) $(RESDIR)
        TokenCheck LocalRes:Messages
        ${INSERTVERSION} LocalRes:Messages > $(RESDIR).Messages
        @echo $(COMPONENT): resource files copied to Messages module

clean:
        $(MAKE) $(MFLAGS) $(MAKECMDGOALS)  TARGET=Dummy EXT=o
        $(MAKE) $(MFLAGS) $(MAKECMDGOALS)  TARGET=Dummy EXT=oMC
        $(MAKE) $(MFLAGS) $(MAKECMDGOALS)  TARGET=Dummy EXT=oHP
        $(MAKE) $(MFLAGS) $(MAKECMDGOALS)  TARGET=Dummy EXT=od
        $(MAKE) $(MFLAGS) $(MAKECMDGOALS)  TARGET=Dummy EXT=i
        @$(WIPE) linked $(WFLAGS)
        @$(WIPE) map    $(WFLAGS)
        @$(WIPE) rm     $(WFLAGS)
        @$(WIPE) aof    $(WFLAGS)
        @$(RM) $(HDR)
        @$(RM) h.OmniClientHdr
        @echo $(COMPONENT): cleaned

# Dynamic dependencies:
