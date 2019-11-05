#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SCRWIDTH  80
#define SCRHEIGHT 25

int getFGCol();
int getBGCol();


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
				printf("%c[%i;%iH", 27, i, j);         //move to pos
				printf("%c[%i;%i;%im", 27, getFGCol(), getBGCol(), 5); //change color
				printf("#");
				fflush(stdout);
				sleep(1);
			}
		}
	}	
}



int getFGCol(){
	return rand()%(37-30+1)+30;  
}
int getBGCol(){
	return rand()%(47-40+1)+40;
}
