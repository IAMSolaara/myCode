import java.io.File;
import java.io.FileNotFoundException;

public class Test {
    public static void main(String[] args) {
        try {
            File f = new File("./test.txt");
            Albero a = new Albero();
            a.caricaAlbero(f);
        }
        catch (FileNotFoundException e) {
            System.out.println(e.getMessage());
        }
        catch (NullPointerException e) {
            System.out.println(e.getMessage());
        }
    }
}