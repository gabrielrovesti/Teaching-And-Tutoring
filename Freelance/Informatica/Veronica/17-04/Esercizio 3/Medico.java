import java.util.ArrayList;

public class Medico extends Persona {
    private String specializzazione;
    private ArrayList<Prenotazione> prenotazioni;

    public Medico(String nome, String cognome, String CF, String specializzazione) {
        super(nome, cognome, CF);
        this.specializzazione = specializzazione;
        this.prenotazioni = new ArrayList<>();
    }

    // Metodi per gestire le prenotazioni
    public void aggiungiPrenotazione(Prenotazione prenotazione) {
        prenotazioni.add(prenotazione);
    }

    public void visualizzaPrenotazioni() {
        for (Prenotazione prenotazione : prenotazioni) {
            System.out.println(prenotazione.getInfo());
        }
    }

    public boolean isDisponibile() {
        // Implementazione della logica per verificare la disponibilità del medico
        return true;
    }
}
