import java.util.Scanner;

public class Esercizio3{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);

        // Creazione vettori di 10 elementi
        int[] arr1 = new int[10];
        int[] arr2 = new int[10];

        // Popolare il primo array con numeri chiesti in input
        System.out.println("Inserisci 10 numeri interi per il primo array:");
        for (int i = 0; i < arr1.length; i++) {
            arr1[i] = input.nextInt();
        }

        // Popolare il secondo array con numeri chiesti in input
        System.out.println("Inserisci 10 numeri interi per il secondo array:");
        for (int i = 0; i < arr2.length; i++) {
            arr2[i] = input.nextInt();
        }

        // Creazione terzo vettore
        int[] arr3 = new int[10];

        for (int i = 0; i < arr1.length; i++) {
            if(arr1[i] < arr2[i])
                arr3[i] = arr1[i];
            else{
                arr3[i] = arr2[i];
            }
        }

        // Stampare i tre array
        System.out.print("Primo array: ");
        for (int i = 0; i < arr1.length; i++) {
            System.out.print(arr1[i] + " ");
        }
        System.out.println();

        System.out.print("Secondo array: ");
        for (int i = 0; i < arr2.length; i++) {
            System.out.print(arr2[i] + " ");
        }
        System.out.println();

        System.out.print("Terzo array (elementi minori): ");
        for (int i = 0; i < arr3.length; i++) {
            System.out.print(arr3[i] + " ");
        }
        System.out.println();
    }

}