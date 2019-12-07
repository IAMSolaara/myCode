/**
 * @author Lorenzo Cauli
 * @version 0.1
 */

/*
 * + maxPeso = 200: static final int # peso: int
 * 
 * + Carrello() + Carrello(in in: Carrello)
 * 
 * + getPeso(): int + carica(in dp: int): boolean
 * 
 * # compreso(in v, min, max): boolean
 * 
 * + toString(): String + equals(in o: Object): boolean
 */
public class Carrello {
    public static final int maxPeso = 200;
    protected int peso;

    /**
     * Costruttore di default.
     */
    public Carrello() {
        peso = 0;
    }

    /**
     * Costruttore di copia.
     * 
     * @param in Riferimento a oggetto Carrello.
     */
    public Carrello(Carrello in) {
        if (in != null)
            peso = in.getPeso();
        else
            peso = 0;
    }

    /**
     * Metodo che restituisce il peso.
     * 
     * @return Il peso corrente del carrello.
     */
    public int getPeso() {
        return peso;
    }

    /**
     * Metodo che carica un determinato peso.
     * 
     * @param dp Il peso da caricare.
     * @return true se il param e' valido, false se non lo e'
     */
    public boolean carica(int dp) {
        boolean out = true;

        if (!compreso(peso + dp, 0, maxPeso))
            out = false;
        else
            peso += dp;

        return out;
    }

    /**
     * Metodo che controlla se un valore e' entro i limiti.
     * 
     * @param v   Valore da controllare
     * @param min Estremo minimo.
     * @param max Estremo massimo.
     * @return true se il valore e' entro i limiti, false se non lo e'
     */
    protected boolean compreso(int v, int min, int max) {
        boolean out = true;
        if (v < min || v > max)
            out = false;
        return out;
    }

    /**
     * Metodo che restituisce lo stato dell'oggetto in una stringa.
     * 
     * @return Una stringa.
     */
    public String toString() {
        return "Peso corrente: " + peso;
    }

    /**
     * Metodo che confronta lo stato di quest' oggetto con quello di un altro.
     * 
     * @param o Riferimento a oggetto Object
     * @return true se sono uguali, false se sono diversi
     */
    public boolean equals(Object o) {
        boolean out = true;
        if (o != null && o instanceof Carrello) {
            if (((Carrello) o).getPeso() != peso)
                out = false;
        } else
            out = false;
        return out;
    }
}