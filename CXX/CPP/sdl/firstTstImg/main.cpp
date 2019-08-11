#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>

using namespace std;

#define SCRWIDTH  640
#define SCRHEIGHT 480

bool SDLPrginit(SDL_Window* win, SDL_Renderer* render, SDL_Event event);

bool loadMedia(SDL_Window *win, SDL_Renderer *render, SDL_Texture *img, string imgpath);

void SDLPrgclose(SDL_Window* win, SDL_Renderer* render, SDL_Texture* img);


int main(int argc, char* args[]){
  SDL_Window* window;          //declare window
  SDL_Renderer* render;        //declare renderer
  SDL_Texture* img;            //declare img texture
  SDL_Event event = {0};       //declare events
  SDL_Rect texture;            //declare texture rectangle

  
  if (!SDLPrginit(window, render, event)){
    printf("\nFailed to init SDL.\n");
  }
  else {
    if (!loadMedia(window, render, img, "images/test.png")) {
      printf("\nFailed to load media.\n");
    }
    else {
      SDL_QueryTexture(img, NULL, NULL, &texture.w, &texture.h);
      SDL_RenderClear(render);
      SDL_RenderCopy(render, img, NULL, &texture);
      SDL_RenderPresent(render);
      SDL_Delay(10000);
    }
  }
  SDLPrgclose(window, render, img);
  return 0;
}

bool SDLPrginit(SDL_Window* win, SDL_Renderer* render, SDL_Event event){
  bool state = true;

  if (SDL_Init( SDL_INIT_EVERYTHING ) < 0) {
    printf("SDL init error %s\n", SDL_GetError());
    state = false;
  }
  else {
    win = SDL_CreateWindow("firstTst", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCRWIDTH, SCRHEIGHT, SDL_WINDOW_SHOWN);
    if (win == NULL) {
      printf("couldn't create window. error %s\n", SDL_GetError());
      state = false;
    }
    else {
      render = SDL_CreateRenderer(win, -1, 0);
      if (render == NULL) {
	printf("Couldn't create renderer. Error %s\n", SDL_GetError());
	state = false;
      }
    }
  }
  return state;
}


bool loadMedia(SDL_Window *win, SDL_Renderer *render, SDL_Texture *img, string imgpath){
  bool state = true;

  const char* path = imgpath.c_str();
  img = IMG_LoadTexture(render, path);
  if (img == NULL) {
    cout << "Couldn't load texture. Error " << SDL_GetError();
    state = false;
  }
  return state;
}

void SDLPrgclose(SDL_Window* win, SDL_Renderer* render, SDL_Texture* img) {
  SDL_DestroyTexture(img);
  SDL_DestroyRenderer(render);
  SDL_DestroyWindow(win);
  SDL_Quit();
}
