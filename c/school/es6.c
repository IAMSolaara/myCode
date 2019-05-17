/*Lorenzo Cauli 3C 06-01-2018
scopo: trovare il valore più piccolo in un vettore
dati:
	arr		I	array int
	min		O	int
*/

#include <stdio.h>
#define VDIM 10

void carica(int arr[], int* min);
void visual(int min);

int main(){
	int arr[VDIM], min;
	/*caricamento vettore e individuamento del valore piu' piccolo*/
	carica(arr, &min);
	/*visualizzazione valore piu' piccolo*/
	visual(min);
return 0;
}

void carica(int arr[], int* min){
	int cont; cont=0;
	while (cont < VDIM){
		printf("Inserire valore.\n"); scanf("%d",&arr[cont]);
		if (cont == 0) *min = arr[cont];
		else if (*min > arr[cont]) *min = arr[cont];
		cont++;
	}
}

void visual(int min){
	printf("Il valore piu' piccolo nel vettore e' %d.\n", min);
}