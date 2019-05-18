#include <stdio.h>
int main() {
	char inC;int nNA, cont, max; max=cont=nNA=inC=0;
	printf("Quanti caratteri inserirai?\n");scanf("%d%*c", &max);
	while(cont < max){
		printf("Inserisci un coso.\n"); scanf("%c%*c", &inC);
		if (inC < 'a' || inC > 'z' || inC < 'A' || inC > 'Z') {printf("asd\n");}
		else nNA++;
		cont++;
	}
	printf("I caratteri non alfabetici inseriti sono %d.\n", nNA);
return 0;}
