// Definizione della classe
import java.util.Random;

public class Libro {
	private int numIdentificazione;
	private String titolo, genere;
	private int numPagine;
	private int prezzo;
	private int segnalibro;
	private int numScaffale;
	private boolean isNoleggiato;
	
	public Libro(String titolo, String genere, int numPagine){
		this.titolo=titolo;
		this.genere=genere;
		this.numPagine=numPagine;
		segnalibro=0;
		numScaffale=-1;
		isNoleggiato=false;
	}
	
	public String toString(){
		return "Il titolo e': "+titolo+" con genere: "+genere+" e il numero pagine e' di: "+numPagine;
	}
	
	public int pagCasuale(){
		Random random = new Random();
		int pagina=random.nextInt(numPagine)+1;
		return pagina;
	}
	
	public void incrementaSegnalibro(int segnalibro){
		if(numPagine < segnalibro){
			System.out.println("Errore");
		}
		else{
			 numPagine += segnalibro;
		}
	}
	
	public void applicaSconto(int sconto){
		if(sconto > 0){
			prezzo *= (sconto / 100);
		}
	}
	//sconto del 15% -> prezzo * (15/100)
	
	// get del prezzo per far vedere lo sconto
	public double getPrezzo(){
		return prezzo;
	}
	
	public int getSegnalibro(){
		return segnalibro;
	}
	
	public void setNumPagine(int numPagine){
		this.numPagine = numPagine;
	}
}

/*
 * 
// Tester usa classe
// Logica del tester -> crei l'oggetto (che non esisteva prima) e gli dai una logica -> OOP

// Serve classe Libro per creare oggetto 
Libro l1 ("Titolo", "Genere", 50); // uso del costruttore

// sintassi (come lo scrivi) --> oggetto.metodo(qui se servono mettiamo parametri)
l1.toString(); // Output -> "Titolo", "Genere", 50

*/



