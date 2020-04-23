import java.io.File;
import java.io.FileNotFoundException;

public class Test {
    public static void main(String[] args) {
        try {
            File f = new File("./test.txt");
            Albero a = new Albero();
            a.caricaAlbero(f);
            System.out.println("Anticipata: "+a.visitaAnticipata());
            System.out.println("Simmetrica: "+a.visitaSimmetrica());
            System.out.println("Posticipata: "+a.visitaPosticipata());
            System.out.println("Foglie: "+a.contaFoglie());
            System.out.println("Nodi: "+a.contaNodi());
            System.out.println(a.ricerca(90));
        }
        catch (FileNotFoundException e) {
            System.out.println(e.getMessage());
        }
        catch (NullPointerException e) {
            System.out.println(e.getMessage());
        }
    }
}
