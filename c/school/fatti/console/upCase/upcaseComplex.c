/*Lorenzo Cauli 3C 19-01-2018
scopo: trasformare le iniziali delle parole di una frase in maiuscole e visualizzare la frase
dati:
	frase		IO	array char
	fraseMod	IO	array char
*/

#include <stdio.h>
#include <string.h>
/*#include <readS.h>
*/
#define VDIM 200

void leggi(const char msg[], char out[], char outMod[]);
void caseChg(char out[]);
void visual(const char msg1[], const char msg2[], const char fr[], const char frMod[]);

int main(){
  char frase[VDIM+1], fraseMod[VDIM+1];
  /*lettura frase e copia in stringa per modifica*/
  leggi("Inserire una frase da max 200 caratteri.\n", frase, fraseMod);
  /*cambiamento */
  caseChg(fraseMod);
  
  visual("La frase prima: ", "La frase dopo: ", frase, fraseMod);
  return 0;
}

void leggi(const char msg[], char out[], char outMod[]){
  printf(msg);
  readS(out, VDIM);
  strcpy(outMod, out);
}

void caseChg(char out[]){
  int i=0, off='a'-'A';
  while (out[i] != '\0'){
    if (i==0 && out[i] <= 'z' && out[i] >= 'a'){
      out[i] = out[i]-off;
      i++;
    }
    else if (out[i] == ' '){
      if (out[i+1] <= 'z' && out[i+1] >= 'a' ){
	out[i+1]=out[i+1]+off;
	i++;
      }
    }
  }
}

void visual(const char msg1[], const char msg2[], const char fr[], const char frMod[]){
  printf("%s %s\n%s %s\n", msg1, fr, msg2, frMod);
}
