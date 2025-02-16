public class OrdinamentoPerInserimento {
    public static void ordinamentoPerInserimento(int[] array) {
        int lunghezza = array.length;

        for (int i = 1; i < lunghezza; ++i) {
            int chiave = array[i];
            int j = i - 1;

            while (j >= 0 && array[j] > chiave) {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = chiave;
        }
    }

    public static void stampaArray(int[] array) {
        for (int elemento : array) {
            System.out.print(elemento + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int[] array = {12, 11, 13, 5, 6};
        System.out.println("Array originale:");
        stampaArray(array);

        ordinamentoPerInserimento(array);

        System.out.println("Array ordinato per inserimento:");
        stampaArray(array);
    }
}
