/**
 * @author Ricco Davide
 * @version 0.1
 */

/* Progetto della classe TreeNode
 *
 * Attributi:
 * - val: int
 * - giudizio: String
 * - left: TreeNode
 * - right: TreeNode
 * - isVote: boolean
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
 * + isVote(): boolean
 * - isNumber(): boolean
 */

public class TreeNode {

	//Attributi
	private String giudizio;
	private int val;
	private TreeNode left, right;
	private boolean isVote;

	//Costruttori
	/**
	 * Crea un' istanza di TreeNode
	 */
	public TreeNode(String val) {

		if (val != null) {
			if (isNumber(val)) { // numero
				this.val = Integer.parseInt(val);
				this.giudizio = null;
				isVote = true;
			} else {
				this.giudizio = val;
				this.val = 0;
				isVote = false;
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
	public int getVote() {
		return val;
	}

	public String getGiudizio() {
		return giudizio;
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
		if (isVote)
			out+=val;
		else out += giudizio;
		return out;
	}
	
	public boolean isVote() {return isVote;}

	private boolean isNumber(String n) {
		try{
			Integer.parseInt(n);
			return true;
		}
		catch(NumberFormatException e){
			return false;
		}
	}
}