/*Lorenzo Cauli 3C 24-01-2018
scopo: calcolare quanto costerebbero due sostituzioni
dati:
	nMatt	I	int		nMatt => 0 && nMatt <= 500
	stato	I	arr char	stato[i] == 'g' || stato[i] == 'l'
	gPrice	I	float		gPrice > 0
	lPrice	I	float		lPrice > 0
*/

#include <stdio.h>

#define VDIM 500

void leggiComp(const char msg[], int* out);
void arrRead(const char msg[], char out[], int neff);
void dmgCount(const char state[], int neff, int* g, int* l);
void leggi(const char msg, float* out);
void visual(const char msg[], const char msg1[], int g, int l, int gp, int lp);

int main(){
	int nMatt, grave=0, light=0, price; char stato[VDIM];
	leggiComp("Quante mattonelle sono rovinate?\n", &nMatt);
	arrRead("Qual'e' lo stato della mattonella numero", stato, nMatt);
	dmgCount(stato, nMatt, &grave, &light);
	leggi("Quanto costa riparare una mattonella lievemente danneggiata?\n", &price);
	visual("Riparare tutte le mattonelle danneggiate costera'", "Riparare solo le mattonelle gravemente danneggiate costera'", grave, light, price);
return 0;
}

void leggiComp(const char msg[], int* out){
	printf("%s", msg); scanf("%d%*c", out);
	while (*out < 0 || *out > 500){
		printf("Il numero inserito e' invalido, inserirne un altro.\n");
		scanf("%d%*c", out);
	}
}

void arrRead(const char msg[], char out[], int neff){
	int cont=0, cont1;
	while (cont < neff){
		cont1=cont+1;
		printf("%s %d? [g/l]\n", msg, cont1);
		scanf("%c%*c", &out[cont]);
		while ( out[cont] != 'g' && out[cont] != 'l' ){
			printf("Il carattere inserito e' invalido, inserirne un altro.\n");
			scanf("%c%*c", &out[cont]);
		}
	}
}

void dmgCount(const char state[], int neff, int* g, int* l){
	int cont=0;
	while (cont < neff){
		if (state[cont] == 'g') *g = *g + 1;
		else *l = *l + 1;
	}
}

void leggi(const char msg, float* out){
	printf("%s", msg);
	scanf("%f%*c", out);
	while (*out <= 0){
		printf("Il numero inserito e' invalido, inserirne un altro.\n");
		scanf("%f%*c", out);
	}
}

void visual(const char msg[], const char msg1[], int g, int l, int p){
	printf("%s %.2f euro.\n", msg, g+l*p);
	printf("%s %.2f euro.\n", msg1, g*p);
}
