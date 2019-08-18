#include <SDL.h>
#include <SDL_image.h>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

#define SCRWIDTH  640
#define SCRHEIGHT 480
#define SPRWIDTH  32
#define SPRHEIGHT 32
#define DESTWIDTH  128
#define DESTHEIGHT 128

int main(){
  //declare window, renderer and events
  SDL_Window* win = NULL;
  SDL_Renderer* renderer = NULL;
  SDL_Event events;

  //declare image file surface and texture
  SDL_Surface* imgFile;
  SDL_Texture* imgTexture;

  //declare destination and source rects
  SDL_Rect imgDest = {5, 5, DESTWIDTH, DESTHEIGHT};
  SDL_Rect imgSrc = {0, 0, SPRWIDTH, SPRHEIGHT};

  //declare source coords
  int srcX = 0;
  int srcY = 0;

  //declare image width and height vars
  int imgW = 0;
  int imgH = 0;

  //declare source direction vars
  int dirX = 1;
  int dirY = 1;
  
  //init
  
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
    if ((imgFile = IMG_Load("images/link.png")) == 0){
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

  int spriteShift = 0;
  
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

    SDL_QueryTexture(imgTexture, NULL, NULL, &imgW, &imgH);

    if (srcX == (imgW - SPRWIDTH)) {
      srcX = 0;
      srcY = srcY + SPRHEIGHT;
    }
    if (srcY >= (imgH)) {
      srcY = 0;
    }

    if (spriteShift > 63) {
      srcX = srcX + SPRWIDTH;
      spriteShift = 0;
    }
    else spriteShift++;

    imgSrc.x = srcX;
    imgSrc.y = srcY;
    
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, imgTexture, &imgSrc, &imgDest);
    
    SDL_RenderPresent(renderer);


  }

  if (imgTexture) SDL_DestroyTexture(imgTexture);
  if (imgFile) SDL_FreeSurface(imgFile);
  
  if (renderer) SDL_DestroyRenderer(renderer);
  if (win) SDL_DestroyWindow(win);
  SDL_Quit();
  return 0;
}
