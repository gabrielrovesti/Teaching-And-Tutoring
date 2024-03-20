class Array{
    // insieme di interi
    int[] vett;
    // insieme di stringhe
    String[] vett1;
    int vettore = new int[10]; // vettore di 10 elementi

    // popolamento array
    // scorri tutto l'array riempiendo gli elementi
    public void popolaArray(int[] vett){
        for(int i=0; i < vett.length; i++){
            vett[i] = i;
            vett1[i] = "A";
        }
    }

    //svuota array
    public void svuotaArray(int[] vett){
        for(int i=0; i < vett.length; i++){
            vett[i] = 0;
            vett1[i] = "";
        }
    }

    // elimina item array
    public eliminaItemArray(int[] vett, int item){
        for(int i=item; i < vett.length-1; i++){
            vett[i] = vett[i+1];
        }

        // Ammesso di eliminare l'elemento in quella posizione

        // for(int i=0; i < vett.length; i++){
        //     if(vett[i] == item) vett[i] = 0;
        // }
    }

    // ricerca lineare 
    // scorro tutti gli elementi del vettore
    // controllo se l'ho trovato o meno
    public void ricercaLineare(int[] vett, int item){
        boolean trovato = false;
        // ricerca dell'elemento item
        // cerchiamo iterativamente - dentro il vettore
        for(int i = 0; i < vett.length; i++){
            // trovo qualcosa che corrisponda ad item
            if(vett[i] == item){
                trovato = true;
                System.out.println("Elemento trovato in posizione: ", i);
            }
        }
        // se non hai trovato nessun elemento
        if(trovato == false) System.out.println("Elemento non trovato");
    }

    // ricerca binaria
    int high, low;
    

    public static void main(String[] args){
        int[] array;
        int item;
        eliminaItemArray(array, 5);

        ricercaLineare(array, item);
    }

    
    
}


// METODO elimina Item Array
// METODO modifica Item Array
// METODO attraversa array
//RICERCA LINEARE
//RICERCA LINEARE con restituzione