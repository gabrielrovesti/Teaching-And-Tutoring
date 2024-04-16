import java.util.Date;

public class Principale {
    public static void main(String[] args) {
        Ospedale ospedale = new Ospedale();

        // Creazione di un medico
        Medico medico = new Medico("Nome Medico", "Cognome Medico", "CF Medico", "Specializzazione Medico");
        ospedale.aggiungiMedico(medico);

        // Creazione di un paziente
        Paziente paziente = new Paziente("Nome Paziente", "Cognome Paziente", "CF Paziente", "Diagnosi Paziente");
        ospedale.aggiungiPaziente(paziente);

        // Esempio di prenotazione di una visita medica
        Prenotazione prenotazione = new Prenotazione(medico, paziente, "Trattamento", new Date());
        // Aggiungere la prenotazione al medico o all'ospedale per ulteriore gestione
    }
}
