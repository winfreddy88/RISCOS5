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
# Makefile for Gopher
#

OBJS        = commands connect processdir readdata\
              ses_ctrl start status stop utils module
CMHGDEPENDS = module processdir
CUSTOMRES   = custom
IMGFILES    = LocalRes:Dir LocalRes:File
RES_OBJ     =
SA_OBJS     = ${OBJS} msgs
DBG_OBJS    = ${OBJS} msgs

include C:Fetchers.FetchMake

#
# Bonus files beyond message translations
#
resources: resources_common LocalRes:Messages ${IMGFILES}
        ${CP} LocalRes:Dir       ${RESFSDIR}.Dir      ${CPFLAGS}
        ${CP} LocalRes:File      ${RESFSDIR}.File     ${CPFLAGS}
        @echo ${COMPONENT}: resources copied to Messages module

#
# Package up more than just the message translations
#
od.msgs: o.msgs
        ${CP} o.msgs od.msgs ${CPFLAGS}
o.msgs: ${MERGEDMSGS} ${DIRS} ${IMGFILES}
        ${RESGEN} messages_file $@ LocalRes:Messages ${RES_PATH}.Messages \
                                   LocalRes:Dir      ${RES_PATH}.Dir \
                                   LocalRes:File     ${RES_PATH}.File

# Dynamic dependencies:
