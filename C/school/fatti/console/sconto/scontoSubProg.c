/* Lorenzo Cauli 3C 20-11-2018
scopo: calcolare sconto e prezzo scontato di un articolo data la percentuale.
Dati:
	priceFull	float	I	priceFull >= 0.00
	priceDiscPerc	int	I	priceDiscPerc	>= 0 && priceDiscPerc <= 100
	priceDiscount	float	O	priceDiscount >= 0
	priceDiscounted	float	O	priceDiscounted >= 0
*/

#include <stdio.h>

void chiedi(const char msg[], float* in) {
	printf("%s", msg); scanf("%f", in);
	while (*in < 0) {printf("Numero invalido, inserirne un altro.\n"); scanf("%f", in);}
}

void chiediInt(const char msg[], int* in) {
	printf("%s", msg); scanf("%d", in);
	while (*in < 0) {printf("Numero invalido, inserirne un altro.\n"); scanf("%d", in);}
}

void calcDisc(float* x, float* y, float a, int b) {
	*x = a / 100;
	*x = *x * b;
	*y = a - *x;
}

int main() {
	int priceDiscPerc; float priceFull, priceDiscounted, priceDiscount; priceDiscPerc=priceFull=priceDiscounted=priceDiscount=0;
	chiedi("Inserire il prezzo di listino dell'articolo.\n", &priceFull);
	chiediInt("Inserire la percentuale dello sconto SENZA %%.\n", &priceDiscPerc);
	calcDisc(&priceDiscount, &priceDiscounted, priceFull, priceDiscPerc);
	printf("Il prezzo scontato dell'articolo e' %.2f euro, dato lo sconto di %.2f euro.\n", priceDiscounted, priceDiscount);
	return 0;
}
