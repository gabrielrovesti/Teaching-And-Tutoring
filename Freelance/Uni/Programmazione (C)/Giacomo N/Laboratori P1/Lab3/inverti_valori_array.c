#include <stdio.h>

/*
    Scrivete una funzione che, dato un array di interi,
    inverta (riordini) i valori dell'array scambiando 
    ogni valore con il suo corrispondente partendo dal fondo. 
    Ad esempio l'inverso dell'array [1,2,4] è [4,2,1]. 
    Nel main si deve stampare l'array invertito utilizzando
    la funzione stampa_array() che vi forniamo noi.

        Per esempio se l'array è [1,2,3,4] si ottiene il seguente output: 
    [ 4 3 2 1 ]
    
    La funzione inverti() deve utilizzare una funzione scambia() - che dovete definire - con due parametri che, appunto, scambia i valori dei due parametri (scambia è la funzione che abbiamo visto più volte a lezione). 
    
 */


/* 
    PRE: L'array A è di dimensione dim 
    POST: per 0<=i<dim: A[i]=A'[dim-1-i], dove A' è A è una copia di A fatta all'inizio della funzione. 
*/
void inverti(int *A, int dim);
void stampa_array(int *A, int dim);
void leggi_array(int *X, int dim);


int main(void) {
         
    int dim;
    scanf("%d", &dim);
    int A[dim];
    leggi_array(A, dim);
        
    inverti(A, dim);
    stampa_array(A, dim);

}


void scambia(int *x, int *y) {

    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;

}

void inverti(int *A, int dim) {

    for (int i = 0; i < dim/2; i+=1) 
        scambia(A+i, A+dim-1-i);
    
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
