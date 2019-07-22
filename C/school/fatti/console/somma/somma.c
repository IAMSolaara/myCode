/*
  analisi: vedi quaderno (inizio anno)
  

 */

/* direttive al preprocessore */
#include <stdio.h>

/* prototipi */
void leggi( const char msg[], float* a );
void somma( float n1, float n2, float* ris );
void comunica( const char msg[], float num );

/*funzione main*/
int main()
{
  /*sezione dichiarativa*/
  float x,y,r;

  /*sezione esecutiva*/

  /*lettura primo numero*/
  leggi("Inserire primo numero: ", &x);

  /*lettura secondo numero*/
  leggi("Inserire secondo numero: ", &y);

  /*somma dei numeri*/
  somma( x, y, &r );

  /*comunicazione del risultato*/
  comunica("Il risultato vale ", r );

  return 0;
}


/* definizione dei sottoprogrammi */

/*
  leggi: operazione di Input
  scopo: chiedere un numero all'esterno
  msg parametro di I
  a   parametro di O
*/
void leggi( const char msg[], float* a ) /*intestazione della procedura*/
{
  /* sezione esecutiva */
  printf("%s",msg);
  scanf("%f", a); /* non si mette & perche' a e' gia' un indirizzo */
} /* leggi */


/*
  somma: operazione di Elaborazione
  scopo: sommare due numeri
  n1  parametro di I
  n2  parametro di I
  ris parametro di O
*/
void somma( float n1, float n2, float* ris )
{
  *ris = n1+n2;
} /*somma*/


/*
  comunica: operazione di Output
  scopo: comunicare un numero
  msg parametro di I
  num parametro di I
*/
void comunica( const char msg[], float num )
{
  printf("%s %f\n",msg,num);
} /* comunica */


/*
  Nei parametri di output, e' necessario indicare l'indirizzo, 
  in modo che il sottoesecutore sappia dove andare a depositare 
  il dato
  Per ottenere l'indirizzo di una variabile di tipo numerico o 
  carattere, si usa l'operatore di indirizzamento &
  esempio:
  scanf ( "%d", &num );

  sottoprogramma = porzione di codice che risolve un sottoproblema
  ed e' eseguita da un sottoesecutore

  chiamata di un sottoprogramma = richiesta di esecuzione del
  sottoprogramma

  definizione di un sottoprogramma = parte di codice che contiene
  le istruzioni che fanno parte del sottoprogramma

  Classificazione dei sottoprogrammi
  1) Sottoprogramma di Input = riceve dati dall'esterno 
  2) Sottoprogramma di Ouput = comunicano dati all'esterno
  3) Sottoprogrammi di Elaborazione = effettuano una elaborazione e
  NON comunicano con l'esterno

  Parametri Attuali = compaiono nelle chiamate dei sottoprogrammi
  possono essere variabili o costanti

  Parametri formali = compaiono nella definizione dei sottoprogrammi
  sono SEMPRE VARIABILI, in cui al momento della chiamata verrà
  copiato il valore di quel particolare parametro attuale passato
  in quel momento

  I parametri formali e attuali devono avere: 
  stesso numero,
  stesso tipo,
  stessa direzione,
  stesso  ordine
  nome diverso

  Nei parametri attuali NON si indica il tipo
  Nei parametri formali si indica il tipo

  Per svolgere lo stesso compito su parametri di tipo diverso,
  l'esecutore deve chiamare due sottoesecutori diversi
  Per esempio: comunicaF, comunicaI

*/

