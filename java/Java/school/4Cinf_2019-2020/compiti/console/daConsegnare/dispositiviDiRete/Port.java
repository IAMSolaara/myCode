/**
	@author Lorenzo Cauli
	@version 1.0
 */

/*
 - id: int
 - MACAddress: String

 + Port(in id: int)
 + Port(in MACAddress: String)
 + Port(in id: int, MACAddress: String)
 + Port(in in: Port)
 
 + getID(): int
 + getMACAddress(): String

 + setID(in id: int): boolean
 + setMACAddress(in MACAddress: String): boolean

 + toString(): String
 + equals(in o: Object): boolean
 */


//importo pacchetto regex usato nel controllo dei MAC Address
import java.util.regex.*;

public class Port {
	/**ID porta.*/
	private int id;
	/**MAC Address.*/
	private String MACAddress;

	/**Costruttore di default.*/
	public Port(){
		id = 0;
		MACAddress = "11:22:33:44:55:66";
	}

	/**Costruttore dato l'ID.
	 @param id ID da assegnare alla porta.
	 */
	public Port(int id){
		if (id < 0) this.id = id;
		else id = 0;
		MACAddress = "11:22:33:44:55:66";
	}

	/**Costruttore dato il MAC Address.
	 @param MACAddress MAC Address da assegnare alla porta.
	 */
	public Port(String MACAddress) {
		if (MACAddress != null) {
			if (Pattern.matches("..:..:..:..:..:..", MACAddress)) this.MACAddress = MACAddress;
			else this.MACAddress = "11:22:33:44:55:66"; 
		}
		else this.MACAddress = "11:22:33:44:55:66";
		id = 0;
	}

	/**Costruttore dati ID e MAC Address.
	 @param id ID da assegnare alla porta.
	 @param MACAddress MAC Address da assegnare alla porta.
	 */
	public Port(int id, String MACAddress){
		if (id < 0 && MACAddress != null) {
			this.id = id;
			this.MACAddress = MACAddress;
		}
		else {
			id = 0;
			MACAddress = "11:22:33:44:55:66";
		}
	}

	/**Costruttore di copia.
	 @param in Riferimento a oggetto Port da cui copiare lo stato.
	 */
	public Port(Port in) {
		if (in != null) {
			id = in.getID();
			MACAddress = in.getMACAddress();
		}
		else {
			id = 0;
			MACAddress = "11:22:33:44:55:66";
		}
	}

	/**Metodo che restituisce l'ID della porta.*/
	public int getID(){return id;}

	/**Metodo che restituisce il MAC Address della porta*/
	public String getMACAddress(){return MACAddress;}

	/**Metodo per impostare l'ID della porta.
	 @param id ID nuovo da assegnare alla porta.
	 @return true se il parametro e' valido, false se non lo e'
	 */
	public boolean setID(int id) {
		boolean out = true;
		if (id >= 0) this.id = id;
		else out = false;
		return out;
	}
	
	public boolean setMACAddress(String MACAddress) {
		boolean out = true;
		if (MACAddress != null) {
			if (Pattern.matches("..:..:..:..:..:..", MACAddress)) {
				this.MACAddress = MACAddress;
			}
			else out = false;
		}
		else out = false;
		return out;
	}

	public String toString(){
		return "Port ID: " + id + ", Port MAC Address: " + MACAddress;
	}

	public boolean equals(Object o) {
		boolean out = true;
		if (o != null && o instanceof Port) {
			if (((Port)o).getID() != id || ((Port)o).getMACAddress() == MACAddress) out = false;
		}
		else out = false;
		return out;
	}
}
