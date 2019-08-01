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
	printf("%s", msg); scanf("%f%*c", in);
	while (*in <= 0) {printf("Il numero inserito e' invalido, inserirne un altro.\n"); scanf("%f%*c", in);}
}
void calc(float b, float h, float* ris, float* ris2){
	char opTmp;
	printf("Calcolare area o perimetro? [a/p].\n"); scanf("%c%*c", &opTmp);
	while (opTmp != 'a' && opTmp != 'p') {printf("Il carattere e' invalido, inserirne un altro.\n");scanf("%c%*c",&opTmp);}
	if (opTmp == 'a') *ris = b * h;
	else *ris2 = (b + h) * 2;
}
void comunica(const char msg[], const char msg2[], float area, float per){
	if (per == 0 && area != 0) printf("%s %.2f.\n", msg, area);
	if (per != 0 && area == 0) printf("%s %.2f.\n", msg2, per);
}
int main(){
	float inB, inH, area, per; per=area=0;
	leggi("Specificare la base.\n", &inB);
	leggi("Specificare l'altezza.\n", &inH);
	calc(inB, inH, &area, &per);
	comunica("L'area vale", "Il perimetro vale", area, per);
return 0;
}
