import java.util.Random;

public class Gatto extends Mammifero {
	public Gatto(double p) {
		super(p);
	}

	public Gatto(Gatto g) {
		super(g);
	}

	public String verso() {
		String out = "";
		Random sc = new Random(System.currentTimeMillis());
		for (int i = 1; i < sc.nextInt(16); i++) out +=" Miao";
		if (sc.nextBoolean()) out += " nigga.";
		else out += ".";
		return out;
	}

	public String toString() {
		return "Questo gatto pesa: " + peso;
	}

	public boolean equals(Object o) {
		boolean out = true;
		if (o != null && o instanceof Gatto) {
			if (!super.equals((Mammifero)o)) out = false;
		}
		else out = false;
		return out;
	}
}
