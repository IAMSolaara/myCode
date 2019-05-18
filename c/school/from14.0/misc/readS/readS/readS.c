#include "readS.h"

void readS(char* s, int len)
{
  char sf[15]; /*variabile che conterrà la stringa di formattazione*/
  sprintf(sf,"%%%d[^\n]",len); /*predispone la stringa di formattazione*/
  scanf(sf,s); /*acquisisce la stringa di len caratteri*/
  while(getchar()!= '\n' ); /*rimuove dal buffer di stdin il carattere \n ed eventuali caratteri in eccesso*/

}


int freadS(FILE* f, char* s, int len)
{
  char sf[15];
  char c;
  int r;

  sprintf(sf,"%%%d[^\n]",len);
  sprintf(s,"");
  r = fscanf(f,sf,s) ;
  if( r!=EOF )
    while( fscanf(f,"%c",&c)!=EOF && c!='\n' );
  return r;
}
