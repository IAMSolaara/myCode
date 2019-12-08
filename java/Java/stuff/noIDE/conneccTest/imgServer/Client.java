import java.awt.*;
import java.io.*;
import java.net.*;

import javax.imageio.ImageIO;

public class Client {

    public static void main(String[] args) {
        Client c = new Client();
        int width = 640;
        int height = 480;
        Frame fr = new Frame("test");

        fr.setSize(width, height);
        fr.setVisible(true);
        fr.addWindowListener(new GestoreFinestra());

        Drawer d = new Drawer();
       
        d.addImg("172.16.2.4", 8086);
        d.setSize(width, height);
        fr.add(d);
    }

    
}