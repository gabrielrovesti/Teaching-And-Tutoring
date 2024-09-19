public class Calciatore {
    private String nome;
    private int numeroMaglia;
    private String ruolo;
    private int golSegnati;
    private double valoreGiocatore;
    private int partiteGiocate;

    public Calciatore(){
        this.nome = "";
        this.numeroMaglia = 0;
        this.ruolo = "";
        this.golSegnati = 0;
        this.valoreGiocatore = 0;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getNumero() {
        return numeroMaglia;
    }

    public void setnumero(String numeroMaglia) {
        this.numeroMaglia = numeroMaglia;
    }

    public int getPartiteGiocate() {
        return partiteGiocate;
    }

    public void setPartiteGiocate(int partiteGiocate) {
        this.partiteGiocate = partiteGiocate;
    }

    public int getGolSegnati() {
        return golSegnati;
    }

    public void setGolSegnati(int golSegnati) {
        this.golSegnati = golSegnati;
    }

    public long getValoreinEuro() {
        return valoreinEuro;
    }

    public void setValoreinEuro(long valoreinEuro) {
        this.valoreinEuro = valoreinEuro;
    }
}
