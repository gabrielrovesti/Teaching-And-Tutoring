public class Persona{
	private String nome;
	private	String cognome;
	private	int eta;
	
	public Persona(String n, String c, int e){};
	
	// overloading = stesso metodo / diversi parametri / utilizzi diversi
	public chiSei(String n, String c, int e);
	public chiSei(String n, String c);
	public chiSei(String n);
}

// sottoclasse/derivata = estendi (extends = parola chiave di Java per sottoclasse)
// Eredita gli attributi della superclasse

// Impiegato.java
public class Impiegato extends Persona{
	private double stipendio; // aggiungiamo/specializziamo
	
	public Impiegato(String n, String c, int e, double s){
		super(n, c, e); // usiamo il costruttore della superclasse per costruire
		// giusto metterne 3 (meno = non stiamo usando il suo costruttore)
		stipendio = s;
	}; 
	
	// overriding = stiamo usando un metodo di una superclasse specializzandolo
	@Override // annotazione = nota per chi sviluppa di una certa operazione
	public chiSei(String n, String c);
}

// Studente.java (derivata)
public class Studente extends Impiegato{
	private int numcorsi;
	
	public Studente(String n, String c, int e, double s, int numcorsi){
		super(n, c, e, s);
		this.numcorsi = numcorsi;
	}
}

// Gerarchia

		Persona	(base)
			|
		Impiegato (derivata)	
			|
		Studente (derivata)	

// polimorfismo 

Persona p = new Studente();
// di solito andiamo da su in giù

