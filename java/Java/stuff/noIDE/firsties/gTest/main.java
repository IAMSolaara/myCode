import java.util.Scanner;

public class main {
    static public void main(String args[]){
	System.out.println("Is your mom gea? (true/false)");
	Scanner fromConsole = new Scanner(System.in);
	//	boolean cnd = fromConsole.nextBoolean();
	checkgae(fromConsole.nextBoolean());


    }
    static void checkgae(boolean sunny){
	if (sunny) System.out.println("I see you're honest. Good boyo");
	else throw new SecurityException("GET OUT YOU LIAR!");
    }
}
