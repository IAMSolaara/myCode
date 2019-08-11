#include <SDL.h>
#include <stdio.h>

#define SCRWIDTH  640
#define SCRHEIGHT 480

bool init(SDL_Window* win, SDL_Surface* surface);

bool loadMedia(SDL_Window* win, SDL_Surface* surface, SDL_Surface* imgSurface);

void close(SDL_Window* win, SDL_Surface* imgSurface);

int main(int argc, char* args[]){
  SDL_Window* window;          //declare window
  SDL_Surface* surface;        //declare screen surface
  SDL_Surface* imgSurface;     //declare image surface where the img will be loaded
  
  if (!init(window, surface)){
    printf("Failed to init SDL.\n");
  }
  else {
    if (!loadMedia(window, surface, imgSurface)) {
      printf("Failed to load media.\n");
    }
    else {
      SDL_BlitSurface(imgSurface, NULL, surface, NULL);
      SDL_UpdateWindowSurface(window);
      SDL_Delay(2000);
    }
  }
  close(window, imgSurface);
  return 0;
}

bool init(SDL_Window* win, SDL_Surface* surface){
  bool state = true;
  
  if (SDL_Init( SDL_INIT_EVERYTHING ) < 0) {
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

void close(SDL_Window* win, SDL_Surface* imgSurface) {
  SDL_FreeSurface(imgSurface);
  SDL_DestroyWindow(win);
  SDL_Quit();
}
