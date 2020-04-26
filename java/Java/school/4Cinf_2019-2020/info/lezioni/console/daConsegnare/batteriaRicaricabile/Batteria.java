/**
 * @author Lorenzo Cauli
 * @version 0.1
 */

/*
 - carica: int  0..100

 + Batteria()
 + Batteria(in carica: int)
 + Batteria(in in: Batteria)

 + getCarica(): int
 
 + utilizza(in u: int): boolean

 - compreso(in val, min, max: int): boolean
 + toString: String
 + equals: boolean
 */

public class Batteria {
	protected int carica;

	/**Costruttore di default.*/
	public Batteria() {
		carica = 100;
	}

	/**Costruttore data la carica.
	 * @param carica Carica da impostare.
	 */
	public Batteria(int carica) {
		if (compreso(carica, 0, 100)) this.carica = carica;
		else carica = 100;
	}

	/**Costruttore di copia.
	 * @param in Riferimento a oggetto Batteria.
	 */
	public Batteria(Batteria in) {
		if (in != null) carica = in.getCarica();
		else carica = 100;
	}

	/**Metodo che restituisce la carica.
	 * @return La carica attuale della batteria.
	 */
	public int getCarica(){return carica;}

	/**Metodo che utilizza la batteria.
	 * @param u Percentuale di utilizzo della batteria.
	 * @return true se il parametro e' valido, false se non lo e'
	 */
	public boolean utilizza(int u) {
		boolean out = true;
		if (u < 0 || (carica - u) < 0) out = false;
		else carica -= u;
		return out;
	}

	protected boolean compreso(int val, int min, int max) {
		boolean out = true;
		if (val < min || val > max) out = false;
		return out;
	}
	
	/**Metodo che restituisce lo stato dell'oggetto in una stringa.
	 * @return Una stringa.
	 */
	public String toString(){
		return "Carica batteria: " + carica + "%";
	}

	/**Metodo che confronta quest'oggetto con un'altro.
	 * @param o Riferimento a oggetto Object
	 * @return true se gli stati degli oggetti sono uguali, false se sono diversi.
	 */
	public boolean equals(Object o) {
		boolean out = true;
		if (o != null && o instanceof Batteria) {
			if ( ((Batteria)o).getCarica() != carica ) out = false;
		}
		else out = false;
		return out;
	}
}
