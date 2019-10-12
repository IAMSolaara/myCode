/**
@author Lorenzo Cauli
@version 0.1
*/

/*
  - x, y: double
  + QUAD1 = 1
  + QUAD2 = 2
  + QUAD3 = 3
  + QUAD4 = 4
  + ASSEX = 5
  + ASSEY = 6

  + Punto(in x,y: double)
  + Punto()
  + Punto(in p: Punto)

  + getX(): double
  + getY(): double

  + trasla(in dx, dy: double): void

  + toString(): String
  + posizione()
  + equals(in o: Object): boolean
*/

public class Punto{
  private double x;
  private double y;

  public static int QUAD1 = 1;
  public static int QUAD2 = 2;
  public static int QUAD3 = 3;
  public static int QUAD4 = 4;
  public static int ASSEX = 5;
  public static int ASSEY = 6;

  /**
    Costruttore date coordinate x e y
    @param x Coordinata x da assegnare al punto
    @param y Coordinata y da assegnare al punto
  */
  public Punto(double x, double y) {
    this.x = x;
    this.y = y;
  }

  /**
    Costruttore con valori di default
  */
  public Punto() {
    x = y  = 0;
  }

  /**
    Costruttore di copia.
    @param in Riferimento oggetto da cui copiare
  */
  public Punto(Punto in){
    if (in == null) {
      x = y = 0;
    }
    else {
      x = in.getX();
      y = in.getY();
    }
  }

  public double getX(){return x;}
  public double getY(){return y;}

  /**
    Metodo per traslare il punto dati i delta.
    @param dx Delta x
    @param dy Delta y
  */
  public void trasla(double dx, double dy){
    x += dx;
    y += dy;
  }

  /**
    Funzione che restituisce lo stato dell'oggetto
    @return La stringa in cui e' contenuto lo stato dell'oggetto
  */
  public String toString(){
    return "(" + x + "," + y + ")";
  }

  /**
    Funzione che restituisce la posizione del punto
    @return La posizione dell'oggetto
  */
  public int posizione(){
    int res;
    if (x == 0 && y != 0) res = ASSEX;
    else if (x != 0 && y == 0) res = ASSEY;
    else if (x == 0 && y != 0) res = ASSEX;
    else if (x > 0 && y > 0) res = QUAD1;
    else if (x < 0 && y > 0) res = QUAD2;
    else if (x > 0 && y < 0) res = QUAD3;
    else if (x < 0 && y < 0) res = QUAD4;
    return res;
  }

  /**
  Confronto di due oggetti
  @param o Oggetto da confrontare
  @return true se i due oggetti hanno lo stesso stato, altrimenti false
  */
  public boolean equals(Object o) {
    boolean result = true;
    if (o == null || !(o instanceof Punto)) result = false;
    else {
      if (x != ((Punto)o).getX() || y != ((Punto)o).getY()) result = false;
    }
    return result;
  }
}
