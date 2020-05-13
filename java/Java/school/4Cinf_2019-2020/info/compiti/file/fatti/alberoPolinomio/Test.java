import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Test {
    public static void main(String[] args) {
        try {
            File f = new File("./test.txt");
            Polinomio a = new Polinomio();
            a.caricaPolinomio(f);
            System.out.println("Simmetrica: "+a.toString());
            System.out.println("Che esponente devo cercare? ");
            Scanner sc = new Scanner(System.in);
            Double res = a.getCoefficente(sc.nextInt());
            if (res == null) System.out.println("Non ho trovato un monomio di quel grado");
            else System.out.println("Ho trovato un monomio con coefficente " + res.toString());
            System.out.println("Con quale x devo valutare il polinomio? ");
            double x = sc.nextDouble();
            System.out.println("Il polinomio si risolve con risultato " + a.eval(x));
        }
        catch (FileNotFoundException e) {
            System.out.println(e.getMessage());
        }
        catch (NullPointerException e) {
            System.out.println(e.getMessage());
        }
    }
}
