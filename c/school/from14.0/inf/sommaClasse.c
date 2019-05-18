#include <stdio.h>

void leggi( const char msg[], float* a );
void somma( float n1, float n2, float* ris );
void comunica( const char msg[], float num );

int main()
{
  float x,y,r;
  leggi("Inserire primo numero: ", &x);
  leggi("Inserire secondo numero: ", &y);
  somma( x, y, &r );
  comunica("Il risultato vale ", r );
  return 0;
}

void leggi( const char msg[], float* a ) /*intestazione della procedura*/
{
  printf("%s",msg);
  scanf("%f", a); /* non si mette & perche' a e' gia' un indirizzo */
} /* leggi */

void somma( float n1, float n2, float* ris ){
  *ris = n1+n2;
} /*somma*/


void comunica( const char msg[], float num ){
  printf("%s %f\n",msg,num);
} /* comunica */
