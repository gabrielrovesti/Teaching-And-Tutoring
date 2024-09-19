#include <stdio.h>
#include <assert.h>

/*
Scrivere una funzione che controlli se due array con lo stesso numero di elementi sono uguali.
Due array (con lo stesso numero di elementi) sono uguali se tutti i corrispondenti
elementi (ovvero quelli nella stessa posizione) sono uguali.

Ad esempio:
* [1,2,3,4] e [1,2,3,4] sono uguali
* [1,2,3,4] e [1,6,3,4] non sono uguali

Il prototipo della funzione confronta_array() è fornito di seguito.
*/


/* 
    PRE: X e Y sono due array di interi con dim elementi 
    POST: restituisce   1 se per 0<=i<dim. X[i]=Y[i]
                        0 altrimenti
*/
int confronta_array(int *X, int *Y, int dim);
void consegna_moodle();

/* 
    PRE: X punta ad un array di dim elementi
    POST: X riempito con valori letti da tastiera
*/
void leggi_array(int *X, int dim);
void test_confronta_array();


int main(void) {

    //test_confronta_array();
    consegna_moodle();

}


int confronta_array(int *X, int *Y, int dim) {

   for(int i=0; i<dim; i+=1) {
       if (X[i]!=Y[i])
        return 0; 
   }
   return 1; 
}


void leggi_array(int *X, int dim) {

    for(int i=0; i<dim; i+=1) {
        scanf("%d", &X[i]);
    }
}


void test_confronta_array() {

    int X[]={1,2,3,4};
    int Y[]={1,2,3,4};
    assert(confronta_array(X,Y,4)==1);

    int Y2[]={1,3,2,4};
    assert(confronta_array(X,Y2,4)==0);

    int Y3[]={1,2,3,1};
    assert(confronta_array(X,Y3,4)==0);

    int Y4[]={2,2,3,4};
    assert(confronta_array(X,Y4,4)==0);

    int X2[]={};
    int Y5[]={};
    assert(confronta_array(X2,Y5,0)==1);

    printf("Tutti i test superati con successo!\n");
}


void consegna_moodle() {

    int dim;
    scanf("%d", &dim);
    int A[dim], B[dim];
    leggi_array(A, dim);
    leggi_array(B, dim);

    if (confronta_array(A, B, dim)==1) 
        printf("Gli array sono uguali\n");
    else 
        printf("Gli array non sono uguali\n");

}
