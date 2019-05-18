/*Lorenzo Cauli 3C 19-01-2018
scopo: trasformare le lettere minuscole di una frase in maiuscole e visualizzarla
dati:
	frase		IO	array char
*/
#include <stdio.h>
#include <string.h>/*
#include <readS.h>*/

#define VDIM 200

void leggi(const char msg[], char out[]);
void caseChg(char out[]);
void visual(const char msg[], const char out[]);

int main(){
	char frase[VDIM+1];
	/*lettura frase*/
	leggi("Inserire una frase da max 200 caratteri.\n", frase);
	/*cambiamento lettere minuscole in maiuscole*/
	caseChg(frase);
	/*visualizzazione della frase modificata*/
	visual("Ecco la frase modificata.", frase);
return 0;
}

void leggi(const char msg[], char out[]){
	printf(msg); scanf("%s", out); /*scanf e' una bozza temporanea in attesa della disponibilita' di readS*/
/*	readS(out, VDIM);
*/}

void caseChg(char out[]){
	/*dichiarazione offset e var indice vettore*/
	int i=0, off='a'-'A';
	/*ciclo fino a che si trova terminatore*/
	while (out[i]!='\0'){
		/*se indice contiene lettera minuscola*/
		if ( out[i] <= 'z' && out[i] >= 'a' ){
			/*sottrazione offset e inc di i*/
			out[i]=out[i]-off;
			i++;
		}
		/* inc i se lettera maiuscola*/
		else i++;
	}
}

void visual(const char msg[], const char out[]){
	printf("%s\n%s\n", msg, out);
}
