CC := gcc
CCSWITCHES := -std=c99 -g
CLIBS := `pkg-config --libs ncurses` -l162lib
CFLAGS := `pkg-config --cflags ncurses`

TARGETS := main.c

default:	${TARGETS}
	${CC} ${CCSWITCHES} ${CFLAGS} ${TARGETS} ${CLIBS}
