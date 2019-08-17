#include<allegro.h>
#include<stdlib.h>
#include<time.h>

#define REFRBASE 500000000
#define REFRESH 0
#define	SCRWIDTH 640
#define	SCRHEIGHT 480


void coccodrillo(BITMAP* bitmap);

int main(){
	srand(time(NULL));
	allegro_init();
	BITMAP* bittomappu=create_bitmap(SCRWIDTH,SCRHEIGHT);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, SCRWIDTH, SCRHEIGHT, 0, 0);
	set_color_depth(8);
	install_keyboard();
	clear(bittomappu);
	clear_to_color(bittomappu, makecol(0,0,0));
	blit(bittomappu, screen, 0, 0, 0, 0, SCRWIDTH, SCRHEIGHT);
	coccodrillo(bittomappu);
	allegro_exit();
return 0;
}

void coccodrillo(BITMAP* bitmap){
	int clk=0;
	int x=320, y=240, dx=1, dy=1, radius=50;
	while(key[KEY_ESC]==0){
       	        if (clk > REFRESH){
			int r=rand()%255+1, g=rand()%255+1, b=rand()%255+1;
			int lr=rand()%255+1, lg=rand()%255+1, lb=rand()%255+1;
			int lx1=rand()%SCRWIDTH+1, lx2=rand()%SCRWIDTH+1, ly1=rand()%SCRHEIGHT+1, ly2=rand()%SCRHEIGHT+1;
			circlefill(bitmap, x, y, radius,  makecol(r,g,b));
		        blit(bitmap, screen, 0, 0, 0, 0, SCRWIDTH, SCRHEIGHT);
			circlefill(bitmap, x, y, radius,  makecol(0,0,0));
		        blit(bitmap, screen, 0, 0, 0, 0, SCRWIDTH, SCRHEIGHT);
       	                clk=0;
			if (x == SCRWIDTH-radius){
				dx=-1;
			}
			if (x == radius){
				dx=1;
			}
			if (y == SCRHEIGHT-radius){
				dy=-1;
			}
			if (y == radius){
				dy=1;
			}
			x=x+dx;
			y=y+dy;
			line(bitmap, lx1, ly1, lx2, ly2, makecol(lr,lg,lb));
       	        }
       	        clk++;
       	}
}


