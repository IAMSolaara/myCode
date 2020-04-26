import java.awt.event.*;

public class GestoreMouse implements MouseListener {
	public void mouseClicked(MouseEvent e) {
		
		Disegno par = (Disegno)e.getSource();
		par.append(new Punto(e.getX(), e.getY()));
		par.repaint();
	}
	public void mouseEntered(MouseEvent e) {}
	public void mouseExited(MouseEvent e) {}
	public void mousePressed(MouseEvent e) {}
	public void mouseReleased(MouseEvent e) {}
}
