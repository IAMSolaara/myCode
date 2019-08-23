CFLAGS := `pkg-config --cflags sdl2 SDL2_image SDL2_ttf SDL2_gfx SDL2_net SDL2_mixer gl glew`

CLIBS := `pkg-config --libs sdl2 SDL2_image SDL2_ttf SDL2_gfx SDL2_net SDL2_mixer gl glew`

default:	main.cpp
	g++ $(CFLAGS) main.cpp $(CLIBS)
debug:		main.cpp
	g++ $(CFLAGS) main.cpp $(CLIBS) -g
custom:
	g++ $(CFLAGS) $(SRCARG) $(CLIBS)
