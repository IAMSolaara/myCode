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
    + eval(): double
    - eval(in node: TreeNode): double

    + visitaAnticipata(): String
    - visitaAnticipata(in node: TreeNode): String

    + visitaPosticipata(): String
    - visitaPosticipata(in node: TreeNode): String

    + contaFoglie(): int
    - contaFoglie(): int

    + contaFoglie(in node: TreeNode): int
    - contaFoglie(in node: TreeNode): int
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
            } else {
                out = new TreeNode(next);
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
    
    public double eval() {
        
        return eval(root);
    }

    private double eval(TreeNode node) {
        double out = 0;
        if (node != null) {
            //controllo se il nodo e' operatore
            if (node.isOperator()) {
                switch (node.getOp()) { //controllo operatore
                    case "+":
                        out += eval(node.getLeft()) + eval(node.getRight());
                        break;
                    case "*":
                        out += eval(node.getLeft()) * eval(node.getRight());
                        break;
                }
            } else out += node.getVal();
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
            //controllo se il nodo e' operatore
            if (node.isOperator()) {
                out += String.format("(%s%s%s)", toString(node.getLeft()), node.toString(), toString(node.getRight()) );
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
}