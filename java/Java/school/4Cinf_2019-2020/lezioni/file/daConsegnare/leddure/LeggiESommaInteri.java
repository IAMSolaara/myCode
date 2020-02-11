import java.util.Scanner;

public class LeggiESommaInteri {
    public static void main(String[] args) {
        int n = 0;
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            n += sc.nextInt();
        }
        System.out.println(n);
    }
}