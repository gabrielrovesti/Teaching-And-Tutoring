
public class LibroTester {
	
	public static void main (String[] args) {
		Libro l = new Libro( "gabriel e daniele", "horror informatico", 300);
		System.out.println(l.toString());
		
		System.out.println( "la pagina e':"+ l.pagCasuale());
		
		// Prima facciamo la modifica
		System.out.println( "Vecchio segnalibro:"+ l.getSegnalibro()); // 0 = mai settato numPagine
		l.setNumPagine(20);
		l.incrementaSegnalibro(50); // 0 + 50
		System.out.println( "Nuovo segnalibro:"+ l.getSegnalibro());
		
		// Prezzo prima dello sconto
		System.out.println(" Prezzo prima: " + l.getPrezzo());
		l.applicaSconto(15); // applicazione sconto
		// Prezzo dopo lo sconto
		System.out.println(" Prezzo dopo: " + l.getPrezzo());

	}
}

