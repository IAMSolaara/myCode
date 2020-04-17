import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

import javax.swing.JButton;

public class ExitPopup {
    public ExitPopup() {
        JFrame popup = new JFrame("popup test");
        popup.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        popup.setSize(160, 50);
        JPanel top = new JPanel();
        top.setSize(160, 20);
        top.setLocation(0,0);
        top.add(new JLabel("You won!"));
        JPanel bottom = new JPanel();
        bottom.setSize(160, 30);
        bottom.setLocation(0,20);
        JButton exitButton = new JButton("OK");
        exitButton.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });
        bottom.add(exitButton);
        popup.getContentPane().setLayout(null);
        popup.getContentPane().add(top);
        popup.getContentPane().add(bottom);

        popup.setVisible(true);
    }
}