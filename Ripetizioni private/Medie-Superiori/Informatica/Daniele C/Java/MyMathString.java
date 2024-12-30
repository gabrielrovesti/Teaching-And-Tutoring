import java.util.Math;

class MyMathString{
	/*
	 ********* TIPI ********
	 
	 Elenco dei tipi:
	 
	 byte = Quanto spazio occupano in memoria i tipi
	 void = vuoto
	 int = intero (4 byte)
	 long/short/byte = tipi diversi di intero
	 double = numeri con virgola mobile più grandi e precisi (8 byte)
	 float = numeri con virgola mobile un po' più piccoli
	 boolean = true/false
	 char = 'a'
	 
	 int a; // numero variabile
	 int a = 50; // numero costante = ha quel valore fisso
	 
	 static = garantisce che esista solo un oggetto di quel tipo in memoria
	 final = valore "finale" = una volta piazzato, non sarà più modificato
	 
	 ********* OPERATORI *********
	 
	 <, >, !=, &&, !, ||, --, ++
	 
	 // Forme accorciate degli operatori comuni
	 
	 int num = 0;
	 num = num + 1 <--> num++;
	 num = num - 1 <--> num--;
	 
	 int var = 50;
	 num += var <--> num = num + var;
	 *=, /=
	 
	 % = divisione intera = modulo
	 
	 8 % 4 = 0
	 
	 4 * 2 = 8
	 
	 12 % 5 = 2
	 Resto è 2
	 
	 ********* STRINGHE ********
	
	String nome = "Alberto";
	
	String input = tast.next(); //next() serve a leggere la stringa
	
	nome.length(); // 7 caratteri
	// length = funzione che prende la lunghezza in caratteri della stringa
	
	// funzione = caratteristica che ti viene data da parte di una certa libreria o classe
	
	// Concatenazione = Attaccare le singole stringhe in successione
	String firstName = "Harry";
	String lastName = "Morgan";
	String name = firstName + lastName;
	
	// Sottostringa = parte di una stringa
	// Esempio: prendo "rr" da Harry
	
	firstName.substring(2,3); (inizio, fine)
	*/
	
	// ------------------------------------- 
	
	/*
	 Creare una classe MyMath contenete metodi statici che dovranno risolvere i seguenti problemi:
	1) Dati 2 valori interi entranti restituisce il minimo
	 */
	 
	// ------------------------------------- 
	
	// int = tipo di ritorno (output) = calcola un numero minimo tra due numeri passati
	
	// a, b = parametri = variabili di un certo tipo dati alla funzione in input
	static int min(int a, int b){
		if(a < b)
			return a;
		else
			return b;
	}
	
	// Es. di esecuzione --> min(4,5) --> Ritorna 4

}
