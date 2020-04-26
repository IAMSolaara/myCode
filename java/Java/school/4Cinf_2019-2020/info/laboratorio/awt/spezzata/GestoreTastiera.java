import java.awt.*;
import java.awt.event.*;

public class GestoreTastiera implements KeyListener {
    public void keyTyped(KeyEvent e) {}
  
    public void keyPressed(KeyEvent e) {
        Disegno par = (Disegno)e.getSource();
        int speed = (e.isShiftDown() ? 10 : 1);

        switch (e.getKeyCode()) {
            case KeyEvent.VK_UP:
                par.trasla(0,-speed);
                break;
            case KeyEvent.VK_DOWN:
                par.trasla(0,speed);
                break;
            case KeyEvent.VK_LEFT:
                
                par.trasla(-speed,0);
                break;
            case KeyEvent.VK_RIGHT:
                
                par.trasla(speed,0);
                break;
        }
        par.repaint();
    }
    
    public void keyReleased(KeyEvent e) {}
}