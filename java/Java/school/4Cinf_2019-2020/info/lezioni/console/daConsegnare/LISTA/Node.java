/**
 * @author Ricco Davide
 * @version 0.1
 */

 /* Progetto della classe Node
  *
  * Attributi:
  * -p: punto
  * -next: Node
  *
  * Metodi:
  *
  * Costruttori:
  * +Node();
  * +Node(in p: double);
  * +Node(in x, y: double);
  *
  * Modificatori:
  * +setPoint(in x, y: double)
  * +trasla(in dX, dY: double);
  * +setNext(Node n);
  *
  * Getter:
  * +getPunto();
  * +getNext();
  * 
  * Altri metodi:
  * +toString(): String
  * +equals(Object o): boolean
  */

public class Node {

	//attributi
	Merce c;
	Node next;

	//metodi
	//costruttori
	public Node (String nome, double p) {

		c = new Merce (nome, p);
		next = null;	 
	}

	//modificatori
	public void setNext (Node n) {

		 next = n;
	}

	//Getters
	public Merce getMerce () {

		return new Merce (c);
	}

	public Node getNext () {

		return next;
	}

	//altri metodi
	public String toString () {

		//sezione dichiarativa
		String s;
		
		//sezione esecutiva
		s = "Merce: "+ c.toString();

		return s;
	}

	public boolean equals (Object o) {

		//sezione dichiarativa
		boolean ris;

		//sezione esecutiva
		ris = false;
		if (o != null && o instanceof Node &&
			((Node)o).getMerce().equals(c)) {

			 ris = true;
		}

		return ris;
	}

}
