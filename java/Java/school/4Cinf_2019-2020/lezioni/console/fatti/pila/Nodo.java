/**
 * @author Cauli Lorenzo
 * @version 3/3/2020
 */

/*Nodo
  - p: Punto
  - next: Nodo

  + Nodo(in p: Punto)

  + getNext(): Nodo
  + setNext(in next: Nodo): void

  + toString(): String
  + trasla(in dx, dy: double): void
 */

public class Nodo {
    private Punto p;
    private Nodo next;

    /**
     * Costruttore dato un punto.
     * @param p Riferimento a oggetto Punto
     */
    public Nodo(Punto p) {
	next = null;
	this.p = new Punto(p); //controlli fatti dal punto
    }

    /** 
     *  Metodo accessorio.
     *	@return Riferimento al prossimo nodo
     */
    public Nodo getNext() {return next;}

    /**
     * Metodo modificatore.
     * @param next Riferimento al nuovo prossimo nodo.
     */
    public void setNext(Nodo next) {this.next = next;}
    
    public Punto getPunto() {return new Punto(p);}

    /**
     * Metodo che restituisce lo stato dell'oggetto in una stringa
     * @return una stringa
     */
    public String toString() {
        return p.toString();
    }

    /**
     * Metodo che trasla il proprio punto.
     * @param dx Delta X
     * @param dy Delta Y
     */
    public void trasla(double dx, double dy) {
	p.trasla(dx, dy);
    }
}
