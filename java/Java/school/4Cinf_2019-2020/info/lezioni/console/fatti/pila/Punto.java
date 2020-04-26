//** ATTENZIONE: IL FILE CONTIENE ERRORI NON CORRETTI


/**
 * @author Ricco Davide, Aresu Matteo, Daniel Muscas, Lai Yvan
 * @version 0.2 2/10/19, 05/10/2019, 9/10/2019
 */

/*
  Punto
  // attributi variabili
  - x, y: double
  // attributi costanti
  + QUAD1 = 1
  + QUAD2 = 2
  + QUAD3 = 3
  + QUAD4 = 4
  + ASSEX = 5
  + ASSEY = 6
  + ORIGINE = 0
  // costruttori
  + Punto( in x, y: double )
  + Punto( )
  + Punto( in p: Punto )
  // metodi accessori
  + getX(): double
  + getY(): double
  // metodi modificatori
  + trasla( in deltax, deltay: double ): void
  // altri metodi
  + toString(): String
  + posizione(): int  // una delle costanti 
  + equals(in obj:Object):boolean 
  + distanza(in Punto:p):double

*/

import java.io.*;

public class Punto implements Serializable{

    //attributi variabili
    private double x, y;

    //attributi costanti
    public static int QUAD1 = 1;
    public static int QUAD2 = 2;
    public static int QUAD3 = 3;
    public static int QUAD4 = 4;
    public static int ASSEX = 5;
    public static int ASSEY = 6;
    public static int ORIGINE = 0;

    //metodi costruttori 
    /**
     * Crea un punto coincidente con l'origine del piano cartesiano
     */
    public Punto () {

	x = y = 0;
    }

    /** 
     * Crea un punto partendo da dei valori definiti dall'utente
     * @param x Ascissa del punto da creare
     * @param y Ordinata del punto da creare
     */
    public Punto (double x, double y) {

	// non ci sono controlli poiche' non ci sono vincoli
	this.x = x;
	this.y = y;
    }

    /**
     * Costruttore di copia
     * Crea un punto che ha lo stesso stato del parametro
     * @param p Punto da copiare
     */
    public Punto (Punto p) {

	if (p != null) {

	    x = p.getX();
	    y = p.getY();
	}
	else {

	    x = y = 0;
	}
    } //Punto (Punto p)

    //metodi accessori
    /**
     * @return Ascissa del punto
     */
    public double getX(){

	return x;
    }

    /**
     * @return Ordinata del punto
     */
    public double getY(){

	return y;
    }

    //metodi modificatori
	
    /**
     * Esegue una traslazione
     * @param deltaX Variazione dell' ascissa
     * @param deltaY Variazione dell' ordinata
     */
    public void trasla (double deltaX, double deltaY) {

	x += deltaX;
	y += deltaY;
    }

    // altri metodi
	
    /** 
     * Crea una stringa contenente lo stato dell' oggetto
     * @return Stringa creata
     */
    public String toString(){

	//sezione dichiarativa 
	String s;

	//sezione esecutiva 
	s = "(" + x + "," + y + ")";
	return s;
		
    }//toString

    /**
     *Determina il quadrante o l'asse in cui si trova il punto
     *@return QUAD1 = Quadrante 1 <br> 
     *        QUAD2 = Quadrante 2 <br> 
     *        QUAD3 = Quadrante 3 <br> 
     *        QUAD4 = Quadrante 4 <br> 
     *        ASSEX = Asse delle ascisse <br> 
     *        ASSEY = Asse delle ordinate <br>
     *        ORIGINE = Origine
     */
    public int posizione () {

	//sezione dichiarativa
	int result;

	//sezione esecutiva
	result = 0;
	if (x>0 && y>0)
	    result = QUAD1;
	else
	    if (x>0 && y<0) 
		result = QUAD4;
	    else
		if (x<0 && y>0)
		    result = QUAD2;
		else
		    if (x<0 && y<0) 
			result = QUAD3;
		    else
			if (x==0 && y==0)
			    result = ORIGINE;
			else
			    if (y==0)
				result = ASSEY;
			    else
				if (x==0)
				    result = ASSEX;
	
	return result;
       
    }//posizione

    /**
     *Confronta due oggetti
     *@param obj Punto da confrontare
     *@return true se i due oggetti hanno lo stesso stato<br>
     *        false se i due oggetti non hanno lo stesso stato
     */
    public boolean equals(Object obj){
	boolean ris=true;

	if(obj==null || obj instanceof Punto==false ||
	   x!=((Punto)obj).getX() || y!=((Punto)obj).getY())
	    ris=false;
	
	return ris;

    }//equals

    /**
     * Calcola la distanza da un punto dato
     * @param p punto da cui calcolare la distanza
     * @return Distanza dal punto p
     */
    public double distanza(Punto p)
    {
	double dist;

	dist=Math.sqrt((p.getX() - x)*(p.getX() - x) +
		       (p.getY() - y)*(p.getY() - y));
	return dist;
    }//distanza
}//class
