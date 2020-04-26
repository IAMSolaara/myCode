import java.awt.*;
public class Disegno extends Canvas {
	private Punto p1;
	private Punto p2;
	private Punto p3;
	private Dimension d1;
	private double d1x = 0.1;
	private double d1y = 0.1;
	private double d2x = 0.1;
	private double d2y = 0.1;
	private float h = 0;


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
//		System.out.println(h);
//		System.out.println(Utils.hslColor(h, 100, 70));
		this.setBackground(Color.getHSBColor((int)Math.round(h), (float)1, (float)0.7));
		g.drawString("please come tp brazil!!!!!! ", 10, 50);
		g.drawString(":>>> 鑄職糞穴 ", 10, 100);
		g.drawLine((int)Math.round(p1.getX()), (int)Math.round(p1.getY()), (int)Math.round(p2.getX()), (int)Math.round(p2.getY()));
		if ( (int)Math.round(p1.getX()) >= this.getWidth()  || (int)Math.round(p1.getX()) <= 0 ) d1x *= -1;
		if ( (int)Math.round(p1.getY()) >= this.getHeight() || (int)Math.round(p1.getY()) <= 0 ) d1y *= -1;
		if ( (int)Math.round(p2.getX()) >= this.getWidth()  || (int)Math.round(p2.getX()) <= 0 ) d2x *= -1;
		if ( (int)Math.round(p2.getY()) >= this.getHeight() || (int)Math.round(p2.getY()) <= 0 ) d2y *= -1;
		p1.trasla(d1x,d1y);
		p2.trasla(d2x,d2y);
		h+=0.01;
		if (h > 360) h = 0;
	}
}
