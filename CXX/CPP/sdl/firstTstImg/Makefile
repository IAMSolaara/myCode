CFLAGS := `pkg-config --cflags sdl2 SDL2_image`

CLIBS := `pkg-config --libs sdl2 SDL2_image`

default:	main.cpp
	g++ ${CFLAGS} main.cpp ${CLIBS}
debug:		main.cpp
	g++ ${CFLAGS} main.cpp ${CLIBS} -g
