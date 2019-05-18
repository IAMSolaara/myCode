/*Lorenzo Cauli 3C 19-03-2019 Verifica di informatica
scopo:	disporre in modo casuale degli elementi in una matrice e infine contare quanti di ciascun elemento sono contenuti in suddetta matrice
dati:
	giardino	O	mat 4x6 char	giardino == 'p' || giardino == 's' || giardino == 'r' || giardino == 't'
	nPrez		O	int		nPrez >= 0
	nSalv		O	int		nSalv >= 0
	nRosm		O	int		nRosm >= 0
	nTimo		O	int		nTimo >= 0

relazione tra i dati:
	if giardino[i][j]=='p' ===> nPrez++;
	if giardino[i][j]=='s' ===> nSalv++;
	if giardino[i][j]=='r' ===> nRosm++;
	if giardino[i][j]=='t' ===> nTimo++;
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MDIM  4		//definizione numero righe
#define VDIM  6		//definizione numero colonne

void init(char out[][VDIM]);
void count(char field[][VDIM], int* p, int* s, int* r, int* t);
void visual(const char msg[], char field[][VDIM], int p, int s, int r, int t);

int main(){
	srand(time(NULL));								//init generatore casuale
	char giardino[MDIM][VDIM];							//dichiarazione matrice giardino
	int nPrez=0, nSalv=0, nRosm=0, nTimo=0;						//dichiarazione variabili per contare le varie piante
	init(giardino);									//init matrice
	count(giardino, &nPrez, &nSalv, &nRosm, &nTimo);				//conteggio delle singole piante
	visual("Questo è il giardino alla fine.", giardino, nPrez, nSalv, nRosm, nTimo);//stampa risultato finale
return 0;
}

/*init, op di elaborazione
scopo: inizializzare la matrice a caratteri casuali
dati:
	out, mat 4x6 char, O, out[i][j] == 'p' || out[i][j] == 's' || out[i][j] == 'r' || out[i][j] == 't'

*/

void init(char out[][VDIM]){
	char selector[]={'p', 's', 'r', 't'};	//dichiarazione e init vettore selettore per assegnare pianta alla matrice
	int sel=0;				//dichiarazione indice selettore per vettore selettore
	int i=0, j;				//dichiarazione indici matrice
	while (i<MDIM){				//ciclo righe
		j=0;				//azzeramento indice ciclo colonne
		while(j<VDIM){			//ciclo colonne
			sel=rand()%4;		//assegnamento a indice selettore di numero casuale tra 0 e 3
			out[i][j]=selector[sel];//assegnamento al corrente elemento della matrice di elemento casuale tramite vettore selettore
			j++;			//incremento indice ciclo colonne
		}
		i++;				//incremento indice ciclo righe
	}
}

/*count, op di elaborazione
scopo: contare quanti singoli elementi di un determinato tipo ci sono nella matrice
dati:
	field, mat 4x6 char, I, field[i][j] == 'p' || field[i][j] == 's' || field[i][j] == 'r' || field[i][j] == 't'
	p, int, O, p >= 0
	s, int, O, s >= 0
	r, int, O, r >= 0
	t, int, O, t >= 0
*/

void count(char field[][VDIM], int* p, int* s, int* r, int* t){
	int i=0, j;						//dichiarazione indici matrice
	while (i<MDIM){						//ciclo righe
		j=0;						//azzeramento indice ciclo colonne
		while (j<VDIM){					//ciclo colonne
			if (field[i][j] == 'p') *p=*p+1;	//incremento prezzemolo se e' trovato l'elemento p
			else if (field[i][j] == 's') *s=*s+1;	//incremento salvia se e' trovato l'elemento s
			else if (field[i][j] == 'r') *r=*r+1;	//incremento rosmarino se e' trovato l'elemento r
			else if (field[i][j] == 't') *t=*t+1;	//incremento timo se e' trovato l'elemento t
			j++;					//incremento indice ciclo colonne
		}
		i++;						//incremento indice ciclo righe
	}
}

/*visual, op di output
scopo: visualizzare quanti elementi sono stati trovati e visualizzare la matrice
dati:
	msg, vet char, I
	field, mat 4x6 char, I, field[i][j] == 'p' || field[i][j] == 's' || field[i][j] == 'r' || field[i][j] == 't'
	p, int, O, p >= 0
	s, int, O, s >= 0
	r, int, O, r >= 0
	t, int, O, t >= 0
*/
void visual(const char msg[], char field[][VDIM], int p, int s, int r, int t){
	int i=0, j;												//dichiarazione indici matrice
	printf("%s\n", msg);											//stampa messaggio
	printf("Ci sono %d piante di prezzemolo, %d di salvia, %d di rosmarino e %d di timo.\n", p, s, r, t);	//stampa altro messaggio
	printf("/-----------\\\n");										//stampa inizio tabella
	while(i<MDIM){												//ciclo righe
		j=0;												//azzeramento indice ciclo colonne
		while(j<VDIM){											//ciclo colonne
			printf("|%c", field[i][j]);								//stampa elemento della matrice corrente
			j++;											//incremento indice ciclo colonne
		}
		printf("|");											//stampa fine riga
		if (i < MDIM-1) printf("\n|-----------|");							//stampa separatore righe
		printf("\n");											//andata a capo a fine riga
		i++;												//incremento indice ciclo righe
	}
	printf("\\-----------/\n");										//stampa fine tabella

}
