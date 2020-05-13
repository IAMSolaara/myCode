/**
    @author Lorenzo Cauli 13/05/2020
    @version 0.1
*/

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/*
    Si sceglie di usare un'albero binario di ricerca perche':
        Non ci possono essere nodi con esponente uguale
        Serve un metodo di ricerca per trovare il coefficente di un certo monomio

    - root: TreeNode

    + Polinomio()
    + caricaPolinomio(in f: File): void
    - caricaPolinomio(in sc: Scanner): void
    - insert(in node: TreeNode, v: int): void

    + toString(): String
    - toString(in node: TreeNode): String

    + getCoefficente(in query: int): double
    - getCoefficente(in node: TreeNode, query: int): TreeNode

    + eval(in val: double): double
    - eval(in node: TreeNode, val: double): double
*/
public class Polinomio {
    private TreeNode root;

    /**
        Costruttore
    */
    public Polinomio() {
        root = null;
    }

    /**
        Metodo pubblico che carica l'albero da un file
        @param f File input
    */
    public void caricaPolinomio(File f) throws FileNotFoundException {
        try {
            Scanner sc = new Scanner(f);
            int exp;
            double coeff;
            boolean start = true;
            TreeNode tmp;
            while (sc.hasNext()) {
                coeff = sc.nextDouble();
                exp = sc.nextInt();
                root = insert(root, exp, coeff);
            }
        } catch (FileNotFoundException e) {
            throw new FileNotFoundException("File non trovato.");
        } catch (NullPointerException e) {
            throw new NullPointerException("Errore lettura file.");
        }
    }

    /**
        Metodo che inserisce un nodo nell'albero col numero fornito
        @param node Radice sottoalbero dove inserire il numero
        @param v Numero da inserire
    */
    private TreeNode insert(TreeNode node, int exp, double coeff) {
        TreeNode out = null;
        if (node != null) {
            out = node;
            if (exp < out.getExp()) {        //se v minore allora sinistro
                out.setLeft(insert(out.getLeft(), exp, coeff));
            }
            else if (exp > out.getExp()) { //destra
                out.setRight(insert(out.getRight(), exp, coeff));
            }
        } else out = new TreeNode(exp, coeff);
        return out;
    }

    /**
        Metodo che fa visita simmetrica
        @return stringa che raffigura l'albero con visita simmetrica
    */  
    public String toString() {
        String out = "";
        out += toString(root);
        return out;
    }

    /**
        Controparte privata toString
    */
    private String toString(TreeNode node) {
        String out = "";
        if (node != null) {
            out += toString(node.getLeft());
            out += " " + node.toString() + " ";
            out += toString(node.getRight());
        }
        return out;
    }

    /**
        Metodo che conta le foglie
        @return numero delle foglie
    */
    public int contaFoglie() {
        int out = 0;
        out = contaFoglie(root);
        return out;
    }

    /**
        Controparte privata contaFoglie
    */
    private int contaFoglie(TreeNode node) {
        int out = 0;
        if (node != null) {
            if (node.getLeft() == null && node.getRight() == null)
                out = 1;
            else {
                out += contaFoglie(node.getLeft());
                out += contaFoglie(node.getRight());
            }
        }
        return out;
    }

    /**
        Metodo che conta i nodi
        @return numero dei nodi
    */
    public int contaNodi() {
        return contaNodi(root);
    }

    /**
        Controparte privata contaNodi
    */
    private int contaNodi(TreeNode node) {
        int out = 0;
        if (node != null) {
            out++;
            out += contaNodi(node.getLeft());
            out += contaNodi(node.getRight());
        }
        return out;
    }


    public Double getCoefficente(int exp) {
        return getCoefficente(root, exp);
    }
    
    /**
        Metodo che cerca un valore nell'albero
        @param node Radice sottoalbero dove cercare il numero
        @param v Numero da cercare
    */
    private Double getCoefficente(TreeNode node, int exp) {
        Double out = null; //esponente non trovato
        if (node != null) {
            if (node.getExp() == exp) out = node.getCoeff();
            else if (exp < node.getExp()) {
                out = getCoefficente(node.getLeft(), exp);
            }
            else {
                out = getCoefficente(node.getRight(), exp);
            }
        }
        return out;
    } 

    public double eval(double x) {
        return eval(root, x);
    }

    private double eval(TreeNode node, double x) {
        double out = 0;
        if (node != null) {
            out += node.eval(x);
            out += eval(node.getLeft(), x);
            out += eval(node.getRight(), x);
        }
        return out;
    }
}