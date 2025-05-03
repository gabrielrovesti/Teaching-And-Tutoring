// Mappa = Import 
import java.util.*;

public class Es14_4 {

    // Mappa = Chiavi / Valori = Stringhe
    private Map<String, String> studentiVoti = new TreeMap<>();
    private Scanner input = new Scanner(System.in);

    // Operazioni da fare -> Metodi
    // (1) Inserimento studenti 
    // (2) Rimozione studenti 
    // (3) Modifica voti 
    // (4) Visualizza voti (stampa)
    // (5) Uscita --> Altrimenti

    public void eseguiProgramma(){
        boolean continua = true;

        while(continua){
            System.out.println("\nMenu:");
            System.out.println("1. Inserisci studente");
            System.out.println("2. Rimuovi studente");
            System.out.println("3. Modifica voto");
            System.out.println("4. Visualizza tutti i voti");
            System.out.println("5. Esci");
            System.out.print("Scelta: ");

            int scelta = input.nextInt();
            input.nextLine();
            
            switch (scelta) {
                case 1:
                    inserisciStudente(); 
                    // Leggiamo input e poi inseriamo 
                    // la tupla {nome, voto} = put
                    break;
                case 2:
                    rimuoviStudente();
                    // Studente [Chiave] - Voto [Valore]
                    // Se ha quella chiave -> remove()
                    break;
                case 3:
                    modificaVoto();
                    // Se trovi chiavi allora modifica -> put()
                    break;
                case 4:
                    visualizzaVoti();
                    // o la mappa è vuota oppure stampiamo in ordine
                    break;
                case 5:
                    continua = false;
                    break;
                default:
                    System.out.println("Opzione non valida!");
            }
        }
    }

    public void inserisciStudente(){
        // Leggiamo studente e voto -> nextLine()

        System.out.print("Nome dello studente: ");
        String nome = input.nextLine();
        System.out.print("Voto (A, B+, B, C+, C, D, F): ");
        String voto = input.nextLine();

        // Inseriamo la coppia nella mappa -> {nome, voto}
        studentiVoti.put(nome, voto);
        System.out.println("Studente aggiunto con successo!");
    }

    public void rimuoviStudente(){
        // Leggiamo nome studente = è la chiave (prima per chiave per poi trovare il valore)
        // for -> complessità maggiore!
        // oppure containsKey [- | -] = coppia di elementi = O (n log n)
        System.out.print("Studente da rimuovere (nome: )");
        String nome = input.nextLine();

        if(studentiVoti.containsKey(nome)){
            // se troviamo, lanciamo "remove"
            // la chiave è "in teoria" univoca, il valore è ripetuto
            // In Python -> dizionario
            studentiVoti.remove(nome);
            System.out.println("Studente rimosso con successo!");
        }
        else{
            System.out.println("Studente non trovato");
        }
    }

    public void modificaVoto(){
        System.out.print("Nome dello studente da modificare: ");
        String nome = input.nextLine();
        // Se troviamo una chiave con quel nome, rimpiazziamo il voto (lo leggiamo e lo mettiamo dentro la map con "put")
        if(studentiVoti.containsKey(nome)){
            System.out.print("Nuovo voto: ");
            String nuovoVoto = input.nextLine();
            studentiVoti.put(nome, nuovoVoto);
            System.out.println("Voto modificato con successo!");
        }
        else{
            System.out.println("Studente non trovato");
        }
    }

    public void visualizzaVoti(){
        // se vuoto -> isEmpty()
        if(studentiVoti.isEmpty())
            System.out.println("Nessuno studente presente");
        
        System.out.println("Elenco voti\n");
        // Entry<K, V> = Key, Value = String, String
        for(Map.Entry<String, String> entry: studentiVoti.entrySet()){
            // Stampa coppia -> entry.key / entry.value
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }
    }

    // Design pattern - Modulare = Ogni cosa / Una funzionalità
    
    public static void main(String[] args) {
        Es14_4 programma = new Es14_4();
        programma.eseguiProgramma();
    }
}
