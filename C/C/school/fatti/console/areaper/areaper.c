/*Lorenzo Cauli 3C 25-11-2018
scopo: calcolare area e perimetro di un rettangolo dati base e altezza
Dati:
	inB	float	I	inB > 0
	inH	float	I	inH > 0
	area	float	O	area > 0
	per	float	O	area > 0
*/
#include<stdio.h>

void leggi(const char msg[], float* in) {
	printf("%s", msg); scanf("%f", in);
	while (*in <= 0) {printf("Il numero inserito e' invalido, inserirne un altro.\n"); scanf("%f", in);}
}
void calcarea(float b, float h, float* ris){
	*ris = b * h;
}
void calcper(float b, float h, float* ris){
	*ris = (b + h) * 2;
}
void comunica(const char msg[], const char msg2[], float per, float area){
	printf("%s %.2f. %s %.2f.\n", msg, area, msg2, per);
}
int main(){
	float inB, inH, area, per; inB=inH=area=per=0;
	leggi("Specificare la base.\n", &inB);
	leggi("Specificare l'altezza.\n", &inH);
	calcarea(inB, inH, &area);
	calcper(inB, inH, &per);
	comunica("L'area vale", "Il perimetro vale", per, area);
return 0;
}
