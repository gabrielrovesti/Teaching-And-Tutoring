import java.util.Scanner;

public class Es4 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Inserisci la lunghezza del vettore: ");
        int N = in.nextInt();
        int[] vettore = new int[N];
        
        System.out.println("Inserisci i valori del vettore:");
        for (int i = 0; i < N; i++) {
            vettore[i] = in.nextInt();
        }
        
        System.out.print("Inserisci il valore B: ");
        int B = in.nextInt();
        
        int somma = 0;
        for (int i = 0; i < N; i++) {
            if (vettore[i] % B == 0) {
                somma += vettore[i];
            }
        }
        
        System.out.println("La somma dei multipli di " + B + " è: " + somma);
    }
}