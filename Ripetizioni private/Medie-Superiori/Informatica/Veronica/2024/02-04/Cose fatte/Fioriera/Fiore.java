public class Fiore{
	private String ini;
	private int n;
	private double h;
	public Fiore(String ini, int n, double h){
		this.ini=ini;
		this.n=n;
		this.h=h;
	}
	public Fiore(){
		ini="p";
		n=5;
		h=15.0;
	}
	public String getIni(){
		return ini;
	}
	public int getN(){
		return n;
	}
	public double getH(){
		return h;
	}
	public String toString(){
		return "l'iniziale e': "+ini+"\ni petali sono: "+n+"\nl'altezza e': "+h;
	}
}
