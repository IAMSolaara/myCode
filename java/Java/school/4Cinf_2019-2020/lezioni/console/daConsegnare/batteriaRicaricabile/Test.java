public class Test {
	public static void main(String[] args) {
		Batteria b1 = new Batteria();
		Batteria b2 = new Batteria(b1);

		System.out.println(b1);
		System.out.println(b2);

		b1.utilizza(90);

		System.out.println(b1);

		if (!b1.utilizza(11)) System.out.println("SHIMATTAAAAAA");

		System.out.println(b1);
		System.out.println(b2);
		
		Batteria b3 = new Batteria(b1);

		System.out.println("b1 e b2 sono " + (b1.equals(b2) ? "uguali" : "diverse") );
		System.out.println("b1 e b3 sono " + (b1.equals(b3) ? "uguali" : "diverse") );
	}
}
