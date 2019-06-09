#include <allegro.h>
#include <stdlib.h>
#include <time.h>

#define SCRWIDTH 640
#define SCRHEIGHT 480

void do_stuff(BITMAP* bmp);
void mouse_call(int flags);
int rnd(int min, int max);

BITMAP* bmp;

int prevC[2];
int mCont=0;

int main(){
  srand(time(NULL));
  allegro_init();
  bmp = create_bitmap(SCRWIDTH, SCRHEIGHT);
  set_gfx_mode(GFX_AUTODETECT_WINDOWED, SCRWIDTH, SCRHEIGHT, 0, 0);
  set_color_depth(8);
  install_keyboard();
  install_mouse();
  mouse_callback = mouse_call;
  enable_hardware_cursor();
  show_mouse(screen);
  clear(bmp);
  clear_to_color(bmp, makecol(0,0,0));
  blit(bmp, screen, 0, 0, 0, 0, SCRWIDTH, SCRHEIGHT);
  while (key[KEY_ESC] == 0) {
    blit(bmp, screen, 0, 0, 0, 0, SCRWIDTH, SCRHEIGHT);
  }
  allegro_exit();
  return 0;
}

void do_stuff(BITMAP* bmp){
 
  if (mCont == 0){
    prevC[0] = mouse_x;
    prevC[1] = mouse_y;
    mCont++;
  }
  
  else if (mCont == 1) {
    line(bmp, prevC[0], prevC[1], mouse_x, mouse_y, makecol(rnd(0, 255), rnd(0, 255), rnd(0, 255)));
    prevC[0] = mouse_x;
    prevC[1] = mouse_y;

  }
}

void mouse_call(int flags){
  if (flags & MOUSE_FLAG_LEFT_DOWN) {
    scare_mouse();
    do_stuff(bmp);
    unscare_mouse();
  }
}

int rnd(int min, int max){
  return rand()%(max-min+1)+min;
}
