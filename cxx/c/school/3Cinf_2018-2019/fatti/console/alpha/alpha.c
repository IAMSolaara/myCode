#include <stdio.h>
int main() {
	char inC;int nNA, cont, max; max=cont=nNA=inC=0;
	printf("Quanti caratteri inserirai?\n");scanf("%d%*c", &max);
	while(cont < max){
		printf("Inserisci un coso.\n"); scanf("%c%*c", &inC);
		if (inC < 65 || inC > 90 && inC < 97 || inC > 122) {nNA++;}
		cont++;
	}
	printf("I caratteri non alfabetici inseriti sono %d.\n", nNA);
return 0;}
