import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CardListener implements ActionListener{
    public void actionPerformed(ActionEvent e) {
        Card parente = ((Card)e.getSource());
        parente.showCard();
        parente.check();
    }
}
