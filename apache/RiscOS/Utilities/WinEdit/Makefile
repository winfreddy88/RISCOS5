# Copyright 2003 Castle Technology Ltd
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
# Makefile for WinEdit
#

COMPONENT  = WinEdit
TARGET     = !RunImage
INSTTYPE   = app
OBJS       = main message error registry document wimp interactor debug menu \
             selection dragdrop template grid data resize dbox winflags \
             extent props justify genheader sort saveas dbmalloc align colours
CINCLUDES  = -IC:
INSTAPP_FILES = !Boot !Run !Sprites !RunImage Palette Sprites Templates
INSTAPP_VERSION = Messages

include CApp

# Dynamic dependencies:
