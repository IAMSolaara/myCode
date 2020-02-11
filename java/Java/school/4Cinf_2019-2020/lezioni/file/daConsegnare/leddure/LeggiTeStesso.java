import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class LeggiTeStesso {
    public String getClassName() {
        return this.getClass().getName();
    }

    public static void main(String[] args) {
        LeggiTeStesso questo = new LeggiTeStesso();
        try {
            int n = 0;
            Scanner sc = new Scanner(new File( questo.getClassName() + ".java" ));
            while (sc.hasNext()) {
                System.out.println(sc.nextLine());
            }
            sc.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Usage: java " + questo.getClassName() + " [FILE]");
        }
    }
}
