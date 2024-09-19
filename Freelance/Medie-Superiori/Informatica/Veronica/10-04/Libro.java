class Libro{
    private String titolo;
    private String autore;
    private int anno;

    public Libro(String t, String a, int an){
        this.titolo = t;
        this.autore = a;
        this.anno = an;
    }

    // Costruttore di copia
    public Libro(Libro libro){
        this.titolo = libro.titolo;
        this.autore = libro.autore;
        this.anno = libro.anno;
    }

    public String getTitolo() {
        return titolo;
    }

    public String getAutore() {
        return autore;
    }

    public int getAnnoPubblicazione() {
        return anno;
    }

    // overriding = ridefinire il metodo predefinito della classe
    // = definire toString per la tyu aclasse ridefinendo quello di default
    @Override
    public String toString(){
        return "Titolo: " + titolo + ", Autore: " + autore + ", Anno: " + anno;
    }
}