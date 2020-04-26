import java.awt.*;

public class Utils {
	public static final double map(double n, double start1, double stop1, double start2, double stop2) {
		return (n - start1) / (stop1 - start1) * (stop2 - start2)+ start2; 
	}

	static public Color hslColor(double h, double s, double l) {
		double q, p, r, g, b;

		if (s == 0) {
			r = g = b = l; // achromatic
		} else {
			q = l < 0.5 ? (l * (1 + s)) : (l + s - l * s);
			p = 2 * l - q;
			r = hue2rgb(p, q, h + 1.0f / 3);
			g = hue2rgb(p, q, h);
			b = hue2rgb(p, q, h - 1.0f / 3);
		}
		return new Color(Math.round(r * 255), Math.round(g * 255), Math.round(b * 255));
	}


	private static double hue2rgb(double p, double q, double h) {
		if (h < 0) {
			h += 1;
		}

		if (h > 1) {
			h -= 1;
		}

		if (6 * h < 1) {
			return p + ((q - p) * 6 * h);
		}

		if (2 * h < 1) {
			return q;
		}

		if (3 * h < 2) {
			return p + ((q - p) * 6 * ((2.0f / 3.0f) - h));
		}

		return p;
	} 

}
