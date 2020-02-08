import java.awt.*;
public class Disegno extends Canvas {
	private static final long serialVersionUID = 162L;
	private Spezzata s;

	public Disegno(){
		this.s = new Spezzata();
	}

	public void paint(Graphics g){
		if (s.getCount() == 0) {}
		else if (s.getCount() == 1) {
			Punto p = new Punto(s.getPunti()[0]);
			g.drawLine( (int)Math.round(p.getX()), (int)Math.round(p.getY()), (int)Math.round(p.getX()), (int)Math.round(p.getY()) );
		}
		else {
			for (int i = 0; i < s.getCount()-1; i++) {
				Punto p1 = new Punto(s.getPunti()[i]);
				Punto p2 = new Punto(s.getPunti()[i+1]);

				g.drawLine((int)Math.round(p1.getX()), (int)Math.round(p1.getY()),
				(int)Math.round(p2.getX()), (int)Math.round(p2.getY()));

			}
		}
	}

	public Spezzata getS(){
		return new Spezzata(s);
	}

	public void append(Punto p){
		s.append(p);
	}
	
	public void trasla(int dx, int dy) {
		s.trasla(dx, dy);
	}
}
