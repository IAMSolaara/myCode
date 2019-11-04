#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/ioctl.h>

int rnd(int min, int max);
int getNextColor(int in);

void main(int argv, char** argc){
	if (argv == 1) printf("Please specify at least 1 parameter.\n");
	else {
		if (atoi(argc[1]) < 0) printf("Invalid parameter.\n");
		
		else {
			struct winsize win;
			ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);

			int scrwidth  = win.ws_col;
			int scrheight = win.ws_row;

			printf("\e[2J");     //clear screen
			int fg = 31;         //declare fg color value
			
			int x,y;

			x = 1; y = scrheight;

			int i;
			for (i = 0; i < atoi(argc[1]); i++) {
				srand(time(NULL));                 //init rng
				
				printf("\e[%i;%im", fg, 49);       //set fg color

				int bar = rnd(1, scrheight);       //generate random bar

				y = scrheight;                     //set starting Y
				
				int j;
				for (j = 0; j < bar; j++) {        //per-bar-character loop
					printf("\e[%i;%iH", y, x);     //move to x,y
					printf("#");                   //print character
					usleep(50000);                 //wait a bit
					fflush(stdout);                //flush stdout stream

					y--;                           //decrement y to go up
				}
				printf("\e[39;49m");           //set default colors for in-between line
				fg = getNextColor(fg);             //get next fg color

				x += 2;
			}
		}
	}
}

int rnd(int min, int max) {
	return rand()%(max-min+1)+min;
}

int getNextColor(int in){
	int out = in;
	if (in > 37 && in < 90) out = 90;
	else if(in > 97) out = 31;
	else out++;
	return out;
}
