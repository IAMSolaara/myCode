import java.io.*;

public class Test {
    public static void main(String[] args) {
        try{
        Scheduler s = new Scheduler(4);
        s.readFromFile("./processi.txt");
        System.out.println(s);
        }
        catch (FileNotFoundException e) {
            System.out.println("");
        }
    }
}