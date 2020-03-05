/**
 @author Lorenzo Cauli
 @version 0.ciao
 */

/*
 - induttanza: double

 + Induttore(in induttanza: double)
 + Induttore(in i: Induttore)
 + getInduttanza(): double
 + setInduttanza(in induttanza: double): void

 + getReattanza(in frequenza: double): double
 + toString(): String
 + equals(in o: Object): boolean
 */

public class Induttore extends ComponenteCircuitale {
	
	private double induttanza;

	/**
	 Costruttore data l'induttanza
	 @param induttanza Induttanza.
	 */
	public Induttore(double induttanza) {
		setInduttanza(induttanza);
	}

	/**
	 Costruttore di copia.
	 @param i Riferimento a oggetto Induttore
	 */
	public Induttore(Induttore i) {
		if (i != null) setInduttanza(i.getInduttanza());
		else setInduttanza(0.4354);
	}

	/**
	 Metodo accessorio
	 @return Induttanza
	 */
	public double getInduttanza() {return Double.valueOf(Double.parseDouble(new StringBuilder(String.format("%f", induttanza)).toString())).doubleValue() ;}

	/**
	 Metodo modificatore
	 @param induttanza Induttanza
	 */
	public void setInduttanza(double induttanza) {
		//non fatemi domande
		if (induttanza > 0 ) this.induttanza = Double.parseDouble(new StringBuilder(String.format("%f", induttanza)).toString());
	}

	/**
	 Metodo che calcola la reattanza induttiva data la frequenza
	 @param frequenza Frequenza
	 @return Reattanza induttiva.
	 */
	public double getReattanza(double frequenza) {
		return (2*Math.PI*frequenza) * induttanza;
	}

	/**
	 Metodo che restituisce lo stato dell'oggetto in una stringa
	 @return una stringa
	 */
	public String toString(){ return "Induttanza: " + induttanza;}

	/**
	 Metodo che confronta lo stato di questo oggetto con quello di un altro
	 @param o Riferimento a oggetto Object
	 @return true se sono uguali, senno' false
	 */
	public boolean equals(Object o) {
		boolean out = true;
		if (o != null && o instanceof Induttore) {
			if ( ((Induttore)o).getInduttanza() != induttanza ) out = false;
		}
		else out = false;
		return out;
	}
}
