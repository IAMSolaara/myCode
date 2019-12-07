/**
 * @author Lorenzo Cauli
 * @version 0.1
 */
/*
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

    public CarrelloConBlocco() {
        super();
        bloccato = true;
    }

    public CarrelloConBlocco(CarrelloConBlocco in) {
        super(in);
        if (in != null) bloccato = in.isBloccato();
        else bloccato = true;
    }

    public boolean carica(int dp) {
        boolean out = true;
        if (!bloccato) {
            if (!compreso(peso+dp, 0, maxPeso)) out = false;
            else peso += dp;
        }
        else out = false;
        return out;
    }

    public boolean isBloccato(){return bloccato;}

    public void blocca(){bloccato = true;}

    public void sblocca(){bloccato = false;}

    public String toString(){
        return super.toString() + ", " +(bloccato ? "Bloccato" : "Sbloccato");
    }

    public boolean equals(Object o){
        boolean out = true;
        if (o != null && o instanceof CarrelloConBlocco) {
            if (!super.equals((Carrello)o) || 
                ((CarrelloConBlocco)o).isBloccato() != bloccato ) out = false;
        }
        return out;
    }
}