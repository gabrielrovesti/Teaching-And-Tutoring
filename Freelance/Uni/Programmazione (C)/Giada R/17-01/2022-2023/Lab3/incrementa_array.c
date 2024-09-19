#include <stdio.h>

/*
* Dato un array di interi positivi (maggiori di 0), un nuovo valore e un indice, incrementare l'array inserendo il nuovo valore nella posizione indicata dall'indice.
* Il programma deve poi stampare il nuovo array. 
* Il programma non deve utilizzare nuove variabili di tipo array, ma modificare l'array di input.
* Inoltre il programma deve sfruttare la conoscenza dei puntatori per accedere agli elementi (non usare A[i] eccetto che per la stampa).
* 
* Per esempio se l'array fosse [2,11,14,3,6,8], il nuovo valore 7 e la posizione 3, l'array incrementato e la stampa attesa dal programma sarebbe:
* "2, 11, 14, 7, 3, 6, 8"
*
* Notate che l'array deve essere dichiarato di dimensione
* maggiore del numero di elementi con cui si inizializza 
* (perché andremo ad inserirne 1), perciò si assume che le 
* restanti posizioni dell'array siano inizializzate a 0. 
* Ad esempio se l'array sopra è stato dichiarato come 
* int[9] allora sarebbe inizializzato come 
* int a[9] = {2,11,14,3,6,8,0,0,0}. 
*
* Per la consegna, utilizzare:
* array = [1,8,4,7,12,3,2]
* valore = 5
* posizione = 4
*/

/*
* Suggerimento:
* Supponiamo che l'elemento sia da aggiungere in posizione x. Dato che la lunghezza (dimensione) dell'array è maggiore del numero di elementi + 1 (che dobbiamo inserire),
* possiamo spostare verso destra ogni elemento di posizione maggiore di x partendo dalla fine, e poi inserire il nuovo valore alla posizione data: 
* Es. vogliamo aggiungere 7 in posizione 1 all'array [1,2,3,0]. L'array diventa:
[1,2,3,3] (copiato il 3 nella cella seguente) -> [1,2,2,3] -> [1,7,2,3]
*/

void leggi_array(int *X, int dim);


/*
    PRE: l'array A ha dimensione length, 0<=pos<length
    POST: sia A' una copia di A fatta all'inizio della funzione.
                0<=i<pos: A[i] = A'[i]
                   i=pos: A[i] = x 
         pos+1<=i<length: A[i] = A'[i-1]
*/
void incrementa_array(int* A, int length, int x, int pos){
    // sposta a destra ogni elemento partendo dal fondo fino alla posizione cercata
    for(int i=length-1; i>pos; i=i-1)
      *(A+i) = *(A+i-1);
    // aggiunge il nuovo valore alla posizione richiesta
    *(A+pos)=x;
}


int main() {
     
    // Per testare più velocemente il vostro algoritmo
    // potete usare le istruzioni fornite sotto. 
    // Quando siete pronti a consegnare potete ricommentare le seguenti righe.
    
    /*
    int length = 10;
    int A[length] = {1,8,4,7,12,3,2,0,0,0}; 
    int x = 5;
    int pos = 4;
    */
     
    // Decommentare le seguenti istruzioni per la consegna. 
    int length, x, pos;
    scanf("%d", &length);
    scanf("%d", &x);
    scanf("%d", &pos);

    int A[length];
    leggi_array(A, length);
    
    incrementa_array(A,length,x,pos);
    
    printf("[");
    for (int i = 0; (i<length) && (A[i]!=0); i+=1)
        printf(" %d",A[i]);
    printf(" ]\n");

    return 0;
}


void leggi_array(int *X, int dim) {
    for(int i=0; i<dim; i+=1)
        scanf("%d", &X[i]);
}
