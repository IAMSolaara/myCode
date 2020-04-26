import java.util.Random;

import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.Timer;

import java.awt.Dimension;
import java.awt.Image;
import java.io.IOException;
import java.io.InputStream;
import java.security.SecureRandom;

public class AlzheimerMastermind {
    private Card tmp = null;
    private int count;
    public CardsPanel display;
    private int maxCardID;
    private int gridWidth;
    private int gridHeight;
    private int cardWidth;
    private int cardHeight;
    private int cardN;

    public static final int CHECK_NEXTCARD = -1;
    public static final int CHECK_WRONG = 0;
    public static final int CHECK_RIGHT = 1;

    public AlzheimerMastermind(int count, CardsPanel cp, int maxCardID, int cardWidth, int cardHeight) {
        this.count = count;
        this.cardN = count;
        this.display = cp;
        this.maxCardID = maxCardID;
        this.cardWidth = cardWidth;
        this.cardHeight = cardHeight;
    }

    public void restart() {
        //System.out.println("restarting");
        count = cardN;
        Card[] tmpcs = generateCards(count, maxCardID, cardWidth, cardHeight);
        display.displayCards(tmpcs);
    }

    public Card[] generateCards(int cardN, int maxCardID, int cardWidth, int cardHeight) {
        Card[] cards = new Card[cardN];
        //System.out.println(cards.length);
        SecureRandom rng = new SecureRandom();
        try {
            for (int i = 0; i < cards.length; i += 2) {
                int id = rng.nextInt(maxCardID) + 1;
                //System.out.println("Got ID: " + id);
                cards[i] = new Card(id,
                        new ImageIcon(
                                readFromResource("card.png").getImage().getScaledInstance(71, 96, Image.SCALE_DEFAULT)),
                        new ImageIcon(readFromResource(String.format("cards_%2d.png", id).replace(' ', '0')).getImage()
                                .getScaledInstance(cardWidth, cardHeight, Image.SCALE_DEFAULT)),
                        this);
                cards[i].setPreferredSize(new Dimension(cardWidth, cardHeight));
                cards[i].addActionListener(new CardListener());
                cards[i + 1] = new Card(id,
                        new ImageIcon(
                                readFromResource("card.png").getImage().getScaledInstance(71, 96, Image.SCALE_DEFAULT)),
                        new ImageIcon(readFromResource(String.format("cards_%2d.png", id).replace(' ', '0')).getImage()
                                .getScaledInstance(cardWidth, cardHeight, Image.SCALE_DEFAULT)),
                        this);
                cards[i + 1].setPreferredSize(new Dimension(cardWidth, cardHeight));
                cards[i + 1].addActionListener(new CardListener());
            }
            shuffleArray(cards);
        } catch (IOException e) {
            System.out.println(e.getMessage());

        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        }
        return cards;
    }

    public int check(Card in) {
        Card c1 = in;
        Card c2 = tmp;
        in.showCard();
        int out = CHECK_NEXTCARD;
        if (tmp == null || tmp == in)
            tmp = in; // get next card or got same card
        else { // a card has already been sent
            if (tmp.id == in.id) { // if cards match
                out = CHECK_RIGHT; // set output to RIGHT
                Timer t = new Timer(500, e -> {
                    c1.setVisible(false); // hide cards
                    c2.setVisible(false);
                });
                t.setRepeats(false);
                t.start();
                count -= 2; // decrement cound
                if (count == 0) { // if all cards are gone then win
                    //System.out.println("YOU WON!!");
                    new ExitPopup(this); // I'm sorry(n't) but I am not going to sent an exception through 4 different
                                         // classes just for this.
                }
            } else { // if cards dont match
                out = CHECK_WRONG;
                Timer t = new Timer(500, e -> {
                    c1.hideCard();
                    c2.hideCard();
                });
                t.setRepeats(false);
                t.start();
            }
            this.tmp = null; // get rid of tmp card
        }
        return out;
    }

    private void shuffleArray(Card[] in) {
        Random rng = new Random(System.currentTimeMillis());

        for (int i = 0; i < in.length; i++) {
            int pos = rng.nextInt(in.length);
            Card tmpc = in[i];
            in[i] = in[pos];
            in[pos] = tmpc;
        }
    }

    private ImageIcon readFromResource(String path) throws IOException, IllegalArgumentException {
        InputStream is = null;
        ImageIcon out = null;
        try {
            is = GUI.class.getResourceAsStream("resources/" + path);
            out = new ImageIcon(ImageIO.read(is));
        } catch (IOException e) {
            throw new IOException("Couldn't load file: resources/" + path);
        } catch (IllegalArgumentException e) {
            throw new IllegalArgumentException("Could not find file: `resources/" + path + "'. Is the name right?");
        }
        return out;
    }
}