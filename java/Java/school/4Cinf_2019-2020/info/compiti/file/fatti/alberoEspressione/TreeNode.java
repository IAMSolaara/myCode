/**
 * @author Ricco Davide
 * @version 0.1
 */

/* Progetto della classe TreeNode
 *
 * Attributi:
 * - val: double
 * - op: String
 * - left: TreeNode
 * - right: TreeNode
 * - isOperator: boolean
 *
 * Metodi:
 * Costruttori:
 * + TreeNode (in val: String)
 * 
 * Accessori:
 * + getVal(): String
 * + getOp(): String
 * + getLeft(): TreeNode 
 * + getRight(): TreeNode
 *
 * Modificatori:
 * + setLeft(in tn: TreeNode): void
 * + setRight(in tn: TreeNode): void
 *
 * Altri metodi:
 * + toString(): String
 * + isOperator(): boolean
 */

public class TreeNode {

	//Attributi
	private String op;
	private double val;
	private TreeNode left, right;
	private boolean isOperator;

	//Costruttori
	/**
	 * Crea un' istanza di TreeNode
	 */
	public TreeNode(String val) {

		if (val != null) {
			if (val.equals("+") || val.equals("*")) { // operatore
				this.op = val;
				this.val = 0;
				isOperator = true;
			} else {
				this.val = Double.parseDouble(val);
				this.op = null;
				isOperator = false;
			}
		}
		left = null;
		right = null;
	}

	//Accessori
	/**
	 * Restituisce il valore del TreeNode
	 * @return Valore del nodo
	 */
	public double getVal() {
		return val;
	}

	public String getOp() {
		return op;
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
		String out = "";
		if (isOperator)
			out+=op;
		else out += val;
		return out;
	}
	
	public boolean isOperator() {return isOperator;}

}