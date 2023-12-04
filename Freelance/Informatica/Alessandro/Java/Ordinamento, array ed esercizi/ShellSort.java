
public class ShellSort {
    public static void shellSort(int[] array) {
        int lunghezza = array.length;

        for (int intervallo = lunghezza / 2; intervallo > 0; intervallo /= 2) {
            for (int i = intervallo; i < lunghezza; i += 1) {
                int temp = array[i];
                int j;
                for (j = i; j >= intervallo && array[j - intervallo] > temp; j -= intervallo) {
                    array[j] = array[j - intervallo];
                }
                array[j] = temp;
            }
        }
    }

    public static void stampaArray(int[] array) {
        for (int elemento : array) {
            System.out.print(elemento + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int[] array = {12, 34, 54, 2, 3};
        System.out.println("Array originale:");
        stampaArray(array);

        shellSort(array);

        System.out.println("Array ordinato con Shell Sort:");
        stampaArray(array);
    }
}
