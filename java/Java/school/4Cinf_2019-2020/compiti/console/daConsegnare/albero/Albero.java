import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Albero {
    private TreeNode root;
    
    public Albero() {
        root = null;
    }

    public void caricaAlbero(File f) throws FileNotFoundException{
        try {
            Scanner sc = new Scanner(f);
            root = caricaAlbero(sc);
        }
        catch (FileNotFoundException e) {
            throw new FileNotFoundException("File non trovato.");
        }
        catch (NullPointerException e) {
            throw new NullPointerException("Errore lettura file.");
        }
    }

    private TreeNode caricaAlbero(Scanner sc) {
        TreeNode out = null;
        String next;
        if (sc.hasNext()) {
            next = sc.next();
            if (!next.equals(".")) {
                out = new TreeNode(Integer.parseInt(next));
                out.setLeft(caricaAlbero(sc));
                out.setRight(caricaAlbero(sc));
            }
        }
        return out;
    }
/* 
    public String visitaAnticipata() {
        String out = "";

    }

    public String visitaPosticipata() {

    }

    public String visitaSimmetrica() {

    }

    private String visitaAnticipata(TreeNode node) {

    }

    private String visitaPosticipata(TreeNode node) {

    }

    private String visitaSimmetrica(TreeNode node) {

    } */
}