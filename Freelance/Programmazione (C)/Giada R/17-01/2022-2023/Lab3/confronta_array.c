#include <stdio.h>

/* 
 * Scrivere una funzione che controlli se due array
 * sono uguali. 
 * Due array sono uguali se tutti i corrispondenti 
 * elementi (ovvero quelli nella stessa posizione) 
 * sono uguali. 
 * Ad esempio [1,2,3,4] e [1,2,3,4] sono uguali, mentre
 * [1,2,3,4] e [1,6,3,4] non lo sono. 
 * Il prototipo della funzione confronta_array() è
 * fornito di seguito. 
 */

int confronta_array(int *X, int *Y, int dim);
void leggi_array(int *X, int dim);

int main(void) {

    // Per testare più velocemente il vostro algoritmo potete 
    // usare gli array sotto (modificandoli secondo le vostre necessità)
    // invece di leggerli da input con scanf. Quando siete pronti a
    // consegnare potete ricommentare le 3 righe seguenti.
     
    /* 
    const int dim = 10;    
    int A[] = {1,2,3,4,5,6,7,8,9,10};
    int B[] = {1,2,3,4,5,6,7,7,9,10}; 
    */
     
    // Legge la dimensione degli array e i valori
    // dei due array da tastiera. Decommentare le 
    // istruzioni seguenti per la consegna. 
    
    int dim;
    scanf("%d", &dim);
    int A[dim], B[dim];
    leggi_array(A, dim);
    leggi_array(B, dim);

    if (confronta_array(A, B, dim)==1) 
        printf("Gli array sono uguali\n");
    else 
        printf("Gli array non sono uguali\n");
    
    return 0;
}


/*
    Confronta due array di interi della stessa dimensione elemento ad elemento: l'i-esimo del primo con l'i-esimo del secondo, per i
    che varia su tutti gli elementi dell'array.
    Restituisce 1 se tutti gli elementi sono uguali
                0 altrimenti
*/
int confronta_array(int *X, int *Y, int dim) {

   for(int i=0; i<dim; i+=1) {
       if (X[i]!=Y[i])
        return 0; 
   }
   return 1; 
}


/* 
    Legge da tastiera dim interi e li carica 
    sull'array X. Si assume che X sia stato 
    dichiarato come int X[dim] nella funzione
    chiamante. 
*/
void leggi_array(int *X, int dim) {

    for(int i=0; i<dim; i+=1) {
        scanf("%d", &X[i]);
    }
}
