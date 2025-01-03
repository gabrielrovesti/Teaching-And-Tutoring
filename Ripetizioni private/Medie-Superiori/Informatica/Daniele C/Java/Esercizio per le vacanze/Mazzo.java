public class Mazzo {
    private final int NCARTE = 52;
    private int x = NCARTE-1;
    private final String[] seme = {"cuori", "quadri", "fiori", "picche"};
    private final int[] valore = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
    private final String[] nome = {"asso","due", "tre", "quattro", "cinque", "sei", "sette", "otto", "nove", "dieci","jack", "regina", "re"};
    private CartaDaGioco[] mazzo;
    
    public Mazzo() {
        mazzo = new CartaDaGioco[NCARTE];
        preparaMazzo();
    }
    
    public void preparaMazzo() {
        int index = 0;
        for(int i = 0; i < seme.length; i++) {
            for(int j = 0; j < nome.length; j++) {
                mazzo[index] = new CartaDaGioco(seme[i], nome[j], valore[j]);
                index++;
            }
        }
    }
    
    public String toString() {
        String s = " \n";
        for(int j = 0; j < NCARTE; j++) {
            s = s + "["+(j+1)+"]" + mazzo[j] + "\n \n";
        }
        return s;
    }
    
    public void mescola() {
        Random rand = new Random();
        for(int i = 0; i < NCARTE; i++) {
            int j = rand.nextInt(NCARTE);
            CartaDaGioco temp = mazzo[i];
            mazzo[i] = mazzo[j];
            mazzo[j] = temp;
        }
    }
    
    public CartaDaGioco pescaPrima() {
        if(x >= 0) {
            CartaDaGioco carta = mazzo[0];
            // Sposta tutte le carte rimanenti di una posizione a sinistra
            for(int i = 0; i < x; i++) {
                mazzo[i] = mazzo[i + 1];
            }
            x--;
            return carta;
        }
        return null;
    }
    
    public CartaDaGioco pescaCasuale() {
        if(x >= 0) {
            Random rand = new Random();
            int index = rand.nextInt(x + 1);
            CartaDaGioco carta = mazzo[index];
            // Sposta tutte le carte dopo l'indice di una posizione a sinistra
            for(int i = index; i < x; i++) {
                mazzo[i] = mazzo[i + 1];
            }
            x--;
            return carta;
        }
        return null;
    }
}