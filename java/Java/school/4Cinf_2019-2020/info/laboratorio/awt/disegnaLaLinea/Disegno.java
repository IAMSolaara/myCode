import java.awt.*;
public class Disegno extends Canvas {
	private Punto p1;
	private Punto p2;

	public Disegno(){
		this.p1 = null;
		this.p2 = null;
	}

	public void paint(Graphics g){
		if (p1 != null && p2 != null)
		g.drawLine((int)Math.round(p1.getX()), (int)Math.round(p1.getY()),
				   (int)Math.round(p2.getX()), (int)Math.round(p2.getY()));
	}

	public Punto getP1(){
		Punto out = null;
		if (p1 != null) out = new Punto(p1);
		return out;
	}

	public Punto getP2(){
		Punto out = null;
		if (p2 != null) out = new Punto(p2);
		return out;
	}

	public void newP1(Punto p){p1 = new Punto(p);}
	public void newP2(Punto p){p2 = new Punto(p);}
}
