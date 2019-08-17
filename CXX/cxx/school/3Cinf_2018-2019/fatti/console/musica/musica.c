/*Lorenzo Cauli 3C 28-10-2018
	scopo: stabilire quanti corsi fare e come organizzarli.

Dati:
	n_Alunni	I	int	n_Alunni >= 0 && n_Alunni < 100
*/

#include<stdio.h>

int main() {
	int n_Alunni;
	printf("Inserisca il numero degli alunni tra i 16 e i 18 anni.\n"); scanf("%d", &n_Alunni);
	while (n_Alunni > 100 || n_Alunni < 0) {printf("Il numero non e' valido, ne inserisca un'altro.\n"); scanf("%d", &n_Alunni);}
	if (n_Alunni < 15) {printf("Non verra' organizzato alcun corso.\n");}
	else if (n_Alunni >= 15 && n_Alunni <= 30) {printf("Verra' organizzato un solo corso.\n");}
	else if (n_Alunni >= 31 && n_Alunni < 60) {printf("Verranno organizzati due corsi.\n");}
	else if (n_Alunni >= 61) {printf("Verranno organizzati due corsi ma ci sarà una selezione.\n");}
	return 0;
}
