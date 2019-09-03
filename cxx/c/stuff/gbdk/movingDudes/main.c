#include <gb/drawing.h>
#include <gb/gb.h>
#include <stdio.h>
#include "tilesets/sbupro.c"
#include "tilesets/bgTileSet.c"
#include "tilesets/depro.c"
#include "maps/bg.c"
#include "maps/blank.c"

void spmain();
void mpmain(UINT8 player);

void main(){
  UINT8 mode = 1;
  printf("Single player [A] or\nMulti player[B]?\n");
  while (mode) {
    switch (joypad()) {
    case J_A:
      spmain();
      break;
    case J_B:
      mode = 0;
      delay(100);
      break;
    }
  }
  printf("Plug link cable now.");
  printf("Which player do you want to be?\nPress A for 1.\nPress B for 2.");
  while (1) {
    switch (joypad()){
    case J_A:
      mpmain(1);
      break;
    case J_B:
      mpmain(2);
      break;
    }
  }
}


void mpmain(UINT8 player){
  UINT8 start = 1;
  //sprite vars
  UINT8 px = 0;
  UINT8 py = 0;

  UINT8 p1x = 16;
  UINT8 p1y = 16;

  UINT8 p2x = 75;
  UINT8 p2y = 75;

  UINT8 pxdir = 1;
  UINT8 pydir = 1;
  int pfcnt;
  for (pfcnt=0; pfcnt<17; pfcnt++){
    printf("\n");
  }
  
  //select bg tileset
  set_bkg_data(0, 7, bgTileSet);
  //select bg tile map
  set_bkg_tiles(0, 4, 19, 17, blank);
  SHOW_BKG;
  //sprite mode set
  SPRITES_8x16;
  //select bg tile map
  set_bkg_tiles(0, 4, 19, 17, background);
  //movement switch
  while (1) {
    switch (joypad()){
    case J_UP:
      py -= pydir;
      delay(5);
      break;
    case J_DOWN:
      py += pydir;
      delay(5);
      break;
    case J_LEFT:
      px -= pxdir;
      delay(5);
      break;
    case J_RIGHT:
      px += pxdir;
      delay(5);
      break;

    }
    if (!start) {
      if (player == 1) {
        p1x = px;
        p1y = py;
      }
      else if (player == 2) {
        p2x = px;
        p2y = py;

      }
    }
    _io_out = px;
    send_byte();
    while (_io_status == IO_SENDING);

    _io_out = py;
    send_byte();
    while (_io_status == IO_SENDING);

    if (player == 1){
      receive_byte();
      p2x = _io_in;
      receive_byte();
      p2y = _io_in;

    }
    else if (player == 2){
      receive_byte();
      p1x = _io_in;
      receive_byte();
      p1y = _io_in;

    }
    //select sprite data
    set_sprite_data(0, 4, sbupro);
    //select left half of player sprite
    set_sprite_tile(0, 0);
    //move it to its coords
    move_sprite(0, p1x, p1y);
    //select right half
    set_sprite_tile(1, 2);
    //move it 8 pixels right to the left half to compose complete 16x16 sprite
    move_sprite(1, p1x+8, p1y);

    //select sprite data
    set_sprite_data(4, 4, depro);
    //select left half of player sprite
    set_sprite_tile(3, 4);
    //move it to its coords
    move_sprite(3, p2x, p2y);
    //select right half
    set_sprite_tile(4, 6);
    //move it 8 pixels right to the left half to compose complete 16x16 sprite
    move_sprite(4, p2x+8, p2y);

    //show dem sprites
    SHOW_BKG;
    SHOW_SPRITES;

    wait_vbl_done();
    start = 0;
  }
}

void spmain(){
  //sprite vars
  UINT8 x = 75;
  UINT8 y = 75;
  UINT8 xdir = 1;
  UINT8 ydir = 1;
  int pfcnt;
  for (pfcnt=0; pfcnt<17; pfcnt++){
    printf("\n");
  }
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
