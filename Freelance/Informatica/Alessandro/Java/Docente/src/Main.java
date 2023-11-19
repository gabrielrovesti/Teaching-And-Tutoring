public class Main {
    public static void main(String[] args) {
        // Crea un array di docenti di tipo Docente
        Docente[] docentiArray = new Docente[3];

        // Popola l'array di docenti
        docentiArray[0] = new Docente("Smith", "D001", 40);
        docentiArray[1] = new Docente("Johnson", "D002", 35);
        docentiArray[2] = new Docente("Williams", "D003", 45);

        // Crea un'istanza di Università
        Universita universita = new Universita(docentiArray);

        // Calcolo età minima tra docenti
        int minAge = universita.etaMinima();

        // Stampa età minima
        System.out.println("Età minima tra i docenti: " + minAge);
    }
}
