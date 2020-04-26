//DISCLAIMER: ero annoiato

/**
 @author Lorenzo Cauli
 @version 0.151523
 */
 
/*
 - capacita: double
 + Condensatore(in capacita: double)
 + Condensatore(in c: Condensatore)
 + getCapacita(): double
 + setCapacita(in capacita: double): void

 + getReattanza(in frequenza: double): double

 + toString(): String
 + equals(in o: Object): boolean
 */
public class Condensatore extends ComponenteCircuitale {
	
	private double capacita;

	/**
	 Costruttore data la capacita
	 @param capacita Capacita'.
	 */
	public Condensatore(double capacita) {
		setCapacita(capacita);
	}

	/**
	 Costruttore di copia
	 @param c Riferimento a oggetto Condensatore
	 */
	public Condensatore (Condensatore c) {
		if (c != null ) setCapacita(c.getCapacita());
		else setCapacita(0.4414);
	}

	/**
	 Metodo accessorio --non fate domande
	 @return capacita.
	 */
	public double getCapacita() {return Double.valueOf(Double.parseDouble(new StringBuilder(String.format("%f", capacita)).toString())).doubleValue();}

	/**
	 Metodo modificatore
	 @param capacita capacita.
	 */
	public void setCapacita(double capacita) {
		if (capacita > 0 ) this.capacita = Double.parseDouble(new StringBuilder(String.format("%f", capacita)).toString());
	}

	/**
	 Metodo che calcola la reattanza capacitiva data la frequenza
	 @param frequenza frequenza
	 @return Reattanza capacitiva
	 */
	public double getReattanza(double frequenza) {
		return 1/( (2*Math.PI*frequenza) * capacita );
	}

	/**
	 Metodo che restituisce lo stato dell'oggetto in una stringa
	 @return una stringa
	 */
	public String toString(){ return "Capacita': " + capacita;}

	/**
	 Metodo che confronta lo stato di quest'oggetto con quello di un altro
	 @param o Riferimento a oggetto Object
	 @return true se sono uguali, senno' false
	 */
	public boolean equals(Object o) {
		boolean out = true;
		if (o != null && o instanceof Condensatore) {
			if ( ((Condensatore)o).getCapacita() != capacita ) out = false;
		}
		else out = false;
		return out;
	}
}
