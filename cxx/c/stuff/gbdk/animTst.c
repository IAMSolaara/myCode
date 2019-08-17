#include <stdio.h>
#include <gb/gb.h>
#include "anim.c"

void main(){
	SPRITES_8x8;
	set_sprite_data(0, 10, anim);
	set_sprite_tile(0, 0);
	move_sprite(0, 75, 75);
	SHOW_SPRITES;
delay(800);
	set_sprite_tile(1, 1);
	set_sprite_tile(2, 2);
	set_sprite_tile(3, 3 );
}
