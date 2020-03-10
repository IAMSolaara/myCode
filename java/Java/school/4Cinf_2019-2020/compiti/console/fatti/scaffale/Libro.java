/**
    @author Lorenzo Cauli
    @version no
*/

/*
    - titolo: String
    - autore: String

    + Libro(in titolo, autore: String)
    + Libro(in l: Libro)

    + getTitolo(): String
    + getAutore(): String
    
    + toString(): String
    + equals(in o: Object): boolean
*/

public class Libro {
    private String titolo;
    private String autore;

    /**Costruttore dati titolo e autore
        @param titolo Titolo libro.
        @param autore Autore libro.
     */
    public Libro(String titolo, String autore) {
        if (titolo != null && autore != null) {
            this.titolo = titolo;
            this.autore = autore;
        }
        else {
            this.titolo = "Come conquistare le donne in modo facile!! Edizione 2049";
            this.autore = "Mario Rossi";
        }
    }

    /**Costruttore di copia.
        @param l Riferimento a oggetto Libro
     */
    public Libro(Libro l) {
        if (l != null) {
            titolo = l.getTitolo();
            autore = l.getAutore();
        }
        else {
            this.titolo = "Come conquistare le donne in modo facile!! Edizione 2049";
            this.autore = "Mario Rossi";
        }
    }

    /**Metodo accessorio
        @return Titolo libro
     */
    public String getTitolo() {return titolo;}
    
    /**Metodo accessorio
        @return Autore libro
     */
    public String getAutore() {return autore;}

    /**Metodo che restituisce lo stato dell'oggetto in una stringa
        @return una stringa burda.
     */
    public String toString() {return titolo + " scritto da " + autore;}

    /**Metodo che confronta lo stato di due oggetti
        @param o Riferimento a oggetto Object
        @return true se sono uguali, senno' false
    */
    public boolean equals(Object o) {
        boolean out = true;
        if (o != null && o instanceof Libro) {
            if (
                !((Libro)o).getTitolo().equals(titolo) ||
                !((Libro)o).getAutore().equals(autore)
            ) out = false;
        } else out = false;
        return out;
    }

    public static void main(String[] args) {
        Libro l = new Libro("jaja lol www", "ur mom");
        Libro l2 = new Libro(null, null);
        Libro l3 = new Libro(l);
        System.out.println(l);
        System.out.println(l2);
        System.out.println(l.equals(l2));
        System.out.println(l.equals(l3));
    }
}