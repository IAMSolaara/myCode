/*Lorenzo Cauli 3C 19/05/2019
scopo: leggere i contenuti di due file e controllare se sono uguali
dati:
tmp, I da file bin
tmp1, I da file bin

relazione tra dati:
se tmp != tmp2 ---> st = 0;
*/

#include <stdio.h>
#include <stdlib.h>

FILE* fileOpen(const char fname[], const char perm[]);
int fileCmp(FILE* f, FILE* f1);
void comunica(int cnd, const char msg[], const char msg1[]);

int main(){
  FILE* f;                                                              //declare file 1
  FILE* f1;                                                             //declare file 2
  int esito;                                                            //declare variabile esito usata in ciclo sentinella
  f=fileOpen("cmp1.dat", "r");	                                        //apertura stream f con cmp1.dat
  f1=fileOpen("cmp2.dat", "r");                                         //apertura stream f1 con cmp2.dat
  esito = fileCmp(f, f1);                                               //memorizzazione esito lettura e controllo file usato in comunica
  comunica(esito, "I file sono uguali.\n", "I file sono diversi.\n");   //comunicazione esito
  fclose(f);                                                            //chiusura stream f
  fclose(f1);                                                           //chiusura stream f1
  return 0;
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

int fileCmp(FILE* f, FILE* f1){
  int tmp, tmp1;                                                                      //declare variabili temporanee
  int st=1;                                                                           //declare variabile stato
  while(fread(&tmp, sizeof(int), 1, f) && fread(&tmp1, sizeof(int), 1, f1) && st){    //ciclo lettura da entrambi i file fino alla fine con st come sentinella
    if (tmp != tmp1) st = 0;                                                          //se le var tmp sono diverse invertire st per finire il ciclo
  }
  return st;                                                                          //restituzione st
}

void comunica(int cnd, const char msg[], const char msg1[]){
  if (cnd) printf("%s", msg);
  else printf("%s", msg1); 
}
