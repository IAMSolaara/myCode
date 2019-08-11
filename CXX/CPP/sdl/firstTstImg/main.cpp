#include <SDL.h>
#include <stdio.h>

#define SCRWIDTH  640
#define SCRHEIGHT 480

bool init(SDL_Window* win, SDL_Surface* surface);

bool loadMedia(SDL_Window* win, SDL_Surface* surface, SDL_Surface* imgSurface);

void close();

int main(int argc, char* args[]){
  SDL_Window* window;          //declare window
  SDL_Surface* surface;        //declare screen surface
  SDL_Surface* imgSurface;     //declare image surface where the img will be loaded
  
  init(window, surface);
  loadMedia(window, surface, imgSurface);

  
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}

bool init(SDL_Window* win, SDL_Surface* surface){
  bool state = true;
  
  if (SDL_Init( SDL_INIT_VIDEO ) < 0) {
    printf("SDL init error %s\n", SDL_GetError());
    state = false;
  }
  else {
    win = SDL_CreateWindow("firstTst", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCRWIDTH, SCRHEIGHT, SDL_WINDOW_SHOWN);
    if (win == NULL) {
      printf("couldn't create window. error %s", SDL_GetError());
      state = false;
    }
    else {
      surface = SDL_GetWindowSurface(win);
      SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));     //fill surface with white color
      SDL_UpdateWindowSurface(win);
      SDL_Delay(10000);
    }
  }
  return state;
}


bool loadMedia(SDL_Window* win, SDL_Surface* surface, SDL_Surface* imgSurface){
  bool state = true;
  char imgPath[] = "images/test.bmp";
  imgSurface = SDL_LoadBMP(imgPath);
  if (imgSurface == NULL) {
    printf("Couldn't load image %s. SDL Error %s\n", imgPath, SDL_GetError());
    state = false;
  }
  return state;
}
