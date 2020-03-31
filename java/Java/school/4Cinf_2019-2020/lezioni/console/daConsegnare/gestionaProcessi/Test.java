/**
 * @author Ricco Davide
 * @version 0.1 26 Mar 2020
 */

import java.io.*;


public class Test {

	public static void main (String args[]) {

		//sezione dichiarativa
		Scheduler schd;

		//sezione esecutiva
		schd = new Scheduler (1);
		try {

			schd.readFromFile (args[0]);
			System.out.println (schd.toString());
			schd.exec();

		}
		catch (FileNotFoundException e) {

			System.out.println (e.getMessage());
		}
		catch (NullPointerException e) {

			System.out.println (e.getMessage());
		}
		catch (ArrayIndexOutOfBoundsException e) {

			System.out.println ("USAGE: java Test <nomeFile>");
		}
		catch (InterruptedException e) {
			System.out.println (e.getMessage());
		}
	}
}
