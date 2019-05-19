/*Lorenzo Cauli 3C 21-10-2018
scopo: evidenziare l'andamento dell'alunno in relazione a due compiti.
dati:
	n_alunni	I	int	n_alunni > 0
	voto		I	int	0 < voto <= 10
	voto1		I	int	0 < voto1 <= 10
	cont		L	int
*/

#include<stdio.h>
int main() {
	/*dichiaro variabili e init*/
	int voto, voto1, n_alunni, cont;
	voto = voto1 = n_alunni = cont = 0;
	/*richiesta numero alunni e error check*/
	printf("Inserisca il numero degli alunni.\n");
	scanf("%d", &n_alunni);
	while (n_alunni <= 0) {printf("Numero non valido, ne inserisca un'altro.\n"); scanf("%d", &n_alunni);}
	/*richiesta dei due voti per ogni alunno, error check di essi, dichiarazione verdetto e incremento di cont*/
	while (cont < n_alunni) {
		printf("Inserisca il voto del primo compito.\n"); scanf("%d", &voto);
		while (voto <= 0 || voto > 10) {printf("Numero non valido, ne inserisca un'altro.\n"); scanf("%d", &voto);}
		printf("Inserisca il voto del secondo compito.\n"); scanf("%d", &voto1);
		while (voto1 <= 0 || voto1 > 10) {printf("Numero non valido, ne inserisca un'altro.\n"); scanf("%d", &voto1);}
		if (voto1 < voto) {printf("L'alunno ha peggiorato.\n");}
		else if (voto1 > voto) {printf("L'alunno ha migliorato.\n");}
		else if (voto1 = voto) {printf("L'alunno non ha migliorato ne peggiorato.\n");}
		cont = cont + 1;
	}
	return 0;
}
