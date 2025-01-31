/**
 * ADT per un Pallocnino ...
 * @author Daniele
 * @version 1.0 - 23 gen 2025
 */


public class Palloncino {
	private double capMassima;
	private double volume;
	private static int numeroPalloncini=0;
	private int numero;

	/**
	 * Costruttore completo
	 * @param capMassima
	 * @param volume
	 * */
		 
	public Palloncino(double capMassima){
		this.capMassima=capMassima;
		this.volume=0;
		numeroPalloncini++;
		numero=numeroPalloncini;
	}
	
	/**
	 * Calcolo raggio
	 * @return il raggio
	 */
	
	public double calcolaRaggio(){
		return Math.pow( 3/4*volume*Math.PI,1/3);
	}
	
	/**
	 * Calcolo Area
	 * @return l'area
	 */
	
	public double calcoloArea(){
		double r=calcolaRaggio();
		return Math.PI*r*r;
		
	}
	
	/**
	 * Capisce se il palloncino esploda o no 
	 * @return l'area
	 */
	
	public boolean aggiungiAria(double quantita){
		if(quantita+volume>capMassima){
			volume=0;
			return false;
		}else{
			volume= quantita+volume;
			return true;
		}
		
		
	}
			
	/**
	 * Restituisce lo stato dell'oggetto
	 * @return una stringa che descrive lo stato dell'oggetto
	 */
	public String toString(){
		return " il palloncino numero: "+numero+" ha un volume di: "+volume+" con raggio di: "+calcolaRaggio()+" e un area di: "+calcoloArea();
	}
	

}	
