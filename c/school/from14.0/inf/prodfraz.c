/*Lorenzo Cauli 3C 11-12-2018
scopo: calcolare e comunicare il prodotto di due frazioni
dati:
	num1	int	I	num1 >= 0
	den1	int	I	den1 > 0
	num2	int	I	num2 >= 0
	den2	int	I	den2 > 0
	numr	int	O	numr >= 0
	denr	int	O	denr > 0
*/

#include <stdio.h>

void leggiNum(const char msg[], int* out);
void leggiDen(const char msg[], int* out);
void calc(int n1, int n2, int d1, int d2, int* nr, int* dr);
void comunica(const char msg[], int d, int n);

int main(){
	/*definizione variabili*/
	int num1, den1, num2, den2, numr, denr;
	/*letture controllate*/
	leggiNum("Specificare numeratore prima frazione.\n", &num1);
	leggiDen("Specificare denominatore prima frazione.\n", &den1);
	leggiNum("Specificare numeratore seconda frazione.\n", &num2);
	leggiDen("Specificare denominatore seconda frazione.\n", &den2);
	/*calcolo del risultato*/
	calc(num1, num2, den1, den2, &numr, &denr);
	/*comunicazione del risultato*/
	comunica("Il risultato e'\n", denr, numr);
return 0;
}

void leggiNum(const char msg[], int* out){
        printf("%s", msg);scanf("%d", out);
        while (*out < 0) {printf("Numero non valido, inserirne un altro.\n"); scanf("%d", out);}
}

void leggiDen(const char msg[], int* out){
        printf("%s", msg);scanf("%d", out);
        while (*out <= 0) {printf("Numero non valido, inserirne un altro.\n"); scanf("%d");}
}

void calc(int n1, int n2, int d1, int d2, int* nr, int* dr){
        *nr = n1 * n2;
        *dr = d1 * d2;
}

void comunica(const char msg[], int d, int n){
        printf("%s", msg);
        printf("%d\n", n);
        printf("--------");
        printf("\n%d\n", d);
}
