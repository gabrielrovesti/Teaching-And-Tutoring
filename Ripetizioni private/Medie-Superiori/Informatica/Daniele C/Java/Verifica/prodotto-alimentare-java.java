import java.time.LocalDate;
import java.time.temporal.ChronoUnit;

/**
 * Sottoclasse ProdottoAlimentare che estende Prodotto
 * Aggiunge la data di scadenza e la logica di sconto specifica
 */
public class ProdottoAlimentare extends Prodotto {
    // Variabile d'istanza aggiuntiva
    private LocalDate dataScadenza;
    
    /**
     * Costruttore della classe ProdottoAlimentare
     * @param codice Codice univoco del prodotto
     * @param descrizione Descrizione sintetica del prodotto
     * @param prezzo Prezzo unitario del prodotto
     * @param dataScadenza Data di scadenza del prodotto alimentare
     */
    public ProdottoAlimentare(String codice, String descrizione, double prezzo, LocalDate dataScadenza) {
        super(codice, descrizione, prezzo);
        this.dataScadenza = dataScadenza;
    }
    
    // Getter e setter per dataScadenza
    public LocalDate getDataScadenza() {
        return dataScadenza;
    }
    
    public void setDataScadenza(LocalDate dataScadenza) {
        this.dataScadenza = dataScadenza;
    }
    
    /**
     * Applica uno sconto del 50% se la data di scadenza è a meno di 10 giorni dalla data attuale
     */
    @Override
    public void applicaSconto(int scontoPercentuale) {
        // Ottengo la data odierna
        LocalDate dataOdierna = LocalDate.now();
        
        // Calcolo la differenza in giorni tra la data di scadenza e la data odierna
        long giorniAllaScadenza = ChronoUnit.DAYS.between(dataOdierna, dataScadenza);
        
        // Se mancano meno di 10 giorni alla scadenza, applico uno sconto del 50%
        if (giorniAllaScadenza < 10) {
            setPrezzo(getPrezzo() - (getPrezzo() * 0.50));
        } else {
            // Altrimenti applico lo sconto standard del 10%
            super.applicaSconto(10);
        }
    }
    
    /**
     * Restituisce una rappresentazione testuale del prodotto alimentare
     * @return Stringa con codice, descrizione, prezzo e data di scadenza
     */
    @Override
    public String toString() {
        if (LocalDate.now().isAfter(dataScadenza)) {
            return super.toString() + " Data Scadenza: " + dataScadenza + " (SCADUTO)";
        }
        return super.toString() + " Data Scadenza: " + dataScadenza;
    }
}
