import java.util.*;

public class EserciziArrayGabriel {
	public static void rotateArray(int[] array){
		if(array.length <= 2){
			int temp = 0;
			int primo = array[0];
			int ultimo = array[1];
			
			temp = primo; 
			primo = ultimo; 
			ultimo = temp; 
		}
		else{
			for(int i = 0; i < array.length; i++){
				int temp = 0;
				int primo = array[i];
				int secondo = array[i+1];
				
				temp = secondo; 
				secondo = primo; 
				array[i] = secondo;
				array[i+1] = temp;
			}  
		}
	}

	public static int[] mergeSorted(int[] array1, int[] array2){
		int lunghezza1 = array1.length;
		int[] array3 = new int[lunghezza1];
		for(int i = 0; i < lunghezza1; i++){
			array3[i] = array1[i];
		}
		int lunghezza2 = array2.length;
		for(int i = 0; i < lunghezza2; i++){
			array3[i] = array2[i];
		}
	}
		
	public static int[] dividiPariDispari(int[] array1, int[] array2){
		int[] pari = new int[array1.length];
		int[] dispari = new int[array2.length];
		for(int i = 0; i < array1.length; i++){
			if(array1[i] % 2==0){
				pari[i] = array1[i];
			}
			else{
				dispari[i] = array2[i];
			}
		}
		// terzo array e return che manca
	}
	
	public static int[] filtra(int[] array1, int valore){
		int[] array2 = new int[array1.length];
		for(int i = 0; i < array1.length; i++){
			if(array1[i] > valore){
				array2[i] = array1[i];
			}
		}
		return array2;
	}

}