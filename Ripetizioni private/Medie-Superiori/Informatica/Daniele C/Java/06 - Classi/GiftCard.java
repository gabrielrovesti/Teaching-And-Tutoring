
/*
 
 Si vuole simulare l’uƟlizzo di una GiŌCard. Una GiŌCard è definita da un marchio (Mediaworld, Trony, Coop, ecc. cioè un negozio, o
una catena di negozi, in cui è possibile uƟlizzarla), da un credito disponibile (e spendibile) e memorizza anche il numero di volte in
cui viene uƟlizzata per fare shopping. La GiŌCard può essere, inoltre, di Ɵpo RICARICABILE (è possibile ricaricarla illimitatamente
senza teƩo massimo di credito) oppure USA e GETTA (la si può uƟlizzare solo fino ad esaurimento, non deve essere possibile alcuna
ricarica)
 
 */
public class GiftCard {
	private String marchio;
	private double credito;
	private int numVolte;
	private boolean isRicaricabile;
	
	//getter
	
	public String getMarchio(){
		return marchio;
	}
	
	public double getCredito(){
		return credito;
	}
	
	public int getNumVolte(){
		return numVolte;
	}
	
	public boolean getIsRicaricabile(){
		return isRicaricabile;
	}
	
	// setter 
	
	public void setMarchio(String marchio){
		this.marchio = marchio;
	}
	
	public void setIsRicaricabile(boolean isRicaricabile){
		this.isRicaricabile = isRicaricabile;
	}
	
	public void setCredito(double credito){
		this.credito = credito;
	}
	
	public void setNumVolte(int numVolte){
		this.numVolte = numVolte;
	}
	
	// costruttore
	GiftCard(String marchio,double credito,int numVolte,boolean isRicaricabile){
		this.marchio=marchio;
		this.credito=credito;
		this.numVolte=numVolte;
		this.isRicaricabile=isRicaricabile;
	}
	// GiftCard g1; g1("MediaWorld", 50, 7, true); - tester
	
	// ------------ METODI ---------------
	
	// parametri formali = parametri dentro le tonde prima di eseguire la funzione
	public void spendiTutto(double cred){
		// int x = 5; // parametro attuale (dentro lo scope/visibilità/graffe di un metodo/funzione)
		if(credito-cred==0){
			System.out.println("Credito svuotato");
		}else{
			System.out.println("Operazione non disponibile!");
		}
	}
	public void spendi(double cred){
		if(credito-cred>=0){
			System.out.println("Credito diminuito di: "+cred+".!");
		}else{
			System.out.println("Operazione non disponibile!");
		}
	}dù
	
	// g1.spendi(50);  - tester
		
	public String toString(){
		return "Marchio della carta: " + marchio + ", credito disponibile" + credito + ", numero di volte" + numVolte + "con tipo: " + isRicaricabile;
		// toString = metodo che stampa tutti i campi privati del tipo classe (qui, il tipo GiftCard)
	}
	// g1.toString();  - tester
	
	public boolean isCompatibile(GiftCard g1, GiftCard g2){
		if(g1.getMarchio()==g2.getMarchio()){
			return true;
		}
		return false;
	}
	
	public double ricarica(double denaro){
		return credito + denaro;
	}
	// se metti un tipo di ritorno, metti return; se metti void, non metti nulla oppure
	// void method(){ return; }
	
	public void ricaricaCompatibile(GiftCard g1, GiftCard g2){
		if(g2.isCompatibile()){
			double cred = g2.getCredito(); // prendiamo il credito
			g2.spendiTutto(); // svuotiamo la seconda
			g1.ricarica(cred); // ricarichiamo la prima col residuo
		}
	}
	// tester: ricaricaCompatibile(g1, g2);
	
	public static void main(String[] args){
	
	}
}

/*
 
 Compartamento classe GiftCardTester:
 
 GiftCard g1("Media", 500, 7, 5);
  GiftCard g2("Trony", 700, 8, 5);
 
 g1.ricarica(90);
 g2.spendi(50);
 g2.spendiTutto();
 
 ricaricaCompatibile(g1, g2);
 */

/*
 
Utilizzare una GiftCard significa che:
1) Una volta costruita, essa assume: un marchio, una tipologia, un credito iniziale e un numero di uƟlizzi pari a zero.
2) È possibile ottenere tutte le informazioni (singole) ivi contenute (metodi getter)
3) E’ possibile reimpostare tutte le informazioni (singole) ivi contenute (metodi setter)
4) È possibile spendere tutto il credito disponibile (con l’effetto, ovviamente, di azzerarlo)
5) È possibile spendere una certa quantità di denaro (solo se il credito lo permette)
6) È possibile stabilire se una GiftCard è compatibile con un’altra GiftCard (se appartengono allo stesso marchio)
7) È possibile ricaricarla immettendo una certa quantità di denaro
8) È possibile ricaricarla utilizzando il credito disponibile di un’altra Giftcard compatibile (che ovviamente verrà svuotata)
9) È possibile ottenere una stringa etichettata che riporta tutte le informazioni ivi contenute
Altre consegne:
10) Scrivere tutti commenti javadoc (con relativa documentazione che verrà salvata su una sottocartella di nome
“javaDocGiftCard”)
11) Scrivere una classe tester per testare i metodi di almeno 2 GiftCard.

 */
