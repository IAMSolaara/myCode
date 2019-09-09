#include <gb/drawing.h>
#include <gb/gb.h>
#include <stdio.h>
#include "tilesets/sbupro.c"
#include "tilesets/bgTileSet.c"
#include "maps/bg.c"


void main(){
  //sprite vars
  UINT8 x = 75;
  UINT8 y = 75;
  UINT8 xdir = 1;
  UINT8 ydir = 1;
  //sprite mode set
  SPRITES_8x16;
  //select sprite data
  set_sprite_data(0, 4, sbupro);
  //select bg tileset
  set_bkg_data(0, 7, bgTileSet);
  //select bg tile map
  set_bkg_tiles(0, 4, 19, 17, background);
  //movement switch
  while (1) {
    switch (joypad()){
    case J_UP:
      y -= ydir;
      delay(5);
      break;
    case J_DOWN:
      y += ydir;
      delay(5);
      break;
    case J_LEFT:
      x -= xdir;
      delay(5);
      break;
    case J_RIGHT:
      x += xdir;
      delay(5);
      break;

    case J_B:
      printf("test.\n");
      delay(100);
      break;
    }
    //select left half of player sprite
    set_sprite_tile(0, 0);
    //move it to its coords
    move_sprite(0, x, y);
    //select right half
    set_sprite_tile(1, 2);
    //move it 8 pixels right to the left half to compose complete 16x16 sprite
    move_sprite(1, x+8, y);
    //show dem sprites
    SHOW_BKG;
    SHOW_SPRITES;

    wait_vbl_done();
  }
}
