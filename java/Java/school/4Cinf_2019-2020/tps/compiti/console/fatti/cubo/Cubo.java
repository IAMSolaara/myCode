
public class Cubo extends Quadrato{
    public Cubo(int l) {
        super(l);
    }

    public double volume() {
        return Math.pow(super.getLato(), 3);
    }

    public static void main(String[] args) {
        Cubo q = new Cubo(4);
        System.out.println(q.volume());
        q.setLato(15.152);
        System.out.println(q.volume());
    }
}