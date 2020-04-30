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
            if (next.equals("+") || next.equals("*")) {
                out = new TreeNode(next);
                out.setLeft(caricaAlbero(sc));
                out.setRight(caricaAlbero(sc));
            } else if (isOperand(next)) {
                out = new TreeNode(next);
                out.setLeft(null);
                out.setRight(null);
            }
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
            out += " " + node.toString() + " ";
            out += toString(node.getLeft());
            out += toString(node.getRight());
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
            //controllo se il nodo e' operatore
            if (isOperator(node.getVal())) {
                out += String.format("(%s%s%s)", visitaSimmetrica(node.getLeft()), node.toString(), visitaSimmetrica(node.getRight()) );
            } else out += node.toString();
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

    public TreeNode ricerca(String query) {
        return ricerca(root, query);
    }

    private TreeNode ricerca(TreeNode node, String query) {
        TreeNode out = null;
        if (node != null) {
            if (node.getVal().equals(query)) {
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

    private boolean isOperator(String in) {
        return (in.equals("+") || in.equals("*") ? true : false);
    }

    private boolean isOperand(String in) {
        try {
            Double.parseDouble(in);
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }
    

    public String eval() {
        String out = "";
        out += eval(root);
        return out;
    }

    private String eval(TreeNode node) {
        String out = "";
        if (node != null) {
            //controllo se il nodo e' operatore
            if (isOperator(node.getVal())) {
                switch (node.getVal()) { //controllo operatore
                    case "+":
                        out += Double.parseDouble(eval(node.getLeft())) + Double.parseDouble(eval(node.getRight()));
                        break;
                    case "*":
                        out += Double.parseDouble(eval(node.getLeft())) * Double.parseDouble(eval(node.getRight()));
                        break;
                }
            } else out += node.toString();
        }
        return out;
    }
}
