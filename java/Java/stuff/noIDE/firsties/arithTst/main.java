public class main {
    public static void main(String[] args){
	for (String i : args) {
	    if (i == "-lol") System.out.println("dont u even try");
	}
	int x = 0x55, y=0xAA;
	System.out.println("Var x: " + x);
	System.out.println("Var y: " + y);
	System.out.println("AND: " + (x & y));
	System.out.println("OR: " + (x | y));
	String[] test = {"ur ", "mom ", "gae", "!\n"};
	for (String i : test) System.out.print(i);
    }
}
