#include <stdio.h>
#include <162lib.h>

void leggi(FILE* f);

int main(){
  //dichiarazione nome logico file
  FILE* f;
  //apertura flusso file
  f = fileOpen("leggiSorgRic.c", "r");
  //lettura con ricorsione
  leggi(f);
  //chiusura flusso file
  fclose(f);
  return 0;
}

void leggi(FILE* f){
  //declare variabile temporanea
  char c;
  //ciclo fino a file file
  if (fscanf(f, "%c", &c) != EOF){
    //stampa di c
    printf("%c", c);
    //richiamo di se stesso
    leggi(f);
  }
}
