#include "162lib.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE* fileOpen(const char filename[], const char perm[]){
        FILE* out;
        out = fopen(filename, perm);
        if (out == NULL){
                perror("File opening error.\n");
                exit(-1);
        }
        return out;
}

void dataRead(tData out){
	scanf("%d%*c", &out.day);
	scanf("%d%*c", &out.month);
	scanf("%d%*c", &out.year);
}

void fdataRead(FILE* file, tData out){
	fscanf(file, "%d%*c", &out.day);
	fscanf(file, "%d%*c", &out.month);
	fscanf(file, "%d%*c", &out.year);
}

void rndGenInit(){
	srand(time(NULL));
}

int rnd(int min, int max){
	return rand()%(max-min+1)+min;
}
