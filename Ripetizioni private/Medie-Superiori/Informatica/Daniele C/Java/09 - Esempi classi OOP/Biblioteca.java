import java.util.Random;
import java.util.ArrayList;

/**
 * Classe che definisce l'ADT Biblioteca
 * @author Antonella Schiavon
 * @version 1.0 - 24 gen 2025
 */
public class Biblioteca {
	private String nome,indirizzo;
	private ArrayList<Libro> libri;
	
	/**
	 * Costruttore che inizializza gli attributi della Biblioteca
	 * @param nome, il nome della biblioteca
	 * @param indirizzo, l'indirizzo della biblioteca
	 */
	public Biblioteca(String nome, String indirizzo) {
		this.nome=nome;
		this.indirizzo=indirizzo;
		libri=new ArrayList<Libro>();
	}
	
	/**
	 * Restituisce il numero di libri posseduti dalla biblioteca
	 * @return il numero di libri
	 */
	public int getNumeroLibri(){
		return libri.size();
	}
	
	/**
	 * Metodo che inserisce un libro in biblioteca
	 * @param l, il libro da inserire
	 * @param scaffale, il numero dello scaffale su cui collocare il libro
	 */
	public void inserisciLibro(Libro l, int scaffale){
		l.setNumScaffale(scaffale);
		libri.add(l);
	}
	
	/**
	 * Metodo che rimuove un libro della biblioteca
	 * @param l, il libro cercato
	 * @return true se la rimozione riesce, false altrimenti
	 */
	public boolean removeLibro(Libro l){
		if(this.getLibro(l) != null && !this.getLibro(l).getIsNoleggiato()){
			libri.remove(this.getLibro(l));
			return true;
		}
		else return false;
	}
	
	/**
	 * Metodo che restituisce un libro della biblioteca
	 * @param l, il libro cercato
	 * @return il riferimento all'oggetto libro trovato
	 */
	public Libro getLibro(Libro l){
		return libri.get(libri.indexOf(l));
	}
	
	
	/**
	 * Metodo che noleggia un libro della biblioteca
	 * @param l, il libro cercato
	 * @return true se il noleggio riesce, false altrimenti
	 */
	public boolean noleggia(Libro l){
		if(this.getLibro(l)!=null && !this.getLibro(l).getIsNoleggiato()){
			this.getLibro(l).setIsNoleggiato(true);
			return true;
		}
		else return false;
	}
	
	
	/**
	 * Metodo che restituisce lo stato attuale dell'oggetto
	 * @return stato dell'oggetto
	 */
	@Override
	public String toString() {
		/*
		return "Biblioteca "+nome+", "+indirizzo+"; possiede "+getNumeroLibri()+" libri.  Catalogo attuale:\n"+
		libri.toString();
		*/
		
		String s="\nBiblioteca "+nome+", "+indirizzo+"; possiede "+getNumeroLibri()+" libri.\nCatalogo attuale:\n";
		for(Libro x:libri){
			s+="\t"+x.toString();
		}
		return s;
	}
	
	
}
