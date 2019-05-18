/*Lorenzo Cauli 3C 18-12-2018
Verifica di informatica
scopo: comunicare un numero date le sue centinaia, decine e unita'
dati:
	uni	int	I	uni >= 0
	dec	int	I	dec >= 0
	cen	int	I	cen >= 0
	num	int	O	num >= 0
relazione tra i dati:
	num = uni + (dec * 10) + (cen * 100)
*/

#include<stdio.h>

void leggiPos(const char msg[], int* out);
void calc(int u, int d, int c, int* out);
void comunica(const char msg[], int n);

int main(){
	/*dichiarazione variabili*/
	int uni, dec, cen, num;
	/*lettura controllata numeri*/
	leggiPos("Specificare unita'.\n", &uni);
	leggiPos("Specificare decine.\n", &dec);
	leggiPos("Specificare centinaia.\n", &cen);
	/*calcolo del numero risultante*/
	calc(uni, dec, cen, &num);
	/*comunicazione del risultato*/
	comunica("Il numero risulta essere", num);
return 0;
}

void leggiPos(const char msg[], int* out){
	printf("%s", msg); scanf("%d", out);
	while (*out < 0) {printf("Numero non valido, inserirne un altro.\n"); scanf("%d", out);}
}

void calc(int u, int d, int c, int* out){
	*out = u + (d * 10) + (c * 100);
}

void comunica(const char msg[], int n){
	printf("%s %d.\n", msg, n);
}
