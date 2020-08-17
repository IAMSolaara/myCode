import java.io.*;

public class LeggiRAF {
	public static void main(String[] args) throws IOException{
		RandomAccessFile raf = new RandomAccessFile("testo.bin", "rw");
		boolean done = false;
		while (!done) {
			try {
				System.out.println(raf.readInt());
			}
			catch(EOFException e) {
				done = true;
			}
		}
		raf.close();
	}
}
