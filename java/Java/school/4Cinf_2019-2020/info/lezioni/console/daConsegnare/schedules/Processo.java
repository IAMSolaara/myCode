/**
 *@author Aresu Matteo 4Cinf
 *@version 0.1, last update 16/10/2019
 */

/*Processo

  //attributi variabili
  - pid : int 1..99
  - nome : String
  - stato : String (pronto/esecuzione/attesa/terminato)
  - tRichiesto : int >=0
  - tOttenuto : int >=0

  //attributi costanti
  + MIN = 1
  + MAX = 99

  //metodi costruttori
  + Processo (in n : String; in tr : int)
  + Processo (Processo p) 

  //metodi accessori
  + getPId () : int
  + getNome () : String
  + getStato () : String
  + getTRichiesto () : int
  + getTOttenuto () : int

  //metodi modificatori
  + esegui (in tempo) : boolean
  + setPronto () : void

  //altri metodi
  + toString () : String

*/

//inizializzazione classe
public class Processo {

    //attributi variabili
    int pid, tRichiesto, tOttenuto;
    String nome, stato;

    //attributi costanti
    public static final int MIN = 1;
    public static final int MAX = 99;

    //metodi costruttori
    /**
     * Costruttore per creare il processo
     * @param n Il nome
     * @param tr Il tempo richiesto
     * @param id L'id 
     */
    public Processo (String n, int tr, int id) {
	if (n != null) {
	    nome = n;
	} else {
	    n = "Processo";
	}

	if (tr <= 0) tRichiesto = 1;
	else tRichiesto = tr;

	if (id < 1 || id > 99) pid = 2;
	else pid = id;
	
	stato = "pronto";
        tOttenuto = 0;
    }

    /**
     * Costruttore di copia
     * @param p Processo da copiare
     */
    public Processo (Processo p) {
	if (p != null) {
	    nome = p.getNome();
	    stato = p.getStato();
	    pid = p.getPId();
	    tOttenuto = p.getTOttenuto();
	    tRichiesto = p.getTRichiesto();
	} else {
	    nome = "Emacs";
	    stato = "Pronto";
	    pid = 1;
	    tRichiesto = 1;
	    tOttenuto = 1;

	}

	if (tRichiesto == tOttenuto) {
	    stato = "terminato";
	}
	    
    }

    //metodi accessori
    /**
     * Metodo accessorio per il nome
     * @return Il nome
     */
    public String getNome () {
	return nome;
    }

    /**
     * Metodo accessorio per lo stato
     * @return Lo stato
     */
    public String getStato () {
	return stato;
    }

    /**
     * Metodo accessorio per il Process Identifier
     * @return Il Process Indentifier
     */
    public int getPId () {
	return pid;
    }

    /**
     * Metodo accessorio per il tempo richiesto
     * @return Il tempo richiesto
     */
    public int getTRichiesto () {
	return tRichiesto;
    }

    /**
     * Metodo accessorio per il tempo ottenuto
     * @return Il tempo ottenuto
     */
    public int getTOttenuto () {
	return tOttenuto;
    }

    //metodi modificatori
    /**
     * Fa avanzare il tempo ottenuto
     */
    public boolean esegui (int tempo) {
	boolean result = false;

	if (stato.equals("pronto") == true && tempo > 0) {
	    stato = "esecuzione";
	    if (tOttenuto + tempo <= tRichiesto) {
		result = true;
		tOttenuto = tOttenuto + tempo;
	    } else {
		tOttenuto = tRichiesto;
	    }
	    if (tOttenuto == tRichiesto) stato = "terminato";
	}

    return result;
    }

    //gestisce solo la transizione da esecuzione a pronto
    public void setPronto () { stato = "pronto"; }

    //altri metodi
    /**
     * Metodo stringa per indicare l'output
     * @return La stringa
     */
    public String toString () {
	return "Nome processo: " + nome + " \nStato: "  + stato + " \nProcess Identifier: " + pid + " \nTempo di caricamento richiesto: "  + tRichiesto + " \nTempo di caricamento ottenuto: "+ tOttenuto  + "\n";
    }


    
}

