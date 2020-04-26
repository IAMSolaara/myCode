import java.util.Arrays;
import java.io.*;

/**
 * @author Lorenzo Cauli
 * @version 0.1
 */

/*
 - punti: Punto[]

 + Spezzata()
 + Spezzata(in dim: int)
 + Spezzata(in punti: Punto[])
 + Spezzata(in in: Spezzata)

 + getPunti(): Punto[]

 + getCount(): int

 + append(in p: Punto): boolean
 + insert(in p: Punto, pos: int): boolean
 + remove(in pos: int): boolean
 + trasla(in dx, dy: int): void

 + toString(): String
 + equals(in o: Object): boolean
*/

public class Spezzata {
    private Punto[] punti;
    int count;

    /**Costruttore di default. */
    public Spezzata() {
        punti = new Punto[100];
        count = 0;
    }

    /**
     * Costruttore data la dimensione.
     * @param dim Dimensione vettore.
     */
    public Spezzata(int dim) {
        if (dim <= 100 && dim > 0) punti = new Punto[dim];
        else punti = new Punto[100];
        count = 0;
    }

    /**
     * Costruttore dato array di punti.
     * @param punti Riferimento ad oggetto Punto[] da importare nella spezzata.
     */
    public Spezzata(Punto[] punti) {
        if (punti != null) {
            this.punti = new Punto[punti.length];
            for (int i = 0; i < punti.length; i++) {
                this.punti[i] = punti[i];
            }
            count = punti.length+1;
        }
        else {
            punti = new Punto[100];
            count = 0;
        }
    }

    /**
     * Costruttore di copia.
     * @param in Riferimento ad oggetto Spezzata.
     */
    public Spezzata(Spezzata in) {
        punti = new Punto[in.getPunti().length];
        for (int i = 0; i < punti.length; i++) {
            if (in.getPunti()[i] == null) punti[i] = null;
            else punti[i] = new Punto(in.getPunti()[i]);
        }
    }

	public Spezzata(ObjectInputStream ois) throws IOException, ClassNotFoundException {
		punti = new Punto[100];
		count = 0;
		try {
			boolean isAtEnd = false;
			while (!isAtEnd && count < 100) {
				try {
					append((Punto)ois.readObject());
					count++;
				}
				catch (EOFException e) {
					isAtEnd = true;
				}
			}
		}
		catch(FileNotFoundException e) {
			throw new FileNotFoundException("File non trovato.");
		}
		catch (IOException e) {
			throw new IOException("Errore apertura file");
		}
		catch (NullPointerException e) {
			punti = new Punto[100];
			count = 0;
		}
	}

    /**
     * Metodo che restituisce i punti.
     * @return Riferimento ad oggetto Punto[] contenente i punti.
     */
    public Punto[] getPunti() {
        Punto[] out = new Punto[punti.length];
        for (int i = 0; i < punti.length; i++) {
            if (punti[i] == null) out[i] = null;
            else out[i] = new Punto(punti[i]);
        }
        return out;
    }

    /**
     * Metodo che conta i punti.
     * @return Il conteggio dei punti.
     */
    public int getCount() {
        return count;
    }

    /**
     * Metodo per aggiungere un punto.
     * @param p Riferimento ad oggetto Punto
     * @return true se il parametro e' valido e la spezzata non ha troppi punti, false se una delle due condizioni non e' soddisfatta.
     */
    public boolean append(Punto p) {
        boolean out = true;
        if (count >= 100) out = false;
        else {
            punti[count] = new Punto(p);
            count++;
        } 
        return out;
    }

    /**
     * Metodo che rimuove un punto in una determinata posizione. WIP
     * @param pos Posizione da cui rimuovere un punto.
     */
    public void remove(int pos) {
        if (pos >= 0 && pos < punti.length) {
            punti[pos] = null;
            for (int i = pos; i < punti.length - 1; i++ ) {
                Punto tmp;
                tmp = punti[i];
                punti[i] = punti[i+1];
                punti[i+1] = tmp;
            }
        }
    }
    
    /**
     * Metodo che trasla tutti i punti nella spezzata.
     * @param dx Delta x traslazione
     * @param dy Delta y traslazione
     */
    public void trasla(int dx, int dy) {
        for (Punto el : punti) {
            if (el != null)el.trasla(dx,dy);
        }
    }

    /**
     * Metodo che restituisce lo stato dell'oggetto in una stringa.
     * @return Una stringa.
     */
    public String toString() {
        String out = "Numero punti: " + count + "\n";
        for (int i = 0; i < punti.length; i++) {
            if (punti[i] != null) out += String.format("\tPunto %d: %s\n", i, punti[i].toString());
        }
        return out;
    }
    
    /**
     * Metodo che confronta quest'oggetto con un'altro.
     * @param o Riferimento a oggetto Object
     * @return true se gli oggetti sono uguali, false se non lo sono
     */
    public boolean equals(Object o) {
        boolean out = true;
        if (o != null && o instanceof Spezzata) {
            if ( 
                !Arrays.equals( ((Spezzata)o).getPunti(), punti) ||
                ((Spezzata)o).getCount() != count
            ) out = false;
        }
        else out = false;
        return out;
    }
}
