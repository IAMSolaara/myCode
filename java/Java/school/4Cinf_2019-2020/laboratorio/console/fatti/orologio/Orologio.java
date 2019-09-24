/**
 * @author Lorenzo Cauli
 * @version 1.0
 */

/* Orologio
   Attributi:
   - ore : int, 0..23
   - minuti : int, 0..59
   - secondi : int, 0..59
   Metodi:
   + Orologio(in o,m,s : int)
   + Orologio(in o,m : int)
   + Orologio(in o : int)
   + Orologio()      //COSTRUTTORE DI DEFAULT
   + getOre() : int
   + getMinuti() : int
   + getSecondi() : int
   + regola(in o,m,s : int) : boolean
   + avanza() : void
   - normalizza() : void
   - compreso(in x, min, max : int) : boolean
*/

public class Orologio {
    private int ore;
    private int minuti;
    private int secondi;

    Orologio(int inOre, int inMin, int inSec) {
	if (!regola(inOre, inMin, inSec)){
	    secondi = minuti = ore = 0;
	}
    }
    
    Orologio(int inOre, int inMin) {
	if (!regola(inOre, inMin, 0)){
	    secondi = minuti = ore = 0;
	}
    }
    
    Orologio(int inOre) {
	if (!regola(inOre, 0, 0)){
	    secondi = minuti = ore = 0;
	}
    }
    
    Orologio() {
	regola(0, 0, 0);
    }

    //** ok mc
    public int getOre() {return ore;}
    public int getMinuti() {return min;}
    public int getSecondi() {return sec;}

    //** ok mc
    public boolean regola(int inOre, int inMin, int inSec) {
        boolean result = true;
	
        if (result && compreso(inSec, 0, 59)) secondi = inSec;
        else result = false;
	
        if (result && compreso(inMin, 0, 59)) minuti = inMin;
        else result = false;
	
        if (result && compreso(inOre, 0, 23)) ore = inOre;
        else result = false;
	
        return result;
    }

    //** ok mc
    private boolean compreso(int query, int min, int max) {
        boolean result = true;

        if (query > max || query < min) result = false;

        return result;
    }

    
    public void avanza(){
        secondi++;
        normalizza();
    }

    private void normalizza(){
        if (secondi > 59) {
            secondi = 0;
	    minuti++;
        }
        if (minuti > 59) {
            minuti = 0;
	    ore++;
        }
	if (ore > 23) ore = 0;
    }
}
