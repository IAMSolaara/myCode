/*Nome:Marras Alessio 
  Classe: 3C 
  Data: 15/11/2018
  Scopo: Progettare e realizzare un programma in c che esegua e visualizzi un'operazione

  Dati
  n1           I    decimale  
  n2           I    decimale
  risultato    O    decimale
  operazione   I    carattere
*/
/*direttive al preprocessore*/

 #include<stdio.h>
  int main () {

    /*prototipi*/
    void leggi(const char msg[],float* n1 );
    void operazione(float n1,float n2,float* ris );
    void comunica 



    /*sezione dichiarativa*/
    float n1,n2;
    float risultato;
    char operazione;
    /*sezione esecutiva*/
      printf("Inserisci il primo numero ");
      scanf("%f%*c",&n1);
     
      printf("Inserisci il carattere ");
      scanf("%c%*c",&operazione);
     
      printf("Inserisci il secondo numero ");
      scanf("%f%*c",&n2);
     
      if (operazione=='+') {
	risultato=n1+n2;
      }
      if (operazione=='-'){
	risultato=n1-n2;
      }
      if(operazione=='*'){
	risultato=n1*n2;
      }
      if (operazione=='/'){
	risultato=n1/n2;
      }
     
      printf("Il risultato e: %.3f\n",risultato);


      return 0;
  }/*main*/
