# Copyright 2016 Castle Technology Ltd
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
# Makefile for FormEd
#

COMPONENT  = FormEd
TARGET     = !RunImage
CUSTOMLINK = custom
INSTTYPE   = app
INSTAPP_FILES = !Boot !Run !RunImage !Help Templates\
        !Sprites !Sprites23 Sprites Sprites23 default
INSTAPP_VERSION = Messages
INSTAPP_DEPENDS = !RunImage

include CApp

!RunImage: bas.!RunImage
        ${RUN}BasCrunch -1 bas.!RunImage $@

# Dynamic dependencies:
