import javax.swing.ImageIcon;
import javax.swing.JPanel;
import javax.swing.JLabel;
import java.awt.Image;

public class ProcessesPanel extends javax.swing.JPanel {
    public void update(Object o) {
        removeAll();
        if (o != null) {
            if (o instanceof Processo) {
                addProcesso(((Processo)o));
            }
            else if (o instanceof Processo[]) {
                for (Processo el : ((Processo[])o)) {
                    addProcesso(el);
                }
            }
        }
        revalidate();
        repaint();
    }
    public void addProcesso(Processo p) {
        //add(new javax.swing.JLabel(p.getNome()));
        add(new JLabel(p.getNome(), new ImageIcon(new ImageIcon(String.format("./%s.png", p.getNome()), p.getNome()).getImage()
                .getScaledInstance(64, 64, Image.SCALE_DEFAULT)), JLabel.CENTER));
    }
}
