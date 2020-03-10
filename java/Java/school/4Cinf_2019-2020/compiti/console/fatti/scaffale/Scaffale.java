/**
    @author Lorenzo Cauli
    @version forse?
 */

/*
    - scaffale: Libro[][]
    - sdim: int
    - rdim: int

    + Scaffale(in sdim, rdim: int)

    - init(in sdim, rdim: int): void

    + find(in r,s: int): Libro
    + insert(in l: Libro, r,s: int): boolean
    + isFull(): boolean
    
    + toString(): String
*/

public class Scaffale {
    private Libro[][] scaffale;
    private int sdim;
    private int rdim;

    /**Costruttore date le dimensioni
        @param sdim Dimensioni scaffale
        @param rdim Dimensioni ripiani
     */
    public Scaffale(int sdim, int rdim) {
        init(sdim,rdim);
    }

    /**Metodo per init
        @param sdim Dimensioni scaffale
        @param rdim Dimensioni ripiani
     */
    private void init(int sdim, int rdim) {
        if (sdim > 0 && rdim > 0) {
            this.sdim = sdim;
            this.rdim = rdim;
        }
        else {
            this.sdim = 1;
            this.rdim = 1;
        }
        scaffale = new Libro[this.sdim][this.rdim];
    }

    /**Metodo accessorio
        @param r Ripiano dove cercare
        @param l Posizione nel ripiano dove cercare
        @return Riferimento a oggetto Libro
     */
    public Libro find(int r, int l) {
        Libro out = null;
        if ((r >= 0 && l >= 0) && (r < sdim && l < rdim)) {
            if (scaffale[r][l] != null) out = new Libro(scaffale[r][l]);
        }
        return out;
    }
    
    /**Metodo modificatore
        @param in Riferimento a oggetto Libro
        @param r Ripiano dove cercare
        @param l Posizione nel ripiano dove cercare
        @return true se il libro e' valido, senno' false
     */
    public boolean insert(Libro in, int r, int l) {
        boolean out = true;
        if ((r >= 0 && l >= 0) && (r < sdim && l < rdim) && in != null) scaffale[r][l] = new Libro(in);
        else out = false;
        return out;
    }

    /**Metodo che controlla se lo scaffale e' pieno
        @return true se e' pieno, senno' false
     */
    public boolean isFull() {
        boolean out = true;
        for (Libro[] sc : scaffale) {
            for (Libro el : sc) {
                if (el == null) out = false;
            }
        }
        return out;
    }

    /**Metodo che restituisce lo stato di un'oggetto in una stringa
        @return una stringa ancora piu' burda
     */
    public String toString() {
        return "" + sdim + " ripiani ogniuno per massimo " + rdim + " libri";
    }

    public static void main(String[] args) {
        int r = 5;
        int l = 16;
        Scaffale s = new Scaffale(r,l);
        System.out.println(s);
        s.insert(new Libro(null,null), 2,1);
        System.out.println(s.isFull());
    }
}