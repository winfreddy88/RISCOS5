# Makefile for BCMSupport

DEBUG ?= FALSE

ifeq ($(DEBUG),TRUE)
CFLAGS += -DDEBUGLIB
CMHGFLAGS += -DDEBUGLIB
LIBS = ${DEBUGLIBS} ${NET5LIBS}
endif

LIBS += ${SYNCLIB}
CINCLUDES += -Itbox:

COMPONENT = BCMSupport

RES_OBJ = messages

# Header export phase
ASMHDRS   = BCMSupport
ASMCHDRS  = BCMSupport
HDRS      =

CMHGDEPENDS = BCMSupport mailbox cpuclock

OBJS = BCMSupport asm mailbox errors cpuclock

include CModule

# Dynamic dependencies:
