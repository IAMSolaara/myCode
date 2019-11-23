/**
 *@author Lorenzo Cauli
 *@version 0.1
 */

/*Sveglia
  sottoclasse di Orologio
  eredita gli attributi di Orologio

  - alarmOre: int		0..23
  - alarmMinuti: int		0..59
  - alarmOn: boolean

  + Sveglia(in ore, minuti, secondi: int)
  + Sveglia(in s: Sveglia)

  + getAlarmOre(): int
  + getAlarmMinuti(): int
  + isAlarmOn(): boolean

  + alarmRegola(in alarmOre, alarmMinuti: int): boolean
  + alarmSwitch(in attivo: boolean): void
  + avanza(): void
  - suona(): void

  + toString(): String
  + equals(in o: Object): boolean
  */

public class Sveglia extends Orologio {
	private int alarmOre;
	private int alarmMinuti;
	private boolean alarmOn;

	/**Costruttore dati ore, minuti e secondi
	 *	@param ore Ore da impostare
	 *	@param minuti Minuti da impostare.
	 *	@param secondi Secondi da impostare
	 */
	public Sveglia(int ore, int minuti, int secondi) {
		super(ore, minuti, secondi);
		alarmOre = 0;
		alarmMinuti = 0;
		alarmOn = false;
	}

	/**Costruttore di copia.
	 *  @param s Riferimento a oggetto Sveglia.
	 */
	public Sveglia(Sveglia s){
		super(s);
		if (s != null) {
			alarmOre = s.getAlarmOre();
			alarmMinuti = s.getAlarmMinuti();
			alarmOn = s.isAlarmOn();
		}
		else {
			alarmOre = 0;
			alarmMinuti = 0;
			alarmOn = false;
		}
	}

	/**Metodo che restituisce le ore della sveglia.*/
	public int getAlarmOre(){return alarmOre;}

	/**Metodo che restituisce le minuti della sveglia.*/
	public int getAlarmMinuti(){return alarmMinuti;}

	/**Metodo che restituisce lo stato di attivita' della sveglia.*/
	public boolean isAlarmOn(){return alarmOn;}

	/**Metodo per impostare l'allarme.
	 *  @param alarmOre Ore della sveglia da impostare.
	 *  @param alarmMinuti Minuti della sveglia da impostare.
	 *  @return true se l'orario e' valido, false se non lo e'
	 */
	public boolean alarmRegola(int alarmOre, int alarmMinuti){
		boolean out = true;
		if (compreso(alarmOre, 0, 23) || compreso(alarmMinuti, 0, 59)) {
			this.alarmOre = alarmOre;
			this.alarmMinuti = alarmMinuti;
		}
		else out = false;
		return out;
	}

	/**Metodo che alterna gli stati di attivita' della sveglia*/
	public void alarmSwitch(){alarmOn = !alarmOn;}

	/**Metodo che avanza l'ora dell'orologio e controlla se e' ora di attivare l'allarme.*/
	public void avanza() {
		super.avanza();
		if (alarmOn && getOre() == alarmOre && getMinuti() == alarmMinuti) suona();
	}

	/**Metodo che fa suonare la sveglia*/
	public void suona(){
		System.out.println("SVEGLIA");
	}
	
	/**
	 * Funzione per restituire lo stato dell'oggetto in una stringa.
	 * @return Una stringa con dentro lo stato dell'oggetto.
	 */
	public String toString(){
		return super.toString() + "; Sveglia " + (alarmOn ? "accesa" : "spenta") + "; Orario allarme: " + alarmOre + ":" + alarmMinuti;
	}

	/**Metodo che confronta lo stato di quest'oggetto con quello di un altro.
	 *  @param o Riferimento a oggetto Object
	 *  @return true se sono uguali, false se sono diversi
	 */
	public boolean equals(Object o) {
		boolean out = true;
		if (o != null || o instanceof Sveglia){
			if ( !super.equals(o)							  ||
				 ((Sveglia)o).getAlarmOre() != alarmOre       ||
				 ((Sveglia)o).getAlarmMinuti() != alarmMinuti ||
				 ((Sveglia)o).isAlarmOn() != alarmOn			 ) out = false;
		}
		else out = false;
		return out;
	}
}
