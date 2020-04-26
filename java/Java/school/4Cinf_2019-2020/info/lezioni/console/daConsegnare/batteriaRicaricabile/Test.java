public class Test {
	public static void main(String[] args) {
		Batteria b1 = new Batteria();
		BatteriaRicaricabile b2 = new BatteriaRicaricabile(b1);
		

		System.out.println(b1);
		System.out.println(b2);

		b2.utilizza(90);

		System.out.println(b1);

		if (!b2.utilizza(11)) System.out.println("OH NOOO");
		b2.ricarica();
		if (!b2.utilizza(11)) System.out.println("OH NOOO");
		else System.out.println("*slaps arms together* NAAISU");

		System.out.println(b1);
		System.out.println(b2);
		
		Batteria b3 = new Batteria(b2);

		System.out.println("b1 e b2 sono " + (b1.equals(b2) ? "uguali" : "diverse") );
		System.out.println("b2 e b3 sono " + (b2.equals(b3) ? "uguali" : "diverse") );
	}
}
