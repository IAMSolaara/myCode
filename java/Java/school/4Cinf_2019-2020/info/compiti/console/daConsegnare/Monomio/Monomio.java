/**
   @author Lorenzo Cauli
   @version 1.0
 */

/*
- exp: int       >=0
- coeff: double

+ Monomio()  //default
+ Monomio(in exp: int)
+ Monomio(in coeff: double)
+ Monomio(in coeff: double, exp: int)
+ Monomio(in in: Monomio)  //costr. di copia

+ getExp(): int
+ getCoeff(): double

+ valuta(in val: double): double
+ moltiplica(in in: Monomio): boolean
+ somma(in in: Monomio): boolean

+ toString(): String
+ equals(in o: Object): boolean

 */

public class Monomio {
    private int exp;
    private double coeff;

    /**Costruttore di default.*/
    public Monomio() {
        coeff = 1;
        exp = 1;
    }

    /**Costruttore dato l'esponente.
       @param exp Esponente del monomio
     */
    public Monomio(int exp) {
        if (exp >= 0) this.exp = exp;
        else this.exp = 1;
        coeff = 1;
    }

    /**Costruttore dato il coefficente.
       @param coeff Coefficente incognita del monomio
     */
    public Monomio(double coeff) {
        this.coeff = coeff;
        exp = 1;
    }

    /**Costruttore dati coefficente e esponente.
       @param exp Esponente del monomio
       @param coeff Coefficente incognita del monomio
     */
    public Monomio (double coeff, int exp) {
        if (exp >= 0) this.exp = exp;
        else this.exp = 1;
        this.coeff = coeff;
    }

    /**Costruttore di copia.
       @param in Riferimento a oggetto Monomio
     */
    public Monomio(Monomio in) {
        if (in != null) {
            exp = in.getExp();
            coeff = in.getCoeff();
        }
        else {
            exp = 1;
            coeff = 1;
        }
    }

    /**Metodo che restituisce l'esponente.
       @return L'esponente
     */
    public int getExp(){return exp;}

    /**Metodo che restituisce il coefficente
       @return Il coefficente
     */
    public double getCoeff(){return coeff;}

    /**Metodo che valuta un monomio dato un valore da assegnare all'incognita x.
       @param val Valore da assegnare alla x
       @return Il valore del monomio data una x
     */
    public double valuta(double val) {return coeff * Math.pow(val, exp);}

    /**Metodo che moltiplica questo monomio per un altro.
       @param in Riferimento a oggetto Monomio
       @return true se il riferimento dato e' valido, false se non lo e'
     */
    public boolean moltiplica(Monomio in) {
        boolean out = true;
        if (in != null) {
            exp *= in.getExp();
            coeff *= in.getCoeff();
        }
        else out = false;
        return out;
    }

    /**Metodo che somma questo monomio con un altro.
       @param in Riferimento a oggetto Monomio
       @return true se il riferimento dato e' valido, false se non lo e'
     */
    public boolean somma(Monomio in) {
        boolean out = true;
        if(in != null) {
            if (in.getExp() == exp) {
                coeff += in.getCoeff();
            }
            else out = false;
        }
        else out = false;
        return out;
    }

    /**Metodo che restituisce lo stato dell'oggetto in una stringa
       @return Stringa che contiene lo stato dell'oggetto
     */
    public String toString(){
        return "" + coeff + "x^" + exp;
    }

    /**Metodo che confronta lo stato di questo oggetto con un'altro.
       @param o Riferimento a oggetto da comparare
       @return true se gli stati sono uguali, false se non lo sono
    */
    public boolean equals(Object o){
        boolean out = true;
        if (o != null && o instanceof Monomio){
            if ( ((Monomio)o).getExp() != exp &&  ((Monomio)o).getCoeff() != coeff) out = false;
        }
        else out = false;
        return out;
    }

}
