/*Lorenzo Cauli 3C 29-11-2018
scopo: tracciare una linea data la sua lunghezza.
*/
#include <stdio.h>

void leggi(const char msg[], int* in);
void plot(int n);

int main(){
	int length;
	leggi("Inserire la lunghezza della riga.\n", &length);
	plot(length);
return 0;
}

void leggi(const char msg[], int* in){
        printf("%s", msg); scanf("%d", in);
        while (*in <= 0) {printf("Numero non valido, inserirne un altro.\n"); scanf("%d", in);}
}

void plot(int n){
        int cont;cont=0;
        while (cont < n) {printf("#"); cont++;}
        printf("\n");
}
