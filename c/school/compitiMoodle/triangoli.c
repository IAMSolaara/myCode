/*Lorenzo Cauli 3C 04-11-2018

scopo: Dire se un triangolo e' di un determinato tipo data la somma dei suoi angoli.

dati:

	ang1	int	I	ang1 > 0
	ang2	int	I	ang2 > 0
	ang3	int	I	ang3 > 0
	nTria	int	I	nTria > 0
	eucl	int	O	eucl >= 0
	iper	int	O	iper >= o
	ellit	int	O	ellit >= 0



*/


#include<stdio.h>

int main() {
	int ang1, ang2, ang3, nTria, cont, angSum, eucl, iper, ellit;
	ang1=ang2=ang3=nTria=cont=angSum=eucl=iper=ellit=0;
	printf("Inserisca il numero di triangoli.\n"); scanf("%d", &nTria);
	while (nTria <= 0) {printf("Il numero inserito non e' valido, ne inserisca un altro.\n"); scanf("%d", &nTria);}
	while (cont < nTria) {
		printf("Inserisca il primo angolo.\n"); scanf("%d", &ang1);
			while (ang1 <= 0) {printf("Il numero inserito non e' valido, ne inserisca un altro.\n"); scanf("%d", &ang1);}
		printf("Inserisca il secondo angolo.\n"); scanf("%d", &ang2);
			while (ang2 <= 0) {printf("Il numero inserito non e' valido, ne inserisca un altro.\n"); scanf("%d", &ang2);}
		printf("Inserisca il terzo angolo.\n"); scanf("%d", &ang3);
			while (ang3 <= 0) {printf("Il numero inserito non e' valido, ne inserisca un altro.\n"); scanf("%d", &ang3);}
		angSum=ang1+ang2+ang3;
		if (angSum == 180) {eucl=eucl+1;}
		else if (angSum > 180) {ellit=ellit+1;}
		else if (angSum < 180) {iper=iper+1;}
		angSum=0;
		cont = cont+1;
	}
	printf("Vi erano %d triangoli euclidei, %d triangoli ellittici e %d triangoli iperbolici.\n", eucl, ellit, iper);
return 0;
}
