import java.util.Iterator;
import java.util.Scanner;

public class Test {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        for (;;) {
            System.out.println("Benvenuto alle casse veloci di Auchan!");
            System.out.println("Iniziare un nuovo scontrino? [y/n]");
            String choice = sc.nextLine();
            if (choice.equals("y"))
                start();
            else if (choice.equals("n"))
                break;
        }
    }

    public static void start() {
        Scanner sc = new Scanner(System.in);
        CassaVeloceDellAuchan cassa = new CassaVeloceDellAuchan();
        boolean on = true;
        while (on) {
            System.out.println("Totale oggetti: " + cassa.getCoseDaComprare().size());
            
            System.out.println("Inserire un'oggetto, rimuovere un'oggetto o terminare lo scontrino? [i,r,t]");
            String choice = sc.nextLine();
            //insert thing
            if (choice.equals("i")) {
                System.out.println("Inserire il nome dell'oggetto.");
                String n = sc.nextLine();
                System.out.println("Inserire il prezzo dell'oggetto.");
                double p = sc.nextDouble();
                System.out.println("Quanti di questo oggetto vuole acquistare?");
                int c = sc.nextInt();
                for (int i = 0; i < c; i++) {
                    cassa.add(new Merce(n,p));
                }
            }
            //remove thing
            else if (choice.equals("r")) {
                
                for (int i = 0; i < cassa.getCoseDaComprare().size(); i++) {
                    System.out.println(String.format("%d: %s - €%.2f", i, cassa.getCoseDaComprare().get(i).getNome(), cassa.getCoseDaComprare().get(i).getPrezzo()));
                }
                System.out.println("Quale oggetto rimuovere?");
                int c = sc.nextInt()-1;
                if (c < 0 || c >= cassa.MAXTHINGS) {
                    System.out.println("");
                }

            }
            //terminate receipt
            else if (choice.equals("t")) {
                double tot = 0;
                Iterator<Merce> it = cassa.getCoseDaComprare().iterator();
                while (it.hasNext()) {
                    tot += it.next().getPrezzo();
                }
                System.out.println("Il totale e' di " + String.format("%.2f", tot));
                System.out.println("Grazie per aver scelto Casse Veloci Auchan. Buona giornata.");

                on = false;
            }
        }
        cassa = null;
    }
}