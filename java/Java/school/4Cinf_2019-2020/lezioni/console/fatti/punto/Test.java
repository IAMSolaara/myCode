public class Test {
  public static void main(String[] args){
    Punto p1,p2,p3;
    p1 = new Punto(1, 2);
    System.out.println("P1" + p1.toString());
    p3 = new Punto(p1);
    p1.trasla(2.3, -3.4);
    System.out.println("P1" + p1.toString());
    p2 = new Punto(p1);
    System.out.println("P2" + p2.toString());
    System.out.println("P3 e P1 sono " + (p3.equals(p1) ? "uguali" : "diversi"));
    System.out.println("P3" + p3.toString());
    p3.trasla(1, -1);
    System.out.println("P3" + p3.toString());
    System.out.println("La distanza tra P1 e P3 e' " + p1.distanza(p3));
    System.out.println("La distanza tra P1 e P2 e' " + p1.distanza(p2));
  }
}
