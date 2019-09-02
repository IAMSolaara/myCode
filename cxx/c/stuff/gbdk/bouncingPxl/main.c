#include <gb/drawing.h>
#include <gb/gb.h>
#include <rand.h>

#define SCRWIDTH  160
#define SCRHEIGHT 144

unsigned int rnd(int min, int max);

int main(){
  initrand((UWORD)162);
  UBYTE cnt = 0;
  UBYTE x = rnd(0, SCRWIDTH);
  UBYTE y = rnd(0, SCRHEIGHT);
  UBYTE xdir = 1;
  UBYTE ydir = 1;
  color(BLACK, WHITE, M_FILL);
  while (1) {
    if (cnt == 255){
      if (x >= SCRWIDTH) xdir = -xdir;
      if (y >= SCRHEIGHT)  ydir = -ydir;
      plot_point(x, y);
      x+=xdir;
      y+=ydir;
    }
    cnt++;
  }
  return 0;
}

unsigned int rnd (int min, int max){
  return rand()%(max-min+1)+min;
}
