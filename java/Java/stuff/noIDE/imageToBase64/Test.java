import java.util.Base64;
import java.io.File;
import java.io.FileInputStream;
import java.io.PrintWriter;

public class Test {
	public static void main(String[] args){
		try {
			File f = new File("/home/lorecast162/Documents/bg.png");
			PrintWriter out = new PrintWriter("./base64.txt");
			String encoded = encodeToBase64(f);
			out.println(encoded);
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}

	public static String encodeToBase64(File f) {
		String out = null;
		try {
			FileInputStream inStream = new FileInputStream(f);
			byte[] bytes = new byte[(int) f.length()];
			inStream.read(bytes);
			out = Base64.getEncoder().encodeToString(bytes);
		} catch (Exception e) {
			e.printStackTrace();
		}
		return out;
	}
}
