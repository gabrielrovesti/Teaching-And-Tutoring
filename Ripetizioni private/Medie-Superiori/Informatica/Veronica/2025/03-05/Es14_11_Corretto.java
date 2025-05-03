import java.util.*;

public class Es14_11 {
    // Coda di priorità
    private PriorityQueue<Attività> attività;
    private Scanner input;
    
    // Classe interna per rappresentare un'attività
    class Attività implements Comparable<Attività> {
        // Priorità e descrizione per ogni elemento coda di priorità
        private int priorità;
        private String descrizione;
        
        // Costruttore
        public Attività(int priorità, String descrizione) {
            this.priorità = priorità;
            this.descrizione = descrizione;
        }
        
        // Comparare elementi tra di loro
        // Logica: Ordine crescente per priorità (1 è la più alta)
        @Override
        public int compareTo(Attività altra) {
            return Integer.compare(this.priorità, altra.priorità);
        }
        
        // toString
        @Override
        public String toString() {
            return "[Priorità: " + priorità + "] " + descrizione;
        }
    }
    
    // Costruttore principale
    public Es14_11() {
        attività = new PriorityQueue<>();
        input = new Scanner(System.in);
    }
    
    // Metodo principale di gestione del programma
    public void esegui() {
        boolean inEsecuzione = true;
        while(inEsecuzione) {
            System.out.println("\n=== Lista Cose da Fare ===");
            System.out.println("1. Aggiungi attività (add)");
            System.out.println("2. Prossima attività (next)");
            System.out.println("3. Esci (quit)");
            System.out.print("> ");
           
            String comando = input.nextLine();
           
            switch (comando) {
                case "1":
                case "add":
                    aggiungiAttività();
                    break;
                case "2":
                case "next":
                    elaboraProssimaAttività();
                    break;
                case "3":
                case "quit":
                    inEsecuzione = false;
                    System.out.println("Arrivederci!");
                    break;
                default:
                    System.out.println("Comando non riconosciuto. Riprova.");
            }
        }
    }
    
    // Metodo per aggiungere una nuova attività
    public void aggiungiAttività() {
        try {
            System.out.print("Inserisci la priorità (1-9, 1 = più urgente): ");
            String inputPriorità = input.nextLine();
            int priorità = Integer.parseInt(inputPriorità);
            
            if(priorità < 1 || priorità > 9) {
                System.out.println("Priorità non valida: deve essere tra 1 e 9");
                return;
            }
           
            System.out.print("Descrizione: ");
            String descrizione = input.nextLine().trim();
            
            if(descrizione.isEmpty()) {
                System.out.println("La descrizione non può essere vuota");
                return;
            }
            
            // Inseriamo l'attività nella coda
            attività.add(new Attività(priorità, descrizione));
            System.out.println("Attività aggiunta correttamente!");
        } catch (NumberFormatException e) {
            System.out.println("Errore: inserisci un numero valido per la priorità");
        }
    }
    
    // Metodo per elaborare la prossima attività
    public void elaboraProssimaAttività() {
        if(attività.isEmpty()) {
            System.out.println("Non ci sono attività da completare!");
            return;
        }
        
        // Estraiamo l'attività a priorità più alta
        Attività prossimaAttività = attività.poll();
        System.out.println("Attività completata: " + prossimaAttività);
    }
    
    // Metodo main
    public static void main(String[] args) {
        Es14_11 listaCoseDaFare = new Es14_11();
        listaCoseDaFare.esegui();
    }
}