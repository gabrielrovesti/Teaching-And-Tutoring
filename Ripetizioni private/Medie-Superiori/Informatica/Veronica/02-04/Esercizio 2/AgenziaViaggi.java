import java.util.ArrayList;
import java.util.List;

public class AgenziaViaggi {
    private List<PacchettoViaggio> pacchettiViaggio;
    private List<Cliente> clienti;
    private List<Prenotazione> prenotazioni;

    public AgenziaViaggi() {
        pacchettiViaggio = new ArrayList<>();
        clienti = new ArrayList<>();
        prenotazioni = new ArrayList<>();
    }

    // Metodi per la gestione dei pacchetti viaggio
    public void aggiungiPacchettoViaggio(PacchettoViaggio pacchetto) {
        pacchettiViaggio.add(pacchetto);
    }

    public void modificaPacchettoViaggio(int id, PacchettoViaggio nuovoPacchetto) {
        for (int i = 0; i < pacchettiViaggio.size(); i++) {
            if (pacchettiViaggio.get(i).getId() == id) {
                pacchettiViaggio.set(i, nuovoPacchetto);
                break;
            }
        }
    }

    public void rimuoviPacchettoViaggio(int id) {
        for (int i = 0; i < pacchettiViaggio.size(); i++) {
            if (pacchettiViaggio.get(i).getId() == id) {
                pacchettiViaggio.remove(i);
                break;
            }
        }
    }

    public void visualizzaPacchettiViaggio() {
        for (PacchettoViaggio pacchetto : pacchettiViaggio) {
            System.out.println(pacchetto);
        }
    }

    public void cercaPacchettiViaggio(String destinazione, int durata, double prezzoMassimo) {
        for (PacchettoViaggio pacchetto : pacchettiViaggio) {
            if (pacchetto.getDestinazione().equals(destinazione) &&
                pacchetto.getDurata() == durata &&
                pacchetto.getPrezzo() <= prezzoMassimo) {
                System.out.println(pacchetto);
            }
        }
    }

    public void applicaSconto(double percentualeSconto) {
        for (PacchettoViaggio pacchetto : pacchettiViaggio) {
            pacchetto.applicaSconto(percentualeSconto);
        }
    }

    // Metodi per la gestione dei clienti
    public void registraCliente(Cliente cliente) {
        clienti.add(cliente);
    }

    public void modificaCliente(String email, Cliente nuovoCliente) {
        for (int i = 0; i < clienti.size(); i++) {
            if (clienti.get(i).getEmail().equals(email)) {
                clienti.set(i, nuovoCliente);
                break;
            }
        }
    }

    public void eliminaCliente(String email) {
        for (int i = 0; i < clienti.size(); i++) {
            if (clienti.get(i).getEmail().equals(email)) {
                clienti.remove(i);
                break;
            }
        }
    }

    public void visualizzaClienti() {
        for (Cliente cliente : clienti) {
            System.out.println(cliente);
        }
    }

    public void cercaCliente(String keyword) {
        for (Cliente cliente : clienti) {
            if (cliente.getNome().contains(keyword) ||
                cliente.getCognome().contains(keyword) ||
                cliente.getEmail().contains(keyword)) {
                System.out.println(cliente);
            }
        }
    }

    // Metodi per la gestione delle prenotazioni
    public void effettuaPrenotazione(String emailCliente, int idPacchetto) {
        Prenotazione prenotazione = new Prenotazione(prenotazioni.size() + 1, emailCliente, idPacchetto);
        prenotazioni.add(prenotazione);
    }

    public void annullaPrenotazione(String emailCliente, int idPacchetto) {
        for (int i = 0; i < prenotazioni.size(); i++) {
            if (prenotazioni.get(i).getEmailCliente().equals(emailCliente) && prenotazioni.get(i).getIdPacchetto() == idPacchetto) {
                prenotazioni.remove(i);
                break;
            }
        }
    }

    public void visualizzaPrenotazioniCliente(String emailCliente) {
        for (Prenotazione prenotazione : prenotazioni) {
            if (prenotazione.getEmailCliente().equals(emailCliente)) {
                System.out.println(prenotazione);
            }
        }
    }

    public void visualizzaPrenotazioniPacchetto(int idPacchetto) {
        for (Prenotazione prenotazione : prenotazioni) {
            if (prenotazione.getIdPacchetto() == idPacchetto) {
                System.out.println(prenotazione);
            }
        }
    }
}
