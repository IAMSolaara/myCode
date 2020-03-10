public class Test {
    public static void main(String args[]) {
        Pila p = new Pila();
        Punto tmp;
        p.push(new Punto(3,1.8086));
        p.push(new Punto(6,3.14));
        p.push(new Punto(9,Math.sqrt(2)));

        tmp = p.pop();
        while (tmp != null) {
            System.out.println(tmp.toString());
            tmp = p.pop();
        }
    }
}