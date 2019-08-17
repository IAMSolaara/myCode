/*Lorenzo Cauli 3C 27-11-2018
scopo: classificare un triangolo rispetto ai lati.
Dati:
	lato1	float	I	lato1 > 0
	lato2	float	I	lato2 > 0
	lato3	float	I	lato3 > 0
*/
#include<stdio.h>

void leggi(const char msg[], float* in);
void classifica(float x, float y, float z);

int main(){
        float lato1,lato2,lato3;
        leggi("Inserire primo lato.\n", &lato1);
        leggi("Inserire secondo lato.\n", &lato2);
        leggi("Inserire terzo lato.\n", &lato3);
        classifica(lato1,lato2,lato3);
return 0;
}
void leggi(const char msg[], float* in){
	printf("%s", msg); scanf("%f", in);
	while (*in <= 0) {printf("Numero non valido, inserirne un altro.\n"); scanf("%f", in);}
}
void classifica(float x, float y, float z){
	if (x == y && x == z) printf("Il triangolo e' equilatero.\n");
	else if (x == y || x == z) printf("Il triangolo e' isoscele.\n");
	else printf("Il triangolo e' scaleno.\n");
}
