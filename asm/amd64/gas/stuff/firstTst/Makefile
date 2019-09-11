CC = as
LD = ld

CCSWITCHES = -o main.o
LDSWITCHES = 

TARGETS = main.s
LDTARGETS = $(TARGETS:.s=.o)

default:	main.s
	${CC} ${CCSWITCHES} ${TARGETS}
	${LD} ${LDSWITCHES} ${LDTARGETS}
