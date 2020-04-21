import javax.imageio.ImageIO;
import javax.swing.ImageIcon;

import javax.swing.JFrame;
import java.awt.GridLayout;
import java.awt.Image;
import java.io.IOException;
import java.io.InputStream;

public class GUI {
    private static ImageIcon readFromResource(String path) throws IOException, IllegalArgumentException {
        InputStream is = null;
        ImageIcon out = null;
        try {
            is = GUI.class.getResourceAsStream("resources/" + path);
            out = new ImageIcon(ImageIO.read(is));
        } catch (IOException e) {
            throw new IOException("Couldn't load file: resources/" + path);
        } catch (IllegalArgumentException e) {
            throw new IllegalArgumentException("Could not find file: `resources/"+path+"'. Is the name right?");
        }
        return out;
    }

    public static void main(String[] args) {
        try {
            boolean debug = false;

            int maxCardID = 13;

            int gridWidth = 4;
            int gridHeight = 3;

            int cardWidth = 71;
            int cardHeight = 96;

            int cardN = (gridWidth * gridHeight);


            JFrame mainWin = new JFrame("Alzheimer");
            mainWin.setSize(640, 480);
            mainWin.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            mainWin.setIconImage(
                                readFromResource("windowIcon.png").getImage().getScaledInstance(20, 20, Image.SCALE_DEFAULT));

            CardsPanel mainPanel = new CardsPanel(new GridLayout(gridWidth, gridHeight, 2, 2));
            AlzheimerMastermind am = new AlzheimerMastermind(cardN, mainPanel, maxCardID, cardWidth, cardHeight);

            if (debug)
                System.out.println("Quantity of cards: " + cardN);

            Card[] cards = am.generateCards(cardN, maxCardID, cardWidth, cardHeight);
            mainPanel.displayCards(cards);

            mainWin.getContentPane().add(mainPanel);
            mainWin.setVisible(true);
        } catch (IOException e) {
            System.out.println(e.getMessage());
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        }
    }
}