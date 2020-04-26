/**
 *	@author Lorenzo Cauli
 *	@version 0.1
 */

public abstract class Mammifero {
	double peso;
	public Mammifero(double p) {
		if (p > 0) peso = p;
		else peso = 100;
	}

	public Mammifero (Mammifero m) {
		if (m != null) peso = m.getPeso();
		else peso = 100;
	}

	public boolean setPeso(double p) {
		boolean out = true;
		if (p > 0) peso = p;
		else out = false;
		return out;
	}

	public double getPeso(){ return peso; }

	public abstract String verso();

	public String toString() {
		return "Peso: " + peso;
	}

	public boolean equals(Object o) {
		boolean out = true;
		if (o != null && o instanceof Mammifero) {
			if (((Mammifero)o).getPeso() != peso) out = false;
		}
		else out = false;
		return out;
	}
}
