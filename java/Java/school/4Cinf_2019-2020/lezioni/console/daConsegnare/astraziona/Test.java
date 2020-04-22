import java.util.Random;

public class Test {
	public static final double MINP = 4;
	public static final double MAXP = 8;

	public static void main(String[] args) {
		Random rng = new Random(System.currentTimeMillis());
		Mammifero[] mammiferi = new Mammifero[rng.nextInt(10)];

		for (int i = 0; i < mammiferi.length; i++) {
			if (rng.nextBoolean()) mammiferi[i] = new Cane(rng.nextDouble()*(MAXP-MINP)+MINP);
			else mammiferi[i] = new Gatto(rng.nextDouble()*(MAXP-MINP)+MINP);
		}

		for (int i = 0; i < mammiferi.length; i++) {
			System.out.println(mammiferi[i].verso());
		}
	}
}
