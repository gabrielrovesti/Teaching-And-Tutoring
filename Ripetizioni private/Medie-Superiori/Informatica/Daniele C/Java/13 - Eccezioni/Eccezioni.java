// IndexOutOfBoundException -> [10] 12

public class Eccezioni{
    // Caso d'uso: accesso fuori dagli indici di un array
    public static Integer[] array = new Integer[10];

    public static void accessoArrayTryCatch(){
        // try = il blocco di codice dove controllo se ci sarà
        // un'eccezione (la devo gestire!)
        try {
            System.out.println("Fuori array: " + array[11]);
        } catch (IndexOutOfBoundsException e) {
            System.out.println("Errore: " + e);
        }
        // catch = Gestiamo l'eccezione facendo qualcosa 
        // Qui stampiamo e basta
        
        // Eccezione: rrore: java.lang.ArrayIndexOutOfBoundsException: Index 11 out of bounds for length 10
    }

    // throws: durante l'esecuzione di quel metodo possono essere generate eccezioni (controllate) dei tipi elencati dopo la parola chiave throws, la cui gestione viene delegata al chiamante.
    public static void accessoArrayThrows() throws ArrayIndexOutOfBoundsException{
        System.out.println("Fuori array: " + array[11]);
    }

    public static void main(String[] args) {
        //accessoArrayTryCatch();
        accessoArrayThrows();
    }   
}