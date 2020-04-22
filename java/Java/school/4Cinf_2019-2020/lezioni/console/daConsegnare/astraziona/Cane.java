import java.util.Random;

public class Cane extends Mammifero {
	public Cane(double p) {
		super(p);
	}

	public Cane(Cane g) {
		super(g);
	}

	public String verso() {
		String out = "";
		Random sc = new Random(System.currentTimeMillis());
		for (int i = 0; i < sc.nextInt(16); i++) out +="Bau ";
		if (sc.nextBoolean()) out += "nigga.";
		else out += ".";
		return out;
	}

	public String toString() {
		return "Questo gatto pesa: " + peso;
	}

	public boolean equals(Object o) {
		boolean out = true;
		if (o != null && o instanceof Cane) {
			if (!super.equals((Mammifero)o)) out = false;
		}
		else out = false;
		return out;
	}
}
