# Copyright 1996 Acorn Computers Ltd
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
# Makefile for Scrap
#

COMPONENT  = Scrap
TARGET     = !RunImage
CUSTOMLINK = custom
INSTTYPE   = app
INSTAPP_FILES = !Boot !Run !RunImage !Help \
        !Sprites:Themes !Sprites11:Themes !Sprites22:Themes \
        Morris4.!Sprites:Themes.Morris4 Morris4.!Sprites22:Themes.Morris4 \
        Ursula.!Sprites:Themes.Ursula Ursula.!Sprites22:Themes.Ursula
INSTAPP_VERSION = Messages
INSTAPP_DEPENDS = !RunImage

include CApp

!RunImage: bas.!RunImage
        ${RUN}BasCrunch -1 bas.!RunImage $@

# Dynamic dependencies:
