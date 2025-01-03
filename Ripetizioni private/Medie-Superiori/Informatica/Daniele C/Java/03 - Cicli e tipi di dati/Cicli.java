import java.util.Scanner;
public class Cicli{
	public static void main(String[] args){
		//tre tipologie di ciclo (iterazione)
		
		// ---- while ----
		// Il ciclo while si usa di solito per farti rimanere nel ciclo finché vale la condizione
		
		int c = 4;
		while(c > 5){ //prima controllo la condizione
			// nota = mettere una condizione che prima o poi diventa falsa
			System.out.println("il numero è maggiore di 5");
		}
		int i;
		
		// ---- for (inizializzazione; condizione; aggiornamento) ----
		// Il ciclo for considera di contare fino ad un certo numero di iterazioni
		// Es. questo ciclo conta partendo da 0, rimanendo nel ciclo finché i<10, 
		// aggiorna poi il contatore "i"
		
		// Questi due sotto sono tra loro equivalenti; controlla le loro differenze di cui sopra
		for(i=0; i<10; i++){
			System.out.println(i); // 0 1 2 ... 9
		}
		
		while(i<10){
			System.out.println(i);
			i++; // devi incrementare il contatore a mano
		}
		Scanner tast = new Scanner(System.in);
		
		//do-while
		// Entri almeno una volta nel ciclo, fai tutto quello che devi fare 
		// e poi valuti la condizione (poi, stesse regole di while)
		int num;
		do{
			System.out.println("dimmi un numero compreso tra 5 e 10 ");
			num = tast.nextInt();
		}while(!(num <=10 && num>=5)); 
		//}while(num >10 || num< 5) ; 
		//io voglio un numero tra 5 e 10
		//num <=10 && num>=5 
	
	}
}
