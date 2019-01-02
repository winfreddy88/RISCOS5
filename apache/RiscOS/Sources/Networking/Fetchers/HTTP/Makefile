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
# Makefile for AcornHTTP
#

COMPONENT    = HTTP
RESFSDIR     = ${RESDIR}${SEP}URL${SEP}${TARGET}
OBJS         = config connect connpool cookie dates decompress dns\
               generic header hosttrack module protocol readdata security\
               ses_ctrl start status stop URLclient utils writedata
CMHGDEPENDS  = cookie header module start
CMHGFILE     = HttpHdr
CDEFINES     = -D${SYSTEM} -DCOMPAT_INET4 -DCOOKIE -DCOMPRESSION -UTML ${OPTIONS}
CINCLUDES    = -ITCPIPLibs:,C:,C:zlib
ROMCDEFINES  = -DROM
CFLAGS       = -Wp
CDFLAGS      = -DTRACE -DUSE_SYSLOG
HDRS         =
ASMCHDRS     = HTTP
ASMHDRS      = HTTP
CMHGAUTOHDR  = HTTP
LIBS        += ${NET4LIBS} ${ZLIB}

include CModule

# Dynamic dependencies:
