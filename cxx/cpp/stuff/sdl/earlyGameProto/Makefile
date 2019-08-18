CFLAGS := `pkg-config --cflags sdl2 SDL2_image SDL2_mixer`

CLIBS := `pkg-config --libs sdl2 SDL2_image SDL2_mixer`

default:	main.cpp
	g++ $(CFLAGS) main.cpp $(CLIBS)
debug:		main.cpp
	g++ $(CFLAGS) main.cpp $(CLIBS) -g
custom:
	g++ $(CFLAGS) $(SRCARG) $(CLIBS)
