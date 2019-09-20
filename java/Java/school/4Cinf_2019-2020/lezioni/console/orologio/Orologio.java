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
        ore = inOre;
        min = inMin;
        sec = inSec;
    }
    Orologio(int inOre, int inMin) {
        ore = inOre;
        min = inMin;
        sec = 0;
    }
    Orologio(int inOre) {
        ore = inOre;
        min = 0;
        sec = 0;
    }
    Orologio() {
        ore = 0;
        min = 0;
        sec = 0;
    }

    public int getOre() {return ore;}
    public int getMinuti() {return min;}
    public int getSecondi() {return sec;}

    public boolean regola(int inOre, int inMin, int inSec) {
        boolean result = true;
        if (compreso(inSec, 0, 59)) sec = inSec;
        else result = false;
        if (compreso(inMin, 0, 59)) min = inMin;
        else result = false;
        if (compreso(inOre, 0, 23)) ore = inOre;
        else result = false;
        return result;
    }

    private boolean compreso(int query, int min, int max) {
        boolean result = true;

        if (query > max || query < min) result = false;

        return result;
    }

    public void avanza(){
        sec++;
        normalizza();
    }

    private void normalizza(){
        int tmp;
        if (sec > 59) {
            tmp = sec % 60;
            min += tmp;
            sec -= tmp * 60;
        }
        if (min > 59) {
            tmp = min % 60;
            ore += tmp;
            min -= tmp * 60;
        }
    }
}
