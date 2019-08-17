/*Lorenzo Cauli 3C 12-10-2018*/
/*Scopo: calcolare la spesa totale di uno scontrino*/
/*Dati:*/
/*n_articoli	I	int	n_articoli > 0*/
/*prezzo	I	float	prezzo => 0*/
/*somma		O	float	somma => 0*/
/*cont		L	int*/

#include <stdio.h>
int main() {
	/*dichiarazione variabili*/
	int n_articoli, cont; float prezzo, somma;
	/*richiesta del numero di articoli*/
	printf("Inserisca il numero di articoli.\n"); scanf("%d", &n_articoli);
	/*error check*/
	while (n_articoli < 0) {
		printf("Numero invalido, ne inserisca un altro.\n"); scanf("%d", &n_articoli);
	}
	/*init variabili*/
	cont = 0; prezzo = 0; somma = 0;
	/*richiesta e error check del prezzo di un'articolo e aggiunta di esso alla somma*/
	while (cont < n_articoli) {
		printf("Inserisca il prezzo dell'articolo.\n"); scanf ("%f", &prezzo);
		while (prezzo < 0){
			printf("Numero invalido, ne inserisca un altro.\n"); scanf("%f", &prezzo);
		}
		somma = somma + prezzo;
		cont = cont + 1;
	}
	/*comunicazione del risultato*/
	printf("La spesa totale ammonta a €%.2f.\n", somma);
}
