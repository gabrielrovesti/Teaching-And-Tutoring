public class BubbleSort {
    public static void bubbleSort(int[] array) {
        int lunghezza = array.length;

        for (int i = 0; i < lunghezza - 1; i++) {
            for (int j = 0; j < lunghezza - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    // Swap
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
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
        int[] array = {64, 34, 25, 12, 22, 11, 90};
        System.out.println("Array originale:");
        stampaArray(array);

        bubbleSort(array);

        System.out.println("Array ordinato con Bubble Sort:");
        stampaArray(array);
    }
}
