public class AgenziaViaggiArray {
    private PacchettoViaggio[] pacchettiViaggio;
    private Cliente[] clienti;
    private Prenotazione[] prenotazioni;
    private int numPacchetti;
    private int numClienti;
    private int numPrenotazioni;
    
    public AgenziaViaggi(int maxPacchetti, int maxClienti, int maxPrenotazioni) {
        pacchettiViaggio = new PacchettoViaggio[maxPacchetti];
        clienti = new Cliente[maxClienti];
        prenotazioni = new Prenotazione[maxPrenotazioni];
        numPacchetti = 0;
        numClienti = 0;
        numPrenotazioni = 0;
    }

    // Metodi per la gestione dei pacchetti viaggio
    public void aggiungiPacchettoViaggio(PacchettoViaggio pacchetto) {
        pacchettiViaggio[numPacchetti++] = pacchetto;
    }

    public void modificaPacchettoViaggio(int id, PacchettoViaggio nuovoPacchetto) {
        for (int i = 0; i < numPacchetti; i++) {
            if (pacchettiViaggio[i].getId() == id) {
                pacchettiViaggio[i] = nuovoPacchetto;
                break;
            }
        }
    }

    public void rimuoviPacchettoViaggio(int id) {
        for (int i = 0; i < numPacchetti; i++) {
            if (pacchettiViaggio[i].getId() == id) {
                for (int j = i; j < numPacchetti - 1; j++) {
                    pacchettiViaggio[j] = pacchettiViaggio[j + 1];
                }
                pacchettiViaggio[--numPacchetti] = null;
                break;
            }
        }
    }

    public void visualizzaPacchettiViaggio() {
        for (int i = 0; i < numPacchetti; i++) {
            System.out.println(pacchettiViaggio[i]);
        }
    }

    public void cercaPacchettiViaggio(String destinazione, int durata, double prezzoMassimo) {
        for (int i = 0; i < numPacchetti; i++) {
            if (pacchettiViaggio[i].getDestinazione().equals(destinazione) &&
                pacchettiViaggio[i].getDurata() == durata &&
                pacchettiViaggio[i].getPrezzo() <= prezzoMassimo) {
                System.out.println(pacchettiViaggio[i]);
            }
        }
    }

    public void applicaSconto(double percentualeSconto) {
        for (int i = 0; i < numPacchetti; i++) {
            pacchettiViaggio[i].applicaSconto(percentualeSconto);
        }
    }

    // Metodi per la gestione dei clienti
    public void registraCliente(Cliente cliente) {
        clienti[numClienti++] = cliente;
    }

    public void modificaCliente(String email, Cliente nuovoCliente) {
        for (int i = 0; i < numClienti; i++) {
            if (clienti[i].getEmail().equals(email)) {
                clienti[i] = nuovoCliente;
                break;
            }
        }
    }

    public void eliminaCliente(String email) {
        for (int i = 0; i < numClienti; i++) {
            if (clienti[i].getEmail().equals(email)) {
                for (int j = i; j < numClienti - 1; j++) {
                    clienti[j] = clienti[j + 1];
                }
                clienti[--numClienti] = null;
                break;
            }
        }
    }

    public void visualizzaClienti() {
        for (int i = 0; i < numClienti; i++) {
            System.out.println(clienti[i]);
        }
    }

    public void cercaCliente(String keyword) {
        for (int i = 0; i < numClienti; i++) {
            if (clienti[i].getNome().contains(keyword) ||
                clienti[i].getCognome().contains(keyword) ||
                clienti[i].getEmail().contains(keyword)) {
                System.out.println(clienti[i]);
            }
        }
    }

    // Metodi per la gestione delle prenotazioni
    public void effettuaPrenotazione(String emailCliente, int idPacchetto) {
        Prenotazione prenotazione = new Prenotazione(++numPrenotazioni, emailCliente, idPacchetto);
        prenotazioni[numPrenotazioni - 1] = prenotazione;
    }

    public void annullaPrenotazione(String emailCliente, int idPacchetto) {
        for (int i = 0; i < numPrenotazioni; i++) {
            if (prenotazioni[i].getEmailCliente().equals(emailCliente) && prenotazioni[i].getIdPacchetto() == idPacchetto) {
                for (int j = i; j < numPrenotazioni - 1; j++) {
                    prenotazioni[j] = prenotazioni[j + 1];
                }
                prenotazioni[--numPrenotazioni] = null;
                break;
            }
        }
    }

    public void visualizzaPrenotazioniCliente(String emailCliente) {
        for (int i = 0; i < numPrenotazioni; i++) {
            if (prenotazioni[i].getEmailCliente().equals(emailCliente)) {
                System.out.println(prenotazioni[i]);
            }
        }
    }

    public void visualizzaPrenotazioniPacchetto(int idPacchetto) {
        for (int i = 0; i < numPrenotazioni; i++) {
            if (prenotazioni[i].getIdPacchetto() == idPacchetto) {
                System.out.println(prenotazioni[i]);
            }
        }
    }
}
