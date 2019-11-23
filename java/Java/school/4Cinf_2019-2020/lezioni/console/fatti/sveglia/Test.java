public class Test {
	public static void main(String[] args) {
		Sveglia s1 = new Sveglia(1, 1, 50);
		Sveglia s2 = new Sveglia(s1);
		s1.alarmSwitch();
		s1.alarmRegola(1, 2);
		System.out.println(s1);
		System.out.println(s2);

		for (int i=0;i<10;i++) {
			s1.avanza();
			System.out.println(s1);
		}
		
		Sveglia s3 = new Sveglia(s1);
		System.out.println("s1 e s3 sono " + (s1.equals(s3) ? "uguali" : "diverse"));
		System.out.println("s1 e s2 sono " + (s1.equals(s2) ? "uguali" : "diverse"));
	}
}
