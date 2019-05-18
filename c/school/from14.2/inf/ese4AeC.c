/*Aresu Matteo, Cao Riccardo 3Cinf 08/01/2019
scopo: filtrare i voti di una classe scolastica e dire quante persone hanno preso un determinato voto

dati:
voti      vet di 30 int   voti[cont]>=0 && voti[cont]<=10
nAlunni   int   I   nAlunni>=1 && nAlunni<=10
votoRI    int   I   votoRI>=0 && votoRI<=10
votoRO    int   O   votoRO>=0

relazione tra i dati:

*/

/*direttive al preprocessore*/
#include <stdio.h>

/*inizializzazione delle costanti*/
#define DIM 30
#define MIN 0
#define MAX 10

/*prototipi*/
void leggiComp(const char msg[], int*alunni, int dim, int min);
void leggiVoti(const char msg[], int*voti, int min, int max);
void carica(int vet[], int alunni);

/*inizio main*/
int main() {
  
  /*sezione dichiarativa*/
  int voti[DIM];
  int nAlunni, votoRI, votoRO;

  /*sezione esecutiva*/
  
  /*lettura compresa numero di alunni*/
  leggiComp("Inserisci il numero degli alunni: ", &nAlunni, DIM, MIN);
  
  /*lettura voti*/
  carica(voti, nAlunni);

  /*filtro voti*/
  



return 0;
}

void leggiComp(const char msg[], int*alunni, int dim, int min)
{
  min=0;
  dim=30;
  printf("%s", msg);
  scanf("%d%*c", alunni);
  while (*alunni<min || *alunni>dim) {
    printf("Inserire un numero di alunni valido");
    scanf("%d%*c", alunni);
  }
}

void leggiVoti(const char msg[], int*voti, int min, int max)
{
  min=0;
  max=10;
  printf("%s", msg);
  scanf("%d%*c", voti);
  while (*voti<min || *voti>max) {
    printf("Inserire un voto valido");
    scanf("%d%*c", voti);
  }
}

void carica(int vet[], int alunni)
{
  /*sezione dichiarativa*/
  int cont;
  
  /*azzeramento contatore*/
  cont=0;
  
  /*sezione esecutiva*/
  while (alunni<cont) {
    leggiVoti("Inserire voto: ", &vet[cont], MIN, MAX);
    cont++;
  }
}

void calcola(int vet[], int votoi, int*votoo)
{
  while(vet[]==votoi){
    

}
