/**
 * @author Ricco Davide
 * @version 0.1 19 Mar 2020
 */

/* TEST */
public class Test {

	public static void main (String args[]) { //Pike dislikes this

		//sezione dichiarativa
		Lista l;

		//sezione esecutiva
		l = new Lista();
		l.push (new Merce("Carta igienica", 3.2));
		l.push (new Merce("Energia - Mario Schifano", 1000));
		l.push (new Merce("Pacco mascherine", 50.55));
		l.push (new Merce("Vodka Spiritus 90", 13.33));

		System.out.println (l.toString());

		l.delete ("Carta igienica");

		System.out.println (l.toString());

	}
}
