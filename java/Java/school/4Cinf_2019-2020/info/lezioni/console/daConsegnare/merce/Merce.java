/**
 * 	@author Lorenzo Cauli
 * 	@version 0.1
 */

/*
 * 	- nome: String
 * 	- prezzo: double > 0
 *
 * 	+ Merce(in nome: String, in p: double)
 * 	+ Merce(in ref: Merce)
 *	
 *	+ getPrezzo(): double
 *	+ getNome(): String
 *
 *	+ setPrezzo(in p: double): boolean
 *
 *	+ toString(): String
 *	+ equals(in o: Object):boolean
 */

public class Merce {
	/**Nome della merce.*/
	private String nome;
	/**Prezzo della merce.*/
	private double prezzo;

	/**Costruttore dati nome e prezzo
	 *	@param nome Nome della merce.
	 *	@param p	Prezzo della merce.
	 */
	public Merce(String nome, double p){
		if (nome != null) this.nome = nome;
		else nome = "N/A";

		if (p > 0) this.prezzo = p;
		else this.prezzo = 8086;
	}

	/**Costruttore di copia</br>
	 * test
	 * @param ref Riferimento all'oggetto da cui copiare.
	 */
	public Merce(Merce ref){
		if (ref != null) {
			nome = ref.getNome();
			prezzo = ref.getPrezzo();
		}
		else {
			nome = "N/A";
			prezzo = 8086;
		}
	}

	/**Metodo per restituire il prezzo*/
	public double getPrezzo(){return prezzo;}

	/**Metodo per restituire il nome*/
	public String getNome(){return nome;}

	/**Metodo per impostare il prezzo.
	 *	@param p Prezzo da impostare.
	 *	@return true se il prezzo e' valido, false se non lo e'
	 */
	public boolean setPrezzo(double p){
		boolean out = true;
		if (p > 0) prezzo = p;
		else out = false;
		return out;		
	}

	/**Metodo per restituire lo stato in una stringa*/
	public String toString(){
		return "" + nome + ": €" + prezzo;
	}

	/**Metodo per verificare che un oggetto sia uguale a questo.
	 * @param o Oggetto da confrontare.
	 * @return true se l'oggetto e' uguale, false se l'oggetto non lo e'
	 */
	public boolean equals(Object o){
		boolean out = true;
		if (o == null || !(o instanceof Merce)) out = false;
		else if (nome != o.getNome() || prezzo != o.getPrezzo()) out = false;
		return out;
	}
}
