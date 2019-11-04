/**
@author Lorenzo Cauli
@version 1.0
 */

/*
  - character: char
  + caseOffset: int

  + Lettera(in c: char)
  + Lettera(in ref: Lettera)

  + getCharacter(): char
  + isMaiuscolo(): boolean

  - compreso(in x, min, max: char): boolean
  + switchCase(): void
  + toString(): String
  + equals(in o: Object): boolean

 */

public class Lettera {
    /**
       Attributo variabile contenente il carattere.
     */
    private char character;
    /**
       Offset tra maiuscole e minuscole usato per il cambio tra maiuscolo e minuscolo.
     */
    public static int offset = 'a' - 'A';

    /**
       Costruttore dato il carattere.
       @param in Carattere da memorizzare
     */
    public Lettera(char in) {
	if (compreso(in, 'A', 'Z') || compreso(in, 'a', 'z')) character = in;
	else character = 'a';
    }

    /**
       Costruttore di copia.
       @param ref Riferimento all'oggetto da cui copiare lo stato
     */
    public Lettera(Lettera ref) {
	if (ref != null) character = ref.getCharacter();
	else character = 'a';
    }

    /**
       Metodo per restiturire il carattere corrente.
       @return Il carattere corrente
     */
    public char getCharacter(){return character;}

    /**
       Metodo per restituire se il carattere e' maiuscolo o minuscolo.
       @return true se il carattere e' maiuscolo, false se e' minuscolo
     */
    public boolean isMaiuscolo(){
	boolean out = true;
	if (compreso(character, 'a', 'z')) out = false;
	return out;
    }

    /**
       Metodo per controllare se un valore e' entro gli estremi.
       @param in Valore da controllare
       @param min Estremo minimo
       @param max Estremo massimo
       @return true se e' entro i limiti, false se OOB
     */
    private boolean compreso(char in, char min, char max){
	boolean out = true;
	if (in < min || in > max) out = false;
	return out;
    }

    /**
       Metodo per cambiare la lettera da minuscola a maiuscola e viceversa.
     */
    public void switchCase(){
	if (isMaiuscolo()) character += offset;
	else character -= offset;
    }

    /**
       Metodo per restituire il carattere in una stringa.
       @return La stringa
     */
    public String toString(){
	return "" + character;
    }
    
    /**
       Metodo per verificare se un oggetto e' uguale a questo.
       @param o Oggetto da controllare
       @return true se l'oggetto e' uguale, false se non lo e'
     */
    public boolean equals(Object o){
	boolean out = true;
	if (o != null && !(o instanceof Lettera)) out = false;
	else {
	    if (((Lettera)o).getCharacter() != character) out = false;
	}
	return out;
    }
}
