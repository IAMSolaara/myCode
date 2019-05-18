/*Lorenzo Cauli 3C 12-01-2018
scopo: simulare un login
dati:
	userIn	I	array char
	passIn	I	array char
*/
#include <stdio.h>
#include <string.h>
#include <readS.h>
#define VDIM 11

void leggi(const char msg[], char out[]);
void logChk(const char uIn[], const char pIn[], const char u[], const char p[], int* rets);
void comunica(const char msg[], const char msgerr[], int rets);

int main(){
	/*dichiarazione user e pass corretti*/
	char user[VDIM]="alunno", pass[VDIM]="12345";
	/*dichiarazione user e pass input*/
	char userIn[VDIM], passIn[VDIM];
	/*dichiarazione vettore stato finto bool*/
	int states=1;
	/*lettura user e pass*/
	leggi("Inserire username.\n", userIn);
	leggi("Inserire password.\n", passIn);
	/*confronto stringhe*/
	logChk(userIn, passIn, user, pass, &states);
	/*comunicazione risultato operazione login*/
	comunica("Login effettuato.\n", "Login non effettuato.\n", states);
return 0;
}

void leggi(const char msg[], char out[]){
	/*lettura stringa*/
	printf("%s", msg);
	readS(out, VDIM-1);
}

void logChk(const char uIn[], const char pIn[], const char u[], const char p[], int* rets){
	/*controllo user, se non corretto il primo indice di rets diventa 1*/
	if (strcmp(uIn, u) != 0) *rets=0;
	/*stessa cosa di prima ma per password e secondo indice di rets*/
	if (strcmp(pIn, p) != 0) *rets=0;
}
void comunica(const char msg[], const char msgerr[], int rets){
	/*utilizzo di rets per notificare login effettuato o meno*/
	if (rets == 1) printf("%s", msg);
		else printf("%s", msgerr);
}
