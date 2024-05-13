import java.util.Scanner;

public class Vettori2{

    public static void main(String[] args) {
    Scanner input = new Scanner(System.in);

    // Dichiarazione vettore
    int[] arr = new int[10];

    // Riempimento vettore
    for(int i = 0; i < arr.length; i++){
        System.out.println("Inserisci l'elemento in posizione " + i);
        arr[i] = input.nextInt();
    }

    // Dichiaro le variabili per trovare minimo e la posizione
    int min = arr[0], posMin = 0;
    // Con max -> max = 0 / posMax = 0;
    for(int i = 0; i < arr.length; i++){
        if (arr[i] < min){
            min = arr[i]; // salvo il minimo (elemento in posizione "i" - arr[i])
            posMin = i; // salvo la posizione (cioè "i")
        }
        // se fosse ricerca massimo
        /*
        if (arr[i] > max){
            max = arr[i]; 
            posMax = i;
        }
         */
    }

    System.out.println("Elemento minimo: " + min);
    System.out.println("Posizione minima: " + posMin);

    input.close();
    }
}


