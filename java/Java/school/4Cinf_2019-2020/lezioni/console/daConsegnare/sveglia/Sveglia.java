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

	public Sveglia(int ore, int minuti, int secondi) {
		super(ore, minuti, secondi);
		alarmOre = 0;
		alarmMinuti = 0;
		alarmOn = false;
	}

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

	public int getAlarmOre(){return alarmOre;}

	public int getAlarmMinuti(){return alarmMinuti;}

	public boolean isAlarmOn(){return alarmOn;}

	public boolean alarmRegola(int alarmOre, int alarmMinuti){
		boolean out = true;
		if (compreso(alarmOre, 0, 23) || compreso(alarmMinuti, 0, 59)) {
			this.alarmOre = alarmOre;
			this.alarmMinuti = alarmMinuti;
		}
		else out = false;
		return out;
	}

	public void alarmSwitch(){alarmOn = !alarmOn;}

	public void avanza() {
		super.avanza();
		if (alarmOn && getOre() == alarmOre && getMinuti() == alarmMinuti) suona();
	}

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
