import java.util.Scanner;

public class ElencoContatti {
    private String[] numeri;
    private String[] nomi;
    private int numContatti;
    private static final int MAX_CONTATTI = 100;

    public ElencoContatti() {
        numeri = new String[MAX_CONTATTI];
        nomi = new String[MAX_CONTATTI];
        numContatti = 0;
    }

    public String aggiungiContatto(String numero, String nome) {
        String messaggio = "";
        if (numContatti < MAX_CONTATTI) {
            nomi[numContatti] = nome;
            numeri[numContatti] = numero;
            numContatti++;
            messaggio = "Contatto aggiunto con successo";
        } else {
            messaggio = "Limite massimo raggiunto";
        }
        return messaggio;
    }

    public String eliminaContatto(String nome) {
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
            return "Contatto rimosso con successo";
        } else {
            return "Contatto non trovato";
        }
    }

    public String elencoContatti() {
        String messaggio = "";
        for (int i = 0; i < numContatti; i++) {
            messaggio += "Nome: " + nomi[i] + " con numero " + numeri[i] + "\n";
        }
        return messaggio;
    }

    public String cercaContatto(String nome) {
        boolean found = false;
        String messaggio = "";
        for (int i = 0; i < numContatti && !found; i++) {
            if (nomi[i].equals(nome)) {
                found = true;
                messaggio += "Contatto trovato\n";
                messaggio += "Nome: " + nomi[i] + " con numero " + numeri[i] + "\n";
            }
        }
        if (!found) {
            messaggio += "Contatto non trovato, prova un altro";
        }
        return messaggio;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ElencoContatti gestore = new ElencoContatti();

        while (true) {
            System.out.println("\nMenu:");
            System.out.println("1. Aggiungi contatto");
            System.out.println("2. Rimuovi contatto");
            System.out.println("3. Visualizza elenco contatti");
            System.out.println("4. Cerca contatto per nome");
            System.out.println("5. Esci");

            System.out.print("Scelta: ");
            int scelta = scanner.nextInt();
            scanner.nextLine();

            switch (scelta) {
                case 1:
                    System.out.print("Nome: ");
                    String nome = scanner.nextLine();
                    System.out.print("Numero di telefono: ");
                    String numero = scanner.nextLine();
                    System.out.println(gestore.aggiungiContatto(numero, nome));
                    break;
                case 2:
                    System.out.print("Nome del contatto da rimuovere: ");
                    String nomeDaRimuovere = scanner.nextLine();
                    System.out.println(gestore.eliminaContatto(nomeDaRimuovere));
                    break;
                case 3:
                    System.out.println(gestore.elencoContatti());
                    break;
                case 4:
                    System.out.print("Nome del contatto da cercare: ");
                    String nomeDaCercare = scanner.nextLine();
                    System.out.println(gestore.cercaContatto(nomeDaCercare));
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
