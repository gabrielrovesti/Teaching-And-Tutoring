import java.util.Scanner;

public class Esercizio1{
    
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        
        // Creazione N
        int N;
    
        System.out.println("Inserisci il valore di N: ");
        
        // N compreso tra 0 e 20
    
        do {
            System.out.print("Inserisci il valore di N (tra 0 e 20): ");
            N = input.nextInt();
        } while (N < 0 || N > 20);
    
        // Creazione vettore di N interi
        int[] vettore = new int[N];
        System.out.println("Inserisci " + N + " numeri:");
        
        // Chiedere in input i numeri per il vettore
        for(int i = 0; i < N; i++){
            System.out.println("Numero " + i + ": ");
            vettore[i] = input.nextInt();
        }
        
        // Creazione vettore con stessa dimensione 
        int[] vettoreRibaltato = new int[N];
        for (int i = 0; i < N; i++) {
            vettoreRibaltato[i] = vettore[N - 1 - i];
        }
        
        // Stampa dei due vettori 
        
        for(int i = 0; i < vettore.length; i++){
            System.out.println("Vettore normale con elemento " + i + " con valore " + vettore[i]);
        }

        for(int i = 0; i < vettore.length; i++){
            System.out.println("Vettore ribaltato con elemento " + i + " con valore " + vettoreRibaltato[i]);
        }
        
    }

    
}