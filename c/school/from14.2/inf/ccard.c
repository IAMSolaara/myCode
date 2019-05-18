/**/
#include <stdio.h>
#include <readS.h>

#define VDIM 15
#define IDIM 50
#define BDIM 719

typedef struct {
	int day;
	int month;
	int year;
}tData;

typedef struct {
	char nome[VDIM];
	char cognome[VDIM];
	char ind[IDIM];
	tData bDate;
}tPerson;

typedef struct {
	float price;
	tData data;
}tAcquisti;

typedef struct {
	char id[VDIM];
	char tipo[VDIM];
	tData expDate;
	tPerson intestatario;
	int nAcquisti;
	tAcquisti acquisti[BDIM];
	int tot;
}tCCard;

void leggiComp(const char msg[], int* out, int min, int max);
void cardRead(const char msg[], tCCard cards[], int nc);
void dataRead(tData* out);
void personRead(tPerson* out);
void payRead(tAcquisti out[], int neff);

int main(){
	tCCard cards[BDIM];
	int nCarte;
	leggiComp("Quante carte sono da registrare?\n", &nCarte, 0, BDIM);
	cardRead("Inserisca i dati della carta numero", cards, nCarte);
	
	
	
	
return 0;
}

void leggiComp(const char msg[], int* out, int min, int max){
	printf("%s", msg);				//stampa messaggio
	scanf("%d%*c", out);				//lettura controllata numero
	while (*out < min || *out > max){
		printf("Numero invalido, ritenta.\n");
		scanf("%d", out);
	}
}

void cardRead(const char msg[], tCCard cards[], int nc){
	int i=0, i2;
	while (i < nc) {
		i2=i+1;
		printf("%s %d.\n", msg, i2);
		printf("Inserisca il numero della carta.\n");
		readS(cards[i].id, VDIM);
		printf("\nSpecifichi il tipo della carta.\n");
		readS(cards[i].tipo, VDIM);
		printf("\nSpecifichi la data di scadenza della carta.\n");
		dataRead(&cards[i].expDate);
		printf("\nSpecifichi i dettagli dell'intestatario.\n");
		personRead(&cards[i].intestatario);
		printf("\nQuanti acquisti sono stati effettuati con questa carta?\n");
		scanf("%d%*c", &cards[i].nAcquisti);
		printf("\nLi descriva tutti.\n");
		payRead(cards[i].acquisti, cards[i].nAcquisti);
		i++;
	}
}

void dataRead(tData* out){
	printf("Specifichi la data in formato giorno mese anno.\n");
	scanf("%d%*c", &out->day);
	scanf("%d%*c", &out->month);
	scanf("%d%*c", &out->year);
}

void personRead(tPerson* out){





}

void payRead(tAcquisti out[], int neff){}
