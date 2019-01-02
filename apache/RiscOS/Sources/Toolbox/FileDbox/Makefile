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
# Makefile for a Toolbox Object module
#
# $Id: Makefile,v 1.4 2000/05/04 12:53:25 sbrodie Exp $
#
# Component specific options:
#
RAMBOTH    = o.msgs

COMMON_OBJ = o.Modhdr_NoD o.auxiliary o.create o.delete o.events o.FindAll\
 o.getstate o.hide o.MakeList o.miscop o.show o.Sort o.Sprite o.task\
 o.getitemtex o.setstate o.getsel o.delitem o.additem

ROM_OBJS = o.mainROM ${COMMON_OBJ}

RAM_OBJS = o.main ${RAMBOTH} ${COMMON_OBJ}

DBG_OBJS = o.Modhdr od.auxiliary od.create od.delete od.events od.FindAll\
 od.getstate od.hide od.MakeList od.miscop od.show od.Sort od.Sprite od.task\
 od.getitemtex od.setstate od.getsel od.delitem od.additem od.main ${RAMBOTH}


CINCLUDES = -ISupport
DFLAGS = -DDesk__MODULE_CLIENT

VPATH = @ Support Support.scrolllist

EXTRARAMLIBS = C:Desk.o.Desk_M
EXTRAROMLIBS = ${EXTRARAMLIBS}

#
# Get main rules
#
include C:tboxlibint.TboxMake


#
# Module specific rules:
#
resources: resources-both
        @echo ${COMPONENT}: resource files copied to Messages module

clean: toolbox-clean
        @echo ${COMPONENT}: cleaned

#---------------------------------------------------------------------------
# Dynamic dependencies:
