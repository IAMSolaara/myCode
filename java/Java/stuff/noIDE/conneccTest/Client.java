import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class Client {
    private Socket clientSocket;
    private PrintWriter out;
    private BufferedReader in;
    
    public void connect(String ip, int port){
        try {
        clientSocket = new Socket(ip, port);
        out = new PrintWriter(clientSocket.getOutputStream(), true);
        in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
        }
        catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    public String sendMessage(String msg){
        String rep = null;
        try{
            out.println(msg);
            rep = in.readLine();
        }
        catch(Exception ex) {
            ex.printStackTrace();
        }
        return rep;
    }

    public void hangUp(){
        try{
            in.close();
            out.close();
            clientSocket.close();
        }
        catch(Exception ex){
            ex.printStackTrace();
        }
    }

    public static void main(String[] args) {
        Client cliente = new Client();
        cliente.connect("172.16.2.4", 8086);
        String msg = "hello server";
        String reply = cliente.sendMessage(msg);
        System.out.println(msg);
        System.out.println(reply);
    }
}