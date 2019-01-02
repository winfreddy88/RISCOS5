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
# Makefile for MakeModes
#

COMPONENT  = MakeModes
TARGET     = !RunImage
INSTTYPE   = app
OBJS       = file MakeModes mmerror mmsubs
LIBS       = ${RLIB}
INSTAPP_DEPENDS = BaseModes
INSTAPP_FILES = !Boot !Run !RunImage !Sprites !Sprites22 !Help Templates\
        Limits MonList MonModes\
        Docs.fig1:Docs Docs.fig2:Docs Docs.fig3:Docs Docs.fig4:Docs Docs.MakeMan:Docs
INSTAPP_VERSION = Messages

include CApp

C_WARNINGS = -Wp

BaseModes:
        ${MKDIR} ${INSTAPP}${SEP}BaseModes
        ${CP} Resources${SEP}BaseModes${SEP}nonVESA  ${INSTAPP}${SEP}BaseModes${SEP}NonVESA  ${CPFLAGS}
        ${CP} Resources${SEP}BaseModes${SEP}VESA     ${INSTAPP}${SEP}BaseModes${SEP}VESA     ${CPFLAGS}
        ${CP} Resources${SEP}BaseModes${SEP}VESA75Hz ${INSTAPP}${SEP}BaseModes${SEP}VESA75Hz ${CPFLAGS}

# Dynamic dependencies:
