public class LampTournament {
    public static void main(String args[]) {
	Lampadina[] lampadario = new Lampadina[10];
	int[] lampadine = new int[lampadario.length];
	
	for (int x = 0; x < lampadario.length; x++){
	    lampadario[x] = new Lampadina(x+20);
	    lampadine[x] = 1;
	}
	for (int i = 0; i < 10; i++){
	    System.out.println("Run " + i);
	    for (int x = 0; x < lampadario.length; x++) {
		if ((lampadine[x] == 1) && (!lampadario[x].isFulminata())) System.out.println("Lampadina " + x + ": " + lampadario[x].getPotenza() + "W, " + (lampadario[x].isAccesa() ? "accesa" : "spenta") + ", " + "integra");
		else {
		    System.out.println("Lampadina " + x + " morta!");
		    lampadine[x] = 0;
		}
		//		System.out.println("Lampadina " + x + ": " + lampadario[x].toString());
		
		for (float w=0; w<2;w+=0.0000001){}
	    }
	    System.out.println();
	}
    }
}
