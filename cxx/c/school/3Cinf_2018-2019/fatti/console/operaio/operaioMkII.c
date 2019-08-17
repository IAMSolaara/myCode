/*Lorenzo Cauli 3C 10-12-2018
scopo: comunicare la paga di un giorno di lavoro di un operaio.
dati:
	norm	int	I	norm >= 0
	extra	int	I	extra >= 0
	oreN	int	I	oreN >=0
	oreE	int	I	oreE >=0
	tot	int	O

*/

#include <stdio.h>

void leggiConf(const char msg[], int* in);
void calc(int nrm, int ext, int nrmH, int extH, int* out);
void comunica(const char msg[], int out);

int main(){
	/*definizione variabili*/
	int norm, extra, oreN, oreE, tot;
	/*letture controllate*/
	leggiConf("Specificare ore lavorative ordinarie.", &oreN);
	leggiConf("Specificare paga oraria ordinaria.", &norm);
	leggiConf("Specificare ore lavorative straordinarie.", &oreE);
	leggiConf("Specificare paga oraria straordinaria.", &extra);
	/*calcolo paga*/
	calc(norm, extra, oreN, oreE, &tot);
	/*comunicazione risultato*/
	comunica("La paga di questa giornata sara' di", tot);
return 0;
}

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
