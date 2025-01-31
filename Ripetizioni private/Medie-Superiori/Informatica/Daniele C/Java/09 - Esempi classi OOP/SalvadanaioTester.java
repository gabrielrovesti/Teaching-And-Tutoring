public class SalvadanaioTester {
	
	public static void main (String[] args) {
		Salvadanaio a = new Salvadanaio( "danielegabriele", false);
		a.inserisci(200);
		System.out.println(a.toString());
		
		Salvadanaio b = new Salvadanaio( "gabrieledaniele", false);
		b.inserisci(300);
		System.out.println(b.toString());
		
		a.trasferisci(b);
		System.out.println(a.toString());
		System.out.println(b.toString());

		int cifra = b.scuoti();
		
		System.out.println( "Sono stati estratti " + cifra + " soldi" );
		
	}
}

