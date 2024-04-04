import java.util.Scanner;

public class GestioneVoti {

    private static final int NUM_MATERIE = 3;
    private static final int MAX_STUDENTI = 50;
    private static final int VOTO_SOGLIA = 7;

    private String[] nomiStudenti;
    private int[][] votiStudenti;
    private int numStudenti;

    public GestioneVoti() {
        nomiStudenti = new String[MAX_STUDENTI];
        votiStudenti = new int[MAX_STUDENTI][NUM_MATERIE];
        numStudenti = 0;
    }

    public void inserisciVoti(String nome, int[] voti) {
        if (numStudenti < MAX_STUDENTI) {
            nomiStudenti[numStudenti] = nome;
            votiStudenti[numStudenti] = voti;
            numStudenti++;
        } else {
            System.out.println("Limite massimo di studenti raggiunto.");
        }
    }

    public double calcolaMediaVotiStudente(int indiceStudente) {
        int[] voti = votiStudenti[indiceStudente];
        double somma = 0;
        for (int voto : voti) {
            somma += voto;
        }
        return somma / NUM_MATERIE;
    }

    public double calcolaMediaVotiMateria(int indiceMateria) {
        double somma = 0;
        for (int i = 0; i < numStudenti; i++) {
            somma += votiStudenti[i][indiceMateria];
        }
        return somma / numStudenti;
    }

    public int contaStudentiConVotoSuperioreASoglia(int soglia) {
        int count = 0;
        for (int i = 0; i < numStudenti; i++) {
            for (int voto : votiStudenti[i]) {
                if (voto > soglia) {
                    count++;
                    break;
                }
            }
        }
        return count;
    }

    public void visualizzaStudentiConVotoMassimoInMateria(int indiceMateria) {
        int votoMassimo = Integer.MIN_VALUE;
        for (int i = 0; i < numStudenti; i++) {
            if (votiStudenti[i][indiceMateria] > votoMassimo) {
                votoMassimo = votiStudenti[i][indiceMateria];
            }
        }
        System.out.println("Studenti con voto massimo in materia " + indiceMateria + ":");
        for (int i = 0; i < numStudenti; i++) {
            if (votiStudenti[i][indiceMateria] == votoMassimo) {
                System.out.println(nomiStudenti[i]);
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        GestioneVoti gestore = new GestioneVoti();

        // Inserimento dei dati degli studenti
        System.out.println("Inserisci i dati degli studenti:");
        for (int i = 0; i < MAX_STUDENTI; i++) {
            System.out.println("Studente " + (i + 1) + ":");
            System.out.print("Nome: ");
            String nome = scanner.nextLine();
            int[] voti = new int[NUM_MATERIE];
            for (int j = 0; j < NUM_MATERIE; j++) {
                System.out.print("Voto in materia " + (j + 1) + ": ");
                voti[j] = scanner.nextInt();
            }
            scanner.nextLine();  // Consuma il newline
            gestore.inserisciVoti(nome, voti);
            System.out.println();
        }

        // Calcolo e visualizzazione della media dei voti di ciascuno studente
        System.out.println("Media dei voti di ciascuno studente:");
        for (int i = 0; i < gestore.numStudenti; i++) {
            System.out.println(gestore.nomiStudenti[i] + ": " + gestore.calcolaMediaVotiStudente(i));
        }

        // Calcolo e visualizzazione della media dei voti di ciascuna materia
        System.out.println("\nMedia dei voti di ciascuna materia:");
        for (int i = 0; i < NUM_MATERIE; i++) {
            System.out.println("Materia " + (i + 1) + ": " + gestore.calcolaMediaVotiMateria(i));
        }

        // Conta studenti con voto superiore a una determinata soglia
        System.out.println("\nNumero di studenti con voto superiore a " + VOTO_SOGLIA + ": " +
                gestore.contaStudentiConVotoSuperioreASoglia(VOTO_SOGLIA));

        // Visualizza studenti con voto massimo in una specifica materia
        int materiaDaCercare = 0; // Indice della materia da cercare (0, 1 o 2)
        gestore.visualizzaStudentiConVotoMassimoInMateria(materiaDaCercare);

        scanner.close();
    }
}
