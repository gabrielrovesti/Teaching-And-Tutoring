public class ContoCorrentePrivato extends ContoCorrente {
    // ereditarietà = quello che serve alla classe padre
    // poi aggiungi contesto

    private String codiceFiscale;
    private String nome;
    private String cognome;

    public ContoCorrentePrivato(String codiceFiscale, String nome, String cognome)
    {
        super(); // usi il metodo della classe padre
        // = ContoCorrente per costruire gli attributi della classe padre
        this.codiceFiscale = codiceFiscale;
        this.nome = nome;
        this.cognome = cognome;
    }

    // Overloading completo
    public ContoCorrentePrivato(String IBAN, double saldo, int conteggioMovimenti, String codiceFiscale, String nome, String cognome)
    {
        super(IBAN, saldo, conteggioMovimenti); // costruisci per overloading anche le cose della classe padre
        this.codiceFiscale = codiceFiscale;
        this.nome = nome;
        this.cognome = cognome;
    }

    public ContoCorrentePrivato(ContoCorrentePrivato _c)
    {
        // prendo i campi della classe padre e vado a costruire
        super(_c.getIBAN(), _c.getSaldo(), _c.getConteggioMovimenti());
        this.codiceFiscale = _c.getCodiceFiscale();
        this.nome = _c.getNome();
        this.cognome = _c.getCognome();
    }

    public String getCodiceFiscale() {
        return codiceFiscale;
    }

    public String getNome() {
        return nome;
    }

    public String getCognome() {
        return cognome;
    }
}
