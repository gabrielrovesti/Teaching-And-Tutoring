
public class MyStackTester {
	
	public static void main (String[] args) {
		// creare l'oggetto 
		
		// oggetto vuoto
		MyStack pila;
		// alternative = uso costruttore
		//MyStack pila2(pila);
		
		// inserire nello stack due stringhe
		pila.push("ciao");
		pila.push("mondo");
		
		// estragga per stamparle a video
		String stringa1 = pila.pop();
		String stringa2 = pila.pop();
		
		//stamparle a video
		System.out.println("Stringa 1: " + stringa1 + "e stringa 2: "+stringa2);
	}
}

