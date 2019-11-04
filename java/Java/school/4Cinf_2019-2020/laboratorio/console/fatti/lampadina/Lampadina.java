/**
@author Lorenzo Cauli
@version 0.1
*/

/* Lampadina
   Attributi:
   - potenza: int, 20..200
   - accesa: boolean
   - fulminata: boolean
   + minP: int
   + maxP: int

   Metodi:
   + Lampadina() // default
   + Lampadina(in p: int)
   + Lampadina(in p: int, s: boolean)
   + Lampadina(in l: Lampadina)
   + getPotenza(): int
   + isAccesa(): boolean
   + isFulminata(): boolean
   - compreso(in x, min, max: int): boolean
   - fulmina(): void
   + toString(): string
 */

import java.util.Random;

public class Lampadina {
    /**Attributo per memorizzare la potenza.*/
    private int potenza;
    /**Attributo per memorizzare lo stato di accensione della lampadina.*/
    private boolean accesa;
    /**Attributo per memorizzare lo stato di fulminio della lampadina*/
    private boolean fulminata;

    public static int minP = 20;
    public static int maxP = 200;
    
    /**
       Costruttore data la potenza.
       @param p Potenza da impostare
     */
    public Lampadina(int p){
	if (compreso(p, minP, maxP)){
	    potenza = p;
	}
	else potenza = minP;
	accesa = false;
	fulminata = false;
    }

    /**
       Costruttore dati potenza e stato di accensione.
       @param p Potenza da impostare
       @param s Stato di accensione da impostare
     */
    public Lampadina(int p, boolean s){
	if (compreso(p, minP, maxP)){
	    potenza = p;
	}
	else potenza = minP;
	accesa = s;
	fulminata = false;
    }

    /**
       Costruttore di copia.
       Verra' copiato lo stato di un altro oggetto Lampadina in quello attuale
       @param l Oggetto da cui copiare lo stato
     */
    public Lampadina(Lampadina l){
	if (l != null){
	    potenza = l.getPotenza();
	    accesa = l.isAccesa();
	    fulminata = l.isFulminata();
	}
	else {
	    potenza = minP;
	    accesa = false;
	    fulminata = false;
	}
    }

    /**Costruttore di default*/
    public Lampadina() {
	potenza = minP;
	accesa = false;
	fulminata = false;
    }

    /**Funzione per restituire la potenza corrente.
       @return La potenza della lampadina
    */
    public int getPotenza(){return potenza;}

    /**Funzione per restituire lo stato di accensione della lampadina.
       @return Stato di accensione della lampadina.
     */
    public boolean isAccesa(){return accesa;}
    
    /**Funzione per restituire lo stato di fulminio della lampadina.
       @return Stato di fulminio della lampadina.
     */
    public boolean isFulminata(){
	fulmina();
	return fulminata;
    }

    /**Funzione per verificare che un valore non sia OOB.
       @param x Valore da verificare
       @param min Estremo minimo
       @param max Estremo massimo
       @return Risultato del confronto. false se OOB, altrimenti true
    */
    private boolean compreso(int x, int min, int max){
	boolean res = true;
	if (x > max || x < min) res = false;
	return res;
    }

    /**Metodo per fulminare la lampadina con RNG.*/
    private void fulmina(){
	if (!fulminata) {
	    Random rng = new Random(System.currentTimeMillis());
	    if (rng.nextBoolean()) fulminata = true;
	    else fulminata = false;
	}
    }

    /**Funzione per restituire lo stato dell'oggetto in una stringa.
       @return Stringa con lo stato dell'oggetto       
     */
    public String toString(){
	String accStr, fulStr;
	
	if (accesa) accStr = "accesa";
	else accStr = "spenta";
	
	if (isFulminata()) fulStr = "fulminata";
	else fulStr = "integra";
	
	return "" + potenza + "W, " + accStr + ", " + fulStr;
    }
}
