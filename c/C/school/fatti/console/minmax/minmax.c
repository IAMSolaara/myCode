/*Lorenzo Cauli 3C 1/12/2018
scopo: dire numero minimo e massimo di una sequenza di dati dato il numero e la sequenza stessa.
dati:
	quanti		int	I	quanti > 0
	elemento	int	I
	min		int	O
	max		int	O
*/

#include <stdio.h>
int main(){
	/*variabili*/
	int quanti, elemento, min, max, cont; cont=0;
	/*lett controllata numero dati*/
	printf("Quanti dati sono nella sequenza?.\n");scanf("%d", &quanti);
	while (quanti <= 0) {printf("Numero non valido, inserirne un altro.\n"); scanf("%d", &quanti);}
	/*input numeri e controllo*/
	while (cont < quanti){
	printf("Inserire il numero.\n"); scanf("%d", &elemento);
	if (cont == 0) min=max=elemento;
	if (elemento < min) min=elemento;
	else if (elemento > max) max=elemento;
	cont++;
	}
	/*comunicazione massimo e minimo*/
	printf("Il numero massimo e' stato %d, il minimo %d.\n", max, min);
return 0;
}
