/* Progetto della classe Scheduler

Attributi:
-ready: CodaAttraversabile;
-execProc: Processo;
-nextPid: int, >0;
-quanto: int, >0;

Metodi:
+Scheduler (in qnt: int);
+readFromFile (in name: String): void; //File di testo
+getQuanto(): int;

+exec(): void; //esegue i processi 
+listReadyProc(): String; //non proprio un toString
+getExecProc(): String; //restituisce il processo in esecuzione
+toString(): String;

TODO:
*/

import java.util.Scanner;
import java.io.*;

public class Scheduler {

	//Attributi
	private	CodaAttraversabile ready;
	private Processo execProc;
	private int nextPid, quanto;

	//metodi
	public Scheduler (int qnt) {

		if (qnt > 0) {
			
			quanto = qnt;
		}
		else quanto = 3;

		execProc = null;
		ready = new CodaAttraversabile();
		nextPid = 1;
	}

	public void readFromFile(String name) throws FileNotFoundException, NullPointerException {
		Scanner s;
		File f;

		try {
			f = new File (name);
			s = new Scanner (f);

			//lettura del file
			while (s.hasNext()) {

				ready.pushFromEnd(new Processo(s.next(), s.nextInt(), nextPid));
				nextPid++;
			}
		}

		catch (FileNotFoundException e) {

			throw new FileNotFoundException ("File non trovato");
		}
		catch (NullPointerException e) {

			throw new NullPointerException ("USAGE: java Test <nomeFile>");
		}
	}

	public void exec() throws InterruptedException {
		//loop fino a fine processi
		while (!ready.empty() || execProc != null) {
			if (execProc != null) {
				System.out.println("Processo in exec: \n" + execProc.toString());
				if (!ready.empty())  System.out.println("Lista processi pronti: \n" + ready.toString() + "\n*********");
				execProc.esegui(quanto); //perche' ares l'ha chiamato esegui e davide exec 
				if (execProc.getTOttenuto() < execProc.getTRichiesto()) {
					//lo metto a pronto perche' e' dopo l'esecuzione
					execProc.setPronto();
					//mando questo processo in ready
					ready.pushFromEnd(execProc);
					//e poi prendo il prossimo
					execProc = ready.pop(); 
				}
				else {
					execProc = null; //pero' dovrebbe tipo morire
				}
			}
			else {
				execProc = ready.pop();
			}
			try {
				Thread.sleep(1000);
			}
			catch (InterruptedException e) {
				throw new InterruptedException("Errore sleep.");
			}
		}
	}

	//getter
	public int getQuanto () {

		return quanto;
	}

	public Processo getExecProc () {

		return new Processo (execProc);
	}

	public String listReadyProc () {

		return ready.toString();
	}

	public String toString () {

		String s;

		s = "Quanto CPU: "+quanto+"\n";
		if (execProc != null) {

			s += "Processo in esecuzione: "+execProc.toString()+"\n";
		}
		else {

			s += "Nessun processo in esecuzione\n";
		}
	
		s += "Prossimo PID: "+nextPid+"\n";
		s += "Processi pronti: "+ready.toString()+"\n";
		return s;
	}

	public Processo[] getReadyProcesses() {
		int procSize = ready.size();
		Processo[] procs = new Processo[procSize];

		return procs;
	}

	//altri metodi

}
