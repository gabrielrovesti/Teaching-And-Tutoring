public class Fioriera{
	private Fiore [] f;
	private int d;
	private int c;
	public Fioriera (int c){
		this.c=c;
		f=new Fiore [c];
		d=0;
	}
	public String toString(){
		String s=" ";
		for(int i=0;i<d;i++){
			s+=f[i];
		}
		return "fiore: "+s;
	}
	
	public void add(Fiore fio){//aggiunge il fiore nel primo posto libero
		if (d < c) { // Verifica se c'è spazio nella fioriera
			f[d] = fio; // Aggiungi il fiore nella posizione d
			d++; // Incrementa il numero di fiori nella fioriera
		} else {
			System.out.println("La fioriera è piena, impossibile aggiungere il fiore.");
		}
	}

	public double alteMed(){//calcola l'altezza media dei fiori nella fioriera
		double hM=0;
		int i=0;
		while (i<d){
			hM+=f[i].getH();
			i++;
		}
		hM/=i;
		return hM;
	}
		
	public boolean alte(Fioriera altra){//confronta le altezze medie
		return (this.alteMed()==altra.alteMed());//ritorna true solo se sono uguali
	}
	public void sosti(Fiore altra, int i){//sostituisce un fiore con un altro solo se hanno la stessa iniziale
		if (f[i].getIni().equals(altra.getIni())){
			f[i]=altra;
		}
	}
	public void tot(){//calcola il totale dei petali dei fiori nella fioriera
		int t=0;
		for (int i=0;i<d;i++){
			t+=f[i].getN();
		}
	}
			
			
}
