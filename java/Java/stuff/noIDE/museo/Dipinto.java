import com.mentalabs.Opera;

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
