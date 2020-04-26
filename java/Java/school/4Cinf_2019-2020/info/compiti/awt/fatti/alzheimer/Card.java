import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JPanel;
import java.awt.Image;


public class Card extends JButton{
    private static final long serialVersionUID = 8187263142514341646L;
    private ImageIcon img;
    private ImageIcon placeholder;
    private AlzheimerMastermind mm;

    public static final int CHECK_NEXTCARD = -1;
    public static final int CHECK_WRONG = 0;
    public static final int CHECK_RIGHT = 1;

    public int id;

    public Card(int id, ImageIcon placeholder, ImageIcon img, AlzheimerMastermind mm) {
        super(placeholder);
        this.img = img;
        this.placeholder = placeholder;
        this.id = id;
        this.mm = mm;
    }

    public int check() {
        return mm.check(this);
    }

    public void showCard() {
        //System.out.println("Showing...");
        this.setIcon(img);
        ((JPanel) getParent()).revalidate();
        ((JPanel) getParent()).repaint();
    }

    public void hideCard() {
        //System.out.println("Hiding...");
        this.setIcon(placeholder);
        ((JPanel) getParent()).revalidate();
        ((JPanel) getParent()).repaint();
    }

    public int getID() {return id;}
}