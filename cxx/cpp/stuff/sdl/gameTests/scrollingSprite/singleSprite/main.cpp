#include <SDL.h>
#include <SDL_image.h>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

#define SCRWIDTH  640
#define SCRHEIGHT 480
#define SPRWIDTH  128
#define SPRHEIGHT 128

SDL_Rect SDLBoxPut(int width, int height, int x, int y);


int main(){
  SDL_Window* win = NULL;
  SDL_Renderer* renderer = NULL;
  SDL_Event events;

  SDL_Surface* imgFile;
  SDL_Texture* imgTexture;

  SDL_Rect imgDest = {5, 5, SPRWIDTH, SPRHEIGHT};
  SDL_Rect imgSrc = {0, 0, SPRWIDTH, SPRHEIGHT};

  int srcX = 0;
  int srcY = 0;

  int imgW = 0;
  int imgH = 0;

  int dirX = 1;
  int dirY = 1;
  
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
    if ((imgFile = SDL_LoadBMP("images/test.bmp")) == 0){
      error << "Failed to load image to surface: " << SDL_GetError();
      throw(error.str());
    }
    if ((imgTexture = SDL_CreateTextureFromSurface(renderer, imgFile)) == 0){
      error << "Failed to initialize image texture: " << SDL_GetError();
      throw(error.str());
    }
    
    SDL_Delay(2000);                                                                                                                                //delay 2 seconds, used for testing
  }

  catch (string error_str) {
    cout << error_str << "\n";
  }

  //mainloop()
  
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
    if (state[SDL_SCANCODE_LEFT]) if (imgDest.x > 0) imgDest.x -= (int)(speed * deltaTime);
    if (state[SDL_SCANCODE_RIGHT]) if (imgDest.x < SCRWIDTH - imgDest.w) imgDest.x += (int)(speed * deltaTime);
    if (state[SDL_SCANCODE_UP]) if (imgDest.y > 0) imgDest.y -= (int)(speed * deltaTime);
    if (state[SDL_SCANCODE_DOWN]) if (imgDest.y < SCRWIDTH - imgDest.h) imgDest.y += (int)(speed * deltaTime);

    imgSrc.x = srcX;
    imgSrc.y = srcY;

    SDL_QueryTexture(imgTexture, NULL, NULL, &imgW, &imgH);

    if (srcX == (imgW - imgSrc.w)) dirX = -1;
    if (srcX == 0) dirX = 1;
    if (srcY == (imgH - imgSrc.h)) dirY = -1;
    if (srcY == 0) dirY = 1;
    
    srcX = srcX + dirX;
    srcY = srcY + dirY;
    
    imgDest.w = imgSrc.w;
    imgDest.h = imgSrc.h;
    
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, imgTexture, &imgSrc, &imgDest);
    
    SDL_RenderPresent(renderer);

    SDL_Delay(1);
  }

  if (imgTexture) SDL_DestroyTexture(imgTexture);
  if (imgFile) SDL_FreeSurface(imgFile);
  
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



