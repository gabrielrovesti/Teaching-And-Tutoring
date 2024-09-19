#include <stdio.h>

/*
 * Scrivete una funzione che, dato un array di interi,
 * inverta (riordini) i valori dell'array scambiando 
 * ogni valore con il suo corrispondente partendo dal fondo. 
 * Ad esempio l'inverso dell'array [1,2,4] è [4,2,1]. 
 * Il programma deve stampare l'array aggiornato utilizzando
 * la funzione stampa_array() che vi forniamo noi.
 * La funzione leggi_array è quella vista nell'esercizio 1.a del laboratorio 3.
 *
 * Per esempio se l'array è [1,2,3,4] si ottiene il seguente output: 
 * [ 4 3 2 1 ]
 *  
 * 
 */

/*
 * Suggerimento:
 * sfruttare una variabile temporanea per lo scambio tra valori e 
 * utilizzare in maniera intelligente la variabile i, usata per scorrere gli indici dell'array, in modo da poter accedere agli ultimi valori in senso decrescente
*/


/* 
    PRE: L'array A è di dimensione dim 
    POST: per 0<=i<dim: A[i]=A'[dim-1-i], dove A' è A è una copia di A fatta all'inizio della funzione. 
*/
void inverti(int *A, int dim);
void stampa_array(int *A, int dim);
void leggi_array(int *X, int dim);

int main(void) {
     
    // Per testare più velocemente il vostro algoritmo
    // potete usare l'array fornito sotto (modificandolo 
    //  secondo le vostre necessità) invece di leggerlo 
    //  da input con scanf. Quando siete pronti a 
    //  consegnare potete ricommentare le seguenti righe.
     
    /* 
    const int dim = 10;    
    int A[] = {1,2,3,4,5,6,7,8,9,10}; 
    */
     
    //  Leggi la dimensione dell' array e i valori da tastiera. 
    //  Decommentare le seguenti istruzioni per la consegna. 
    
    int dim;
    scanf("%d", &dim);
    int A[dim];
    leggi_array(A, dim);
    
    int tmp; 
    
    inverti(A, dim);
    stampa_array(A, dim);

    return 0;
}


void inverti(int *A, int dim) {

    int tmp; // utilizza una variabile per lo scambio tra elementi
    for (int i = 0; i < dim/2; i+=1) { // scorre l'array scambiando gli elementi
        tmp = A[i];
        A[i] =A[dim-1-i]; // dim = 10, quindi l'ultimo indice è dim - 1 (9), dim-1-i scorre progressivamente dall'ultimo indice al primo 
        A[dim-1-i] = tmp;
    }
    
}


void stampa_array(int *A, int dim) {

    printf("[");
    for (int i = 0; i < dim; i+=1)
        printf(" %d",A[i]);
    printf(" ]\n");

}


void leggi_array(int *X, int dim) {
    for(int i=0; i<dim; i+=1)
        scanf("%d", &X[i]);
}
