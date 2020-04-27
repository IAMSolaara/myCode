import java.io.File;
import java.io.FileNotFoundException;
//import java.util.Scanner;

public class Test {
    public static void main(String[] args) {
        try {
            File f = new File("./test.txt");
            File f2 = new File("./test2.txt");
            Albero a = new Albero();
            Albero a2 = new Albero();
            a.caricaAlbero(f);
            System.out.println("a: \n" + a.toString());
            //a2.caricaAlbero(f2);
            //System.out.println("a2: \n" + a2.toString());
            //a.merge(a2, "Mimmo");
            //System.out.println("a: \n"+a.export());

            //System.out.println(String.format("Madre: %s, Padre: %s", parents[0] == null? "" : parents[0] , parents[1] == null ? "" : parents[1]));
            System.out.println(a.aggiungiGenitore("Enza", "Achtung", true));
            System.out.println("a: \n" + a.toString());

        }
        catch (FileNotFoundException e) {
            System.out.println(e.getMessage());
        }
        catch (NullPointerException e) {
            System.out.println(e.getMessage());
        }
    }
}
