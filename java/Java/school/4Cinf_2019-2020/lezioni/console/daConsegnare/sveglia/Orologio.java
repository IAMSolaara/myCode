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
+ Orologio(in clk: Orologio)
+ Orologio()      //COSTRUTTORE DI DEFAULT
+ getOre() : int
+ getMinuti() : int
+ getSecondi() : int
+ regola(in o,m,s : int) : boolean
+ avanza() : void
- normalizza() : void
# compreso(in x, min, max : int) : boolean
*/

public class Orologio {
	/** Attributo dove vengono memorizzate le ore.*/
	private int ore;
	/** Attributo dove vengono memorizzati i minuti.*/
	private int minuti;
	/** Attributo dove vengono memorizzati i secondi.*/
	private int secondi;

	/**
	 * Costruttore con ore, minuti e secondi.
	 * @param inOre Ore da impostare
	 * @param inMin Minuti da impostare
	 * @param inSec Secondi da impostare
	 */
	public Orologio(int inOre, int inMin, int inSec) {
		if (!regola(inOre, inMin, inSec)){
			secondi = minuti = ore = 0;
		}
	}

	/**
	 * Costruttore con ore e minuti.
	 * I secondi avranno valore di default.
	 * @param inOre Ore da impostare
	 * @param inMin Minuti da impostare
	 */    
	public Orologio(int inOre, int inMin) {
		if (!regola(inOre, inMin, 0)){
			secondi = minuti = ore = 0;
		}
	}

	/**
	 * Costruttore con ore.
	 * I secondi e i minuti avranno valore di default.
	 * @param inOre Ore da impostare
	 */    
	public Orologio(int inOre) {
		if (!regola(inOre, 0, 0)){
			secondi = minuti = ore = 0;
		}
	}

	/**
	 * Costruttore di copia.
	 * Verra' copiato lo stato dell'oggetto nel parametro in caso esso sia valido.
	 * @param clk Oggetto da cui copiare lo stato.
	 */
	public Orologio(Orologio clk) {
		if (clk != null) {
			regola(clk.getOre(), clk.getMinuti(), clk.getSecondi());
		}
		else regola(0, 0, 0);
	}

	/**
	 * Costruttore di default.
	 * Tutti gli attributi avranno valore di default.
	 */
	public Orologio() {regola(0, 0, 0);
	}

	//** ok mc
	/** Metodo get per ottenere le ore attualmente memorizzate nell'orologio.
	 * @return Le ore
	 */
	public int getOre() {return ore;}

	/** Metodo get per ottenere i minuti attualmente memorizzati nell'orologio.
	 * @return I minuti
	 */
	public int getMinuti() {return minuti;}

	/** Metodo get per ottenere i secondi attualmente memorizzati nell'orologio.
	 * @return I secondi
	 */
	public int getSecondi() {return secondi;}

	//** ok mc
	/**
	 * Funzione per regolare l'orologio.
	 * @param inOre Ore da impostare
	 * @param inMin Minuti da impostare
	 * @param inSec Secondi da impostare
	 * @return Il risultato dei controlli
	 */
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
	/**
	 * Funzione per controllare che un valore sia entro determinati limiti.
	 * @param query Valore da controllare
	 * @param min Estremo minimo del limite
	 * @param max Estremo massimo del limite
	 * @return Risultato del controllo. true se e' entro i limiti, senno' false
	 */
	protected boolean compreso(int query, int min, int max) {
		boolean result = true;

		if (query > max || query < min) result = false;

		return result;
	}

	//** ok mc
	/**
	 * Metodo per avanzare l'orologio, chiama poi il metodo normalizza.
	 */
	public void avanza(){
		secondi++;
		normalizza();
	}

	/**
	 * Metodo per normalizzare l'orologio dopo che e' stato avanzato.
	 */
	private void normalizza(){
		if (secondi > 59) {
			secondi = 0;
			minuti++;
			if (minuti > 59) {
				minuti = 0;
				ore++;
				if (ore > 23) ore = 0;
			}
		}
	}

	/**
	 * Funzione per restituire lo stato dell'orologio in una stringa.
	 * @return Una stringa con dentro ore, minuti e secondi.
	 */
	public String toString(){
		return "" + ore + ":" + minuti + ":" + secondi;
	}

	/**
	  Metodo che confronta lo stato di quest'oggetto con quello di un altro.
	  @param o Riferimento a Object con cui confrontarsi.
	  @return true se sono uguali, false se sono diversi
	  */
	public boolean equals(Object o) {
		boolean out = true;
		if (o != null || o instanceof Orologio) {
			if ( ((Orologio)o).getOre()     != ore    ||
					((Orologio)o).getMinuti()  != minuti ||
					((Orologio)o).getSecondi() != secondi   ) out = false;
		}
		else out = false;
		return out;
	}
}
