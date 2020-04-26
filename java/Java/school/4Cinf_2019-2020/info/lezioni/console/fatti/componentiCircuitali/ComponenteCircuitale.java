/**
 @author Lorenzo Cauli
 @version 0.11111111111
 */

/*
 + getReattanza(in frequenza: double): double //abstract
 */

public abstract class ComponenteCircuitale {
	/**
	 Metodo che restituisce la reattanza del componente.
	 @param frequenza Frequenza attraversata dal componente.
	 @return la reattanza.
	 */
	public abstract double getReattanza(double frequenza);
}

