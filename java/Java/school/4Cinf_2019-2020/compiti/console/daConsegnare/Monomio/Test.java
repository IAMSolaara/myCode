public class Test {
    public static void main(String[] args) {
        Monomio m1 = new Monomio(-1.212, 4);
        Monomio m2 = new Monomio(m1);
        Monomio m3 = new Monomio(m1);
        System.out.println(m1.toString());
        System.out.println(m2.toString());
        m1.moltiplica(m2);
        System.out.println("m1 * m2 = " + m1.toString());
        m3.somma(m2);
        System.out.println("m3 + m2 = " + m3.toString());
        Monomio m4 = new Monomio(m3);
        System.out.println("m3 e m4 sono " + ((m3.equals(m4)) ? "uguali" : "diversi"));
    }
}
