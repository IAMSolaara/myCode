/* Lorenzo Cauli 3C	26-09-2018 */
#include<stdio.h>

int main() {
	int a,b;
	char op;
	float res;
	a = 0; b = 0;
	printf("Immettere un numero\n");
	scanf("%d%*c",&a);
	printf("Immetterne un altro\n");
	scanf("%d%*c",&b);
	printf("Immettere un operatore\n");
	scanf("%c%*c",&op);
	while (op != '+' && op != '-' && op != '*' && op != '/') {
		printf("Operatore invalido, inserirne un altro\n");
		scanf("%c%*c",&op);
	}
	if (op == '+') {
	res = a + b;
	}
	if (op == '-') {
        res = a - b;
        }

	if (op == '/') {
	        if (a != 0 && b == 0) {
		printf("Divisione impossibile\n");
		}
	else {
		if (a == 0 && b == 0) {
		printf("Divisione indeterminata");
	}
	else {
		if (a != 0 && b != 0) {
		res = a / b;
		}
	}
	}
	}
	if (op == '*') {
        res = a * b;
        }
	printf("%.2f\n",res);
	return 0;
}
