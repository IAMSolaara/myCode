import java.io.*;
import com.mentalabs.Opera;



public class main {
    
    public static void main(String args[]) {
	Dipinto Genti = new Dipinto("st001", "sala01", "Genti che danzano felicemente", 1945, "Adolf Hitler", "Olio su olio", 420, 69);
		
    }
    public class Dipinto extends Opera {
	private String tecnica;
	private int base;
	private int altezza;
	public Dipinto(String idDipinto, String salaDipinto, String nomeDipinto, int annoDipinto, String autoreDipinto, String tecnicaDipinto, int baseDipinto, int altezzaDipinto) {
	    super(idDipinto, salaDipinto, nomeDipinto, annoDipinto, autoreDipinto);
	    this.tecnica = tecnicaDipinto;
	    this.base = baseDipinto;
	    this.altezza = altezzaDipinto;
	}
    }
    public class Statua extends Opera {
	private String materiale;
	private Statua(String idStatua, String salaStatua, String nomeStatua, int annoStatua, String autoreStatua, String materialeStatua) {
	    super(idStatua, salaStatua, nomeStatua, annoStatua, autoreStatua);
	    this.materiale = materialeStatua;
	}
    }

    
}



