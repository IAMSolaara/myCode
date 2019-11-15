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
 + isAttivo(): boolean

 + alarmRegola(in alarmOre, alarmMinuti: int): boolean
 + alarmSwitch(in attivo: boolean): void
 + avanza(): void
 
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
		 	 
		 }
	}
}
