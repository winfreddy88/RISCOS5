# Copyright 1999 Pace Micro Technology plc
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
# Makefile for OmniNFS
#

COMPONENT    = OmniNFS
OBJS         = CallBack omninfs serverlist
HDRS         =
CMHGDEPENDS  = omninfs
CMHGDFLAGS   = -DDEBUG
CDFLAGS      = -DDEBUG
CFLAGS       = -DNDEBUG -DINET -DCOMPAT_INET4
CINCLUDES    = -ITCPIPLibs:
ROMCDEFINES  = -DROM
LIBS         = ${NET4LIBS} ${ASMUTILS}
RES_PATH     = ThirdParty.OmniClient
INSTRES_FILES = Sprites
INSTRES_VERSION = Messages

include CModule

CFLAGS      += -Wp

# Dynamic dependencies:
