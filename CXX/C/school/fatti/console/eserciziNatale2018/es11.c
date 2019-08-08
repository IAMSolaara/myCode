/*Lorenzo Cauli 3C 06-01-2018
scopo: generare un numero casuale e visualizzarne la tabellina tramite un vettore
dati:
	arr		O	arr int
*/

#include <stdio.h>
#include <time.h>

#define DIM  10
#define VMIN 1
#define VMAX 10

void genera(int* val, int min, int max);
void tabel(int n, int tab[]);
void visual(int arr[], int n);

int main(){
	int x, arr[DIM];
	/*init generatore num casuale*/
	srand(time(NULL));
	/*generazione numero*/
	genera(&x,VMIN,VMAX);
	/*caricamento tabellina nel vettore*/
	tabel(x, arr);
	/*visualizzazione del numero generato e la sua tabellina*/
	visual(arr, x);
return 0;
}

void genera(int* val, int min, int max){
	*val = rand()%(max-min+1)+min;
}

void tabel(int n, int tab[]){
	int cont, fact2; cont=0; fact2 = cont+1;
	while (cont < DIM){
		tab[cont] = n * fact2;
		cont++; fact2++;
	}
}

void visual(int arr[], int n){
	int cont; cont=0;
	printf("Il numero generato e' il numero %d.\n", n);
	while (cont < DIM){
		printf("%d\n", arr[cont]);
		cont++;
	}
}