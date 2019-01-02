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
# Makefile for zlib and zlibmodlib libraries
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date       Name         Description
# ----       ----         -----------
# 30-Mar-98  KJB          Created.
#

COMPONENT ?= zlib
HDRS = zlib zconf
CFLAGS += -Wnp # Kill some of the warnings

ifeq (${COMPONENT},zlib)

# zlib rules
OBJS = \
 adler32 \
 compress \
 crc32 \
 deflate \
 gzclose \
 gzlib \
 gzread \
 gzwrite \
 infback \
 inffast \
 inflate \
 inftrees \
 trees \
 uncompr \
 zutil

# Add in an extra target suitable for utilities
LIBRARIES = zlib zlibzm zlibu
UTIL_OBJS = $(addprefix ou.,${OBJS})
CLEAN_DEPEND = cleanutil

else

# zlibmodlib rules
OBJS = modlib compress uncompr

endif

include CLibrary

# Utility build rules
.SUFFIXES: .ou

.c.ou:; ${CC} ${CFLAGS} ${C_NO_ZI} ${C_NO_STKCHK} -o $@ $<

${LIBEXT}.zlibu: ${UTIL_OBJS} ou.extradir ${DIRS}
        ${AR} ${ARFLAGS} ${LIBEXT}.zlibu ${UTIL_OBJS}

ou.extradir::
        ${MKDIR} ou
        ${TOUCH} $@

cleanutil:
        @IfThere ou        Then ${ECHO} ${WIPE} ou ${WFLAGS}
        @IfThere ou        Then ${WIPE} ou ${WFLAGS}


# Dynamic dependencies:
