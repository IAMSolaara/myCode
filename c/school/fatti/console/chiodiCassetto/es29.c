/*Lorenzo Cauli 3C 17-01-2019
scopo: visualizzare quanti chiodi vi sono in ogni cassetto
dati:
	cass	O	array int
relazione:
cass[cont]=totale degli indici / 20
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VDIM 20
#define MAX 10
#define MIN 0

void sparti(int arr[]);
void init(int arr[], int vuoti);
void leggiComp(const char msg[], int* out);
void visual(const char msg[], const int arr[]);

int main(){
	/*definizione vettore*/
	int cass[VDIM], vuoti;
	/*init generatore*/
	srand(time(NULL));
	/*lettura controllata cassetti vuoti*/
	leggiComp("Specificare quanti cassetti sono vuoti.\n", &vuoti);
	/*init vettore cassettiera*/
	init(cass, vuoti);
	/*divisione chiodi per cassetto*/
	sparti(cass);
	/*visualizzazione cassettiera*/
	visual("Questa e' la cassettiera al termine dell' operazione.\n", cass);
return 0;
}

void leggiComp(const char msg[], int* out){
	printf(msg); scanf("%d", out);
	while (*out < 0 || *out > 20){
		printf("Numero non valido, inserire un altro.\n");
		scanf("%d", out);
	}
}

void init(int arr[], int vuoti){
	int cont=vuoti-1;
	while (cont < VDIM){
		arr[cont] = rand()%(MAX-MIN+1)+MIN;
		cont++;
	}
}

void sparti(int arr[]){
	int cont=0, tot=0;
	while(cont < VDIM){
		tot = tot+arr[cont]; cont++;
	}
	cont=0;
	while(cont < VDIM){
		arr[cont] = tot / VDIM;
		cont++;
	}
}

void visual(const char msg[], const int arr[]){
	int cont=0, cont1;
	printf(msg);
	while (cont < VDIM){
		cont1 = cont+1;
		printf("Cassetto numero %d: %d chiodi.\n", cont1, arr[cont]);
		cont++;
	}
}
