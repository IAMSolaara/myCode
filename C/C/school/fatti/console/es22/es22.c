/*Lorenzo Cauli 3C 08-01-2018
scopo: calcolare bit di parita' in base alla modalita' scelta e al numero inserito
dati:
	arr	I/O	array int
	mode	I	char		mode == 'p' || mode == 'd'
*/

#include <stdio.h>
#define VDIM 8

void carica(const char msg[], int arr[]);
void visual(const char msg[], const int arr[]);

int main(){
	int arr[VDIM];
	/*caricamento dati nel vettore, scelta modalita' e calcolo bit parita'*/
	carica("Inserire il bit.\n", arr);
	/*visualizzazione numero risultato*/
	visual("Il numero binario, incluso il bit di parita' equivale a ", arr);
return 0;
}

void carica(const char msg[], int arr[]){
	int cont, bn/*contatore bit usato per il calcolo*/; bn=cont=1; char mode;
	/*richiesta modalita'*/
	printf("Calcolare per parita' pari o dispari? [p/d]");scanf("%c%*c", &mode);
	while(mode != 'd' && mode != 'p') {printf("Carattere inserito invalido. Inserirne un altro.\n");scanf("%c%*c", &mode);}
	/*ciclo input numero e incremento contatore bit*/
	while(cont < VDIM){
		printf("%s", msg); scanf("%d", &arr[cont]);
		if (arr[cont] == 1) bn++;
		cont++;
	}
	/*calcolo bit parita' dispari*/
	if (mode == 'd'){
		if (bn == 2 || bn == 4 || bn == 6) arr[0] = 0;
		else arr[0] = 1;
	}
	/*calcolo bit parita' pari*/
	if (mode == 'p'){
                if (bn == 2 || bn == 4 || bn == 6) arr[0] = 1;
                else arr[0] = 0;
        }
}

void visual(const char msg[], const int arr[]){
	int cont = 0;
	printf("%s", msg);
	while (cont < VDIM) {printf("%d", arr[cont]); cont++;}
	printf("\n");
}
