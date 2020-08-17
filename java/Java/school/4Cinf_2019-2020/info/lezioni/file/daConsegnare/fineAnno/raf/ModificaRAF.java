import java.io.*;

public class ModificaRAF {
	public static void main(String[] args) throws IOException{
		RandomAccessFile raf = new RandomAccessFile("testo.bin", "rw");
		boolean done = false;
		while (!done) {
			try {
				long pos = raf.getFilePointer();
				int n = raf.readInt();
				raf.seek(pos);
				raf.writeInt(n*2);
			}
			catch(EOFException e) {
				done = true;
			}
		}
		raf.close();
	}
}
