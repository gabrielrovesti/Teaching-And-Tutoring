import java.util.Scanner;

public class Esercizio2{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);

        // Creare un vettore di 10 numeri interi
        int[] vettore = new int[10];

        // Inserimento dei valori per il vettore
        for(int i = 0; i < 10; i++){
            System.out.println("Numero " + i + ":");
            vettore[i] = input.nextInt();
        }

        // Controllo elementi pari e dispari vettore
        int nP = 0, nD = 0;

        for(int i = 0; i < 10; i++){
            if(vettore[i] % 2 == 0){
                nP++;
            }
            else{
                nD++;
            }
        }

        for(int i = 0; i < vettore.length; i++){
            System.out.println(vettore[i]);
        }
    }
}