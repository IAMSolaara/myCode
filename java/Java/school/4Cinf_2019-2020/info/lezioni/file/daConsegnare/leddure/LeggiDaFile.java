import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class LeggiDaFile {
    public String getClassName() {
        return this.getClass().getName();
    }
    public static void main(String[] args) {
        LeggiDaFile questo = new LeggiDaFile();
        try {
            int n = 0;
            Scanner sc = new Scanner(new File(args[0]));
            while (sc.hasNext()) {
                n += sc.nextInt();
            }
            System.out.println(n);
            sc.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Usage: java " + questo.getClassName() + " [FILE]");
        }
    }
}
