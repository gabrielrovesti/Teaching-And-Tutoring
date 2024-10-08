public class Main {
    public static void main(String[] args) {
        GestioneLibri gestioneLibri = new GestioneLibri(10);

        gestioneLibri.aggiungiLibro("Il nome della rosa", "Umberto Eco", 1980);
        gestioneLibri.aggiungiLibro("1984", "George Orwell", 1949);
        gestioneLibri.aggiungiLibro("Il signore degli anelli", "J.R.R. Tolkien", 1954);

        gestioneLibri.stampaLibri();

        System.out.println("Indice del libro '1984': " + gestioneLibri.cercaLibro("1984"));

        System.out.println("Libri di George Orwell: " + gestioneLibri.libriPerAutore("George Orwell"));

        System.out.println("Libri pubblicati prima del 1960: " + gestioneLibri.libriPremaAnno(1960));

        gestioneLibri.rimuoviLibro("Il nome della rosa");
        gestioneLibri.stampaLibri();
    }
}
