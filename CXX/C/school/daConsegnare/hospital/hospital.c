/*Lorenzo Cauli 3C 14/05/2019
scopo: memorizzare in un record i dati dei pazienti in un ospedale, calcolare il valore minimo di emoglobina e comunicare se e' sotto un valore minimo 
  di riferimento
dati:
  ospedale I da file array 30 tPaziente
  refValue I int
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
int minVal(int v[], int dim);
void controlla(tPaziente v[], int n, int rval, int out[][EDIM]);
void comunica(tPaziente v[], int rval, int n);

int main(){
  FILE* file;
  int refValue, neff;
  tPaziente ospedale[HDIM];
  int pazSotto[HDIM][EDIM];
  file = fileOpen("hosp.txt", "r");
  carica(file, &neff, ospedale);
  refValue = leggiPos("Qual e' il valore di riferimento?\n");
  controlla(ospedale, neff, refValue, pazSotto);
  comunica(ospedale, refValue, neff);  
  fclose(file);
  return 0;
}

void carica(FILE* file, int* n, tPaziente out[]){
  int i, j;
  fscanf(file, "%d%*c", n);
  i = 0;
  j = 0;
  while(i < *n) {
    freadS(file, out[i].id, SDIM);
    emoRead(file, out[i].ricoveri[j].emo);
    out[i].ricoveri[j].minEmo = minVal(out[i].ricoveri[j].emo, EDIM);
    i++;
    j++;
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
  int tmp;
  printf("%s", msg);
  scanf("%d%*c", &tmp);
  while (tmp < 0) {
    printf("Numero invalido.\n");
    scanf("%d%*c", &tmp);
  }
  return tmp;
}

int minVal(int v[], int dim){
  int i=1;
  int min;
  min = v[0];
  while (i < dim) {
    if (v[i] < min) min = v[i];
    i++;
  }
  return min;
}

void controlla(tPaziente v[], int n, int rval, int out[][EDIM]){
  int i, j, k, k1;
  i=j=k=k1=0;
  while (i < n) {
    while (j < EDIM) {
      if (v[i].ricoveri[j].minEmo < rval) {
	out[k][k1] = j;
	k1++;
      }
      j++;
    }
    k++;
    i++;
  }


}

void comunica(tPaziente v[], int rval, int n){
  int i, j;
  i=j=0;
  
}
