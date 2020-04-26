public class Camera {
    private int letti;
    private int persone;
    private double COSTO_SINGOLO;
    private double costo;

    public Camera(int posti, double COSTO_SINGOLO) {
        if (posti >= 2 && posti <= 5) letti = posti;
        else letti = 2;
        persone = 0;
        if (COSTO_SINGOLO >= 0) this.COSTO_SINGOLO = COSTO_SINGOLO;
        else this.COSTO_SINGOLO = 10;
        costo = COSTO_SINGOLO * letti;
    }

    public Camera(Camera c) {
        if (c != null) {
            letti = c.getLetti();
            persone = c.getPersone();
            COSTO_SINGOLO = c.getCOSTO_SINGOLO();
            costo = c.getCosto();
        }
        else {
            letti = 2;
            persone = 0;
            COSTO_SINGOLO = 10;
            costo = COSTO_SINGOLO * letti;
        }
    }

    public boolean accettaOspiti(int ospiti) {
        boolean out = true;
        if (ospiti <= 5 && ospiti >= 1) {
            if (ospiti > letti - persone) out = false;
            else persone = ospiti;
        } else out = false;
        return out;
    }

    public boolean congedaOspiti(int ospiti) {
        boolean out = true;
        if (ospiti > 0) {
            if (persone - ospiti >= 0) persone -= ospiti;
        }else out = false;
        return out;
    }

    public double getCosto() {return costo;}

    public int getLetti() {return letti;}

    public int getPersone() {return persone;}

    public double getCOSTO_SINGOLO() {return COSTO_SINGOLO;}

    public String toString() {
        return String.format("Standa da %d posti, che contiene attualmente %d persone e costa %.2f euri.", letti, persone, costo);
    }
}