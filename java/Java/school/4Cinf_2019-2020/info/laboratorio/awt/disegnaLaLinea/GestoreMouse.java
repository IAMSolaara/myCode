import java.awt.event.*;

public class GestoreMouse implements MouseListener {
	public void mouseClicked(MouseEvent e) {}
	public void mouseEntered(MouseEvent e) {}
	public void mouseExited(MouseEvent e) {}
	
	public void mousePressed(MouseEvent e) {
		Disegno par = (Disegno)e.getSource();
		par.newP1(new Punto(e.getX(), e.getY()));
	}

	public void mouseReleased(MouseEvent e) {
		Disegno par = (Disegno)e.getSource();
		par.newP2(new Punto(e.getX(), e.getY()));
		par.repaint();
	} 
}
