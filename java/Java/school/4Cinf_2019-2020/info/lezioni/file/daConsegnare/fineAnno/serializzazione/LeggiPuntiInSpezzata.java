import java.io.*;

public class LeggiPuntiInSpezzata {
    public static void main(String[] args) {
        try {
            Spezzata s = new Spezzata();
            FileInputStream fis = new FileInputStream(new File("punti.ser"));
            ObjectInputStream ois = new ObjectInputStream(fis);
            boolean done = false;
            while (!done) {
                try {
                    s.append( ((Punto)ois.readObject()) );
                }
                catch (EOFException e) {
                    done = true;
                }
                catch (ClassNotFoundException e) {
                    System.out.println("Classe non trovata?");
                }
            }

            System.out.println(s);
        }
        catch (FileNotFoundException e) {
            System.out.println("File non trovato");
        }
        catch (IOException e) {
            System.out.println("Errore di I/O");
        }
    }
}