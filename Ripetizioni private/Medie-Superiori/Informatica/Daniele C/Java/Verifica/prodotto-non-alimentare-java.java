/**
 * Sottoclasse ProdottoNonAlimentare che estende Prodotto
 * Aggiunge l'informazione sul materiale e la logica di sconto specifica
 */
public class ProdottoNonAlimentare extends Prodotto {
    // Variabile d'istanza aggiuntiva
    private String materiale;
    
    /**
     * Costruttore della classe ProdottoNonAlimentare
     * @param codice Codice univoco del prodotto
     * @param descrizione Descrizione sintetica del prodotto
     * @param prezzo Prezzo unitario del prodotto
     * @param materiale Materiale principale di cui è composto il prodotto
     */
    public ProdottoNonAlimentare(String codice, String descrizione, double prezzo, String materiale) {
        super(codice, descrizione, prezzo);
        this.materiale = materiale;
    }
    
    // Getter e setter per materiale
    public String getMateriale() {
        return materiale;
    }
    
    public void setMateriale(String materiale) {
        this.materiale = materiale;
    }
    
    /**
     * Verifica se il materiale è riciclabile
     * @return true se il materiale è carta, vetro o plastica
     */
    public boolean isMaterialeRiciclabile() {
        // Converto in minuscolo per rendere il controllo case-insensitive
        String materialeLowerCase = materiale.toLowerCase();
        return materialeLowerCase.equals("carta") || 
               materialeLowerCase.equals("vetro") || 
               materialeLowerCase.equals("plastica");
    }
    
    /**
     * Applica uno sconto del 20% se il materiale è riciclabile
     */
    @Override
    public void applicaSconto(int scontoPercentuale) {
        if (isMaterialeRiciclabile()) {
            setPrezzo(getPrezzo() - (getPrezzo() * 0.20));
        } else {
            // Altrimenti applico lo sconto standard del 10%
            super.applicaSconto(10);
        }
    }
    
    /**
     * Restituisce una rappresentazione testuale del prodotto non alimentare
     * @return Stringa con codice, descrizione, prezzo e materiale
     */
    @Override
    public String toString() {
        return super.toString() + " Materiale: " + materiale + 
               (isMaterialeRiciclabile() ? " (riciclabile)" : "");
    }
}
