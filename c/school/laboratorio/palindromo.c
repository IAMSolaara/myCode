/*Lorenzo Cauli 3C 22-01-2019
scopo:	comunicare all'utente se il numero inserito e' un palindromo
dati:
	numIn	I	arr int
*/

#include <stdio.h>
#define VDIM 10 

void init(int out[]);
void leggi(const char msg[], int* out);
void arrRead(int neff, int out[]);
void palChk(const int out[], int neff, int* state);

int main(){
	/*declare vettore numero, stato e num effettivo*/
	int numIn[VDIM],state=0, neff;
	/*init zerofill vettore*/
	init(numIn);
	/*lettura num effettivo*/
	leggi("Specificare quante cifre inserira'.\n", &neff);
	/*lettura cifre vettore*/
	arrRead(neff, numIn);
	/*controllo se e' palindromo, PS: nonostante sto consegnando ancora non ho capito come fare bene la funzione, mi potrebbe spiegare come farlo nelle annotazioni, per favore?*/
	palChk(numIn, neff, &state);
	if (state == 0) {printf("PALINDROMO\n");}
	else if (state == 1) {printf("NON PALINDROMO\n");}
return 0;
}

void leggi(const char msg[], int* out){
        printf(msg);
	scanf("%d", out);	
}

void init(int out[]){
	/*zerofill vettore*/
	int cont=0;
	while (cont < VDIM) {
		out[cont]=0;
		cont++;
	}
}

void arrRead(int neff, int out[]){
	/*lettura cifre per vettore*/
	int cont=0;
	while (cont < neff) {
		leggi("Inserire cifra.\n", &out[cont]);
		cont++;
	}
}

void palChk(const int out[], int neff, int* state){
	int cont=0, off;
	/*ciclo controllo palindromo*/
	while (cont < (neff / 2)){
		off=(neff-1)-cont;
		if (out[cont] == out[cont+off]){
			*state = 1;
		}
		else *state = 0;
		cont++;
	}	
}