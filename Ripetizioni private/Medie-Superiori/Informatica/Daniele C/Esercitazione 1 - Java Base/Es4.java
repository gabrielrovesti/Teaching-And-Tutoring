import java.util.Scanner;

public class Es4 {
	
	public static void main (String[] args) {
		Scanner tast = new Scanner(System.in);

		System.out.println("Poker");
		System.out.println("----------------------");
		System.out.println("I punteggi in ordine decrescente sono (k,q,j,9,8,7,6,5,4,3,2,1), i semi in ordine decrescente sono  (cuori, quadri, fiori, picche)");

		System.out.println("Inserisci valore prima carta (numero 1-12): ");
		int carta1 = tast.nextInt();
		System.out.println("Inserisci valore seconda carta (numero 1-12): ");
		int carta2 = tast.nextInt();
		
		System.out.println("Inserisci valore del primo seme (c=4 - q=3 - f=2 - p=1): ");
		int seme1 = tast.nextInt();
		//char seme1 = tast.next().charAt(0);
		
		System.out.println("Inserisci valore del secondo seme (c=4 - q=3 - f=2 - p=1): ");
		int seme2 = tast.nextInt();
		
		if (carta1 > carta2)
			System.out.println("Carta1 maggiore");
		if (carta1 < carta2)
			System.out.println("Carta2 maggiore");
		if (carta1 == carta2){
			
			if (seme1 > seme2)
				System.out.println("Carta1 maggiore con seme più grande");
			else
				System.out.println("Carta2 maggiore con seme più grande");
		}	
	}
}
