# Copyright 1999 Pace Micro Technology plc
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
# Makefile for Portable (7500FE based)
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date       Name         Description
# ----       ----         -----------
# 09-Mar-01  SNB          Recreated
#

COMPONENT  ?= Portable75
TARGET     ?= ${COMPONENT}
HEADER1    = Portable
ROM_SOURCE = GetAll.s
RESOURCES  = no

include StdTools
include AAsmModule

ASFLAGS = -PD "${COMPONENT} SETL {TRUE}"

# Dynamic dependencies:
