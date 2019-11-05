#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rnd(int min, int max);
int getNextColor(int in);

void main(int argv, char** argc){
	if (argv == 1) printf("Please specify at least 1 parameter.\n");
	else {
		if (atoi(argc[1]) < 0) printf("Invalid parameter.\n");
		else {
			printf("\e[2J");
			int fg, bg;
			fg = 31;
			bg = 49;
			int i;
			for (i = 0; i < atoi(argc[1]); i++) {
				srand(time(NULL));
				printf("\e[%i;%im", fg, bg);
				int bar = rnd(1, 40);
				int x;
				for (x = 0; x < bar; x++) {
					printf("#");
					usleep(50000);
					fflush(stdout);
				}
				printf("\e[39;49m\n\n");
				fg = getNextColor(fg);
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
