import java.util.ArrayList;

// Metodi = add - clear - contains - get - isEmpty - remove - set - size
// Metodi standard per container

public class GestioneLibri{

    private ArrayList<Libro> libri;
    // Generico = <>
    // ArrayList<double>
    // ArrayList<int>
    private int dim;

    public GestioneLibri(int d){
        this.dim = d;
        this.libri = new ArrayList<>();
    }

    public boolean aggiungiLibro(Libro libro){
        if(libri.size() < dim){
            libri.add(libro);
            return true;
        }
        else{
            return false;
        }    
    }

    /*
    public boolean aggiungiLibro(String titolo, String autore, int annoPubblicazione) {
        if (raccoltaLibri.size() < dimensioneMassima) {
            raccoltaLibri.add(new Libro(titolo, autore, annoPubblicazione));
            return true;
        } else {
            return false; // Raccolta piena
        }
    }
    */

   public boolean rimuoviLibro(String titolo){
        // for range-based
        for (Libro libro : libri){
            if(libro.getTitolo().equals(titolo)){
                libri.remove(libro);
                return true;
            }
        }
        return false;
   }

        // For normale
        /*
        for(int i = 0; i < libri.size(); i++){
            if(libri.get(i).getTitolo().equals(titolo)){
                libri.remove(libro);
                return true;
            }
        }
        */

       public String stampaLibri(){
            String ritorna;
            libri.sort();
            for (Libro libro : libri) {
                ritorna += libro.toString();
            }  
                return ritorna;
       }

    public ArrayList<String> libriPerAutore(String autore) {
        ArrayList<String> libriAutore = new ArrayList<>();
        for (Libro libro : libri) {
            if (libro.getAutore().equals(autore)) {
                libriAutore.add(libro.getTitolo());
            }
        }
        return libriAutore;
    }

       public int cercaLibro(String titolo) {
        for (int i = 0; i < libri.size(); i++) {
            if (libri.get(i).getTitolo().equals(titolo)) {
                return i; // Libro trovato, restituisce l'indice
            }
        }
        return -1; // Libro non trovato
    }

    public ArrayList<String> libriPremaAnno(int anno) {
        ArrayList<String> libriPrimaAnno = new ArrayList<>();
        for (Libro libro : libri) {
            if (libro.getAnnoPubblicazione() < anno) {
                libriPrimaAnno.add(libro.getTitolo());
            }
        }
        return libriPrimaAnno;
    }
}