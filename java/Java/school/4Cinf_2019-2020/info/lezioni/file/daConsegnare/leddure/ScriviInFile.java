import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;

public class ScriviInFile {
    public String getClassName() {
        return this.getClass().getName();
    }
    public static void main(String[] args) {
        ScriviInFile questo = new ScriviInFile();
        try {
            PrintStream fps = new PrintStream(new File(args[0]));
            Scanner sc = new Scanner(System.in);

            while (sc.hasNext()) {
                fps.println(sc.nextInt());
            }

            sc.close();
            fps.close();
        } catch (FileNotFoundException e) {
            System.out.println("Impossibile creare il file.");
        }
        catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Usage: java " + questo.getClassName()+ " [FILE]");
        }
    }
}