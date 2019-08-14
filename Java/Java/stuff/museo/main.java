import java.io.*;
import com.mentalabs.museo;

public class main {
    public class statua extends museo {
	String materiale;
	public statua(String idStatua, String salaStatua, String nomeStatua, int annoStatua, String autoreStatua, String materialeStatua) {
	    super(idStatua, salaStatua, nomeStatua, annoStatua, autoreStatua);
	    this.materiale = materialeStatua;
	}
    }
    public class dipinto extends museo {
	String tecnica;
	int base;
	int altezza;
	public dipinto(String idDipinto, String salaDipinto, String nomeDipinto, int annoDipinto, String autoreDipinto, String tecnicaDipinto, int baseDipinto, int altezzaDipinto) {
	    super(idDipinto, salaDipinto, nomeDipinto, annoDipinto, autoreDipinto);
	    this.tecnica = tecnicaDipinto;
	    this.base = baseDipinto;
	    this.altezza = altezzaDipinto;
	}
    }
    public static void main(String args[]) {
	dipinto Genti = new dipinto("st001", "sala01", "Genti che danzano felicemente", 1945, "Adolf Hitler", "Olio su olio". 420d, 69d);
	
	
	
	
	
	
    }
}
