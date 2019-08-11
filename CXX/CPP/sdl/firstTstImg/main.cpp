#include <SDL.h>
#include <stdio.h>
#include <iostream>

using namespace std;

#define SCRWIDTH  640
#define SCRHEIGHT 480

bool init(SDL_Window* win, SDL_Renderer* render, SDL_Event* event);

bool loadMedia(SDL_Window *win, SDL_Renderer *render, SDL_Texture *img, string imgpath);

void close(SDL_Window* win, SDL_Renderer* render, SDL_Texture* img);


int main(int argc, char* args[]){
  SDL_Window* window;          //declare window
  //  SDL_Surface* surface;        //declare screen surface
  //  SDL_Surface* imgSurface;     //declare image surface where the img will be loaded
  SDL_Renderer* render;        //declare renderer
  SDL_Texture* img;            //declare img texture
  SDL_Event event = {0};       //declare events
  
  if (!init(window, render, &event)){
    printf("Failed to init SDL.\n");
  }
  else {
    if (!loadMedia(window, render, img, "images/test.bmp")) {
      printf("Failed to load media.\n");
    }
    else {
      
      SDL_Delay(10000);
    }
  }
  close(window, render, img);
  return 0;
}

bool init(SDL_Window* win, SDL_Renderer* render, SDL_Event* event){
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


  return state;
}

void close(SDL_Window* win, SDL_Renderer* render, SDL_Texture* img) {
  SDL_DestroyTexture(img);
  SDL_DestroyRenderer(render);
  SDL_DestroyWindow(win);
  SDL_Quit();
}
