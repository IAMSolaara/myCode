import java.awt.*;
public class Disegno extends Canvas {
	public Punto p1;
	public Punto p2;

	public Disegno(Punto p1, Punto p2){
		this.p1 = new Punto(p1);
		this.p2 = new Punto(p2);
	}

	public void paint(Graphics g){
		g.drawLine((int)Math.round(p1.getX()), (int)Math.round(p1.getY()), (int)Math.round(p2.getX()), (int)Math.round(p2.getY()));
	}

	public Punto getP1(){return new Punto(p1);}
	public Punto getP2(){return new Punto(p2);}
}
