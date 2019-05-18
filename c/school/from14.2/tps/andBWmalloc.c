/*Lorenzo Cauli 3C
scopo: morire




*/

#include <stdio.h>
#include <stdlib.h>

int* riserva(int n);

int main(){
	int* v1; int* v2; int* vRis;	//declare puntatori a vettori dinamicy
	v1 = riserva(4);		//allocazione vettore 1
	v2 = riserva(4);		//allocazione vettore 2
	vRis = riserva(4);		//allocazione vettore risultato
	init(v1);
	
	
	
	free(v1); free(v2); free(vRis);
	return 0;
}

int* riserva(int n){
	int* out;
	out = (int*)malloc(sizeof(int) * n);
	if (out == NULL) {printf("Errore nell'allocazione memoria.\n"); exit(-1);}
	return out;
}

void init(int* out){
