#include <SDL.h>
#include <SDL_image.h>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

#define SCRWIDTH  640
#define SCRHEIGHT 480

SDL_Rect SDLBoxPut(int width, int height, int x, int y);


int main(){
  SDL_Window* win = NULL;
  SDL_Renderer* renderer = NULL;
  SDL_Event events;

  //init()
  
  std::stringstream error;
  try{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0){                                                                                                              //SDL library functions init.
      error << "Failed to initialize SDL: " << SDL_GetError();                                                                                      //in case of errors, throw them
      throw(error.str());
    }
    if ((win = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCRWIDTH, SCRHEIGHT, SDL_WINDOW_RESIZABLE)) == NULL){       //create main SDL window, 640 * 480, centered in both axis and resizable
      error << "Failed to create a window: " << SDL_GetError();
      throw(error.str());
    }
    if ((renderer = SDL_CreateRenderer(win, -1, (SDL_RENDERER_ACCELERATED))) == 0) {                                    //create renderer for main window in index -1, accelerated and using VSync
      error << "Failed to initialize renderer: " << SDL_GetError();
      throw(error.str());
    }
    SDL_Delay(2000);                                                                                                                                //delay 2 seconds, used for testing
  }

  catch (string error_str) {
    cout << error_str << "\n";
  }

  //mainloop()
  
  SDL_Rect box = SDLBoxPut(100, 100, SCRWIDTH/8, SCRHEIGHT/8);
  bool mainLoop = true;

  double beforeTime = SDL_GetPerformanceCounter() / SDL_GetPerformanceFrequency();
  double speed = 1.0f;
  
  while (mainLoop) {
    while (SDL_PollEvent(&events)){
      switch (events.type) {
      case SDL_QUIT:
	mainLoop = false;
	break;
      }
    }
    double currentTime = (double) SDL_GetPerformanceCounter() / SDL_GetPerformanceFrequency();
    double deltaTime = (currentTime - beforeTime) * 1000;
    beforeTime = currentTime;

    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_LEFT]) if (box.x > 0) box.x -= (int)(speed * deltaTime);
    if (state[SDL_SCANCODE_RIGHT]) if (box.x < SCRWIDTH - box.w) box.x += (int)(speed * deltaTime);
    if (state[SDL_SCANCODE_UP]) if (box.y > 0) box.y -= (int)(speed * deltaTime);
    if (state[SDL_SCANCODE_DOWN]) if (box.y < SCRWIDTH - box.h) box.y += (int)(speed * deltaTime);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
    SDL_RenderFillRect(renderer, &box);

    SDL_RenderPresent(renderer);

    SDL_Delay(1);
  }
  
  if (renderer) SDL_DestroyRenderer(renderer);
  if (win) SDL_DestroyWindow(win);
  SDL_Quit();
  return 0;
}

SDL_Rect SDLBoxPut(int width, int height, int x, int y){
  SDL_Rect out;
  out.w = width;
  out.h = height;
  out.x = x;
  out.y = y;
  return out;
}

