import java.util.Scanner;

public class Es3 {
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        System.out.println("Inserisci la lunghezza del vettore: ");
        int N = in.nextInt();

        int[] arr = new int[N];

        for(int i = 0; i < N; i++){
            System.out.println("Inserisci il valore" + i + " :");
            arr[i] = in.nextInt();
        }

        System.out.println("Inserisci il valore di A: ");
        int A = in.nextInt();

        int cont = 0;   // Variabile che conta
        for(int i = 0; i < N; i++){
            if(arr[i] > A) {
                cont ++;
            }
        }
        System.out.println("Il numero di elementi maggiori di A è: " + cont);
    }
}
