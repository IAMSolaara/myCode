import java.io.*;

public class CreaRAF {
	public static void main(String[] args) throws IOException{
		RandomAccessFile raf = new RandomAccessFile("testo.bin", "rw");
		
		raf.writeInt(255);
		raf.writeInt(162);
		raf.writeInt(-5134);
		raf.close();
	}
}
