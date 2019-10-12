public class Test {
	public static void main(String[] args) {
	   Lettera letereeno = new Lettera('A'); 
	   Lettera leterno2 = new Lettera(letereeno);
	   letereeno.switchCase();
	   System.out.println(letereeno.toString() + " e' " + (letereeno.isMaiuscolo() ? "maiuscola" : "minuscola"));
	   System.out.println(leterno2.toString() + " e' " + (leterno2.isMaiuscolo() ? "maiuscola" : "minuscola"));
	   System.out.println("letereeno e' " + (letereeno.equals(leterno2) ? "uguale a" : "diverso da") + " leterno2");
	}
}
