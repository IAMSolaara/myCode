import java.util.Random;

public class AlberoDanaro {
    public static final int LUCINA_ACCESA = 4;
    public static final int LUCINA_SPENTA = 3;

    public static final int PALLINA_1 = 2;
    public static final int PALLINA_0 = 1;

    public static final int RAMO = 0;
    public static final int SFONDO = -1;
    public static final int CEPPO = -2;

    private int[][] pic;
    private int width;
    private int height;
    public static final int CEPPOHEIGHT = 3;

    public AlberoDanaro(int width, int height) {
        this.height = height;
        this.width = width;
        pic = new int[this.height][this.width];
        buildTree();
    }

    public void buildTree() {
        initTree();
        layFoundation();
        placeThings();
    }

    private void initTree() {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                pic[i][j] = SFONDO;
            }
        }
    }

    private void layFoundation() {
        int i = 0;
        int m = (width / 2);
        System.out.println(m);
        int off = 0;
        int offDir = 1;
        boolean inside = false;
        
        while (i < height) {
            pic[i][m + off] = RAMO;
            pic[i][m - off] = RAMO;
            off += offDir;
            if (i > 1 && i < height - 1) {
                if (m + off >= width - 1 || off == 1) {
                    offDir *= -1;
                }
            }
            if (i >= height - CEPPOHEIGHT) {
                for (int ceppoCnt = 0; ceppoCnt < width; ceppoCnt++) {
                    if (pic[i][ceppoCnt] == RAMO) inside = !inside;
                    if (ceppoCnt < width - 2 && ceppoCnt >= 2 && pic[i][ceppoCnt] != RAMO && inside)
                        pic[i][ceppoCnt] = CEPPO;
                    //else pic[i][ceppoCnt] = SFONDO;

                }
            }
            i++;
        }
    }

    private void placeThings() {
        Random rng = new Random(System.currentTimeMillis());

        boolean inside = false;
        for (int i = 1; i < height; i++) {
            for (int j = 0; j < width; j++) {
                // check if inside the tree or not
                if (pic[i][j] == RAMO)
                    inside = !inside;
                // if inside check if current cell isnt the tree's branch
                else if (inside && pic[i][j] != RAMO && i < height - CEPPOHEIGHT) {
                    if (rng.nextInt(9) % 4 == 1)
                        pic[i][j] = rng.nextInt(3) + PALLINA_0;
                    else pic[i][j] = SFONDO;
                }
            }
        }

    }

    public void nextFrame() {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                switch (pic[i][j]) {
                case PALLINA_0:
                    pic[i][j] = PALLINA_1;
                    break;
                case PALLINA_1:
                    pic[i][j] = PALLINA_0;
                    break;
                case LUCINA_ACCESA:
                    pic[i][j] = LUCINA_SPENTA;
                    break;
                case LUCINA_SPENTA:
                    pic[i][j] = LUCINA_ACCESA;
                    break;
                }
            }
        }
    }

    public String toString() {
        String out = "";
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                switch (pic[i][j]) {
                case RAMO:
                    out += "=";
                    break;
                case PALLINA_0:
                    out += "o";
                    break;
                case PALLINA_1:
                    out += "O";
                    break;
                case LUCINA_SPENTA:
                    out += "x";
                    break;
                case LUCINA_ACCESA:
                    out += "+";
                    break;
                case SFONDO:
                    out += " ";
                    break;
                case CEPPO:
                    out += "|";
                    break;
                }
            }
            if (i != height - 1)out += "\n";
        }
        return out;
    }
}