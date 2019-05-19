/*Lorenzo Cauli 3C 13-10-2018
Scopo: contare gli alunni maschi e femmine
Dati
	n_alunni	I	int	n_alunni > 0
	ch			I	char
	m			O	int	m > 0
	f			O	int	f > 0
*/
#include<stdio.h>

int main() {
	/*dichiarazione variabili*/
	int n_alunni, m, f, cont; char ch;
	/*richiesta del numero alunni e error check*/
	printf("Inserisca il numero di alunni.\n"); scanf("%d%*c", &n_alunni);
	while (n_alunni < 0) {
		printf("Numero non valido, ne inserisca un altro.\n"); scanf("%d%*c", &n_alunni);
	}
	/*init variabili*/
	cont = 0; m = 0; f = 0;
	/*richiesta del genere dell'alunno e error checking correlati*/
	while (cont < n_alunni) {
		printf("Mi dica se l'alunno è maschio o femmina [m/f].\n"); scanf("%c%*c", &ch);
		while (ch != 'm' && ch != 'f') {
			printf("Il carattere inserito è invalido, ne inserisca un'altro.\n"); scanf("%c%*c", &ch);
		}
		if (ch == 'm') {
			m = m + 1;
		}
		else if (ch == 'f') {
			f = f + 1;
		}
		cont = cont + 1;
	}
	/*comunicazione risultato*/
	printf("Gli alunni maschi sono %d, le alunne femmine sono %d\n", m, f);
	return 0;
}
