/**
 * @author Lorenzo Cauli 13/05/2020
 * @version 0.1
 */

/* Progetto della classe TreeNode
 *
 * Attributi:
 * - exp: int >=0
 * - coeff: double
 * - left: TreeNode
 * - right: TreeNode
 *
 * Metodi:
 * Costruttori:
 * + TreeNode (in exp: int, coeff: double)
 * 
 * Accessori:
 * + getExp(): int
 * + getCoeff(): double
 * + getLeft(): TreeNode 
 * + getRight(): TreeNode
 *
 * Modificatori:
 * + setLeft(in tn: TreeNode): void
 * + setRight(in tn: TreeNode): void
 *
 * Altri metodi:
 * + toString(): String
 */

public class TreeNode {

	//Attributi
	private int exp;
	private double coeff;
	private TreeNode left, right;

	//Costruttori
	/**
	 * Crea un' istanza di TreeNode
	 */
	public TreeNode(int exp, double coeff) {
		this.coeff = coeff;
		if (exp >= 0) this.exp = exp;
		else exp = 1;
		left = null;
		right = null;
	}

	//Accessori
	/**
	 * Restituisce il valore del TreeNode
	 * @return Valore del nodo
	 */
	public double getCoeff() {
		return coeff;
	}

	public int getExp() {
		return exp;
	}

	/**
	 * Restituisce il nodo sinistro
	 * @return Nodo sinistro
	 */
	public TreeNode getLeft() {
		
		return left;
	}

	/**
	 * Restituisce il nodo destro
	 * @return Nodo destro
	 */
	public TreeNode getRight() {
		
		return right;
	}

	/**
	 * Imposta il nodo sinistro
	 * @param tn Nodo sinistro da impostare
	 */
	public void setLeft(TreeNode tn) {

		left = tn;
	}

	/**
	 * Imposta il nodo destro
	 * @param tn Nodo destro da impostare
	 */
	public void setRight(TreeNode tn) {

		right = tn;
	}

	//Altri metodi
	/**
	 * Restituisce una stringa con lo stato dell'oggetto
	 * @return Stringa con lo stato dell'oggetto
	 */
	public String toString() {
		return ""+coeff+"x^"+exp;
	}

	public double eval(double x ){ 
		return Math.pow(x, exp) * coeff;
	}
}