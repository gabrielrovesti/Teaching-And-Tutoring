// Esempio metodi ricorsivi

public class Ricorsione{
    void contatorefinoa10(int numero){ 
    //Numero che si incrementa fino a 10
    // Caso base = situazioni limite
    // che ti fermano la ricorsione
    if(numero == null && numero == 10) break;
    // Caso ricorsivo = chiamo lo stesso metodo 
    // facendolo avanzare con i parametri
        System.out.println(contatorefinoa10(numero + 1));
    }
}

public static void main(String[] args){

    Ricorsione rc;

    rc.contatorefinoa10(3);
}

// Fattoriale (e.g., fattoriale di 5 --> 5 * 4 * 3 * 2 * 1)
// 0! = 1 

public static int fatt(int n){
    
    // caso base
    if (n == 0) return 1;
    // caso ricorsivo - induttivo
    int numero = n * fatt(n-1);

    return numero; 
}


static int minimo(int a[], int i, int min, int n){
    // Es. trovare il minimo in un array di 10 elementi

    int min;

    // Mi devo chiedere: come ci arrivo alla fine?
    //Caso base
    if(i == n)  // Sono arrivato alla fine = ritorno il minimo
        return min;
    else
        return minimo(a, i+1, a[i], n);

    return minimo(a, i+1, min, n);

    // Le chiamate in memoria
    /*
    minimo(a, 0, min, 10)
    minimo(a, 1, min, 10)
    ...
    minimo(a, 9, min, 10) // Se sei qui hai scansionato tutti gli elementi
    */
    5 6 7 1 3 4 5 2 0
}

static int contatoreDecrescente(int numero){
    // caso base 
    if (numero == 0) return 0;
    return contatoreDecrescente(numero - 1);
}
// Numeri triangolari
/*
            1
    2           3
4       5    6      7
*/
public static int numeroTriangolare(int n) { 
    int risultato;

    // caso base 
    if (n==0)   return 0;
    risultato = n + numeroTriangolare(n-1);
}

// contatoreDecrescente(10) - diminuisce finché il numero è positivo

public static void main(String[] args){
    int numero = fatt(3);
    System.out.println("Fattoriale è: " + numero);
    
    int a = new int[10];
    int n = a.length;

    // Troviamo il minimo usando array="a", partendo da una posizione="i"
    // partendo da un valore che sappiamo sicuramente sarà sostituito da uno più piccolo="min"
    // arrivando fino alla fine dell'array="n"

    //mini = INT_MAX;
    int min = minimo(a, 0, mini, n);
}
