class Sort{

    // controlla gli elementi a coppie
    public void BubbleSort(int[] vett){
        for(int i = 0; i < vett.length; i++){
            for(int j = 1; j < vett.length-1; j++){
                // Scambiare gli elementi
                if(vett[i] > vett[j]){
                    int temp = vett[i];
                    vett[i] = vett[j];
                    vett[j] = temp;
                }
            }
        }
    }

    // insertion sort: ragiona su indici "i" e "j"
    public void insertionSort(int[] vett) {
        int lunghezza = vett.length;

        for (int i = 1; i < lunghezza; ++i) {
            int chiave = vett[i];
            int j = i - 1;

            while (j >= 0 && vett[j] > chiave) {
                vett[j + 1] = vett[j];
                j = j - 1;
            }
            vett[j + 1] = chiave;
        }
    }

}