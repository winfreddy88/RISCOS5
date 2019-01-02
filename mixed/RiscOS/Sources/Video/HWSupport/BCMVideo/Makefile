# Copyright 2012 Castle Technology Ltd
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
# Makefile for BCMVideo

COMPONENT = BCMVideo
TARGET	  = BCMVideo
	
# By default, the shared makefiles do a lot of the work of installing a
# Messages file in ResourceFS. This is how to overrides it:
#CUSTOMRES = custom 

# By default, the shared makefiles assume you want to use CMHG to create
# your module header. This is how to override it:
CMHGFILE =

# Header export phase
#ASMHDRS   = 
#ASMCHDRS  = 
HDRS      =
OBJS     = BCMVideo

# CModule is equally useful for assembler modules. Its advantages over the
# AAmModule makefile are that you can use multiple source files (permitting
# more encapsulation, which is good programing practice) and it allows you
# to use non-postion-independent code, provided you do BL __RelocCode early
# in module initialisation.
include CModule


# Dynamic dependencies:
