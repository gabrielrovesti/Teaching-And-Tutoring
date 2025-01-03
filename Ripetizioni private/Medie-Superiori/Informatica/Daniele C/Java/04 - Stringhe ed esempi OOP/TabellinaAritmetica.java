import java.util.Scanner;

/*

Scrivere un programma JAVA TabellineAritmetiche che chiede in ingresso all’utente un
numero intero da memorizzare nella variabile n e visualizza in uscita la tabellina aritmetica
del numero stesso. Se ad esempio il numero inserito è 5 le righe visualizzate devono
essere
5×1=5
5×2=10
5×3=15
5×4=20
5×5=25
5×6=30
5×7=35
5×8=40
5×9=45
5×10=50


*/

public class TabellinaAritmetica {
	
	public static void main (String[] args) {
		Scanner tast= new Scanner( System.in);
		int n;
		System.out.println(" Inserisci numero:");
		n= tast.nextInt();
		for( int i= 1; i<=10; i++) {
			System.out.println("Numero " + i + "=" + n*i);
		}
		
		/*
		while(i < 10){
			System.out.println("Numero " + i + "=" + n*i);
			i++;
		}
		
		i = 1;
		do{
			System.out.println("Numero " + i + "=" + n*i);
			i++;
		}while(i < 10);
		*/
	}
}

