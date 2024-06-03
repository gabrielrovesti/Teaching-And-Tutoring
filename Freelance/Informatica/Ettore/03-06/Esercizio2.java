import java.util.Scanner;

public class Esercizio2 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int[] arr = new int[15];

        int[] inverso = new int[15];
        int[] supMedia = new int[15];

        for(int i = 0; i < 15; i++){
            inverso[14 - i] = arr[i];
        }

        int media = 0;
        int somma = 0;

        for(int i = 0; i < 15; i++){
            media += arr[i];
        }

        media = somma / 15; // se so quanti sono gli elementi
        // oppure
        media = somma / arr.length;

        for(int i = 0; i < 15; i++){
            if(arr[i] > media){
                supMedia[i] = arr[i];
            }
        }

        for(int i = 0; i < 15; i++){
            System.out.println(supMedia[i]);
            System.out.println(inverso[i]);
        }
    }
}
