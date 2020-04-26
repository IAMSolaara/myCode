public class Test {
	public static void main(String args[]) {
		Lampadario lampadariottino = new Lampadario(new Lampadina(100), new Lampadina(151));
		Lampadario lampadariotto = new Lampadario(lampadariottino);

		System.out.println("Lampadariotto:   " + lampadariotto.toString());
		System.out.println("Lampadariottino: " + lampadariottino.toString());
		System.out.println("lampadariotto e lampadariottino sono " + (lampadariotto.equals(lampadariottino) ? "uguali" : "diversi"));
		lampadariotto.accendi();
		System.out.println("Lampadariotto e' " + (lampadariotto.isAcceso() ? "acceso" : "spento"));
		System.out.println("Lampadariotto:   " + lampadariotto.toString());
		System.out.println("Lampadariottino e' " + (lampadariottino.isAcceso() ? "acceso" : "spento"));
	}
}
