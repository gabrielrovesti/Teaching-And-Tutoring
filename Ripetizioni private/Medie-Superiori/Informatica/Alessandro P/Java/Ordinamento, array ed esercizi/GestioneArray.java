public class GestioneArray {
    private int[] array;
    private int size;  // Dimensione corrente dell'array

    public GestioneArray(int capacity) {
        array = new int[capacity];
        size = 0;
    }

    // Inserisce un elemento all'indice specificato
    public void inserisciElemento(int index, int elemento) {
        if (index < 0 || index > size) {
            System.out.println("Indice non valido.");
            return;
        }

        // Shift degli elementi per fare spazio al nuovo elemento
        for (int i = size - 1; i >= index; i--) {
            array[i + 1] = array[i];
        }

        array[index] = elemento;
        size++;
    }

    // Elimina l'elemento all'indice specificato
    public void eliminaElemento(int index) {
        if (index < 0 || index >= size) {
            System.out.println("Indice non valido.");
            return;
        }

        // Shift degli elementi per coprire il buco lasciato dall'elemento eliminato
        for (int i = index; i < size - 1; i++) {
            array[i] = array[i + 1];
        }

        size--;
    }

    // Svuota l'intero array
    public void svuotaArray() {
        array = new int[array.length];
        size = 0;
    }

    // Stampa l'array
    public void stampaArray() {
        for (int i = 0; i < size; i++) {
            System.out.print(array[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        GestioneArray gestioneArray = new GestioneArray(10);

        gestioneArray.inserisciElemento(0, 5);
        gestioneArray.inserisciElemento(1, 10);
        gestioneArray.inserisciElemento(2, 15);

        System.out.println("Array dopo l'inserimento:");
        gestioneArray.stampaArray();

        gestioneArray.eliminaElemento(1);

        System.out.println("Array dopo l'eliminazione:");
        gestioneArray.stampaArray();

        gestioneArray.svuotaArray();

        System.out.println("Array dopo lo svuotamento:");
        gestioneArray.stampaArray();
    }
}
