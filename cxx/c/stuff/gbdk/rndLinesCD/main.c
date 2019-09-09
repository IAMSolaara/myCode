#include <gb/gb.h>
#include <gb/drawing.h>

#define SCRWIDTH  160
#define SCRHEIGHT 144

extern UBYTE _cpu;

int CGBMode();
int DMGMode();

int main(){
  int st;
  switch (_cpu){
  case 0x11:
    st = CGBMode();
    break;
  case 0x01:
  case 0xFF:
    st = DMGMode();
    break;
  }
  return st;
}

int CGBMode(){
  UBYTE cnt = 0;
  //declare coords and directions
  UBYTE x1 = 10;
  UBYTE y1 = 10;
  UBYTE x2 = x1 * 4;
  UBYTE y2 = y1 * 5;

  UBYTE pal[] = {RGB_RED, RGB_GREEN, RGB_BLUE, RGB_YELLOW, RGB_CYAN, RGB_PINK, RGB_BLACK, RGB_WHITE};
  while (1){
    if (cnt >= 255) {
      line(x1, y1, x2, y2);
      color(RGB_RED, RGB_BLACK, M_FILL);
      x1 += x1;
      y1 += y1;
      cnt = 0;
    }
    cnt++;
  }
}
int DMGMode(){
  UBYTE x1 = 10;
  UBYTE y1 = 10;
  UBYTE x2 = x1 * 4;
  UBYTE y2 = y1 * 5;
  color(BLACK, WHITE, M_FILL);
  //declare coords and directions

  while (1){
    line(x1, y1, x2, y2);
  }
}
