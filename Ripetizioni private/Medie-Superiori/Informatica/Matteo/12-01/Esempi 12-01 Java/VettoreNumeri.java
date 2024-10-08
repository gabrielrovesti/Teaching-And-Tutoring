import java.util.Scanner;

public class VettoreNumeri {
    private int n;
    private int[] vettore;
    private float media;
    private float somma;

    // Costruttore
    VettoreNumeri(int x) {
        this.n = x;
        this.vettore = new int[n];

        Scanner sc = new Scanner(System.in);

        for (int k = 0; k < n; k++) {
            try {
                System.out.println("Inserisci elemento nel posto: " + (k + 1));
                vettore[k] = sc.nextInt();
            } catch (Exception e) {
                System.out.println("Errore di inserimento, riprova");
                sc.next(); 
                k--; 
            }
        }
    }

    // Metodo di calcolo somma
    public float calcoloSomma() {
        somma = 0;
        for (int k = 0; k < n; k++) {
            somma += vettore[k];
        }
        return somma;
    }

    // Metodo di calcolo media
    public float calcoloMedia() {
        media = 0; 
        for (int k = 0; k < n; k++) {
            media += vettore[k];
        }
        media /= n;
        return media;
    }

    // Funzionalità di stampa
    public void stampa() {
        System.out.println("La somma e la media dell'array sono:");
        System.out.println("Somma: " + somma);
        System.out.println("Media: " + media);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int dimensione = 0;

        System.out.println("Digita la dimensione dell'array: ");
        dimensione = sc.nextInt();

        // Creazione del vettore
        VettoreNumeri vettore = new VettoreNumeri(dimensione);
        vettore.calcoloSomma(); // Calcolo somma
        vettore.calcoloMedia(); // Calcolo media
        vettore.stampa(); // Stampa risultati
    }
}
