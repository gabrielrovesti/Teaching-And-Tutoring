import java.util.Scanner;

public class GestioneContatti {

    private static final int MAX_CONTATTI = 100;
    private String[] nomi;
    private String[] numeri;
    private int numContatti;

    public GestioneContatti() {
        nomi = new String[MAX_CONTATTI];
        numeri = new String[MAX_CONTATTI];
        numContatti = 0;
    }

    public void aggiungiContatto(String nome, String numero) {
        if (numContatti < MAX_CONTATTI) {
            nomi[numContatti] = nome;
            numeri[numContatti] = numero;
            numContatti++;
            System.out.println("Contatto aggiunto con successo.");
        } else {
            System.out.println("Limite massimo di contatti raggiunto.");
        }
    }

    
    public void rimuoviContatto(String nome) {
        int indice = -1;
        for (int i = 0; i < numContatti; i++) {
            if (nomi[i].equals(nome)) {
                indice = i;
                break;
            }
        }
        if (indice != -1) {
            for (int i = indice; i < numContatti - 1; i++) {
                nomi[i] = nomi[i + 1];
                numeri[i] = numeri[i + 1];
            }
            nomi[numContatti - 1] = null;
            numeri[numContatti - 1] = null;
            numContatti--;
            System.out.println("Contatto rimosso con successo.");
        } else {
            System.out.println("Contatto non trovato.");
        }
    }

    public void visualizzaElencoContatti() {
        System.out.println("Elenco dei contatti:");
        for (int i = 0; i < numContatti; i++) {
            System.out.println(nomi[i] + ": " + numeri[i]);
        }
    }

    public void cercaContatto(String nome) {
        boolean trovato = false;
        for (int i = 0; i < numContatti; i++) {
            if (nomi[i].equals (nome)) {
                System.out.println("Contatto trovato:");
                System.out.println(nomi[i] + ": " + numeri[i]);
                trovato = true;
                break;
            }
        }
        if (!trovato) {
            System.out.println("Contatto non trovato.");
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        GestioneContatti gestore = new GestioneContatti();

        while (true) {
            System.out.println("\nMenu:");
            System.out.println("1. Aggiungi contatto");
            System.out.println("2. Rimuovi contatto");
            System.out.println("3. Visualizza elenco contatti");
            System.out.println("4. Cerca contatto per nome");
            System.out.println("5. Esci");

            System.out.print("Scelta: ");
            int scelta = scanner.nextInt();
            scanner.nextLine();  // Consuma il newline

            switch (scelta) {
                case 1:
                    System.out.print("Nome: ");
                    String nome = scanner.nextLine();
                    System.out.print("Numero di telefono: ");
                    String numero = scanner.nextLine();
                    gestore.aggiungiContatto(nome, numero);
                    break;
                case 2:
                    System.out.print("Nome del contatto da rimuovere: ");
                    String nomeDaRimuovere = scanner.nextLine();
                    gestore.rimuoviContatto(nomeDaRimuovere);
                    break;
                case 3:
                    gestore.visualizzaElencoContatti();
                    break;
                case 4:
                    System.out.print("Nome del contatto da cercare: ");
                    String nomeDaCercare = scanner.nextLine();
                    gestore.cercaContatto(nomeDaCercare);
                    break;
                case 5:
                    System.out.println("Arrivederci!");
                    System.exit(0);
                default:
                    System.out.println("Scelta non valida. Riprova.");
            }
        }
    }
}