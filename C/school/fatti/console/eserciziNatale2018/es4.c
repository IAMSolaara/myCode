/*Lorenzo Cauli 3C 06-01-2018
scopo: caricare voti in un vettore e visualizzare quanti alunni hanno preso un determinato voto
dati:
	voti	I	array int	voti[cont] > 0 && voti[cont] <= 10
	nAlunni	I	int			nAlunni >= MAXAL
	nAlVot	O	int
*/

#include <stdio.h>
#define MAXAL 30

void leggiComp(const char msg[], int* out);
void carica(const char msg[], int voti[], int nAl);
void visual(const char msg[], const int voti[], int nAl);

int main(){
	int voti[MAXAL], nAlunni;
	/*lettura numero alunni*/
	leggiComp("Specificare numero degli alunni.\n", &nAlunni);
	carica("Inserire il voto numero", voti, nAlunni);
	visual("Quale voto devo visualizzare?\n", voti, nAlunni);
return 0;
}

void leggiComp(const char msg[], int* out){
	printf("%s", msg); scanf("%d", out);
	while (*out > MAXAL) {printf("Numero invalido, inserirne un altro.\n"); scanf("%d", out);}
}

void carica(const char msg[], int voti[], int nAl){
	int cont, nv; cont = 0;nv =cont+1;
	while (cont < nAl){
		printf("%s %d.\n", msg, nv); scanf("%d", &voti[cont]);
		while (voti[cont] > 10 || voti[cont] < 1) {printf("Numero invalido, inserirne un altro.\n"); scanf("%d", &voti[cont]);}
	cont++;nv++;
	}
}
void visual(const char msg[], const int voti[], int nAl){
	int visvot, nAlVot, cont; nAlVot=cont=0;
	printf("%s", msg); scanf("%d", &visvot);
	while (cont < nAl){
		if (voti[cont] == visvot) {nAlVot++;}
		cont++;
	}
	printf("Gli alunni che hanno preso %d sono %d.\n", visvot, nAlVot);
}