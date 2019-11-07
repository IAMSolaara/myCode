import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.File;
import javax.imageio.ImageIO;

public class main {
    
    public static void main(String[] args) {
	ImageIcon good = new ImageIcon("./good.png");
	ImageIcon bad = new ImageIcon("./bad.png");
	
	JFrame frame = new JFrame("162test");                             //string arg to JFrame is win title --162
	frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);             //set close behaviour --162
	frame.setSize(300,300);                                           //set win size --162
	JPanel panelN = new JPanel();
	JPanel panelS = new JPanel();
	JButton button1 = new JButton("Press");                           //create button object --162
	JButton button2 = new JButton("Don't");                           //create button object --162
	JLabel label = new JLabel("");
	
	button2.addActionListener(new ActionListener() {
	    public void actionPerformed(ActionEvent e){
		label.setText("BAD BOYO");
		frame.setIconImage(bad.getImage());
	    }
	});
	button1.addActionListener(new ActionListener() {
	    public void actionPerformed(ActionEvent e){
		label.setText("GOOD BOYO");
		frame.setIconImage(good.getImage());
	    }
	});
	panelS.add(button2);
	panelS.add(button1);
	panelN.add(label);
	frame.getContentPane().add(BorderLayout.SOUTH, panelS);            //add panel to frame
	frame.getContentPane().add(BorderLayout.NORTH, panelN);            //add panel to frame
	frame.setVisible(true);                                           //show frame to the world --162
        
    }
}
