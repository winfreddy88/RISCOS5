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
# Makefile for URL
#

COMPONENT    = URL
RESFSDIR     = ${RESDIR}${SEP}URL${SEP}${TARGET}
OBJS         = directswi enumerate generic geturl module parseurl\
               protocol proxy readdata register status stop utils
CMHGDEPENDS  = protocol
CDEFINES     = -D${SYSTEM} -DCOMPAT_INET4 -UTML -UDIRECTSWI
CINCLUDES    = -IC: -IC:TCPIPLibs
ROMCDEFINES  = -DROM
CFLAGS       = -Wp
CDFLAGS      = -DDEBUGLIB
HDRS         =
ASMCHDRS     = URL
ASMHDRS      = URL
CMHGAUTOHDR  = URL
LIBS        += ${NET4LIBS}
INSTRES_FILES =\
    images.internal-gopher-binary:images\
    images.internal-gopher-image:images\
    images.internal-gopher-index:images\
    images.internal-gopher-menu:images\
    images.internal-gopher-menu-grey:images\
    images.internal-gopher-movie:images\
    images.internal-gopher-sound:images\
    images.internal-gopher-telnet:images\
    images.internal-gopher-text:images\
    images.internal-gopher-unknown:images\
    images.internal-gopher-unknown-grey:images

include CModule

# Dynamic dependencies:
