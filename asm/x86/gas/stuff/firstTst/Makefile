CC = gcc
LD = ld

CCSWITCHES = -c
LDSWITCHES = 

TARGETS = main.s
LDTARGETS = $(TARGETS:.s=.o)

default:	main.s
	${CC} ${CCSWITCHES} ${TARGETS}
	${LD} ${LDSWITCHES} ${LDTARGETS}
