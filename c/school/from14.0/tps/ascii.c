#include <stdio.h>

int main() {
	char asc; int cont, max, scont;
	scont=asc=0; max=222; cont = 33;
	while (cont < max) {asc = cont; printf(" %c ", asc); cont++; scont++;
		if (scont > 7) {printf("\n"); scont = 0;}
		if (cont == max) {printf("\n");} }
	return 0;
}
