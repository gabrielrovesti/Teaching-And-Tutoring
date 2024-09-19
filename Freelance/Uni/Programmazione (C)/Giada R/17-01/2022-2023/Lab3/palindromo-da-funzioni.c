#include<stdio.h>

/*
 * Dato un array di interi di lunghezza N, scrivere un programma che stampa
 * "Array palindromo" se l'array è palindromo o "Array non palindromo" se non lo è.
 * Un array è definito palindromo se invertendolo rimane uguale (es. [1, 2, 3, 2, 1] è palindromo)
 * 
 * Per questa l'implementazione ci rifaremo letteralmente alla
 * la definizione sopra: creeremo una funzione che 
 * inverte un array ed una che confronta due array. 
 * Realizzate le due funzioni secondo i prototipi forniti
 * ed infine usatele all'interno di una funzione 
 * palindromo che realizzi la consegna. 
 */

int confronta_array(int *X, int *Y, int dim);
void inverti(int *A, int dim);
void leggi_array(int *X, int dim);
int palindromo(int array[], int n);


int main(){
    int N;
    //leggere da input grandezza array
    scanf("%d", &N);

    int array[N];

    //leggere da input dati array
    leggi_array(array, N);

    if(palindromo(array, N) == 1){
        printf("Array palindromo\n");
    } else printf("Array non palindromo\n");
    
}


/* 
    A è palindromo se 0<=i<n: A[i]=A[dim-1-i]
    PRE: A ha dimensione n
    POST Restituisce 1 se l'array è palindromo 
                     0 altrimenti.
*/
int palindromo(int A[], int n) {
    // creiamo una copia dell'array passato per parametro
    int inverted_array[n];
    for(int i = 0; i<n; i+=1){
        inverted_array[i] = A[i];
    }
    // invertiamolo
    inverti(inverted_array, n);
    return confronta_array(A, inverted_array, n);
}


int confronta_array(int *X, int *Y, int dim) {
    /*
        Confronta due array di interi della stessa dimensione elemento ad elemento: l'i-esimo 
        del primo con l'i-esimo del secondo, per i
        che varia su tutti gli elementi dell'array.
        Restituisce 1 se tutti gli elementi sono uguali
                    0 altrimenti
    */
   for(int i=0; i<dim; i+=1) {
       if (X[i]!=Y[i])
        return 0; // i due array non sono uguali
   }
   return 1; 
}


void inverti(int *A, int dim) {

    int tmp; // utilizza una variabile per lo scambio tra elementi
    for (int i = 0; i < dim/2; i+=1) { // scorre l'array scambiando gli elementi
        tmp = A[i];
        A[i] =A[dim-1-i]; // dim = 10, quindi l'ultimo indice è dim - 1 (9), dim-1-i scorre progressivamente dall'ultimo indice al primo 
        A[dim-1-i] = tmp;
    }
    
}

void leggi_array(int *X, int dim) {
    for(int i=0; i<dim; i+=1)
        scanf("%d", &X[i]);
}