public class Array{
    // Metodo per la ricerca lineare
    public static int ricercaLineare(int[] vettore, int elemento) {
        for(i=0; i<vettore.length; i++){
            if(vettore[i] == elemento){
                System.out.print("L'elemento trovato è" + elemento);
                return elemento;
            }
            else return -1;
        }
    }

    // Metodo per la ricerca binaria (l'array deve essere ordinato)
    public static int ricercaBinaria(int[] vettore, int elemento) {
        // elemento iniziale -elemento finale - mediana
        int inizio = 0;
        int fine = vettore.length-1;
        int mediana = inizio + ((fine - inizio) /  2);

        while(inizio < fine){
            if(array[mediana] < elemento){
                inizio = mediana + 1;
            }
            //else caso maggiore - decrmento 
            //else caso uguale - esco
        }
    }

    public static void main(String[] args) {
        int[] vettore = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        int elemento = 7;

        // Esempio di utilizzo della ricerca lineare
        int lineare = linearSearch(vettore, elemento);
        System.out.println("Ricerca Lineare: Elemento " + elemento);

        // Esempio di utilizzo della ricerca binaria
        // L'array deve essere ordinato per utilizzare la ricerca binaria
        Arrays.sort(myArray);
        int binario = binarySearch(vettore, elemento);
        System.out.println("Ricerca Binaria: Elemento " + elemento);
    }
}