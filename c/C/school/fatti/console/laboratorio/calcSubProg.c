/*Lorenzo Cauli 3C 19-11-2018

Scopo: eseguire dei calcoli dati due numeri e un tipo di operazione.
Dati
	x	int	I	x >= 0
	y	int	I	y >= 0
	op	char	I	op == '+' || op == '-' || op == '*' || op == '/'
	ris	float	O	ris >=0
*/

#include <stdio.h>

void comunica(float res) {
	printf("Il risultato e' %.2f.\n", res);
}

void chiedi(int* in) {
	printf("Inserisca un numero.\n"); scanf("%d%*c", in);
	while (in < 0) {printf("Numero invalido, ne inserisca un altro.\n"); scanf("%d%*c", in);}
}
void operazione (int n1, int n2, float* res, char op) {
	if (op == '+') {*res=n1+n2;}
	else if (op == '-') {*res=n1-n2;}
	else if (op == '*') {*res=n1*n2;}
	else if (op == '/') {*res=n1/n2;}
}

void chiediOp(char* op) {
	printf("Che operazione devo svolgere? [+,-,*,/]\n"); scanf("%c%*c", op);
	while (*op != '+' && *op != '-' && *op != '*' && *op != '/') {printf("Carattere non valido, inserirne un altro. [+,-,*,/]\n"); scanf("%c%*c", op);}
}


int main() {
	int x,y; float ris; char op; x=y=ris=0;
	chiedi(&x);
	chiedi(&y);
	chiediOp(&op);
	operazione(x, y, &ris, op);
	comunica(ris);
	return 0;
}
