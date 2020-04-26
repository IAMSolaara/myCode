public class Parola {
    private String parola;
    private int freq;

    public Parola(String parola) {
        if (parola != null) this.parola = parola;
        else parola = "a";
        freq = 1;
    }

    public Parola(Parola in) {
        if (in != null) {
            parola = in.getParola();
            freq = in.getFreq();
        }
        else {
            parola = "a";
            freq = 1;
        }
    }

    public String getParola() {
        return new String(parola);
    }

    public int getFreq() {
        return freq;
    }

    public String incFreq() {
        freq++;
    }

    public String toString() {
        return String.format("Parola: %s, Frequenza: %d", parola, freq);
    }

    public boolean equals(Object o) {
        boolean out = true;
        if (o != null && o instanceof Parola) {
            if (    !((Parola)o).getParola().equals(parola) ||
                    ((Parola)o).getFreq() != freq )
        }
        else out = false;
        return out;
    }
}