/**
 * @author Aresu Matteo 4Cinf
 * @version 0.1, Last Update 23/03/2020
 */

/*Nodo

  //attributi variabili
  - next : Nodo
  - p : Processo

  //metodi costruttori
  + Nodo (in p : Processo)
  
  //metodi accessori
  + getNext () : Nodo
  + getProcesso () : Processo
  
  //metodi modificatori
  + setNext (in n : Nodo) : void
  + setPronto () : void
  + esegui (in tempo : int) : boolean 

  //altri metodi
  + toString () : String

*/

//definizione classe
public class Nodo {

    //attributi variabili
    private Nodo next;
    private Processo p;

    //metodi costruttori
    /**
     * Metodo Costruttore
     */
    public Nodo (Processo p) {
	next = null;
	this.p = new Processo (p); //**a mc perche' i controlli stanno dentro il costruttore di copia
    }

    //metodi accessori
    /**
     * Metodo Accessorio Processo
     * @return Il processo
     */
    public Processo getProcesso() { return new Processo (p); }

    /**
     * Metodo Accessorio Next
     * @return Il prossimo nodo
     */
    public Nodo getNext () { return next; }

    //metodi modificatori
    /**
     * Metodo Modificatore next
     * @param next Il prossimo elemento della lista
     */
    public void setNext (Nodo next) { this.next = next; }

    public boolean esegui (int tempo) {
        return p.esegui(tempo);
    }

    public void setPronto () {
	p.setPronto();
    }

    //altri metodi
    /**
     * Metodo Stringa che restituisce lo stato dell'oggetto
     * @return Lo stato dell'oggetto
     */
    public String toString () {
	return p.toString();
    }

}//fine classe

      

