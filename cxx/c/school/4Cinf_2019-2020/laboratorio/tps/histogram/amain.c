#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rnd(int min, int max);
int getNextColor(int in);
int* alloca(int len);
void init(int* out, int len);

void main(int argv, char** argc){
	if (argv == 1) printf("Please specify at least 1 parameter.\n");
	else {
		if (atoi(argc[1]) < 0) printf("Invalid parameter.\n");
		else {
			int bars = atoi(argc[1]);
			srand(time(NULL));
			printf("\e[2J");

			int* arr = alloca(bars);

			int fg, bg;
			fg = 31;
			bg = 49;

			init(arr, bars);
/*
			int i;
			for (i = 0; i < atoi(argc[1]); i++) {
				int* tmp = arr;
				while (tmp < arr + (atoi(argc[1]) - 1)) {
					*tmp = rnd(1, 40);
					tmp++;
				}
			}
*/			
			int* tmp = arr;/*
			while (tmp < arr + atoi(argc[1])) {
				printf("\e[%i;%im", fg, bg);
				int x;
				for (x = 0; x < *tmp; x++) {
					printf("#");
					usleep(50000);
					fflush(stdout);
				}
				printf("\e[39;49m\n\n");
				fg = getNextColor(fg);
				tmp++;
			}*/
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

int* alloca(int len){
	int* p;
	p = (int*)malloc(sizeof(int)*len);
	if (p == NULL) {
		printf("malloc error.\n");
		exit(-1);
	}
	return p;
}

void init(int* out, int len){
	int* tmp;
    tmp	= out;
	while (tmp < (out + len) -1) {
		*tmp = rnd(1,40);
		tmp++;
	}
}
