import java.io.*;

public class LeggiDaBinario {
    public static void main(String[] args) {
        try {
            FileInputStream fis = new FileInputStream(new File("puntiBurdi.bin"));
            DataInputStream dis = new DataInputStream(fis);

            boolean done = false;
            while (!done) {
                try {
                   System.out.println(dis.readDouble());
                }
                catch (EOFException e) {
                    done = true;
                }
            }

            dis.close();
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }
    
}