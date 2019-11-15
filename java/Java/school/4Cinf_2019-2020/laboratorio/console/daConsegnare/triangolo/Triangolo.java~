/**
   @author Lorenzo Cauli
   @version 0.1
 */

/*
	- p1: Punto
	- p2: Punto
	- p3: Punto
 	- perim: double >0
	- area: double >0

 	+ Triangolo(in p1, p2, p3: Punto)
	+ Triangolo(in t: Triangolo)

	+ getP1(): Punto
	+ getP2(): Punto
	+ getP3(): Punto
	+ getPerim(): double
	+ getArea(): double

	- calcPerim(): void
	- calcArea(): void
	+ trasla(in deltaX, deltaY: double): void
	+ toString(): String
	+ equals(in o: Object): boolean
 */

public class Triangolo {
	private Punto p1;
	private Punto p2;
	private Punto p3;
	private double perim;
	private double area;

	/** Costruttore dati 3 oggetti Punto.
	 *	@param p1 Riferimento oggetto primo punto.
	 *  @param p2 Riferimento oggetto secondo punto.
	 *  @param p3 Riferimento oggetto terzo punto.
	 */
	public Triangolo(Punto p1, Punto p2, Punto p3){
		if (p1 != null || p2 != null || p3 != null) {
			this.p1 = new Punto(p1.getX(), p1.getY());
			this.p2 = new Punto(p2.getX(), p2.getY());
			this.p3 = new Punto(p3.getX(), p3.getY());
		}
		else {
			this.p1 = new Punto(0,0);
			this.p2 = new Punto(1,1);
			this.p3 = new Punto(2,2);
		}
		calcArea();
		calcPerim();
	}

	/** Costruttore di copia.
	 *  @param t Riferimento a oggetto triangolo da cui copiare lo stato.
	 */
	public Triangolo(Triangolo t) {
		if (t != null) {
			p1 = t.getP1();
			p2 = t.getP2();
			p3 = t.getP3();
			area = t.getArea();
			perim = t.getPerim();
		}

		else {
			p1 = new Punto(0,0);
			p2 = new Punto(1,1);
			p3 = new Punto(2,2);
			calcArea();
			calcPerim();
		}
	}

	/**Metodo che restituisce un riferimento al primo punto.*/
	public Punto getP1(){return p1;}
	/**Metodo che restituisce un riferimento al secondo punto.*/
	public Punto getP2(){return p2;}
	/**Metodo che restituisce un riferimento al terzo punto.*/
	public Punto getP3(){return p3;}
	/**Metodo che restituisce l'area.*/
	public double getArea(){return area;}
	/**Metodo che restituisce il perimetro.*/
	public double getPerim(){return perim;}

	/**Metodo che calcola il perimetro.*/
	private void calcPerim(){
		double l1 = p1.distanza(p2);
		double l2 = p1.distanza(p3);
		double l3 = p2.distanza(p3);
		perim = l1+l2+l3;
	}

	/**Metodo che calcola l'area.*/
	private void calcArea(){
		double p = perim/2;
		double l1 = p1.distanza(p2);
		double l2 = p1.distanza(p3);
		double l3 = p2.distanza(p3);
		area = Math.sqrt(p*(p-l1)*(p-l2)*(p-l3));
	}

	/**Metodo che trasla il triangolo.
	 *	@param deltaX Delta asse X
	 *	@param deltaY Delta asse Y
	 */	
	public void trasla(double deltaX, double deltaY){
		p1.trasla(deltaX, deltaY);
		p2.trasla(deltaX, deltaY);
		p2.trasla(deltaX, deltaY);
	}

	/**Metodo che restituisce lo stato dell'oggetto in una stringa.
	 * @return Una stringa contenente lo stato dell'oggetto
	 */
	public String toString(){
		return "P1(" + p1.getX() + ";" + p1.getY() + ") P2(" + p2.getX() + ";" + p2.getY() + ") P3(" + p3.getX() + ";" + p3.getY() + ") Perimetro: " + perim + "Area: " + area;
	}

	public boolean equals(Object o){
		boolean out = true;
		if (o == null || !(o instanceof Triangolo)) out = false;
		else {
			
		}
		return out;
	}

}

