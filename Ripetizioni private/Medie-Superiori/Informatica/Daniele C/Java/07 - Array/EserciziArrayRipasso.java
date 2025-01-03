import java.util.*;

// import java.util.Scanner; // per leggere i valori da tastiera

// Funzioni - Parametri
// I pezzi di cui si ha bisogno --> tra le tonde

// Es. somma due numeri

// num1 e num2 sono par. formali (noti all'inizio della funzione)
// aka - avranno uno scopo noto
//public double somma(double num1, double num2){
//	int sum = 0; 	// attuale = rimane dentro lo scope (visibilità)
//					// della funzione
//	return sum;
//}

public class EserciziArrayRipasso {
	
	public static void ruotaAvanti(int[] array){
		if(array.length <= 2){
			int temp = 0; // temporanea
			int primo = array[0];
			int ultimo = array[1];
			
			temp = primo; 
			primo = ultimo; // il primo diventa l'ultimo
			ultimo = temp; // l'ultimo diventa il primo
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
	
	/*
	  //Rotate the given array by n times toward right    
        for(int i = 0; i < n; i++){    
            int j, last;    
            //Stores the last element of array    
            last = arr[arr.length-1];    
            
            for(j = arr.length-1; j > 0; j--){    
                //Shift element of array by one    
                arr[j] = arr[j-1];    
            }    
            //Last element of array will be added to the start of array.    
            arr[0] = last;    
        }    
	*/
	
	public static void scambiaMeta(int[] array){
		// elemento di metà
		// se dim. pari = array.length / 2
		// se dim. dispari = (array.length / 2)+1
		int lunghezza = array.length;
		for(int i = 0; i < lunghezza; i++){    
			if(lunghezza % 2 == 0){
				int pivot = lunghezza % 2;
			}
			if(lunghezza % 2 != 0){
				int pivot = (lunghezza % 2)+1;
			}
		}
	}
	
	public static int[] concatenaArray(int[] array1, int[] array2){
		int lunghezza1 = array1.length;
		int array3 = new int[lunghezza1];
		for(int i = 0; i < lunghezza1; i++){
			array3[i] = array1[i];
		}
		int lunghezza2 = array2.length;
		for(int i = 0; i < lunghezza1; i++){
			array3[i] = array2[i];
		}
	}
	
	public static Boolean valorePiuFrequente(boolean[] array){
		int contaTrue = 0;
		int contaFalse = 0;
		for(int i = 0; i < array.length; i++){
			if (array[i] == false)
				contaFalse++;
			if (array[i] == true)
				 contaTrue++;
		}
		if(contaTrue > contaFalse)
			return true;
		if(contaTrue < contaFalse)
			return false;
		if(contaTrue == contaFalse)
			return null;
	}
	
	public static int verificaOrdinamento(int[] array) {
		int verifica = 0;	// indefinito
		for(int i = 0; i < array.length; i++){
			if(array[i] < array[i+1])	//crescente
				verifica = 1;
			if(array[i] > array[i+1])	//decrescente
				verifica = -1;
		}
		return verifica;
	}
	
	public static Integer trovaValoreRipetuto(int[] array){
		for(int i = 0; i < array.length; i++){
			int valore = array[i];	// salvo il valore attuale e controllo da quello
			for(int j = i+1; j < array.length; j++){
				if(valore == array[j]){
					break;	// se lo trovo, stampo
				}
			}
		}
		System.out.println("Il valore ripetuto due volte è: " + valore);
	}
	
	public static int[] compattaPariDispari(int[] array){
		int lunghezza = array.length;
		int[] array2 = new int[lunghezza]; //assume stessa size
		
		int[] pari = new int[lunghezza];
		int[] dispari = new int[lunghezza];
		for(int i = 0; i < lunghezza; i++){
			if(array[i] % 2 == 0){ //pari
				pari[i] = array[i];
			}
			if(array[i] % 2 != 0){ //dispari
				dispari[i] = array[i];
			}
		}
		array2 = concatenaArray(pari, dispari);
		// attacco dispari a pari
		// questo per mantenere stesso ordine
		return array2;
	}
	
	public static int[] trovaPosizioniMassimo(int[] array){
		int[] massimo = new int[array.length];
		int max = 0;
		// trova il massimo
		for(int i = 0; i < array.length; i++){
			if(array[i] > max){
				max = array[i]; // 7
			}
		}
		// troviamo le posizioni massime
		for(int i = 0; i < array.length; i++){
			if(max == array[i]){
				massimo[i] = i; // 0 2 5
			}
		}
		return massimo;
	}
	
	public static boolean verificaTuttiMultipliMinimo(int[] array){
		boolean verifica = false;
		int min = 0;
		// trova il minimo
		for(int i = 0; i < array.length; i++){
			if(array[i] < min){
				min = array[i];
			}
		}
		// verifica se è multiplo
		for(int i = 0; i < array.length; i++){
			// multiplo del minimo =
			// numero / minimo dà resto 0 = true
			if(array[i] % min == 0){
				verifica = true;
			}
		}
		return verifica;
	}
	
	public static void main(String[] args) {
		
		
		Scanner tast = new Scanner(System.in);
		
		// new = Allocazione dello spazio per un certo oggetto
		// "alla bisogna"
		
		// uso tipico -> tast.nextInt();
	}
}

/*
// Array come classe (OOP)
class Array{
	// campi
	private:
		int size;
		int[] vettore;
	public:
	// costruttori / get / set
	
	// metodi
	int max(int[] vett){};
}

int[] array = new int[100]; // array

class ArrayTester{
	public static void main (String[] args) {
		Array a1;
		
		// uso metodi
		int massimo = max(a1);
	}
}
*/
