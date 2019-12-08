import java.net.*;
import java.io.*;

public class GreetingsServer {
    private ServerSocket serverSocket;
    private Socket clientSocket;
    private PrintWriter out;
    private BufferedReader in;

    public void start(int port) {
        try {
            serverSocket = new ServerSocket(port);
            clientSocket = serverSocket.accept();
            out = new PrintWriter(clientSocket.getOutputStream(), true);
            in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            String greeting = in.readLine();
            if ("hello server".equals(greeting)) {
                System.out.println("I got the right message.");
                out.println("hello incel");
            } else {
                System.out.println("idk who this cunt is, I'm kicking it out.");
                out.println("YOU CAME TO THE WRONG HOUSE FOOL");
            }
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    public void stop() {
        try {
            in.close();
            out.close();
            clientSocket.close();
            serverSocket.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    public static void main(String[] args) {
        GreetingsServer srv = new GreetingsServer();
        srv.start(8086);
    }
}