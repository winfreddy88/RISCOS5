# 
# CDDL HEADER START
# 
# The contents of this file are subject to the terms of the
# Common Development and Distribution License (the "Licence").
# You may not use this file except in compliance with the Licence.
# 
# You can obtain a copy of the licence at
# RiscOS/Sources/ThirdParty/Endurance/Lib/DThreads/LICENCE.
# See the Licence for the specific language governing permissions
# and limitations under the Licence.
# 
# When distributing Covered Code, include this CDDL HEADER in each
# file and include the Licence file. If applicable, add the
# following below this CDDL HEADER, with the fields enclosed by
# brackets "[]" replaced with your own identifying information:
# Portions Copyright [yyyy] [name of copyright owner]
# 
# CDDL HEADER END
# 
# 
# Copyright 2007 Endurance Technology Ltd.  All rights reserved.
# Use is subject to license terms.
# 
# Makefile for DThreads test harness
#
# ***********************************
# ***    C h a n g e   L i s t    ***
# ***********************************
# Date         Name    Description
# ----         ----    -----------
# 22-Jun-2007  BJGA    Created

COMPONENT   = DThreads test module
TARGET      = DThrTest
CMHGFILE    = ModHdr
RES_OBJ     = 
OBJS        = Test
LIBS        = C:DThreads.o.DThreads
DBG_LIBS    = C:DThreads.o.DThreadsD
CFLAGS      = -zps0 -ff -fah

include StdTools
include ModStdRule
include DbgRules
include ModuleLibs
include CModule

# Dynamic dependencies:
