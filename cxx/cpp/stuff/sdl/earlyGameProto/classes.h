#ifndef CLASSES_H

#include <iostream>
#include <string>
using namespace std;

#define CLASSES_H
//define sprite class
class Sprite_SDL162 {
 public:
  //constructor
  Sprite_SDL162(){};

  void loadTexture(const char* path, SDL_Renderer* render) {
    SDL_Surface* tmpSurface = NULL;
    stringstream error;
    try {
      // load player spritesheet
      if ((tmpSurface = IMG_Load(path)) == NULL){
	error << "Failed to load image to surface: " << SDL_GetError();
	throw(error.str());
      }
      
      if ((texture = SDL_CreateTextureFromSurface(render, tmpSurface)) == NULL){
	error << "Failed to initialize image texture: " << SDL_GetError();
	throw(error.str());
      }
    }
    
    catch (string error_str) {
      cout << error_str << "\n";
    }
    
    SDL_FreeSurface(tmpSurface);
  }

  void setRects(int destW, int destH, int srcW, int srcH){

    destRect = {5, 5, destW, destH};
    srcRect = {0, 0, srcW, srcH};
  }

  void setSpriteDims(int w, int h) {
    sprWidth = w;
    sprHeight = h;
  }
  
  int sprWidth;
  int sprHeight;
  
  int destWidth;
  int destHeight;
  
  //declare destination and source rects
  SDL_Rect destRect;
  SDL_Rect srcRect;

  //declare source coords
  int srcX = 0;
  int srcY = 0;

  //declare image width and height vars
  int spriteSheetWidth = 0;
  int spriteSheetHeight = 0;
  
  //sprite texture
  SDL_Texture *texture = NULL;
  //sprite animation speed
  int shiftSpeed;
  //sprite movement speed
  int speed;

  


};
#endif
