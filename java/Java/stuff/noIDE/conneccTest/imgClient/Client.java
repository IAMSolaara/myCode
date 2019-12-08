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
        if (args.length == 2) {
            d.addImg(args[0], Integer.parseInt(args[1]));
        } else {
            d.addImg("127.0.0.1", 8086);

        }
        d.setSize(width, height);
        fr.add(d);
    }

}