/*Lorenzo Cauli 3C 29-11-2018
scopo: tracciare un rettangolo dati base e altezza.
*/
#include <stdio.h>

void leggi(const char msg[], int* in);
void plot(int l, int h);

int main(){
	int length, height;
	leggi("Inserire la larghezza del rettangolo.\n", &length);
	leggi("Inserire l'altezza del rettangolo.\n", &height);
	plot(length, height);
return 0;
}

void leggi(const char msg[], int* in){
        printf("%s", msg); scanf("%d", in);
        while (*in <= 0) {printf("Numero non valido, inserirne un altro.\n"); scanf("%d", in);}
}

void plot(int l, int h){
	int cont, cont2; cont2=cont=0;
        while (cont2 < h){
		while (cont < l) {printf("#"); cont++; printf("\n");}
		cont2++;
	}
}
