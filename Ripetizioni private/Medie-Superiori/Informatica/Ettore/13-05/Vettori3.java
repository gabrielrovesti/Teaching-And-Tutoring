import java.util.Scanner;

public class Vettori3{

    public static void main(String[] args) {
    Scanner input = new Scanner(System.in);

    int[] arr = new int[10];

    for(int i = 0; i < arr.length; i++){
         System.out.println("Inserisci l'elemento in posizione " + i);
       arr[i] = input.nextInt();
    }

    // Dichiarazione variabili utili
    int max = arr[0], min = arr[0], somma = 0;
    double media = 0;

    for(int i = 0; i < arr.length; i++){
        int num = arr[i];
        if (num < min) {
            min = num;
        }
        if (num > max) {
            max = num;
        }
        somma += num;
    }

    media = somma / arr.length;

    System.out.println("Valore minimo: " + min);
    System.out.println("Valore massimo: " + max);
    System.out.println("Media: " + media);

    input.close();
    }
}