CC := g++
CCSWITCHES := -g
CLIBS := `pkg-config --libs ncurses` -l162lib
CFLAGS := `pkg-config --cflags ncurses`


default:	*.cpp
	${CC} ${CCSWITCHES} ${CFLAGS} *.cpp ${CLIBS}
