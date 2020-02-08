import java.util.List;
import java.util.ArrayList;

public class CassaVeloceDellAuchan {
    public static final int MAXTHINGS = 15;

    List<Merce> coseDaComprare;

    public CassaVeloceDellAuchan() {
        coseDaComprare = new ArrayList<Merce>();
    }

    public CassaVeloceDellAuchan(CassaVeloceDellAuchan in) {
        coseDaComprare = new ArrayList<Merce>(in.getCoseDaComprare());
    }

    public ArrayList<Merce> getCoseDaComprare() {
        return new ArrayList<Merce>(coseDaComprare);
    }

    public boolean add(Merce m) {
        boolean out = true;
        if (coseDaComprare.size() >= MAXTHINGS || m == null) out = false;
        else {
            coseDaComprare.add(m);
        }
        return out;
    }
}
