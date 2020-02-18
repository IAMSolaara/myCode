import java.io.*;
import java.util.*;

public class AccessoCasuale {
	public static void main(String[] args) throws IOException{
		RandomAccessFile raf = new RandomAccessFile("testo.bin", "rw");
		
		//raf.writeChars("abcd");
		//raf.writeInt(255);
		byte[] bti = raf.readLine().getBytes();
		System.out.println(Arrays.toString(bti));
		raf.close();
	}
}
