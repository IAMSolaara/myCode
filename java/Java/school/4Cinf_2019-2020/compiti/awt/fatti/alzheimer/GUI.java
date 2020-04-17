import javax.imageio.ImageIO;
import javax.swing.ImageIcon;

import javax.swing.JFrame;
import javax.swing.JPanel;

import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.Image;
import java.io.IOException;
import java.io.InputStream;
import java.security.SecureRandom;
import java.util.Random;

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

    public static void shuffleArray(Card[] in) {
        Random rng = new Random(System.currentTimeMillis());

        for (int i = 0; i < in.length; i++) {
            int pos = rng.nextInt(in.length);
            Card tmpc = in[i];
            in[i] = in[pos];
            in[pos] = tmpc;
        }
    }

    public static void main(String[] args) {
        try {
            boolean debug = true;

            int maxCardID = 13;

            SecureRandom rng = new SecureRandom();

            int gridWidth = 4;
            int gridHeight = 3;

            int cardWidth = 71;
            int cardHeight = 96;

            JFrame mainWin = new JFrame("Alzheimer");
            mainWin.setSize(640, 480);
            mainWin.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            mainWin.setIconImage(
                                readFromResource("windowIcon.png").getImage().getScaledInstance(20, 20, Image.SCALE_DEFAULT));

            JPanel mainPanel = new JPanel(new GridLayout(gridWidth, gridHeight, 2, 2));

            int cardN = (gridWidth * gridHeight);
            if (debug)
                System.out.println("Quantity of cards: " + cardN);
            AlzheimerMastermind am = new AlzheimerMastermind(cardN);

            Card[] cards = new Card[cardN];

            for (int i = 0; i < cards.length; i += 2) {
                int id = rng.nextInt(maxCardID)+1;
                if (debug)
                    System.out.println(id);
                cards[i] = new Card(id,
                        new ImageIcon(
                                readFromResource("card.png").getImage().getScaledInstance(71, 96, Image.SCALE_DEFAULT)),
                        new ImageIcon(
                                readFromResource(String.format("cards_%2d.png", id).replace(' ', '0'))
                                        .getImage().getScaledInstance(cardWidth, cardHeight, Image.SCALE_DEFAULT)),
                        am);
                cards[i].setPreferredSize(new Dimension(cardWidth, cardHeight));
                cards[i].addActionListener(new CardListener());
                cards[i + 1] = new Card(id,
                        new ImageIcon(
                                readFromResource("card.png").getImage().getScaledInstance(71, 96, Image.SCALE_DEFAULT)),
                        new ImageIcon(
                                readFromResource(String.format("cards_%2d.png", id).replace(' ', '0'))
                                        .getImage().getScaledInstance(cardWidth, cardHeight, Image.SCALE_DEFAULT)),
                        am);
                cards[i + 1].setPreferredSize(new Dimension(cardWidth, cardHeight));
                cards[i + 1].addActionListener(new CardListener());
            }
            if (debug)
                System.out.println("Cards generated.");

            shuffleArray(cards);
            if (debug)
                System.out.println("Cards shuffled.");

            for (int i = 0; i < cards.length; i++) {
                mainPanel.add(cards[i]);
                if (debug) 
                    System.out.println("Card " + (i + 1) + " added.");
            }

            mainWin.getContentPane().add(mainPanel);
            mainWin.setVisible(true);
        } catch (IOException e) {
            System.out.println(e.getMessage());
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        }
    }
}