/*

ax = b // primo grado

ax^2 + bx + c = 0 // secondo grado

*/

import java.util.Scanner;
import java.lang.Math; // fun<ioni matematiche

public class Es3 {
	
	public static void main (String[] args) {
		Scanner tast = new Scanner(System.in);
		
		System.out.println("---- EQUAZIONI PRIMO GRADO ---- ");
		
		System.out.println (" Inserisci \"a\": ");
		int a = tast.nextInt();
		System.out.println (" Inserisci \"b\": ");
		int b = tast.nextInt();
		
		// 3x = 6 --> x = b/a -> determinata
		
		// 3x = 0 -> "b" non c'è -> x = 0
		
		// x = b --> "a" non c'è, alloa x è "b"
		
		// 0*x = 6 --> impossibile
		
		// a == b --> infinite soluzioni
		
		if(a == b)
			System.out.println (" E' un'equazione indeterminata ");
		if(a !=0 && b !=0){ // if a != NULL && b != NULL
			// se "a" e "b" esistono
			System.out.println (" E' un'equazione determinata ");
			int x = b/a;
			System.out.println (" La soluzione è: " + x);
			// NON fare divisione per zero - ti dà NaN = Not a Number
		 }
		 if(a == 0)
			System.out.println ( " E' una equazione impossibile ");

			
		System.out.println("---- EQUAZIONI SECONDO GRADO ---- ");
		
		System.out.println (" Inserisci \"a\": ");
		a = tast.nextInt();
		System.out.println (" Inserisci \"b\": ");
		b = tast.nextInt();
		System.out.println (" Inserisci \"c\": ");
		int c = tast.nextInt();
		int delta = (b*b)-4*a*c;
		if( a!=0 && b!=0 && c!=0 )  {
			
			// Math.pow(b, 2) - base, esponente
			// potenza usando Java
			int x1 = (int) (-b - Math.sqrt(delta)) / (2 * a);
			int x2 = (int) (-b + Math.sqrt(delta)) / (2 * a);
		
			System.out.println("Le soluzioni sono: " + x1 + " e: " + x2);
		}
		if(a != 0 && b == 0 && c == 0){
			int x = (int) (-b - Math.sqrt(delta)) / (2 * a);
			System.out.println("La soluzione e': " + x);
		}
		if ( delta <0 )
			System.out.println (" La soluzione e' impossibile ");
	} 
	
	
}
