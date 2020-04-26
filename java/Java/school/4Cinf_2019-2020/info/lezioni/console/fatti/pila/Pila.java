/**
    @author Lorenzo Cauli
    @version 0.1 09/03/2020
 */

/* Pila
    - head: Nodo

    + Pila()

    + push(in p: Punto): boolean
    + pop(): Punto
*/

public class Pila {
    private Nodo head;

    /**Costruttore senza parametri */
    public Pila() {
        head = null;
    }

    /**Metodo che aggiunge un punto in testa.
     *  @param p Riferimento a oggetto Punto
     *  @return true se il parametro e' valido, false se non lo e'
     */
    public boolean push(Punto p) {
        boolean out = true;
        if (p == null) out = false;
        else {
            Nodo n = new Nodo(p);
            n.setNext(head);
            head = n;
        }
        return out;
    }

    public Punto pop() {
        Nodo n = head;
        Punto out = null;

        if (head != null) {
            head = head.getNext();
            n.setNext(null);
            out = n.getPunto();
        }
        return out;
    }

}