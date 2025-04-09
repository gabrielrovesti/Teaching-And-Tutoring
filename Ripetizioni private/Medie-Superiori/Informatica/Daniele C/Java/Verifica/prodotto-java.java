/**
 * Classe Prodotto che rappresenta un generico prodotto di un negozio.
 * Contiene codice, descrizione e prezzo unitario.
 */
public class Prodotto {
    // Variabili d'istanza (private come richiesto)
    private String codice;
    private String descrizione;
    private double prezzo;
    
    /**
     * Costruttore della classe Prodotto
     * @param codice Codice univoco del prodotto
     * @param descrizione Descrizione sintetica del prodotto
     * @param prezzo Prezzo unitario del prodotto
     */
    public Prodotto(String codice, String descrizione, double prezzo) {
        this.codice = codice;
        this.descrizione = descrizione;
        this.prezzo = prezzo;
    }
    
    // Metodi getter
    public String getCodice() {
        return codice;
    }
    
    public String getDescrizione() {
        return descrizione;
    }
    
    public double getPrezzo() {
        return prezzo;
    }
    
    // Metodi setter
    public void setCodice(String codice) {
        this.codice = codice;
    }
    
    public void setDescrizione(String descrizione) {
        this.descrizione = descrizione;
    }
    
    public void setPrezzo(double prezzo) {
        this.prezzo = prezzo;
    }
    
    /**
     * Applica uno sconto fisso del 10% al prodotto
     * @param scontoPercentuale Deve essere sempre 10
     */
    public void applicaSconto(int scontoPercentuale) {
        // Come richiesto, questo metodo applica sempre e solo uno sconto del 10%
        if (scontoPercentuale == 10) {
            prezzo = prezzo - (prezzo * 0.10);
        }
    }
    
    /**
     * Restituisce una rappresentazione testuale del prodotto
     * @return Stringa con codice, descrizione e prezzo
     */
    public String toString() {
        return "Codice: " + codice + " Descrizione: " + descrizione + " Prezzo: " + prezzo + " euro";
    }
}
