import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

import javax.swing.JButton;

public class ExitPopup {
    public ExitPopup(AlzheimerMastermind am) {
        JFrame popup = new JFrame("popup test");
        popup.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        popup.setSize(180, 90);
        JPanel top = new JPanel();
        top.setSize(popup.getWidth(), 20);
        top.setLocation(0,0);
        top.add(new JLabel("You won! Wanna retry?"));
        JPanel bottom = new JPanel();
        bottom.setSize(popup.getWidth(), popup.getHeight() - top.getHeight());
        bottom.setLocation(0,20);
        JButton restartButton = new JButton("Yes");
        restartButton.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e) {
                am.restart();
                popup.dispose();
            }
        });
        JButton  exitButton = new JButton("No");
        exitButton.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });
        bottom.add(exitButton);
        bottom.add(restartButton);
        popup.getContentPane().setLayout(null);
        popup.getContentPane().add(top);
        popup.getContentPane().add(bottom);

        popup.setVisible(true);
    }
}