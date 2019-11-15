<<<<<<< HEAD
/*
 *
 *
 */
/*



   */
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class main {
    int clicks=0;
    public static void main(String args[]) {
	
	JFrame frame = new JFrame("Clicker Program");
	frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	frame.setSize(300,300);
	JPanel panelN = new JPanel();
	JPanel butPan = new JPanel();
	JLabel label = new JLabel("Clicks: " + clicks);
	JButton button = new JButton("Click");
	button.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e){
		    clicks=clicks+1;
		    label.setText("Clicks: " + clicks);
		}
	    });
	panelN.add(label);
	butPan.add(button);
	frame.getContentPane().add(BorderLayout.NORTH, panelN);
	frame.getContentPane().add(butPan);
    }
}
=======
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class main {
    int clicks=0;
    public static void main(String args[]) {
	
	JFrame frame = new JFrame("Clicker Program");
	frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	frame.setSize(300,300);
	JPanel panelN = new JPanel();
	JPanel butPan = new JPanel();
	JLabel label = new JLabel("Clicks: " + clicks);
	JButton button = new JButton("Click");
	button.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e){
		    clicks=clicks+1;
		    label.setText("Clicks: " + clicks);
		}
	    });
	panelN.add(label);
	butPan.add(button);
	frame.getContentPane().add(BorderLayout.NORTH, panelN);
	frame.getContentPane().add(butPan);
    }
}
>>>>>>> 5f60b881b453f754b63e2ea06b2fcc7e9ad7f739
