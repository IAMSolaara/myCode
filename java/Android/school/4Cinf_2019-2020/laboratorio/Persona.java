package app.saluti;

public class Persona {
	private String nome;

	public Persona(String nome) {
		if (nome != null) this.nome = nome;
		else this.nome = "Mario";
	}

	public String getNome(){return nome;}

	public String toString() {
		return "Il nome e'" + getNome();
	}

	public boolean equals(Object o) {
		boolean out = true;
		if (o != null && o instanceof Persona) {
			if ( !nome.equals(((Persona)o).getNome()) ) out = false;
		}
		else out = false;
		return out;
	}
}
