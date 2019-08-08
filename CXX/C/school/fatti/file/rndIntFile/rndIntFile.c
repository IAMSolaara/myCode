#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define DIM 100
#define MIN 0
#define MAX 100

int rnd(int min, int max);
FILE* fileOpen(const char fname[], const char perm[]);
void init(int out[], int dim);

int main(){
	FILE* f;
	int dim;			//declare variabile dimensione vettore
	int v[DIM];			//declare variabile vettore
	srand(time(NULL));		//init generatore numeri casuali
	f=fileOpen("out.dat", "w");
	dim = rnd(MIN, DIM);		//init dimensione vettore con numero casuale
	init(v, dim);
	fwrite(v, sizeof(int), dim, f);
	fclose(f);
	return 0;
}

int rnd(int min, int max){
	return rand()%(max-min+1)+min;
}

FILE* fileOpen(const char fname[], const char perm[]){
	FILE* out;
	out = fopen(fname, perm);
	if (out == NULL) {
		printf("Errore apertura file.\n");
		exit(-1);
	}
	return out;
}

void init(int out[], int dim){
	int i;
	i=0;
	while (i < dim){
		out[i] = rnd(MIN, MAX);
		i++;
	}
}
