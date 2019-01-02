# Copyright 1999 Element 14 Ltd
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
# Makefile for FrontEnd
#

COMPONENT ?= FrontEnd

CFLAGS     = ${C_STKCHK}
CDEFINES   = -DTEST_RELEASE -DINCLUDES_AS_INCLUDES
CDFLAGS    = -DTRACE

CMHGFILE   = FEhdr
CUSTOMRES  = no
HDRS       =
OBJS       = FEbkg  FEcmdline  FEdbox  FEexit  FEfileicon \
             FEhelp  FEiconbar  FEinfo  FEinit  FEinterr  FEmem \
             FEmenus  FEmsg  FEoptions  FEoutput  FEsaveas  FEtask \
             FEtxtwin  frontend  gen  lexer  parser  slist  utils
LIBS       = ${FLEXLIB} ${RLIB} ${ASMUTILS}

include CModule

# Dynamic dependencies:
