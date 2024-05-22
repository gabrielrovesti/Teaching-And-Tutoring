import java.util.Scanner;

public class Es6 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Inserisci la lunghezza del vettore: ");
        int N = scanner.nextInt();
        int[] vettore = new int[N];
        
        System.out.println("Inserisci i valori del vettore:");
        for (int i = 0; i < N; i++) {
            vettore[i] = scanner.nextInt();
        }
        
        System.out.print("Inserisci il valore C: ");
        int C = scanner.nextInt();
        
        int posizione = -1;
        for (int i = 0; i < N; i++) {
            if (vettore[i] == C) {
                posizione = i;
                break;
            }
        }
        
        if (posizione != -1) {
            System.out.println("La prima occorrenza di " + C + " si trova alla posizione: " + posizione);
        } else {
            System.out.println("Il valore " + C + " non è presente nel vettore.");
        }
    }
}