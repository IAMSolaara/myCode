import com.mentalabs.Calc;
import java.util.Scanner;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;


public class Main {
    public static void main(String args[]) {
	String op[] = {"+", "-", "*", "/"};
	Scanner stdin = new Scanner(System.in);
	Calc calcolatrice = new Calc();

	JFrame mainWin = new JFrame("lorecast162's GUI Calculator with objects.");
	mainWin.setSize(450,300);
	mainWin.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	
	
	JPanel panelN = new JPanel();
	JLabel resLabel = new JLabel("");
	panelN.add(resLabel);
	
	JPanel panelS = new JPanel();
	JTextField fact1 = new JTextField(10);
	JTextField fact2 = new JTextField(10);
	JButton goButton = new JButton("Run");
	JComboBox opSel = new JComboBox(op);

	goButton.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
		    calcolatrice.setX(Double.valueOf(fact1.getText()));
		    calcolatrice.setY(Double.valueOf(fact2.getText()));
		    calcolatrice.setOp((String)opSel.getSelectedItem());
		    calcolatrice.calcRun();
		    resLabel.setText(Double.toString(calcolatrice.getResult()));
		    //next are for debugging
		    /*
		    System.out.println(Double.valueOf(fact1.getText()));
		    System.out.println(Double.valueOf(fact2.getText()));
		    System.out.println((String)opSel.getSelectedItem());
		    System.out.println(calcolatrice.getResult());
		    System.out.println();
		    System.out.println(calcolatrice.getX());
		    System.out.println(calcolatrice.getY());
		    System.out.println(calcolatrice.getOp());
		    System.out.println(calcolatrice.getResult());
		    System.out.println();
		    */
		}
	    });
	panelS.add(fact1);
	panelS.add(opSel);
	panelS.add(fact2);
	panelS.add(goButton);

	mainWin.getContentPane().add(BorderLayout.NORTH, panelN);
	mainWin.getContentPane().add(BorderLayout.SOUTH, panelS);

	mainWin.setVisible(true);
    }
}
