#include <gb/drawing.h>

int main(){
  UBYTE cnt = 0;
  UBYTE x = 0;
  UBYTE y = 0;
  color(BLACK, WHITE, M_FILL);
  while (x < 160 && y < 144) {
    if (cnt == 255){
      plot_point(x, y);
      x++; y++;
    }
    cnt++;
  }
  return 0;
}
