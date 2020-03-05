public class Test {
	public static void main(String[] args) {
		Condensatore c1 = new Condensatore(015);
		Condensatore c2 = new Condensatore(1552);

		System.out.println(c1);
		System.out.println(c2);
		System.out.println("c1 e c2 sono " + ( c1.equals(c2) ? "uguali" : "diversi" ));
		System.out.println(c1.getReattanza(1000));

		Induttore i1 = new Induttore(015);
		Induttore i2 = new Induttore(1552);

		System.out.println(i1);
		System.out.println(i2);
		System.out.println("i1 e i2 sono " + ( i1.equals(i2) ? "uguali" : "diversi" ));
		System.out.println(i1.getReattanza(1000));
	}
}
