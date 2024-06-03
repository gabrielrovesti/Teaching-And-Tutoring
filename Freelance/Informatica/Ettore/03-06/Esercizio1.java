import java.util.Scanner;
public class Esercizio1{
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Inserisci la dimensione del vettore (1-30): ");
        int N = in.nextInt();

        while(N < 1 || N > 30){
            System.out.print("Dimensione non valida. Inserisci un valore tra 1 e 30: ");
            N = in.nextInt();
        }

        int[] arr = new int[N];

        for(int i = 0; i < N; i++){
            arr[i] = in.nextInt();
        }

        int[] dispari = new int[N];

        for(int i = 0; i < N; i++){
            if(arr[i] % 2 != 0){
                dispari[i] = arr[i];
            }
        }

        for(int i = 0; i < N; i++){
            if(arr[i] % 2 != 0){
                System.out.println("Vettore con elemento: " + dispari[i]);
            }
        }
    }
}
