import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/*
    - root: TreeNode

    + Albero()
    + caricaAlbero(in f: File): void
    - caricaAlbero(in sc: Scanner): void

    + toString(): String
    - toString(in node: TreeNode): String

    + visitaAnticipata(): String
    - visitaAnticipata(in node: TreeNode): String

    + visitaPosticipata(): String
    - visitaPosticipata(in node: TreeNode): String

    + contaFoglie(): int
    - contaFoglie(): int

    + contaFoglie(in node: TreeNode): int
    - contaFoglie(in node: TreeNode): int

    + classifica(in vote: int): String
    - classifica(in node: TreeNode, vote: int): String
*/
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
            out = new TreeNode(next);
            if (out.isVote()) {
                out.setLeft(caricaAlbero(sc));
                out.setRight(caricaAlbero(sc));
            } else {
                out.setLeft(null);
                out.setRight(null);
            }
        }
        return out;
    }

    public String visitaAnticipata() {
        String out = "";
        out += visitaAnticipata(root);
        return out;
    }

    private String visitaAnticipata(TreeNode node) {
        String out = "";
        if (node != null) {
            out += " " + node.toString() + " ";
            out += visitaAnticipata(node.getLeft());
            out += visitaAnticipata(node.getRight());
        }
        return out;
    }
    
    public String toString() {
        String out = "";
        out += toString(root);
        return out;
    }

    private String toString(TreeNode node) {
        String out = "";
        if (node != null) {
            out += toString(node.getLeft());
            out += " " + node.toString() + " ";
            out += toString(node.getRight());
        }
        return out;
    }

    public String visitaPosticipata() {
        String out = "";
        out += visitaPosticipata(root);
        return out;
    }

    private String visitaPosticipata(TreeNode node) {
        String out = "";
        if (node != null) {
            out += visitaPosticipata(node.getLeft());
            out += visitaPosticipata(node.getRight());
            out += " " + node.toString() + " ";
        }
        return out;
    }

    public int contaFoglie() {
        int out = 0;
        out = contaFoglie(root);
        return out;
    }

    private int contaFoglie(TreeNode node) {
		int out = 0;
		if (node != null) {
			if (node.getLeft() == null && node.getRight() == null) out = 1;
			else {
				out += contaFoglie(node.getLeft());
				out += contaFoglie(node.getRight());
			}
		}
        return out;
    }

    public int contaNodi() {
        return contaNodi(root);
    }

    private int contaNodi(TreeNode node) {
        int out = 0;
        if (node != null) {
            out++;
            out += contaNodi(node.getLeft());
            out += contaNodi(node.getRight());
        }
        return out;
    }

    public String classifica(int vote) {
        return classifica(root, vote);
    }

    private String classifica(TreeNode node, int vote) {
        String out = "";
        if (node != null && ( vote > 0 && vote <= 10)) { //controllo parametri
            if (node.isVote()) {                         //controllo se e' voto
                if (vote < node.getVote()) {             //controllo se il voto passato e' minore di quello del nodo
                    out += node.getLeft().toString();    //escono le informazioni
                } else
                    out += classifica(node.getRight(), vote);  //altrimenti si passa al prossimo grado
            } else out += node.toString();              //altrimenti e' un giudizio e si ritorna toString del nodo
        } else out += "voto non valido.";
        return out;
    }
}