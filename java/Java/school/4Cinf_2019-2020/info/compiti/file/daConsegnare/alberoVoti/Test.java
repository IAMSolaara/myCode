import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Test {
    public static void main(String[] args) {
        try {
            File f = new File("./test.txt");
            Albero a = new Albero();
            a.caricaAlbero(f);
            System.out.println("Simmetrica: "+a.toString());
            System.out.println("Anticipata: "+a.visitaAnticipata());
            System.out.println("Posticipata: "+a.visitaPosticipata());
            System.out.println("Foglie: "+a.contaFoglie());
            System.out.println("Nodi: "+a.contaNodi());
            Scanner stdin = new Scanner(System.in);
            int v = stdin.nextInt();
            System.out.println("" + v + " e': " + a.classifica(v));
        }
        catch (FileNotFoundException e) {
            System.out.println(e.getMessage());
        }
        catch (NullPointerException e) {
            System.out.println(e.getMessage());
        }
    }
}
