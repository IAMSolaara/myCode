import javax.swing.Timer;

public class AlzheimerMastermind {
    private Card tmp = null;
    private int count;

    public static final int CHECK_NEXTCARD = -1;
    public static final int CHECK_WRONG = 0;
    public static final int CHECK_RIGHT = 1;

    public AlzheimerMastermind(int count){
        this.count = count;
    }

    public int check(Card in) {
        Card c1 = in;
        Card c2 = tmp;
        in.showCard();
        int out = CHECK_NEXTCARD;
        if (tmp == null || tmp == in) tmp = in;  //get next card or got same card
        else {      //a card has already been sent
            if (tmp.id == in.id) { //if cards match
                out = CHECK_RIGHT; //set output to RIGHT
                Timer t = new Timer(500, e -> {
                    c1.setVisible(false);  //hide cards
                    c2.setVisible(false);
                });
                t.setRepeats(false);
                t.start();
                count -= 2;             //decrement cound
                if (count == 0) {       //if all cards are gone then win
                    System.out.println("YOU WON!!");
                    System.exit(0);     //I'm sorry(n't) but I am not going to sent an exception through 4 different classes just for this.
                }
            }
            else { //if cards dont match
                out = CHECK_WRONG;
                Timer t = new Timer(500, e -> {
                    c1.hideCard();
                    c2.hideCard();
                });
                t.setRepeats(false);
                t.start();
            }
            this.tmp = null; //get rid of tmp card
        }
        return out;
    }
}