/**
 * @author Lorenzo Cauli
 * @version 0.1
 */

/*
 * + MAXPESO = 200: static final int 
 * - peso: int
 * - prelevato: boolean
 * 
 * + Carrello() 
 * + Carrello(in in: Carrello)
 * 
 * + getPeso(): int 
 * + isPrelevato(): boolean
 * + carica(in dp: int): boolean
 * 
 * - compreso(in v, min, max): boolean
 * 
 * + toString(): String 
 * + equals(in o: Object): boolean
 */
public class Carrello {
    public static final int MAXPESO = 200;
    private int peso;
    private boolean prelevato;

    /**
     * Costruttore di default.
     */
    public Carrello() {
        peso = 0;
        prelevato = false;
    }

    /**
     * Costruttore di copia.
     * 
     * @param in Riferimento a oggetto Carrello.
     */
    public Carrello(Carrello in) {
        if (in != null){
            peso = in.getPeso();
            prelevato = in.isPrelevato();
        }
        else {
            peso = 0;
            prelevato = false;
        }
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
     * Metodo che restituisce prelevato.
     * @return Prelevato.
     */
    public boolean isPrelevato(){
        return prelevato;
    }

    /**
     * Metodo che preleva il carrello.
     */
    public boolean preleva(){
        prelevato = true;
        return true;
    }

    /**
     * Metodo che deposita il carrello.
     */
    public void deposita(){
        prelevato = false;
    }

    /**
     * Metodo che carica un determinato peso.
     * 
     * @param dp Il peso da caricare.
     * @return true se il param e' valido, false se non lo e'
     */
    public boolean carica(int dp) {
        boolean out = true;
        if (prelevato) {
            if (dp > 0) {
                if (compreso(peso + dp, 0, MAXPESO)){
                    peso += dp;                
                }
                else{
                    out = false;
                }
            }
            else out = false;
        }
        else out = false;

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
    private boolean compreso(int v, int min, int max) {
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
        return "Peso corrente: " + peso + ", " + (prelevato ? "Prelevato" : "Non prelevato");
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
            if (((Carrello) o).getPeso()     != peso         ||
                ((Carrello) o).isPrelevato() != prelevato  )
                out = false;
        } else
            out = false;
        return out;
    }
}