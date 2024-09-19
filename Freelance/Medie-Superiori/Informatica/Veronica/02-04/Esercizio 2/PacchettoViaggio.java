class PacchettoViaggio {
    private int id;
    private String destinazione;
    private int durata;
    private double prezzo;
    private int postiDisponibili;

    public PacchettoViaggio(int id, String destinazione, int durata, double prezzo, int postiDisponibili) {
        this.id = id;
        this.destinazione = destinazione;
        this.durata = durata;
        this.prezzo = prezzo;
        this.postiDisponibili = postiDisponibili;
    }

    public int getId() {
        return id;
    }

    public String getDestinazione() {
        return destinazione;
    }

    public int getDurata() {
        return durata;
    }

    public double getPrezzo() {
        return prezzo;
    }

    public int getPostiDisponibili() {
        return postiDisponibili;
    }

    public void applicaSconto(double percentualeSconto) {
        this.prezzo -= this.prezzo * percentualeSconto / 100;
    }

    public void aggiornaPostiDisponibili(int postiPrenotati) {
        this.postiDisponibili -= postiPrenotati;
    }
}
