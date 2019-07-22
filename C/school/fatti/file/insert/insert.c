#include <stdio.h>
#include <162lib.h>

#define DIM 10

int carica(FILE* f, int v[]);
void visualizza(int v[], int n);
void ordinaIns(int v[], int n);

int main(){
  int n;
  int v[DIM];
  FILE* f;
  f = fileOpen("in.dat", "r");
  n = carica(f, v);
  visualizza(v, n);
  ordinaIns(v, n);
  visualizza(v, n);
  return 0;
}

int carica(FILE* f, int v[]){
  int i, tmp;
  i=0;
  while (i < DIM && fread(&tmp, sizeof(int), 1, f)) {
    v[i] = tmp;
    i++;    
  }
  return i;
}

void visualizza(int v[], int n){
  int i;
  i = 0;
  while (i < n) {
    printf("%d ", v[i]);
    i++;
  }
  printf("\n");
  
}

void ordinaIns(int v[], int n){
  int i, j, tmp;
  i=1;
  while (i < n){
    tmp = v[i];
    j = i-1;
    while (j >=0 && v[j] > tmp) {
      v[j+1] = v[j];
      j--;
    }
    v[j+1] = tmp;
    i++;
  }
}
