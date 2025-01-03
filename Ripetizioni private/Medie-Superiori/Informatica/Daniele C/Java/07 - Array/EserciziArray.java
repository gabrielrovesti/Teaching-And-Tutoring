import java.util.Scanner;
import java.util.Arrays;

// * = importa tutto!
// import java.util.*;

public class EserciziArray{

    public static void main(String[] args) {
		
		int[] array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        
        // diverso da int[] array = new int[10]; 
        // gli dici solo "quanto grande è l'array"
        
        // Esercizio 3: Valore massimo array
		int max = 0;
		for(int i = 0; i < array.length; i++){
			if(array[i] > max){
				max = array[i]; // salvare il nuovo massimo
			}
		}
		
		System.out.println("Il massimo è: " + max);
		
		// Come funzione
		// int findMax(int[] array)
		
		// Parallelamente: Valore minimo array
		int min = 0;
		for(int i = 0; i < array.length; i++){
			if(array[i] < min){
				min = array[i]; // salvare il nuovo minimo
			}
		}
		
		System.out.println("Il minimo è: " + min);
		
		// Come funzione
		// int findMin(int[] array)
		
		// 4: Contare gli elementi maggiori di un valore
		
		// funzione:
		// int contaMax(int[] array, int valore)
		
		Scanner tast = new Scanner(System.in);
		
		System.out.println("Inserisci il valore: ");
		int valore = tast.nextInt(); // valore in input preso dal bomber
		
		int conta = 0;
		for(int i = 0; i < array.length; i++){
			if(valore > array[i]){
				conta++;
			}
		}
		System.out.println("Elementi maggiori di: " + valore + " è : " +conta);
		
		// 6: Copia di un array
		
		// Domanda - gli array hanno sempre la stessa size (dimensione)?
		// No!
		
		// array = 10 elementi
		// array2 = 10 elementi (occhio che può cambiare!)
		for(int i = 0; i < array.length; i++){
			array2[i] = array[i];
			// 1 == 1, 2 == 2, ... 10 == 10
		}
		
		// In short (usando la libreria): 
		// int[] array2 = Arrays.copyOf(array1, array1.length);
		
		// Come funzione
		// void copia(int[] array1, int[] array2)
		
		// 10: Unione di due array
		
		// array1: 1 2 3 4 5 6 7 8 9 10
		// array2: 2 3 4 5 6 7 8 9 10 11
		for(int i = 0; i < array.length; i++){
			array3[i] = array[i]; // 1
			array3[i+1] = array2[i]; // 2
		}
		// Concatenare = attaccare = viene fatto in Java da "+" con le stringhe!
		// Es. "ciao" + "mondo" = "ciao mondo"
		
		// Come funzione
		// int[] concatena(int[] array1, int[] array2)
    }

}
