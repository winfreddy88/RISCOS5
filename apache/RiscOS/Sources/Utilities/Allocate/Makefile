# Copyright 2015 Castle Technology Ltd
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
# Makefile for Allocate
#

COMPONENT  = Allocate
TARGET     = !RunImage
INSTTYPE   = app
LIBS       = ${RLIB}
OBJS       = details file main alist object\
             datafile uuencode replyform helpwin 
INSTAPP_FILES = !Boot !Help !Run !RunImage Templates \
        !Sprites [!Sprites22] [!Sprites11] ResTypes:Resources
INSTAPP_VERSION = Messages
INSTAPP_DEPENDS = ResHelp

include CApp

ResHelp:
        ${MKDIR} ${INSTAPP}${SEP}Resources${SEP}Help
        ${CP} LocalRes:Help ${INSTAPP}${SEP}Resources${SEP}Help ${CPFLAGS}

# Dynamic dependencies:
