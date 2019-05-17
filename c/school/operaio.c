#include <stdio.h>

void leggiConf(const char msg[], int* in){
	printf("%s\n", msg); scanf("%d", in);
	while(*in < 0) {printf("Numero inserito invalido, inserirne un altro.\n"); scanf("%d", in);}
}

void calc(int nrm, int ext, int nrmH, int extH, int* out){
	*out = (nrm * nrmH) + (ext * extH);
}

void comunica(const char msg[], int out){
	printf("%s %d euro.\n", msg, out);
}

int main(){
	int norm, extra, oreN, oreE, tot;
	leggiConf("Specificare ore lavorative ordinarie.", &oreN);
	leggiConf("Specificare paga oraria ordinaria.", &norm);
	leggiConf("Specificare ore lavorative straordinarie.", &oreE);
	leggiConf("Specificare paga oraria straordinaria.", &extra);
	calc(norm, extra, oreN, oreE, &tot);
	comunica("La paga di questa giornata sara' di", tot);
return 0;
}
