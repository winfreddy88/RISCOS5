# Makefile for RPiFiles

TARGET     ?= ${COMPONENT}
RESFSDIR   ?= ${RESDIR}${SEP}${TARGET}

include StdTools

resources:
	${WIPE} ${RESFSDIR} ${WFLAGS}
	${CP} Resources ${RESFSDIR} ${CPFLAGS}
        @${ECHO} ${COMPONENT}: resources copied to Messages module

# Dynamic dependencies:
