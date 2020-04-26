import java.io.File;
import java.io.FileNotFoundException;

public class Test {
    public static void main(String[] args) {
        try {
            File f = new File("./test.txt");
            File f2 = new File("./test2.txt");
            Albero a = new Albero();
            Albero a2 = new Albero();
            a.caricaAlbero(f);
            a2.caricaAlbero(f2);
            System.out.println("Albero: "+a);
            System.out.println("Albero: "+a2);
            a.merge(a2, "Gesu'");
            System.out.println("Albero: "+a);
            //System.out.println(a.ricerca("Mario"));
        }
        catch (FileNotFoundException e) {
            System.out.println(e.getMessage());
        }
        catch (NullPointerException e) {
            System.out.println(e.getMessage());
        }
    }
}
