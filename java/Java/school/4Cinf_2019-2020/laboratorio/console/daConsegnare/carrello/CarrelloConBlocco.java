/**
 * @author Lorenzo Cauli
 * @version 0.1
 */
/*
    CarrelloConBlocco ext Carrello
    - bloccato: boolean

    + CarrelloConBlocco()
    + CarrelloConBlocco(in in: CarrelloConBlocco)

    + carica(int dp): boolean

    + isBloccato(): boolean

    + blocca(): void
    + sblocca(): void

    + toString(): String
    + equals(Object o): boolean
 */

public class CarrelloConBlocco extends Carrello {
    private boolean bloccato;

    /**
     * Costruttore di default.
     */
    public CarrelloConBlocco() {
        super();
        bloccato = true;
    }

    /**
     * Costruttore di copia.
     * @param in Riferimento a oggetto CarrelloConBlocco
     */
    public CarrelloConBlocco(CarrelloConBlocco in) {
        super(in);
        if (in != null) bloccato = in.isBloccato();
        else bloccato = true;
    }

    /**
     * Metodo che carica del peso.
     * @param dp Il peso da sommare al carrello.
     * @return true se l'operazione e' andata bene, false se no.
     */
    public boolean carica(int dp) {
        boolean out = true;
        if (!bloccato) {
            out = super.carica(dp);
        }
        else out = false;
        return out;
    }

    /**
     * Metodo che restituisce bloccato.
     * @return bloccato.
     */
    public boolean isBloccato(){return bloccato;}

    /**Metodo che blocca il carrello. */
    public void blocca(){bloccato = true;}

    /**Metodo che sblocca il carrello. */
    public void sblocca(){bloccato = false;}

    public boolean preleva(){
        return super.preleva();
    }

    /**
     * Metodo che restituisce una stringa.
     * @return Lo stato dell'oggetto.
     */
    public String toString(){
        return super.toString() + ", " +(bloccato ? "Bloccato" : "Sbloccato");
    }

    /**
     * Metodo che confronta lo stato di due oggetti.
     * @param o Riferimento a oggetto Object
     * @return true se sono uguali, false se sono diversi.
     */
    public boolean equals(Object o){
        boolean out = true;
        if (o != null && o instanceof CarrelloConBlocco) {
            if (!super.equals((Carrello)o) || 
                ((CarrelloConBlocco)o).isBloccato() != bloccato ) out = false;
        }
        return out;
    }
}