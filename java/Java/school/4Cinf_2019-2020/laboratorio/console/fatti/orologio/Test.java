public class Test {
    public static void main(String[] args){
	Orologio clk = new Orologio(21, 12, 1);
	Orologio clk2 = new Orologio(clk);

	System.out.println(clk.toString());
	System.out.println(clk2.toString());
	for (int x = 0; x < 3600; x++) {
	    clk.avanza();
	    System.out.println("Clock 1: " + clk.toString());
	    System.out.println("Clock 2: " + clk2.toString());
	    
	} 
    }
}
