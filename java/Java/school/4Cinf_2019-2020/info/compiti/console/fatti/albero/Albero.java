import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/*
    - root: TreeNode
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
            if (!next.equals(".")) {
                out = new TreeNode(Integer.parseInt(next));
                out.setLeft(caricaAlbero(sc));
                out.setRight(caricaAlbero(sc));
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

    public String visitaSimmetrica() {
        String out = "";
        out += visitaSimmetrica(root);
        return out;
    }

    private String visitaSimmetrica(TreeNode node) {
        String out = "";
        if (node != null) {
            out += visitaSimmetrica(node.getLeft());
            out += " " + node.toString() + " ";
            out += visitaSimmetrica(node.getRight());
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

    public TreeNode ricerca(int query) {
        return ricerca(root, query);
    }

    private TreeNode ricerca(TreeNode node, int query) {
        TreeNode out = null;
        if (node != null) {
            if (node.getVal() == query) {
                out = node;
            }
            else {
                TreeNode leftRes = ricerca(node.getLeft(), query);
                if (leftRes == null) {
                    TreeNode rightRes = ricerca(node.getRight(), query);
                    if (rightRes != null) {
                        out = rightRes;
                    }
                } else out = leftRes;
            }
        }
        return out;
    }

}
