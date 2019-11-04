public class Test {
    public static void main(String args[]) {
	Lampadina[] lampadario = new Lampadina[10];
	for (int x = 0; x < lampadario.length; x++){
	    lampadario[x] = new Lampadina(x+20);
	}
	for (int i = 0; i < 10; i++){
	    System.out.println("Run " + i);
	    for (int x = 0; x < lampadario.length; x++) {
		System.out.println("Lampadina " + x + ": " + lampadario[x].toString());
		for (float w=0; w<2;w+=0.0000001){}
	    }
	    System.out.println();
	}
    }
}
