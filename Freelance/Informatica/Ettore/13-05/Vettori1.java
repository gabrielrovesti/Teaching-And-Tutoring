import java.util.Scanner;

public class Vettori1{

    public static void main(String[] args) {
    // Dichiarazione array di interi
    int[] arr = new int[10];
    //[][][][]...[] (come il vettore appare in memoria)
    // le quadre dopo int servono a dire quanti elementi

    Scanner input = new Scanner(System.in);

    // Inserire 10 elementi di input
    for(int i = 0; i < arr.length; i++){
        System.out.println("Inserisci l'elemento in posizione " + i);
        arr[i] = input.nextInt();
        // leggendo elemento in posizione "i"
    }

    // Somma pari e somma dispari
    int sP = 0, sD = 0;

    // Verifichiamo che elementi hanno indice pari o dispari

    for(int i = 0; i < arr.length; i++){ // scorriamo tutto il vettore riempito
        if(i % 2 == 0){
            sP = sP + arr[i]; // somma dell'elemento in indice "i"
            // altrimenti: sp += arr[i];
        }
        else{
            sD = sD + arr[i]; 
        }
    }

    System.out.println("Somma degli elementi con indice pari: " + sP);
    System.out.println("Somma degli elementi con indice dispari: " + sD);

    input.close();
    }
}