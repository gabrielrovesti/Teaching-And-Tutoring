public class Main {
    public static void main(String[] args) {
        // Creazione dell'agenzia
        AgenziaViaggi agenzia = new AgenziaViaggi();

        // Aggiunta di pacchetti viaggio all'agenzia
        agenzia.aggiungiPacchettoViaggio(new PacchettoViaggio(1, "Parigi", 7, 1500.0, 10));
        agenzia.aggiungiPacchettoViaggio(new PacchettoViaggio(2, "Roma", 10, 2000.0, 5));

        // Registrazione di clienti all'agenzia
        agenzia.registraCliente(new Cliente("cliente1@email.com", "Mario", "Rossi"));
        agenzia.registraCliente(new Cliente("cliente2@email.com", "Luigi", "Verdi"));

        // Effettuazione di prenotazioni
        agenzia.effettuaPrenotazione("cliente1@email.com", 1); // Mario Rossi prenota il pacchetto 1
        agenzia.effettuaPrenotazione("cliente2@email.com", 2); // Luigi Verdi prenota il pacchetto 2

        // Visualizzazione dei pacchetti viaggio disponibili
        System.out.println("Pacchetti viaggio disponibili:");
        agenzia.visualizzaPacchettiViaggio();

        // Visualizzazione delle prenotazioni per un cliente specifico
        System.out.println("Prenotazioni per Mario Rossi:");
        agenzia.visualizzaPrenotazioniCliente("cliente1@email.com");

        // Visualizzazione delle prenotazioni per un pacchetto viaggio specifico
        System.out.println("Prenotazioni per il pacchetto 1:");
        agenzia.visualizzaPrenotazioniPacchetto(1);
    }
}
