import java.awt.*;
public class Disegno extends Canvas {
	private Punto p1;
	private Punto p2;
	private Punto p3;

	public Disegno(Punto p1, Punto p2){
		this.p1 = new Punto(p1);
		this.p2 = new Punto(p2);
		this.p3 = new Punto();
	}
	public Disegno(Punto p1, Punto p2, Punto p3){
		this.p1 = new Punto(p1);
		this.p2 = new Punto(p2);
		this.p3 = new Punto(p3);
	}

	public void paint(Graphics g){
		g.drawLine((int)Math.round(p1.getX()), (int)Math.round(p1.getY()), (int)Math.round(p2.getX()), (int)Math.round(p2.getY()));

		if (  (int)Math.round(p1.getX()) >= WIDTH  || 
			  (int)Math.round(p1.getX()) <= 0      ||
			  (int)Math.round(p1.getY()) >= HEIGHT ||
			  (int)Math.round(p1.getY()) <= 0      ||

			  (int)Math.round(p2.getX()) >= WIDTH  || 
			  (int)Math.round(p2.getX()) <= 0      ||
			  (int)Math.round(p2.getY()) >= HEIGHT ||
			  (int)Math.round(p2.getY()) <= 0         ) {
			p1.trasla(0.1,0.1);
			p2.trasla(0.1,0.1);
		}
	}
}
