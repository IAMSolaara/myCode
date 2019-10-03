#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SCRWIDTH  80
#define SCRHEIGHT 25


void main(int argv, char** argc) {
	if (argv == 1) printf("Please specify at least 1 parameter.\n");
	else {
		if (atoi(argc[1]) < 0) printf("Invalid parameter.\n");
		else {
			int i,j;
			i=j=0;
			srand(time(NULL));
			int x;
			for (x = 0; x < atoi(argc[1]); x++) {
				i = rand()%(SCRHEIGHT);
				j = rand()%(SCRWIDTH);
				printf("%c[%i;%iH", 27, i, j);
				printf("%c[%i;%i;%im", 27, 36, 45, 5);
				printf("#");
				fflush(stdout);
				sleep(1);
			}
		}
	}	
}
