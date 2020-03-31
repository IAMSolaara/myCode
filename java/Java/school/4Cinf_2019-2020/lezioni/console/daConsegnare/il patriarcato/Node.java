/**
 * @author Lorenzo Cauli
 * @version 0.1
 */

 /* 
  - p: punto
  - next: Node
 
  Costruttori:
  + Node();
  + Node(in p: double);
  + Node(in x, y: double);
 
  + setPoint(in x, y: double)
  + trasla(in dX, dY: double);
  + setNext(Node n);
 

  + getPunto();
  + getNext();
  
  + toString(): String
  + equals(Object o): boolean
  */

public class Node {

	private Merce c;
	private Node next;

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
		return "Merce: "+ c.toString();
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