class GestoreProdotti{
    private int numeroProdotti;
    private double totalePrezzo;
    private String nomeProdotto;
    private double prezzo;

    // Costruttore = stesso nome della classe
    // dà valore ai campi della classe
    public GestoreProdotti(String nome, double pr){
        // variabile.campo = campo;
        this.nomeProdotto = nome;
        this.prezzo = pr;
    }

    // Metodo = esegue un'operazione qualsiasi
    public String getNomeProdotto(){
        return nomeProdotto;
    }

    public double getPrezzo(){
        return prezzo;
    }

    public static double getPrezzoMedio(){
        // Media = Totale / Quantità
        if(numeroProdotti == 0) return -1.0;
        return totalePrezzo / numeroProdotti;
    }
}