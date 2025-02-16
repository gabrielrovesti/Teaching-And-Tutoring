public class Universita {
    // Array di tipo Docente - visibilità/nome classe/nome variabile e parentesi quadre[]
    private Docente docenti[];

    // Come creare un array
    // int[] gradi; - senza numero di elementi predefinito
    // int gradi = new int[10]; - con 10 elementi

    // Costruttore (che inizializza l'insieme dei docenti)
    public Universita(Docente[] d) {
        // Creare un array con una lunghezza uguale a "d"
        docenti = new Docente[d.length];
        // Ciclo per assegnare a ciascun elemento di "docenti" gli elementi di "d"
        for (int i = 0; i < d.length; i++) {
            // Assegniamo a ciascun elemento di "docenti" un nuovo elemento di "d"
            docenti[i] = new Docente(d[i]);
        }
    }

    // Metodo etaMinima - trova l'età minima tra i docenti
    public int etaMinima() {
        // Dichiarare il primo elemento (int) - suggerimento: chiamalo getEta();
        int min = docenti[0].getEtà();
        // Ciclare per trovare il minimo
        for (int i = 0; i < docenti.length; i++) {
            if (min > docenti[i].getEtà()) {
                min = docenti[i].getEtà();
            }
        }
        // Ritornare il minimo
        return min;
    }
}
