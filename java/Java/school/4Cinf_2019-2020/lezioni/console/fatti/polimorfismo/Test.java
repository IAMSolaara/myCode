import java.util.Random;

public class Test {
	public static void main(String[] args) {
		Random rng = new Random(System.currentTimeMillis());

		Orologio o;
		
		if (rng.nextInt(10) > 8) o = new Sveglia(23, 59, 59);
		else o = new Orologio(23, 59, 59);

		if (o instanceof Sveglia) {
			((Sveglia)o).alarmSwitch();
		}

		o.avanza();

		System.out.println(o);

	}
}
