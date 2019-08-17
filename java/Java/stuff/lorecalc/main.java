import com.mentalabs.Calc;
import java.util.Scanner;

public class main {
    public static void main(String args[]) {
	Scanner stdin = new Scanner(System.in);
	Calc calcolatrice = new Calc();
	String operation;
	System.out.println("Specify first operand.");
	calcolatrice.setX(stdin.nextDouble());
	System.out.println("Specify second operand.");
	calcolatrice.setY(stdin.nextDouble());
	System.out.println("Specify operation.");
	calcolatrice.setOp(stdin.next());
	calcolatrice.calcRun();
	System.out.println(calcolatrice.getResult());

	
	
    }
}
