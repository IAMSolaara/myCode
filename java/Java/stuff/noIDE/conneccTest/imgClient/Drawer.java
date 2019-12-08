import java.awt.*;
import java.io.*;
import java.net.*;

import javax.imageio.ImageIO;

public class Drawer extends Canvas {
    private Image wp;
    private Socket clientSocket;

    public Drawer() {
        wp = null;
    }

    public void addImg(String ip, int port) {
        try {
            clientSocket = new Socket(ip, port);
            PrintWriter outWriter = new PrintWriter(clientSocket.getOutputStream(), true);
            wp = ImageIO.read(clientSocket.getInputStream());
            clientSocket.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    public void paint(Graphics g) {
        if (wp != null) {
            g.drawImage(wp, 0, 0, getWidth(), getHeight(), null);
        }
    }

    public InputStream getImageFromServer(String ip, int port) {
        InputStream out = null;
        try {
            
           
        } catch (Exception ex) {
            ex.printStackTrace();
        }
        return out;
    }
}