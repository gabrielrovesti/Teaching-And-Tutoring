import java.util.Scanner; // importo per leggere gli input

public class Es2 {
	
	public static void main (String[] args) {
		Scanner tast = new Scanner(System.in);
		System.out.println ("Inserisci il primo numero: ");
		int num1 = tast.nextInt();
		// tast = serve a leggere l'input
		
		// nextInt = leggere un intero
		// nextLine = leggere una stringa
		// nextDouble = leggere un double (numero con la virgola)
		
		System.out.println ("Inserisci il secondo numero: ");
		int num2 = tast.nextInt();
		
		System.out.println ("Inserisci il terzo numero: ");
		int num3 = tast.nextInt();
		
		// OR = || (la prima O la seconda)
		// AND = && (la prima E la seconda)
		
		if(num1 + num2 > num3 && num1 + num3 > num2 && num2 + num3 > num1){
			System.out.println ("E' un triangolo");
		}
		else{
			System.out.println ("Non e' un triangolo");
		}
		/*
		else{ //else = altrimenti = condizione contraria
			
		}
		*/
		//else if(..)
		// Esempio: else if(num1 - num2 > 0)...
		
		// == (uguaglianza tra numeri)
		// equals (uguaglianza tra stringhe)
		
		// carattere = 'a'
		// stringa = insieme di caratteri = "ciao"
		
	}	
}

