import java.net.*;
import java.nio.file.Files;
import java.util.Scanner;
import java.io.*;

public class Server {
    private ServerSocket serverSocket;
    private Socket clientSocket;
    private OutputStream out;
    private InputStream in;

    public void start(int port) {
        try {
            serverSocket = new ServerSocket(port);
            clientSocket = serverSocket.accept();
            out = clientSocket.getOutputStream();
            out.flush();
            in = clientSocket.getInputStream();

            File outFile = new File("./test.png");
            byte[] data = Files.readAllBytes(outFile.toPath());
            out.write(data);
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
        Server srv = new Server();
        srv.start(8086);
    }
}