import java.util.Scanner;

public class Es5 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Inserisci la lunghezza del vettore: ");
        int N = scanner.nextInt();
        int[] vettore = new int[N];
        
        System.out.println("Inserisci i valori del vettore:");
        for (int i = 0; i < N; i++) {
            vettore[i] = scanner.nextInt();
        }
        
        int minimo = vettore[0];
        int massimo = vettore[0];
        
        for (int i = 1; i < N; i++) {
            if (vettore[i] < minimo) {
                minimo = vettore[i];
            }
            if (vettore[i] > massimo) {
                massimo = vettore[i];
            }
        }
        
        System.out.println("Il valore minimo è: " + minimo);
        System.out.println("Il valore massimo è: " + massimo);
    }
}