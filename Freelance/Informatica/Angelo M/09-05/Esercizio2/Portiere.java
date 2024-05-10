public class Portiere extends Calciatore
{
    private int golSubiti;
    private int rigoriSubiti;
    private int rigoriParati;

    public Portiere()
    {
        super();
    }

    //COSTRUTTORI
    public Portiere(String nome,
                    int partiteGiocate,
                    int golSegnati,
                    long valoreinEuro,
                    int golSubiti, int rigoriSubiti, int rigoriParati)
    {
        super(nome, partiteGiocate, golSegnati, valoreinEuro);
        this.golSubiti = golSubiti;
        this.rigoriSubiti = rigoriSubiti;
        this.rigoriParati = rigoriParati;
    }

    public Portiere(Portiere p)
    {
        super(p);
        this.golSubiti = p.getGolSubiti();
        this.rigoriParati = p.getRigoriParati();
        this.rigoriSubiti = p.getRigoriSubiti();
    }

    //METODI DI ACCESSO

    public int getGolSubiti() {
        return golSubiti;
    }

    public void setGolSubiti(int golSubiti) {
        this.golSubiti = golSubiti;
    }

    public int getRigoriSubiti() {
        return rigoriSubiti;
    }

    public void setRigoriSubiti(int rigoriSubiti) {
        this.rigoriSubiti = rigoriSubiti;
    }

    public int getRigoriParati() {
        return rigoriParati;
    }

    public void setRigoriParati(int rigoriParati) {
        this.rigoriParati = rigoriParati;
    }

    //METODI ACCESSORI
    public void stampaInfo()
    {
        System.out.println("|-------------------------------------|");
        System.out.println("|              PORTIERE               |");
        System.out.println("|-------------------------------------|");
        System.out.println("| Nome            : " + String.format("%-18s", this.getNome()) + "|");
        System.out.println("| # Gol segnati   : " + String.format("%-18s", this.getGolSegnati()) + "|");
        System.out.println("| # Presenza      : " + String.format("%-18s", this.getPartiteGiocate()) + "|");
        System.out.println("| # Media Gol     : " + String.format("%-18s", this.mediaGol()) + "|");
        System.out.println("| # Gol subiti    : " + String.format("%-18s", this.golSubiti) + "|");
        System.out.println("| # Rigori parati : " + String.format("%-18s", this.rigoriParati) + "|");
        System.out.println("| # Rigori subiti : " + String.format("%-18s", this.rigoriSubiti)+ "|");
        System.out.println("| # Valore        : " + String.format("%-18s", this.getValoreinEuro()) + "|");
        System.out.println("|-------------------------------------|");
    }
}