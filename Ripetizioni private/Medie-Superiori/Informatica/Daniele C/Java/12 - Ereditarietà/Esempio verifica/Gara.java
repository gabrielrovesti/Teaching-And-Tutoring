/** Studente:
 *  classe  :
 *  data    :
 */
 
import java.util.Random;

public class Gara {
	private String nomeGara;
	private boolean garaInCorso;
	private ArrayList<Pilota> piloti; 
	
	public Gara(String ng){ /* NON MODIFICARE */
		nomeGara = ng;
		garaInCorso = false;
		piloti = new ArrayList<Pilota>();
	}
	
	public void aggiungiPilota(Pilota p){
		piloti.add(p);
		// oppure
		// piloti = new ArrayList<Pilota>(p);
	}

	public void grigliaDiPartenza(ArrayList<Pilota> pilotiInGara){
		for(int i = 0; i < pilotiQualificati.size(); i++){
			System.out.println("Pilota: " + pilotiQualificati.get(i).toString());
		}
	}
    
	public void classifica(){ /* NON MODIFICARE */
		System.out.println("Posizioni in gara:");
		for (int i=0;i<piloti.size();i++)
			System.out.println( (i+1)+"\t"+piloti.get(i) );
		System.out.println();
	} 

	public void start(){ /* NON MODIFICARE */
		garaInCorso = true;
		System.out.println("Benvenuti al "+nomeGara);
		System.out.println("La griglia di partenza e': ");
		classifica();
	}
	
	// Scopo della funzione: Data una certa gara, vogliamo trovare il pilota X e prenderne la posizione
	private int posCorrente(String nomeGara, Pilota pil){
		int posizione = 0;
		
		if(getGaraInCorso()){
			for(int i = 0; i < piloti.size(); i++){
				if(pil.getPilota().equals(piloti.get(i).getPilota())){
					posizione = i;
				}
			}
		}
		else{
			System.out.println("Gara non in corso");
		}
		
		return posizione;
	}
	
	/*
	private String nomeGara;
	private boolean garaInCorso;
	private ArrayList<Pilota> piloti; 
    */
	
	// Scopo funzione: Un certo pilota, che ha una gara in corso, viene messo fuori gara e stampa "Squalificato"
	public void fuoriGara(Pilota pil){
		for(int i = 0; i < piloti.size(); i++){
			// this = Siamo nella classe Gara
			// Usiamo il set per fare in modo di non toccare "in basso" i campi privati
			this.setGaraInCorso(false);
			System.out.println("Squalificato");
		}
	}
    
	/*
	private String nomeGara;
	private boolean garaInCorso;
	private ArrayList<Pilota> piloti; 
    */
    
	// Utilizzo: pilota1.effettuaSorpasso(pilota2); // pilota2 pilota1 (prima) -- pilota1 pilota2 (dopo)
	public void effettuaSorpasso(Pilota pil){ // (pilota1)
		for(int i = 0; i < piloti.size(); i++){
			Pilota temp = piloti.get(i).getPilota(); // salviamo (pilota2)
			piloti.get(i+1).getPilota() = pil; // brutto (scambio)
			temp = pil; // abbiamo messo (pilota1) in prima posizione
		}
	}
    
    // pitStop -> La gente ti sorpassa finché sei ai box (c'è un pilota)
    // c'è un tempo casuale!
    public void pitStop(Pilota pil){
		for(int i = 0; i < piloti.size(); i++){
			piloti.get(i).effettuaSorpasso(pil); // tutti i piloti ti superano!
			Random random = new Random();
			random.nextInt(piloti.size() + 1); // tempo casuale dati tutti i piloti
		}
    }
    
	public void stop() {
		garaInCorso = false;
		System.out.println("Gara terminata!");

		if (piloti.size() > 0) {
			System.out.println("Vincitore: " + piloti.get(0));  // Il primo della lista è il vincitore
			System.out.println("Ultimo: " + piloti.get(piloti.size() - 1));  // L'ultimo è in fondo alla lista
		} else {
			System.out.println("Nessun pilota in gara.");
		}
		
		classifica(); // Stampa la classifica finale
	}


} /* fine class Gara */ 
