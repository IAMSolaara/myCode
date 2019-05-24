/* Lorenzo Cauli 3C 20-11-2018
scopo: calcolare sconto e prezzo scontato di un articolo data la percentuale.
Dati:
	priceFull	float	I	priceFull >= 0.00
	priceDiscPerc	int	I	priceDiscPerc	>= 0 && priceDiscPerc <= 100
	priceDiscEff	float	O	priceDiscEff >= 0
	priceDisc	float	O	priceDisc >= 0
*/

#include <stdio.h>

int main() {
	int priceDiscPerc; float priceFull, priceDisc, priceDiscEff; priceDiscPerc=priceFull=priceDisc=priceDiscEff=0;
	printf("Inserire il prezzo di listino dell'articolo.\n"); scanf("%f", &priceFull);
	while (priceFull < 0) {printf("Numero invalido, inserirne un altro.\n"); scanf("%f", &priceFull);}
	printf("Inserire la percentuale dello sconto SENZA %%.\n"); scanf("%d", &priceDiscPerc);
	while (priceDiscPerc < 0) {printf("Numero invalido, inserirne un altro.\n"); scanf("%d", &priceDiscPerc);}
	priceDiscEff = priceFull / 100;
	priceDiscEff = priceDiscEff * priceDiscPerc;
	priceDisc = priceFull - priceDiscEff;
	printf("Il prezzo scontato dell'articolo e' %.2f euro, dato lo sconto di %.2f euro.\n", priceDisc, priceDiscEff);
	return 0;
}
