#include <gb/drawing.h>
#include <gb/gb.h>
#include "dude.c"

void main(){
  SPRITES_8x16;
  set_sprite_data(0, 8, dude);
  set_sprite_tile(0, 0);
  move_sprite(0, 75, 75);
  set_sprite_tile(1, 2);
  move_sprite(0, 75+8, 75);
  SHOW_SPRITES;
}
