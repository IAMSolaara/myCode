import java.io.*;
import java.util.Scanner;

public class ScriviInBinario {
	public static void main(String[] args) {
		try {
			FileOutputStream fos = new FileOutputStream(new File("puntiBurdi.bin"));
			DataOutputStream dos = new DataOutputStream(fos);

			Scanner sc = new Scanner(new File("puntiTesti.txt"));
			
			while (sc.hasNext()) {
				dos.writeDouble(sc.nextDouble());
			}

			sc.close();		

			dos.close();
			fos.close();
		}
		catch(IOException e) {
			e.printStackTrace();
		}
	}
}
