/*Lorenzo Cauli 3C verifica di TPS 11/05/2019
scopo: allocare dinamicamente un vettore in memoria e generare valori casuali su cui svolgere un'operazione diversa dipendentemente dalla condizione
dati:
	v O array int random(3...20) *p = 4...30
relazione tra i dati:
	se *p > 24 --> *p = *p / 2
	altrimenti se *p < 6 --> *p = *p * 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* riserva(int n);
int rnd(int min, int max);
void carica(int* out, int dim);
void visual(int* v, int dim);
void correggi(int* out, int dim);

int main(){
	srand(time(NULL));		//init generatore numeri casuali
	int* v;				//declare puntatore vettore
	int dim;			//declare variabile dimensione
	dim = rnd(3, 20);		//init dimensione con numero casuale
	v = riserva(dim);		//allocazione vettore di dimensione dim
	carica(v, dim);			//caricamento vettore con numeri casuali
	visual(v, dim);			//visualizzazione vettore con numeri casuali
	correggi(v, dim);		//correzione vettore con operazione precedentemente indicata
	visual(v, dim);			//visualizzazione vettore corretto
	free(v);			//rilascio memoria
	return 0;
}

/*rnd, op di elaborazione
scopo: restituzione valore casuale compreso tra i limiti passati
min I int
max I int
*/

int rnd(int min, int max){
	return rand()%(max-min+1)+min;	//restituzione numero casuale
}

/*riserva, op di elaborazione
scopo: restituzione di un puntatore di area di memoria allocata dinamicamente
n I int 3...20
*/

int* riserva(int n){
	int* p;							//declare puntatore da restituire
	p = (int*)malloc(sizeof(int) * n);			//allocazione con malloc
	if (p == NULL){						//condizione che controlla se il vettore non e' stato allocato
		printf("Errore allocazione in memoria");	//stampa messaggio di errore
		exit(-1);					//uscita da programma con errore
	}
	return p;						//restituzione puntatore
}

/*carica, op di elaborazione
scopo: caricare un vettore
out O array int random(3...20) *p = 4..30
dim I int 3...20
*/

void carica(int* out, int dim){
	int* p;				//declare puntatore vettore
	p = out;			//init puntatore con indirizzo vettore dinamico
	while (p < out + dim){		//ciclo init vettore con p come puntatore indice vettore
		*p = rnd(4, 30);	//init di valore puntato da p con numeri casuali
		p++;			//incremento indirizzo puntato da p
	}
}

/*visual, op di output
scopo: visualizzare gli elementi di un vettore
v I array int random(3...20) *p = 4..30
dim I int 3...20
*/

void visual(int* v, int dim){
	int* p;				//declare puntatore vettore
	p = v;				//init puntatore con indirizzo vettore dinamico
	while (p < v + dim){		//ciclo stampa di elementi del vettore
		printf("%d ", *p);	//stampa elemento puntato da p
		p++;			//incremento indirizzo puntato da p
	}
	printf("\n");			//stampa newline
}

/*correggi, operazione di elaborazione
scopo: effettuare un'operazione sui singoli elementi di un vettore
v O array in random(3..20) *p = 4..30
dim I int 3..20
*/

void correggi(int* out, int dim){
	int* p;					//declare puntatore vettore
	p = out;				//init puntatore con indirizzo vettore dinamico
	while (p < out + dim){			//ciclo modifica vettore con p come puntatore indice vettore
		if (*p < 6) *p *= 2;		//controllo se il valore puntato da p e' minore di 6, quindi raddoppiamento del valore in caso la condizione sia vera
		else if (*p > 24) *p /= 2;	//controllo simile a quello sopra ma se p e' maggiore di 24 quindi dimezzo del valore
		p++;				//incremento indirizzo puntato da p
	}
}
