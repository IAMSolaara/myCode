/*Lorenzo Cauli 3C 14/05/2019
scopo: memorizzare in un record i dati dei pazienti in un ospedale, calcolare il valore minimo di emoglobina e comunicare se e' sotto un valore minimo 
	di riferimento
dati:
	ricoveri 




 */

#include <stdio.h>
#include <readS.h>
#include <stdlib.h>

#include <162lib.h>

#define HDIM 30
#define SDIM 5
#define EDIM 5

typedef struct{
	int emo[EDIM];
	int minEmo;
}tRicovero;

typedef struct {
	char id[SDIM+1];
	tRicovero ricoveri[EDIM];
}tPaziente;

void carica(FILE* file, int* n, tPaziente out[]);
void emoRead(FILE* file, int out[]);
int leggiPos(const char msg[]);

int main(){
	FILE* file;
	int refValue, neff;
	tPaziente ospedale[HDIM];
	file = fileOpen("hosp.txt", "r");
	carica(file, &neff, ospedale);
	refValue = leggiPos("Qual e' il valore di riferimento?\n");
	
	
	fclose(file);
	return 0;
}

void carica(FILE* file, int* n, tPaziente out[]){
  	int i;
	fscanf(file, "%d%*c", n);
	i = 0;
	while(i < *n) {
	  freadS(file, out->id, SDIM+1);
          emoRead(file, out->ricoveri->emo);
	  i++;
	}
}

void emoRead(FILE* file, int out[]) {
  int i;
  i = 0;
  while (i < EDIM) {
    fscanf(file, "%d%*c", &out[i]);
    i++;
  }
}

int leggiPos(const char msg[]){
  
  printf("%s", msg);
  scanf