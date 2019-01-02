# Copyright 2017 Castle Technology Ltd
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
# Makefile for Access+
#

COMPONENT  = Access+
TARGET     = !RunImage
INSTTYPE   = app
OBJS       = access
LIBS       = ${RLIB}
INSTAPP_FILES = !Boot !Run !RunImage !Sprites:Themes !Help Templates StartImage:Resources\
         Morris4.!Sprites:Themes.Morris4 Morris4.!Sprites22:Themes.Morris4\
         Ursula.!Sprites:Themes.Ursula Ursula.!Sprites22:Themes.Ursula
INSTAPP_VERSION = Messages

include CApp

C_WARNINGS = -Wp

# Dynamic dependencies:
