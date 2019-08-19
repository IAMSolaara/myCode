#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <sstream>
#include <string>
#include <iostream>
#include "classes.h"
using namespace std;

#define INITSCRWIDTH  800
#define INITSCRHEIGHT 600
#define SPRWIDTH  32
#define SPRHEIGHT 32
#define SPRDESTWIDTH  64
#define SPRDESTHEIGHT 64
#define INITSPRSPEED 2
#define INITSPRSHFTSPEED 3


int main(){

  Sprite_SDL162 player;
  
  //declare window, renderer and events
  SDL_Window* win = NULL;
  SDL_Renderer* renderer = NULL;
  SDL_Event events;

  //declare image file surface and texture
  SDL_Surface* imgSurface;

  SDL_Texture* bgTexture;

  //declare screen dimension vars
  int scrWidth = INITSCRWIDTH;
  int scrHeight = INITSCRHEIGHT;  

  //declare background rects
  SDL_Rect bgDestRect = {0, 0, scrWidth, scrHeight};
  //  SDL_Rect bgSrcRect = {0, 0, scrWidth / 2, scrHeight / 2};
  
  //declare music
  Mix_Music *bgmusic = NULL;

  Mix_Chunk *sfx1 = NULL;
  
  //init
  player.setSpriteDims(32,32);
  player.setRects(SPRDESTWIDTH, SPRDESTHEIGHT, SPRWIDTH, SPRHEIGHT);
  player.shiftSpeed = 3;
  player.speed = 2;

  
  std::stringstream error;
  try{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0){                                                                                                              //SDL library functions init.
      error << "Failed to initialize SDL: " << SDL_GetError();                                                                                      //in case of errors, throw them
      throw(error.str());
    }
    if ((win = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, scrWidth, scrHeight, SDL_WINDOW_RESIZABLE)) == NULL){       //create main SDL window, 640 * 480, centered in both axis and resizable
      error << "Failed to create a window: " << SDL_GetError();
      throw(error.str());
    }
    if ((renderer = SDL_CreateRenderer(win, -1, (SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC))) == NULL) {                                    //create renderer for main window in index -1, accelerated and using VSync
      error << "Failed to initialize renderer: " << SDL_GetError();
      throw(error.str());
    }

    player.loadTexture("res/spritesheets/link.png", renderer);
    
    // load background
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
  Mix_PlayMusic(bgmusic, -1);
  
  while (mainLoop) {
    moving = false;
    SDL_PumpEvents();
    while (SDL_PollEvent(&events)){
      switch (events.type) {
      //handle window events
      case SDL_WINDOWEVENT:
	switch (events.window.event) {
	case SDL_WINDOWEVENT_RESIZED:
	  bgDestRect.w = scrWidth = events.window.data1;
	  bgDestRect.h = scrHeight = events.window.data2;
	  break;
	}
	break;
      case SDL_QUIT:
	mainLoop = false;
	break;
      }
    }
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    //if Z is pressed
    if (state[SDL_SCANCODE_Z]) {
      //      Mix_PlayChannel(-1, sfx1, 0);
    }

    //if X is pressed
    if (state[SDL_SCANCODE_X]) {
      player.speed = 4;
    }

    else player.speed = 2;
    
    //if left arrow is pressed
    if (state[SDL_SCANCODE_LEFT]) {
      player.srcRect.y = 32;
      if (player.destRect.x > 0) {
	player.destRect.x -= player.speed;
	moving = true;
      }
    }
    
    //right arrow is pressed
    else if (state[SDL_SCANCODE_RIGHT]) {
      player.srcRect.y = 64;
      if (player.destRect.x < scrWidth - player.destRect.w) {
	
	player.destRect.x += player.speed;
	moving = true; 
      }
    }
    
    //up arrow is pressed
    else if (state[SDL_SCANCODE_UP]) {
      player.srcRect.y=96;
      if (player.destRect.y > 0) {

	player.destRect.y -= player.speed;
	moving = true;
      }
    }

    //down arrow is pressed
    else if (state[SDL_SCANCODE_DOWN]) {
      player.srcRect.y = 0;
      if (player.destRect.y < scrHeight - player.destRect.h) {

	player.destRect.y += player.speed;
	moving = true;
      }
    }

    else moving = false;

    SDL_QueryTexture(player.texture, NULL, NULL, &player.spriteSheetWidth, &player.spriteSheetHeight);
    
    if (player.srcRect.x == (player.spriteSheetWidth - SPRWIDTH)) {
      player.srcRect.x = 32;
    }
    
    if (moving) {
      if (spriteShift > player.shiftSpeed) {
	player.srcRect.x += player.sprWidth;
	spriteShift = 0;
      }
      else spriteShift++;
    }

    else {
      player.srcRect.x = 0;
    }
    
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, bgTexture, NULL, &bgDestRect);
    
    SDL_RenderCopy(renderer, player.texture, &player.srcRect, &player.destRect);
    
    SDL_RenderPresent(renderer);
  }

  if (player.texture) SDL_DestroyTexture(player.texture);
  if (imgSurface) 
  
  if (renderer) SDL_DestroyRenderer(renderer);
  if (win) SDL_DestroyWindow(win);

  if (bgmusic) Mix_FreeMusic(bgmusic);

  Mix_Quit();
  IMG_Quit();
  SDL_Quit();
  return 0;
}
