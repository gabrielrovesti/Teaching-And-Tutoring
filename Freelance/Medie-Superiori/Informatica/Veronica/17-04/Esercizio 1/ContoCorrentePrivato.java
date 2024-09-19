public class ContoCorrentePrivato extends ContoCorrente
{
    private String codiceFiscale;
    private String nome;
    private String cognome;

    public ContoCorrentePrivato(String codiceFiscale, String nome, String cognome)
    {
        super();
        this.codiceFiscale = codiceFiscale;
        this.nome = nome;
        this.cognome = cognome;
    }

    public ContoCorrentePrivato(String IBAN, double saldo, int conteggioMovimenti, String codiceFiscale, String nome, String cognome)
    {
        super(IBAN, saldo, conteggioMovimenti);
        this.codiceFiscale = codiceFiscale;
        this.nome = nome;
        this.cognome = cognome;
    }

    public ContoCorrentePrivato(ContoCorrentePrivato _c)
    {
        super(_c.getIBAN(), _c.getSaldo(), _c.getConteggioMovimenti());
        this.codiceFiscale = _c.getCodiceFiscale();
        this.nome = _c.getNome();
        this.cognome = _c.getCognome();
    }

    // METODI DI ACCESSO
    public String getCodiceFiscale() {
        return codiceFiscale;
    }

    public void setCodiceFiscale(String codiceFiscale) {
        this.codiceFiscale = codiceFiscale;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCognome() {
        return cognome;
    }

    public void setCognome(String cognome) {
        this.cognome = cognome;
    }

    @Override
    public void stampaInfo()
    {
        System.out.println("|--------------INFO CONTO-----------------|");
        System.out.println("| IBAN: " + this.getIBAN());
        System.out.println("| Cognome: " + this.cognome);
        System.out.println("| Nome: " + this.nome);
        System.out.println("| Saldo: " + this.getSaldo());
        System.out.println("| #Movimenti:" + this.getConteggioMovimenti());
        System.out.println("|-----------------------------------------|");
        System.out.println();
    }
}
