import java.io.*;
import java.util.*;

public class Serializziona {
	public static void main(String[] args) {
		try {
			FileOutputStream fos = new FileOutputStream(new File("punti.ser"));
			ObjectOutputStream oos = new ObjectOutputStream(fos);
			Random rng = new Random(System.currentTimeMillis());
			int cnt = rng.nextInt(10)+10;
			for (int i = 0; i < cnt; i++) {
				oos.writeObject(new Punto(rng.nextDouble()*1000, rng.nextDouble()*1000));
			}
			oos.close();
			fos.close();
		}
		catch(IOException e) {
			System.out.println("General I/O failure.");
		}
	}
}
