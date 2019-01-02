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
# Makefile for FTP
#

OBJS        = commands connect header processdir protocol readdata\
              rewrite ses_ctrl start status stop utils module
CMHGDEPENDS = module ses_ctrl readdata
CUSTOMRES   = custom
IMGFILES    = LocalRes:Dir LocalRes:DirGrey LocalRes:File LocalRes:FileGrey
RES_OBJ     =
SA_OBJS     = ${OBJS} msgs
DBG_OBJS    = ${OBJS} msgs

include C:Fetchers.FetchMake

#
# Bonus files beyond message translations
#
resources: resources_common LocalRes:Messages ${IMGFILES}
        ${CP} LocalRes:Dir       ${RESFSDIR}.Dir      ${CPFLAGS}
        ${CP} LocalRes:DirGrey   ${RESFSDIR}.DirGrey  ${CPFLAGS}
        ${CP} LocalRes:File      ${RESFSDIR}.File     ${CPFLAGS}
        ${CP} LocalRes:FileGrey  ${RESFSDIR}.FileGrey ${CPFLAGS}
        @echo ${COMPONENT}: resources copied to Messages module

#
# Package up more than just the message translations
#
od.msgs: o.msgs
        ${CP} o.msgs od.msgs ${CPFLAGS}
o.msgs: ${MERGEDMSGS} ${DIRS} ${IMGFILES}
        ${RESGEN} messages_file $@ LocalRes:Messages ${RES_PATH}.Messages \
                                   LocalRes:Dir      ${RES_PATH}.Dir \
                                   LocalRes:DirGrey  ${RES_PATH}.DirGrey \
                                   LocalRes:File     ${RES_PATH}.File \
                                   LocalRes:FileGrey ${RES_PATH}.FileGrey

# Dynamic dependencies:
