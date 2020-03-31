/**
 * @author Ricco Davide
 * @version 0.1 18 Mar 2020
 */

/* Progetto della classe Lista
 *
 * Attributi:
 * - head: Node;
 *  
 * Metodi:
 * Costruttori:
 * + Lista ();
 * + Lista (File); TODO
 *
 * Modificatori:
 * + push (in m: Merce): boolean;
 * + delete (in nome: String);
 * 
 * Altri:
 * + toString(): String;
 */ 

public class Lista {

	//attributi
	private Node head;

	//metodi
	//Costruttori
	public Lista () {

		head = null;
	}

	//modificatori
	public boolean push (Merce m) {

		//sezione dichiarativa
		boolean ris;	

		//sezione esecutiva
		ris = false;
		if (m != null) {

			Node n = new Node (m.getNome(), m.getPrezzo());
			n.setNext (head);
			head = n;
			ris = true;
		}

		return ris;
	}
	
	public boolean delete (String name) {

		//sezione dichiarativa
		boolean found; //variabile che contiene il nostro risultato
		Node tmp; //nodo per salvare il nodo precedente

		//sezione esecutiva
		found = false;
		tmp = head;
		if (name != null && tmp != null) {

			if (name.equals(head.getMerce().getNome())) {

				pop();
				found = true;
			}//esegui in caso il nome sia lo stesso di head
			else {
				while (!found && tmp.getNext() != null) {
					if (name.equals(tmp.getNext().getMerce().getNome())) {

						tmp.setNext(tmp.getNext());
						found = true;
					} //fine if
					else {
						tmp = tmp.getNext();
					}
				} //fine while
			} //fine else
		}

		return found;
	}

	private boolean pop() { //funziona

		//sezione dichiarativa
		boolean ris;

		//sezione esecutiva
		ris = false;
		if (head != null) {

			head = head.getNext();	
			ris = true;
		}

		return ris;
	}


	public String toString () {

		//sezione dichiarativa
		String str;
		Node tmp;

		//sezione esecutiva
		str = "";
		tmp = head;
		while (tmp != null) {

			str += tmp.toString()+"\n";
			tmp = tmp.getNext();
		}

		return str;
	}
}
