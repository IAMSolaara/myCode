import java.awt.*;

public class GUI {
	public static void main(String[] args) {
		int width  = 800;
		int height = 600;

		//set up frame
		Frame fr1 = new Frame("Titolo");
		fr1.setSize(width,height);
		fr1.setVisible(true);
		fr1.addWindowListener(new GestoreFinestra());
		
		Disegno dis = new Disegno();
		fr1.add(dis);

		dis.setSize(width,height);
		dis.addMouseListener(new GestoreMouse());
		dis.addKeyListener(new GestoreTastiera());
	}
}
