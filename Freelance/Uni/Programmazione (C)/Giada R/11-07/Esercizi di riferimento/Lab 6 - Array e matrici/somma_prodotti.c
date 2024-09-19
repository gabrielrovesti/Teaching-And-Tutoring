#include <stdio.h>
#include <basic/array.h>

/*
    Scrivere una funzione che, dato un array A di dim interi, calcoli la somma dei prodotti tra il primo e l'ultimo elemento dell'array, tra il secondo ed il penultimo ecc...
    Per esempio, dato l'array [1,2,3,4,5,6] la funzione calcola 1*6+2*5+3*4. Se l'array è dispari, l'elemento centrale va moltiplicato con sè stesso.
    Il tipo restituito dalla funzione è void, però deve essere possibile stampare nel main la somma calcolata. 
*/
void somma_prodotti_inversi(int *X, int dim, int *somma) {

    *somma = 0;
    for(int i=0;i<dim/2;i+=1) {
        *somma += X[i] * X[dim-1-i];
    }
    if ((dim % 2)==1) 
        *somma += X[dim/2]*X[dim/2];
}


int main(void) {

    /* Per velocizzare i vostri test potete usare le seguenti istruzioni*/

    /*int dim = 7;
    int A[] = {1,2,3,4,5,6,7};*/

    /* Da commentare se si usano le istruzioni precedenti, necessarie per
       la consegna su Moodle*/
    int dim;
    scanf("%d", &dim);
    int A[dim];
    leggi_array(A, dim);

    int somma;

    somma_prodotti_inversi(A, dim, &somma);
    printf("%d\n", somma);
}
