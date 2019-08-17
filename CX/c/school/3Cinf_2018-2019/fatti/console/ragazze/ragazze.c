/*Lorenzo Cauli 3C 11-05-2018

scopo: Dire se la media di una studentessa è buona, ottima o insufficiente

dati:

	inMedia	int	I	inMedia > 0 && inMedia <= 10
	nAlunni	int	I	nAlunni > 14 && nAlunni <= 30
	inGen	char	I	inGen == 'm' || inGen == 'f'
	good	int	O	good >= 0
	ins	int	O	ins >= 0
	ott	int	O	ott >= 0
*/


#include<stdio.h>
#define MINALUNNI 15
#define MAXALUNNI 30

int main() {
	int nAlunni, nRagazze, cont, ins, ott, good, inMedia; char inGen;
	cont=nAlunni=ins=ott=good=inMedia=0;
	printf("Inserisca un numero di alunni compreso tra 15 e 30.\n"); scanf("%d%*c", &nAlunni);
	while (nAlunni < MINALUNNI || nAlunni > MAXALUNNI) {printf("Il numero inserito non e' valido, inserirne un'altro.\n"); scanf("%d%*c", &nAlunni);}
	while (cont < nAlunni) {
		printf("L'alunno e' maschio o femmina?"); scanf("%c%*c", &inGen);
		while (inGen != 'm' && inGen != 'f') {printf("Il carattere inserito non e' valido, ne inserisca un'altro.\n"); scanf("%c%*c", &inGen);}
		if (inGen == 'f') {printf("Inserisca la media dell'alunna.\n"); scanf("%d%*c", &inMedia);
			while (inMedia < 0 || inMedia > 10) {printf("Il numero inserito non e' valido, ne inserisca un'altro.\n"); scanf("%d%*c", &inMedia);}
			if (inMedia >= 1 && inMedia < 6) {ins = ins+1;}
			else if (inMedia >= 6 && inMedia < 9) {good = good+1;}
			else if (inMedia == 9 || inMedia == 10) {ott = ott+1;}
		}
		cont = cont+1;
	}
	printf("Vi sono %d ragazze con media insufficiente, %d ragazze con media buona e %d ragazze con media ottima.\n", ins, good, ott);
return 0;
}
