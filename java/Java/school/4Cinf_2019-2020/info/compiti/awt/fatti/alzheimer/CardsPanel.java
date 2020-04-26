import javax.swing.JPanel;
import java.awt.LayoutManager;

public class CardsPanel extends JPanel{

    private static final long serialVersionUID = -4408735925886770848L;

    public CardsPanel(LayoutManager layout) {
        super(layout);
    }

    public void displayCards(Card[] cards) {
        //System.out.println(cards);
        //System.out.println("Flushing cards...");
        removeAll();
        //System.out.println("Adding new cards...");
        for (Card el : cards) {
            add(el);
        }
        //System.out.println("Revalidating self...");
        revalidate();
        //System.out.println("Repainting self...");
        repaint();
        /*for (Component el : getComponents()) {
            System.out.println(el instanceof Card);
        }*/
    }

}