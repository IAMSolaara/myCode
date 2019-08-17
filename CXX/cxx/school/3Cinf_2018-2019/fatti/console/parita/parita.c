/* Ricco Davide, 3C, 8-01-2018
Scopo: Scrivere un programma per calcolare il bit di parita' (pari o dispari secondo la scelta dell'utente) di
un numero di 8 bit, memorizzandolo nella posizione piu' significativa.

Dati: 
Scelta, I, P || D
vete, I 
DIM, I, 8
vet [0], O, 0 || 1

Relazione tra i dati: 
Se scelta = P 
vet [0] = 1 se gli 1 del vettore sono dispari
altrimenti vet [0] = 0

Altrimenti 
vet [0] = 0 se gli 1 del vettore sono dispari
altrimenti vet [1] = 1
*/

/* direttive preprocessore */
#include <stdio.h>

/* dichiarazione prototipi */
void selezione (const char msg [], char* risp);
void carica (int vet[]);
void calcola (int vet[], char opzione);
void printMsg (const char msg [], const int vet[]);
void leggiComp (const char msg [], int* val, int min, int max, int id);


/* definizione costanti */
#define DIM 8

/* prorgramma principale */
int main () {

	/* sezione dichiarativa */
	int numero[DIM];
	char scelta;

	/* sezione esecutiva */ 
	selezione ("Si desidera calcolare il bit di parita' pari (P) o dispari (D)?", &scelta);
	carica (numero);
	calcola (numero, scelta);
	printMsg ("Il bit di parita' vale ", numero);
	return 0;
}

void selezione (const char msg [], char* risp) {

	printf ("%s ", msg);
	scanf ("%c%*c", risp);
	while ( *risp != 'P' && *risp != 'D'){

		printf ("Opzione non valida.\n%s ", msg);
		scanf ("%c%*c", risp);
	}
	if (*risp == 'P') {
		printf ("Si e' scelto di calcolare il bit di parita' in modo pari.\n");
	}	
	else {
		printf ("Si e' scelto di calcolare il bit di parita' in modo dispari.\n");
	}
}

void carica (int vet[]) {

	/* sezione dichiarativa */
	int cont1, cont2;

	/* sezione esecutiva */
	cont1 = 8;
	cont2 = 1;
	while (cont1 > 1) {
		leggiComp ("Inserire il valore del bit n.", &vet[cont1], 0, 1, cont2);
		cont1--;
		cont2++;
	}
}

void calcola (int vet[], char opzione) {
	/* sezione dichiarativa */
	int cont, val, resto;
	
	/* sezione esecutiva */
	cont = 7;
	while (cont >= 1) {
		
		val = val + vet[cont]; 
		cont--;
	}
	resto = val%2;
	if (opzione == 'P') {

		if (resto == 1){

			vet[0] = 1;
		}
		else {

			vet[0] = 0;
		}	
	}	
	
	else {
		if (resto == 1) {

			 vet[0] = 0; 
		}
		else {

			vet[0] = 1;
		}
	}
}	

void printMsg (const char msg [], const int vet[]) {

	printf ("%s%d\n", msg, vet[0]);
}

void leggiComp (const char msg [], int* val, int min, int max, int id) {

	printf ("%s%d: ", msg, id); 
	scanf ("%d%*c", val);
	while (*val < min || *val > max) {

		printf ("Valore non valido. Inserire un valore che sia %d o %d: ", min, max);
		scanf ("%d%*c", val);
	}
}
