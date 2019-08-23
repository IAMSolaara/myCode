#include <iostream>
#include <sstream>
#include <SDL.h>
#include <GL/glew.h>
#include <SDL_opengl.h>

using namespace std;

bool SDL_GL_162Init(SDL_Window* win, int scrW, int scrH, SDL_GLContext* context);


int main(){
  //declare screen size variables
  int scrWidth = 640;
  int scrHeight = 480;

  SDL_Window* mainWin;
  SDL_GLContext mainContext;
  SDL_Event event;

  SDL_GL_162Init(mainWin, scrWidth, scrHeight, &mainContext);
  


  return 0;
}

bool SDL_GL_162Init(SDL_Window* win, int scrW, int scrH, SDL_GLContext* context){
  bool st = true;
  stringstream err;

  try {
    //SDL Init
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
      err << "Failed to initialize SDL: " << SDL_GetError();
      throw(err.str());
    }
    //create window
    if ((win = SDL_CreateWindow("GLTest", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, scrW, scrH, SDL_WINDOW_OPENGL)) == NULL) {
      err << "Failed to initialize main window: " << SDL_GetError();
      throw (err.str());
   }
    //set GL context attributes
    if (SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE) < 0) {
      err << "Failed to set GL context profile mask: " << SDL_GetError();
      throw (err.str());
    }
    if (SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2) < 0) {
      err << "Failed to set GL context minor version: " << SDL_GetError();
      throw (err.str());
    }
    if (SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1) < 0) {
      err << "Failed to enable GL double buffer: " << SDL_GetError();
      throw(err.str());
    }
    //actually create GL context
    if ((*context = SDL_GL_CreateContext(win)) == NULL) {
      err << "Failed to create GL context: " << SDL_GetError();
      throw (err.str());
    }

  }

  catch (string err){
    cout << err << "\n";
    st = false;
  }
  glewExperimental = GL_TRUE;
  glewInit();
  return st;
}
