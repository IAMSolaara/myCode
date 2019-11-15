/**
	@author Lorenzo Cauli
	@version 0.1
  */

/*
 - l1: Lampadina
 - l2: Lampadina

 + Lampadario()
 + Lampadario(in l1, l2: Lampadina)
 + Lampadario(in in: Lampadario)

 + getL1(): Lampadina
 + getL2(): Lampadina

 + isAcceso(): boolean

 + sostituisci(in n: int): boolean
 + accendi(): void
 + spegni(): void
 
 + toString(): String
 + equals(in o: Object): boolean
   */

public class Lampadario {
	private Lampadina l1;
	private Lampadina l2;

	/**Costruttore di default.*/
	public Lampadario() {
		l1 = new Lampadina();
		l2 = new Lampadina();
	}

	/**Costruttore date 2 lampadine.
	 * @param l1 Prima lampadina.
	 * @param l2 Seconda lampadina.
	 */
	public Lampadario(Lampadina l1, Lampadina l2) {
		if (l1 != null && l2 != null) {
			this.l1 = new Lampadina(l1);
			this.l2 = new Lampadina(l2);
		}
		else {
			this.l1 = new Lampadina();
			this.l2 = new Lampadina();
		}
	}

	/** Costruttore di copia
	 *  @param in Lampadario da cui copiare lo stato.
	 */
	public Lampadario(Lampadario in) {
		if (in != null) {
			l1 = new Lampadina(in.getL1());
			l2 = new Lampadina(in.getL2());
		}
		else {
			l1 = new Lampadina();
			l2 = new Lampadina();
		}
	}

	/**Metodo che restituisce il riferimento a lampadina 1.
	 * @return riferimento a l1
	 */
	public Lampadina getL1(){return l1;}
	/**Metodo che restituisce il riferimento a lampadina 2.
	 * @return riferimento a l2
	 */
	public Lampadina getL2(){return l2;}

	/**Metodo che controlla se il Lampadario e' acceso.
	 * @return true se almeno una lampadina e' accesa, false se entrambe sono spente.
	 */
	public boolean isAcceso() {return l1.isAccesa() | l2.isAccesa();}

	/**Metodo che crea un nuovo oggetto per l1 o l2.
	 * @param n Numero della lampadina da sostituire
	 * @return true se la lampadina e' stata sostituita, false se il parametro era invalido.
	 */
	public boolean sostituisci(int n) {
		boolean out = true;
		switch (n) {
			case 1:
				l1 = new Lampadina();
				break;
			case 2:
				l2 = new Lampadina();
				break;
			default:
				out = false;
				break;
		}
		return out;
	}

	/**Metodo che spegne il lampadario*/
	public void spegni() {
		l1.spegni();
		l2.spegni();
	}
	
	/**Metodo che accende il lampadario*/
	public void accendi() {
		l1.accendi();
		l2.accendi();
	}

	/**Metodo che restituisce lo stato del lampadario in una stringa.
	 * @return una stringa
	 */
	public String toString(){ 
		return "l1: " + l1.toString() + ", l2: " + l2.toString();
	}

	/**Metodo che confronta lo stato di quest'oggetto con un altro.
	 * @param o Riferimento a oggetto
	 * @return true se sono uguali, false se sono diversi.
	 */
	public boolean equals(Object o) {
		boolean out = true;
		if (o != null && o instanceof Lampadario) {
			if (   !(l1.equals( ((Lampadario)o).getL1() )) 
				|| !(l2.equals( ((Lampadario)o).getL2() )) ) out = false;
		}
		else out = false;
		return out;
	}
}
