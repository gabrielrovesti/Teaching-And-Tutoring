public class Es2 {
    public static void main(String[] args) {

        int arr[] = {2,3,5,6,9};
        // vettore costante
    
        // Stampa in ordine inverso
        for(int i = 4; i >= 0; i--){
            System.out.println("L'elemento è: " + arr[i]);
        }
        System.out.println();
    
        // Stampa solo i valori dispari
        for(int i = 0; i < 5; i++){
            if (arr[i] % 2 == 1){
                System.out.println("Elemento dell'array è: " + arr[i]);
            }
            // Più generalmente; se i % 2 == 0
        }
        System.out.println();

        for(int i = 0; i < 5; i++){
            if(i % 2 == 1){
                System.out.println("Valore dispari dell'array è: " + arr[i]);
            }
        }
    }


}
