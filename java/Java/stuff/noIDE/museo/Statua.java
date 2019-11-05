import com.mentalabs.Opera;

public class Statua extends Opera {
    private String materiale;
    private Statua(String idStatua, String salaStatua, String nomeStatua, int annoStatua, String autoreStatua, String materialeStatua) {
	super(idStatua, salaStatua, nomeStatua, annoStatua, autoreStatua);
	this.materiale = materialeStatua;
    }
}
