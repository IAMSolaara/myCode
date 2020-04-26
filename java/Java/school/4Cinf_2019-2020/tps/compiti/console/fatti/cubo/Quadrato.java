public class Quadrato {
    private double lato;

    public Quadrato(double l) {
        setLato(l);
    }

    /** Metodi **/
    public void setLato(double l) {
        lato = l;
    }

    public double getLato() {
        return lato;
    }

    public double area() {
        return (lato * lato);
    }

    public static void main(String[] args) {
        Quadrato Q1 = new Quadrato(10);
        Q1.setLato(3);
        System.out.println("Il lato 2 vale " + Q1.getLato());
        System.out.println("area vale " + Q1.area());
    }
}
