public class Calciatore
{
    private String nome;
    private int partiteGiocate;
    private int golSegnati;
    private long valoreinEuro;

    //COSTRUTTORI
    public Calciatore() { }

    public Calciatore(String nome, int partiteGiocate, int golSegnati, long valoreinEuro)
    {
        this.nome = nome;
        this.partiteGiocate = partiteGiocate;
        this.golSegnati = golSegnati;
        this.valoreinEuro = valoreinEuro;
    }

    public Calciatore(Calciatore c)
    {
        this.nome = c.getNome();
        this.partiteGiocate = c.getPartiteGiocate();
        this.golSegnati = c.getGolSegnati();
        this.valoreinEuro = c.getValoreinEuro();
    }

    //METODI DI ACCESSO


    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
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

    //METODI ACCESSORI
    public void stampaInfo()
    {
        System.out.println("|-------------------------------------|");
        System.out.println("|              CALCIATORE             |");
        System.out.println("|-------------------------------------|");
        System.out.println("| Nome            : " + String.format("%-18s", this.nome) + "|");
        System.out.println("| # Gol segnati   : " + String.format("%-18s", this.golSegnati) + "|");
        System.out.println("| # Presenza      : " + String.format("%-18s", this.partiteGiocate) + "|");
        System.out.println("| # Media Gol     : " + String.format("%-18s", this.mediaGol()) + "|");
        System.out.println("| # Valore        : " + String.format("%-18s", this.valoreinEuro) + "|");
        System.out.println("|-------------------------------------|");
    }

    public double mediaGol()
    {
        double media = 0;

        media = (double)this.golSegnati / (double)this.partiteGiocate;
        media = Math.round(media * 100.0)/100.0;
        return media;
    }
}
