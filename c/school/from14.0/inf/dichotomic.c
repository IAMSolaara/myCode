/*Lorenzo Cauli 3C 31-01-2019
scopo: effettuare ricerca dicotomica su un vettore
dati:
	query	I	int
	arr	O	arr int
	index	O	int
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VDIM 10
#define MAX 100
#define MIN (-100)


void init(int out[]);
void order(int out[]);
void swap(int* x, int* y);
void leggiComp(const char msg[], int* out);
void search(int arr[], int q, int* out);
void visual(const char msg[], int i);
void arrView(const char msg[], int out[]);

int main(){
	int arr[VDIM], query, index = 0;
	srand(time(NULL));
	init(arr);
	order(arr);
	arrView("Questo e' il vettore: ", arr);
	leggiComp("Specificare il numero che si sta cercando.\n", &query);
	search(arr, query, &index);
	visual("Il numero cercato e' all'indice numero", index);
return 0;
}

void init(int out[]){
	int cont=0;
	while (cont < VDIM){
		out[cont]=rand()%(MAX-MIN+1)+MIN;
	cont++;
	}
}

void order(int out[]){
	int i=0, j;
	while (i < VDIM-1){
		j=i+1;
		while (j < VDIM){
			if (out[i] > out[j]){
				swap(&out[i], &out[j]);
			}
			j++;
		}
		i++;
	}
}

void swap(int* x, int* y){
	int tmp;
	tmp=*x;
	*x=*y;
	*y=tmp;
}

void leggiComp(const char msg[], int* out){
	int cont=0;
	printf("%s", msg);
	scanf("%d", out);
	while (*out > MAX || *out < MIN){
		printf("Il numero inserito e' invalido, inserirne un altro.\n");
		scanf("%d", out);
	}
}

void search(int arr[], int q, int* out){
	int i=0, f=VDIM-1, m;
	while (f!= i && i!= m && f != m || arr[m] == q ){
		m=(i+f)/2;
		if (arr[m] > q){
			f = m-1;
		}
		else if (arr[m] < q){
			i = m+1;
		}
		else if (arr[m] == q){
			*out = m;
		}
		else if (i == m && i == f){
			*out = m;
		}
	}
}

void visual(const char msg[], int i){
	printf("%s %d.\n", msg, i);
}

void arrView(const char msg[], int out[]){
	int cont=0;
	printf("%s", msg);
	while (cont < VDIM){
		printf(" %d ", out[cont]);
		cont++;
	}
	printf("\n");
}
