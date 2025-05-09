import java.util.Random;

public class Salvadanaio {
	
	private String proprietario;
	private int gruzzoletto;
	private boolean isRotto;
	
	public Salvadanaio(String proprietario, boolean isRotto){
		this.isRotto = isRotto;
		this.proprietario = proprietario;
		gruzzoletto = 0;
	}
	
	/*
	Volendo:
	
	public Salvadanaio(String proprietario){
		this(proprietario, false);
	}
	*/
	
	public String toString(){
		return (" il salvadanaio e' di: "+ proprietario + " con: " + gruzzoletto + " in stato: " + isRotto );
	}
	
	public int rompi(){
		isRotto = true;
		return gruzzoletto;
	}
	
	public void ripara(){
		isRotto = false;
		gruzzoletto = 0;
	}
	
	public void inserisci(int denaro){
		if(isRotto == false){
			gruzzoletto = gruzzoletto + denaro;
		}
		// booleano - allora puoi accorciarlo
		// if(!isRotto) - false
		// if(isRotto) - true
		
		// Altro caso -> addizione lunga
		// var = var + urc;
		
		// Addizione corta
		// var += urc;
		
	}
	
	public int svuota(){
		int roba = gruzzoletto;
		gruzzoletto = 0;
		return roba;
	}
	
	public void trasferisci(Salvadanaio b){
		int risparmio = this.svuota();
		// alternativa a (a.svuota) - che però andrebbe creato!
		b.inserisci(risparmio);
	}
	
	public int scuoti(){
		if (gruzzoletto <= 1) {
			return gruzzoletto; // Se c'è solo 1 o 0 soldi, restituiamo quello che c'è
		}

		Rando m random = new Random();
		return random.nextInt(gruzzoletto - 1) + 1; // Numero tra 1 e (gruzzoletto - 1)
	}

	
	public String getProprietario() {
		return proprietario;
	}

	public int getGruzzoletto() {
		return gruzzoletto;
	}

	public boolean getIsRotto() {
		return isRotto;
	}

}

