#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rnd(int min, int max);
int main(int argv, char** argc){
	if (argv < 3) printf("Please give at least 2 parameters.\n");
	else {
		if (atoi(argc[1]) < 0 || atoi(argc[2]) < 0) printf("Invalid parameter.\n");
		else {
			srand(time(NULL));
			int i,j;
			for (i = 0; i < atoi(argc[1]); i++)
				printf("%d\n", rnd(0,atoi(argc[2])));
		}
	}
}

int rnd(int min, int max) {
	return rand()%(max-min+1)+min;
}

