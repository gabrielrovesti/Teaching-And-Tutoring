/*
 * 
 * Automobile
 * 
 * <p>
 * Classe che modella l'utilizzo di un automobile, con certi parametri
 * </p>
 * 
 * Doc = documentazione = info aggiuntive per codice
 * 
 * Es. di somma (metodo sotto)
 * @param = Due numeri da dividere
 * @return = Ritorna il numero diviso dati num1 e num2
 */
public class Automobile {
	
	// Attributi = proprietà della classe
	private String nomeAuto;
	private double Resa;
	private double CapienzaSerb;
	private double LitriSerb;
	
	// Getter
	public String getnomeAuto(){
		return nomeAuto;
	}
	public double getResa(){
		return Resa;
	}
	public double getCapienzaSerb(){
		return CapienzaSerb;
	}
	public double getLitriSerb(){
		return LitriSerb;
	}
	
	// Setter
	public void setnomeAuto(String na){
		nomeAuto = na;
		// oppure
		// public void setnomeAuto(String nomeAuto)
		// this.nomeAuto = nomeAuto;
	}
	public void setCapienzaSerb(String cb){
		CapienzaSerb = cb;
	}
	public void setResa(String rs){
		Resa = rs;
	}
	public void setLitriSerb(String ls){
		LitriSerb = ls;
	}
	
	// Costruttore (simile al precedente setNomeAuto)
	Automobile(string nomeAuto){
		this.nomeAuto = nomeAuto;
	}
	
	// Costruttori
	Automobile(string nomeAuto,double Resa,double CapienzaSerb,double LitriSerb){
		this.nomeAuto = nomeAuto;
		this.Resa = Resa;
		this.CapienzaSerb=CapienzaSerb;
		this.LitriSerb=LitriSerb;
	}
	
	Automobile(double LitriSerb){
		this.LitriSerb=LitriSerb;
	}
	
	// Metodi
	public String toString(){
		return"nomeAuto: " + nomeAuto + "Resa" + Resa + "CapienzaSerb" + CapienzaSerb + "LitriSerb" + LitriSerb;
	}
	/* isPercorribile: tabilisce se, data una certa distanza da percorre, la vettura sia in grado di coprirla
	oppure no
	 * 
	 * 
	 * @param La distanza da percorrere
	 * @return La vettura sia in grado o meno di percorrere una certa distanza
	 */
	public boolean isPercorribile(double distanza){
		if(Resa-distanza<0)
			return false;
		else
			return true;
	}
	
	public void percorri(double distanza){
		if(Resa>distanza)
			Resa=Resa-distanza;
			//Oppure: Resa -= distanza;
		}
		/*
		 * Stessa cosa: noi mettiamo return da solo solamente per logica
		else
			return;
		*/
	}
	
	public double autonomia(){
		
	}
	
	public boolean inRiserva(){
		
	}
	
	public void faPieno(){
		
	}
	
	public boolean consumaMeno(){
		
	}
}

/*
// Eccezione = comportamenti 

// try = controli il pezzo di codice
// catch = prendi l'eccezione che ti lancia il pezzo di codice con try
// throws = il metodo lancia in caso di errore da solo l'eccezione
public void divisione(int num1, int num2) {
	try{
		// codice
		
		int diviso = num1 / num2;
		return diviso;
		
		// potresti avere 8/0 (errore grosso)
		
	}
	catch(MathException e){
		System.out.println("Occhio divisione per zero");
		throw IOException;
	}
	
	*/
	
