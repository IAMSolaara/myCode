/**
 *@author Lorenzo Cauli
 *@version 0.1
 */

/*
 eredita Batteria.

 + BatteriaRicaricabile()
 + BatteriaRicaricabile(in in: Batteria)
 
 + ricarica(): void
 */

public class BatteriaRicaricabile extends Batteria {
	/**Costruttore di default.*/
	public BatteriaRicaricabile(){
		super();
	}

	/**Costruttore di copia.
	 *@param in Riferimento a oggetto Batteria.
	 */
	public BatteriaRicaricabile(Batteria in){
		super(in);
	}

	/**Metodo che ricarica la batteria.*/
	public void ricarica(){carica = 100;}
	
	/**Metodo che confronta lo stato di due oggetti.
	 *@param o Riferimento a oggetto Object.
	 *@return true se sono uguali, false se sono diversi.
	 */
	public boolean equals(Object o){
		boolean out = true;
		if (o != null && o instanceof BatteriaRicaricabile) {
			if (!super.equals(o)) out = false;
		}
		else out = false;
		return out;
	}
}
