public class Test {
    public static void main(String[] args) {
        //normale
        Carrello c1 = new Carrello();
        for (int i =0; i < 12; i++) {
            if (!c1.carica(i*10)) System.out.println("Carica fallito");
            System.out.println(c1);
        }
        Carrello c2 = new Carrello(c1);

        System.out.println("c1 e c2 sono " + (c1.equals(c2) ? "uguali" : "diversi"));
        Carrello c3 = new Carrello();
        System.out.println("c1 e c3 sono " + (c1.equals(c3) ? "uguali" : "diversi"));

        //con blocco
        CarrelloConBlocco cb1 = new CarrelloConBlocco();

        System.out.println(cb1);
    }
}