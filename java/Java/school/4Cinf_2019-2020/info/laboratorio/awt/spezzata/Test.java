public class Test {
    public static void main(String[] args) {
        Spezzata s = new Spezzata();
        System.out.println("s: " + s.toString());
        s.append(new Punto(-1, 1.20));
        s.append(new Punto(+6, -9.666));
        s.append(new Punto(-5, -4));
        System.out.println("s: " + s.toString());
        s.trasla(+1, -2);
        System.out.println("s: " + s.toString());
        Spezzata s2 = new Spezzata(s);
        System.out.println("s2: " + s2.toString());
    }
}