#include <allegro.h>

#define SCRWIDTH 640
#define SCRHEIGHT 480

void do_stuff(BITMAP* bmp);
void mouse_call(int flags);

BITMAP* bmp;

int main(){
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
  clear_to_color(bmp, makecol(255,255,255));
  blit(bmp, screen, 0, 0, 0, 0, SCRWIDTH, SCRHEIGHT);
  while (key[KEY_ESC] == 0) {
    blit(bmp, screen, 0, 0, 0, 0, SCRWIDTH, SCRHEIGHT);
  }
  allegro_exit();
  return 0;
}

void do_stuff(BITMAP* bmp){
  circlefill(bmp, mouse_x, mouse_y, 50,  makecol(0,0,0));
}

void mouse_call(int flags){
  if (flags & MOUSE_FLAG_LEFT_DOWN) {
    scare_mouse();
    do_stuff(bmp);
    unscare_mouse();
  }
}
