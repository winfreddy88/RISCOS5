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
# Makefile for FontEd
#

COMPONENT  = FontEd
TARGET     = !RunImage
INSTTYPE   = app
OBJS       = main wlink misc drag editchar heap help isqrt loadsave menu\
             redraw draw sprites suspend scaffold thicken includes
LIBS       = ${RLIB}
INSTAPP_FILES = !Boot !Run !RunImage !Sprites !Sprites22 !Help Templates
INSTAPP_VERSION = Messages

include CApp

# Dynamic dependencies:
