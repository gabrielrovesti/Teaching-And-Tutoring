import java.util.Scanner;

public class Es7 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Inserisci la lunghezza del vettore: ");
        int N = scanner.nextInt();
        int[] vettore = new int[N];
        
        System.out.println("Inserisci i valori del vettore:");
        for (int i = 0; i < N; i++) {
            vettore[i] = scanner.nextInt();
        }
        
        int conteggioPari = 0;
        for (int i = 0; i < N; i++) {
            if (vettore[i] % 2 == 0) {
                conteggioPari++;
            }
        }
        
        int[] vettorePari = new int[conteggioPari];
        int indice = 0;
        for (int i = 0; i < N; i++) {
            if (vettore[i] % 2 == 0) {
                vettorePari[indice] = vettore[i];
                indice++;
            }
        }
        
        System.out.print("Il nuovo vettore con gli elementi pari è: ");
        for (int i = 0; i < conteggioPari; i++) {
            System.out.print(vettorePari[i] + " ");
        }
    }
}