
#include <stdio.h>
int main() {
	int car;
	printf("Inserisca un carattere.\n"); scanf("%d%*c", &car);
	if (car <= 'z' && car >= 'a') {
		printf("Il carattere inserito e' una lettera minuscola.\n");
/*		printf("%c\n", car);
*/	}
	else if (car <= 'Z' && car >= 'A') {
                printf("Il carattere inserito e' una lettera maiuscola.\n");
/*	        printf("brutto %c\n", car);
*/	}
	else if (car <= 9 && car >= 0) {
                printf("Il carattere inserito e' un numero.\n");
/*        	printf("%c\n", car);
*/	}
return 0;
}

