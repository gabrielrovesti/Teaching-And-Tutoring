public class Array{
    private int campo;

    // Metodo = funzionalità offerta dalla classe
    // importante = Visibilità / Tipo di ritorno / Parametri (dentro alle tonde)
    public void stampa(){
        System.out.println("Campo " + campo);
    }

    //Costruttore - metodo
    public Array(int c){
        campo = c;
    }

    // Costruttore di copia
    public Array(Array other){
        other.campo = campo; //copiamo tutti i campi
    }
}

public static void main(String[] args()){
    Array a(5); //uso del costruttore normale

    Array b(a); //uso costruttore di copia

    int[] array = {1, 2, 3, 4, 5}; 
    // Array o Vettore = Contenitore di un insieme di elementi
    // Usare/stampare/cancellare tutti gli elementi
    // oppure uno specifico

    // Cicli - servono per muoversi nell'insieme di elementi
    for(int i=0; i < array.length; i++){ 
        System.out.println(array[i]); // 1 2 3 4 5
        //Accediamo agli elementi con le quadre 

        // Parto a contare dalla posizione 0
        // e scorro tutti gli elementi presi in posizione delle quadre
        // 0 a 4
    }

    
}