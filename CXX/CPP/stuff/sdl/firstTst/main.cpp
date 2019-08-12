#include <SDL.h>
#include <stdio.h>

#define SCRWIDTH  640
#define SCRHEIGHT 480

bool init();

bool loadMedia();

void close();

int main(int argc, char* args[]){
  init();
  return 0;
}

bool init(){
  SDL_Window* window;          //declare window
  SDL_Surface* surface;        //declare screen surface

  if (SDL_Init( SDL_INIT_VIDEO ) < 0) printf("SDL init error %s\n", SDL_GetError());
  else {
    window = SDL_CreateWindow("firstTst", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCRWIDTH, SCRHEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) printf("couldn't create window. error %s", SDL_GetError());
    else {
      surface = SDL_GetWindowSurface(window);
      SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));     //fill surface with white color
      SDL_UpdateWindowSurface(window);
      SDL_Delay(2000);
    }
  }
  SDL_DestroyWindow(window);
  SDL_Quit();
}
