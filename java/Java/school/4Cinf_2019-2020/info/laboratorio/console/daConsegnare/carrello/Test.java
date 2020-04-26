import java.util.Random;

public class Test {
    public static void main(String[] args) {
        //normale
        System.out.println("Carrello.");
        Carrello c1 = new Carrello();
        c1.preleva();
        for (int i =0; i < 12; i++) {
            if (!c1.carica(i*10)) System.out.println("Carica fallito");
            System.out.println(c1);
        }
        Carrello c2 = new Carrello(c1);

        System.out.println("c1 e c2 sono " + (c1.equals(c2) ? "uguali" : "diversi"));
        Carrello c3 = new Carrello();
        System.out.println("c1 e c3 sono " + (c1.equals(c3) ? "uguali" : "diversi"));

        //con blocco
        System.out.println("Carr. con blocco.");
        CarrelloConBlocco cb1 = new CarrelloConBlocco();

        System.out.println(cb1);
        if (!cb1.carica(10)) System.out.println("Carica fallito");
        cb1.preleva();
        System.out.println(cb1);
        if (!cb1.carica(10)) System.out.println("Carica fallito");
        cb1.sblocca();
        System.out.println(cb1);
        if (!cb1.carica(10)) System.out.println("Carica fallito");
        System.out.println(cb1);

        //polimorfismo
        System.out.println("Polimorfismo");
        Carrello cp;
        Random rng = new Random(System.currentTimeMillis());
        if ((rng.nextInt(10) % 2) == 1) cp = new Carrello();
        else cp = new CarrelloConBlocco();
        
        if (cp instanceof CarrelloConBlocco) ((CarrelloConBlocco)cp).sblocca();

        cp.preleva();
        System.out.println(cp);
    }
}