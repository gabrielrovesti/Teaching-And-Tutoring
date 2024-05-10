public class Calciatore {
    private String nome;
    private int partite;
    private int gol;
    private double valore;

    // Costruttori
    public Calciatore(){
        this.nome = "";
        this.partite = 0;
        this.gol = 0;
        this.valore = 0.0;
    }
    // default
    // Esempio di utilizzo: Calciatore c;
    // viene chiamato a prescindere

    // Costruttore di copia
    public Calciatore(Calciatore c)
    {
        this.nome = c.getNome();
        this.partiteGiocate = c.getPartite();
        this.golSegnati = c.getGol();
        this.valoreinEuro = c.getValore();
    }
    // Esempio di utilizzo: Calciatore c1(c);

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getPartite() {
        return partite;
    }

    public void setPartite(int partite) {
        this.partite = partite;
    }

    public int getGol() {
        return gol;
    }

    public void setGolSegnati(int gol) {
        this.gol = gol;
    }

    public long getValore() {
        return valore;
    }

    public void setValore(long valore) {
        this.valore = valore;
    }
}
