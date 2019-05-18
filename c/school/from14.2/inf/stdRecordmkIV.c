/*Lorenzo Cauli 3C 04-02-2019
scopo: memorizzare in un record diverse informazioni
strutture:
	recStudente
		nome	array 30 char
		cognome	array 30 char
		eta	int		eta >= 6 && eta <= 25
		media	float		media >= 1 && media <= 10
		voti	array 10 int	voti[i] >= 1 && voti[i] <= 10
		nVoti	int		nVoti >= 1 && nVoti <= 10
dati:
	s	I (file)	recStudente
	s	O		recStudente
relazione tra i dati:
	s.media = somma voti / nVoti
*/

#include <stdio.h>
#include <string.h>
#include <readS.h>
#include <stdlib.h>

#define VDIM 30
#define VVDIM 30

typedef struct{
	int giorno;
	int mese;
	int anno;
}tdata;

typedef struct{
	int voto;
	char materia[VDIM+1];
	tdata data;
}tInterr;

typedef struct{			//definizione struttura record
	char nome[VDIM+1];
	char cognome[VDIM+1];
	tdata dataNasc;
	float media;
	int nVoti;
	tInterr interr[VVDIM];
}recStudente;    /* ok mc  */

FILE* fileOpen(const char filename[], const char perm[]);
void fileReadToRecord(recStudente out[], int neff, FILE* file);
void calcMedia(recStudente out[]);
void visual(recStudente stud[], int neff);
void readVoti(FILE* file, recStudente* out);

/* ok mc */
int main(){
	int nStud;
	recStudente studente[VDIM];				//dichiarazione variabile record studente
	FILE* fileStud;						//dichiarazione nome logico file
	fileStud = fileOpen("studente.txt", "r");		//apertura file
	
	fileReadToRecord(studente, nStud, fileStud);		//memorizzazione dati da file
	visual(studente, nStud);				//visualizzazione record
	fclose(fileStud);					//chiusura file
return 0;
}

/*fileOpen, op di elaborazione
scopo: aprire un file
filename, I
perm, I
restituisce il nome logico del file
*/

FILE* fileOpen(const char filename[], const char perm[]){
	FILE* out;					//dichiarazione nome logico temporaneo
	out = fopen(filename, perm);			//apertura file
	if (out == NULL){				//controllo operazione apertura file
		perror("Errore apertura file.\n");	//comunicazione errore apertura file
		exit(-1);				//uscita dal programma
	}
	return out;					//restituzione nome logico
}

/*fileReadToRecord, op di I
scopo: memorizzare in un record i contenuti di un file
out, O
file, I
*/

void fileReadToRecord(recStudente out[], int neff, FILE* file){
	int i=0, k=0;
	while(freadS(file, out[i].nome, VDIM) != EOF) {
	 	freadS(file, out[i].cognome, VDIM);			//lettura cognome da file e memorizzazione nel record
		fscanf(file, "%d", &out[i].dataNasc.giorno);
		fscanf(file, "%d", &out[i].dataNasc.mese);
		fscanf(file, "%d", &out[i].dataNasc.anno);
		fscanf(file, "%d", &out[i].nVoti);
		readVoti(file, &out[i]);
	}
}

/*calcMedia, op di elaborazione
scopo: calcolare la media dei voti memorizzati in un vettore in un record
out, O
*/

void calcMedia(recStudente *out){
	float tmp=0;				//dichiarazione e init variabile temporanea
	int i=0;				//dichiarazione e init variabile indice
	while (i < out->nVoti) {		//ciclo di somma voti
		tmp = tmp + out->voti[i];	//somma tra var temporanea e voto selezionato
		i++;				//incremento indice
	}
	out->media = tmp / out->nVoti;		//memorizzazione risultato media nel record
}

/*visual, op di O
scopo: visualizzare i contenuti di un record
stud, I

*/

void visual(recStudente stud[]){
	int i=0;								//init indice vettore voti
	printf("Lo studente si chiama %s %s.\n", stud.nome, stud.cognome);	//visualizzazione nome e cognome
	printf("Ha %d anni.\n", stud.eta);					//visualizzazione eta'
	printf("Ha come media dei voti %.2f\n", stud.media);			//visualizzazione media
	printf("Questi sono i suoi voti.\n");					//visualizzazione voti
	while (i < stud.nVoti) {						//ciclo visualizzazione voti
		printf("%d\n", stud.voti[i]);					//visualizzazione voto corrente
		i++;								//incremento indice
	}
}

void readVoti(FILE* file, recStudente *out){
	int cont=0;
	while (cont < out->nVoti){
		fscanf(file, "%d", &out->Interr[cont].voto);
		freadS(file, out->Interr[cont].materia, VDIM);
		fscanf(file, "%d", &out->Interr[cont].data.giorno);
		fscanf(file, "%d", &out->Interr[cont].data.mese);
		fscanf(file, "%d", &out->Interr[cont].data.anno);
	}
	
	
}
