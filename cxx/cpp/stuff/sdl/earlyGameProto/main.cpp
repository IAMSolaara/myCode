#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

#define SCRWIDTH  640
#define SCRHEIGHT 480
#define SPRWIDTH  32
#define SPRHEIGHT 32
#define SPRDESTWIDTH  128
#define SPRDESTHEIGHT 128
#define SPRSPEED 2

int main(){
  //declare window, renderer and events
  SDL_Window* win = NULL;
  SDL_Renderer* renderer = NULL;
  SDL_Event events;

  //declare image file surface and texture
  SDL_Surface* imgSurface;
  SDL_Texture* playerSpriteSheetTexture;
  SDL_Texture* bgTexture;

  //declare destination and source rects
  SDL_Rect playerDestRect = {5, 5, SPRDESTWIDTH, SPRDESTHEIGHT};
  SDL_Rect playerSrcRect = {0, 0, SPRWIDTH, SPRHEIGHT};

  //declare source coords
  int srcX = 0;
  int srcY = 0;

  //declare image width and height vars
  int imgW = 0;
  int imgH = 0;

  //declare source direction vars
  int dirX = 1;
  int dirY = 1;

  //declare music
  Mix_Music *bgmusic = NULL;

  Mix_Chunk *sfx1 = NULL;
  
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
    if ((renderer = SDL_CreateRenderer(win, -1, (SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC))) == NULL) {                                    //create renderer for main window in index -1, accelerated and using VSync
      error << "Failed to initialize renderer: " << SDL_GetError();
      throw(error.str());
    }
    // load player spritesheet
    if ((imgSurface = IMG_Load("res/spritesheets/link.png")) == NULL){
      error << "Failed to load image to surface: " << SDL_GetError();
      throw(error.str());
    }
    if ((playerSpriteSheetTexture = SDL_CreateTextureFromSurface(renderer, imgSurface)) == NULL){
      error << "Failed to initialize image texture: " << SDL_GetError();
      throw(error.str());
    }
    SDL_FreeSurface(imgSurface);
    
    // load player spritesheet
    if ((imgSurface = IMG_Load("res/bg/grass_2.png")) == NULL){
      error << "Failed to load image to surface: " << SDL_GetError();
      throw(error.str());
    }
    if ((bgTexture = SDL_CreateTextureFromSurface(renderer, imgSurface)) == NULL){
      error << "Failed to initialize image texture: " << SDL_GetError();
      throw(error.str());
    }
    SDL_FreeSurface(imgSurface);
    //init audio
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
      error << "Failed to initialize audio: " << SDL_GetError();
      throw(error.str());
    }

    //load music
    if ((bgmusic = Mix_LoadMUS("res/music/bgmusic.ogg")) == NULL){
      error << "Failed to load music: " << SDL_GetError();
      throw(error.str());
    }

    //load sfxs
    if ((sfx1 = Mix_LoadWAV("res/sfx/bruh.ogg")) == NULL) {
      error << "Failed to load SFXs: " << SDL_GetError();
      throw(error.str());
    }
  }

  catch (string error_str) {
    cout << error_str << "\n";
  }

  //mainloop()

  int spriteShift = 0;
  
  bool mainLoop = true;
  bool moving;
  /*
  double beforeTime = SDL_GetPerformanceCounter() / SDL_GetPerformanceFrequency();
  double speed = 0.5f;
  */
  Mix_PlayMusic(bgmusic, -1);
  
  while (mainLoop) {
    moving = false;
    SDL_PumpEvents();
    while (SDL_PollEvent(&events)){
      switch (events.type) {
      case SDL_QUIT:
	mainLoop = false;
	break;
      }
    }/*
    double currentTime = (double) SDL_GetPerformanceCounter() / SDL_GetPerformanceFrequency();
    double deltaTime = (currentTime - beforeTime) * 1000;
    beforeTime = currentTime;
     */
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    //if Z is pressed
    if (state[SDL_SCANCODE_Z]) {
      Mix_PlayChannel(-1, sfx1, 0);
    }
    
    //if left arrow is pressed
    if (state[SDL_SCANCODE_LEFT]) {
      srcY = 32;
      if (playerDestRect.x > 0) {
	playerDestRect.x -= SPRSPEED;
	moving = true;
      }
    }
    
    //right arrow is pressed
    else if (state[SDL_SCANCODE_RIGHT]) {
      srcY = 64;
      if (playerDestRect.x < SCRWIDTH - playerDestRect.w) {
	playerDestRect.x += SPRSPEED;
	moving = true;
      }
    }
    
    //up arrow is pressed
    else if (state[SDL_SCANCODE_UP]) {
      srcY=96;
      if (playerDestRect.y > 0) {
	playerDestRect.y -= SPRSPEED;
	moving = true;
      }
    }

    //down arrow is pressed
    else if (state[SDL_SCANCODE_DOWN]) {
      srcY = 0;
      if (playerDestRect.y < SCRWIDTH - playerDestRect.h) {
	playerDestRect.y += SPRSPEED;
	moving = true;
      }
    }

    else moving = false;

    SDL_QueryTexture(playerSpriteSheetTexture, NULL, NULL, &imgW, &imgH);
    
    if (srcX == (imgW - SPRWIDTH)) {
      srcX = 32;
    }
    
    if (moving) {
      if (spriteShift > 3) {
	srcX = srcX + SPRWIDTH;
	spriteShift = 0;
      }
      else spriteShift++;
    }

    else {
      srcX = 0;
    }
    
    playerSrcRect.x = srcX;
    playerSrcRect.y = srcY;
    
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, bgTexture, NULL, NULL);
    
    SDL_RenderCopy(renderer, playerSpriteSheetTexture, &playerSrcRect, &playerDestRect);
    
    SDL_RenderPresent(renderer);
  }

  if (playerSpriteSheetTexture) SDL_DestroyTexture(playerSpriteSheetTexture);
  if (imgSurface) 
  
  if (renderer) SDL_DestroyRenderer(renderer);
  if (win) SDL_DestroyWindow(win);

  if (bgmusic) Mix_FreeMusic(bgmusic);

  Mix_Quit();
  IMG_Quit();
  SDL_Quit();
  return 0;
}
