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
		l.inserisciOrdinato (new Merce("Carta igienica", 3.2));
		l.inserisciOrdinato (new Merce("Energia - Mario Schifano", 1000));
		l.inserisciOrdinato (new Merce("Pacco mascherine", 50.55));
		l.inserisciOrdinato (new Merce("Vodka Spiritus 90", 13.33));
        l.inserisciOrdinato(new Merce("Amuchina", Double.MAX_VALUE));
        l.inserisciOrdinato(new Merce("Rotocalco", 0));
        //stonks

		System.out.println (l.toString());

		l.delete ("Carta igienica");

		System.out.println (l.toString());

	}
}