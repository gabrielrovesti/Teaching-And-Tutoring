#include <stdio.h>
#include <assert.h>

/*
    Scrivete una funzione che trovi il minimo ed il massimo
    di una lista di interi non vuota.
*/


/* 
    PRE: A ha dim>0 elementi.
    POST: *i contiene l'indice del valore minore in A, *j l'indice del maggiore (se c'è più di un elemento di valore minore/maggiore, si stampa quello di indice minore) 
*/
void min_max(int *A, int dim, int *i, int *j);
void test_min_max();
void consegna_moodle();


int main(void) {

    test_min_max();
    //consegna_moodle();

}


void min_max(int *A, int dim, int *i, int *j) {

    *i = 0, *j = 0; 
    for (int k = 1; k < dim; k += 1){
        if (A[k] < A[*i])
            *i = k;
        if (A[k] > A[*j])
            *j = k;
    }

}


void consegna_moodle() {

    int N;
    scanf("%d", &N);
    int array[N];
    for(int i = 0; i < N; i+=1){
        scanf("%d", array+i);
    }
    
    int min_indice, max_indice;

    min_max(array, N, &min_indice, &max_indice); 

    printf("%d %d\n", min_indice, max_indice); 

}


void test_min_max() {

    int i,j;
    int a[] = {3, 5, 1, 7, 0, 9, 4, 6, 2, 8};
    min_max(a, 10, &i, &j);
    assert((i==4) && (j==5));

    int b[] = {3, 5, 1, 0, 3, 1, 0, 9, 2, 8};
    min_max(b, 10, &i, &j);
    assert((i==3) && (j==7));

    int c[] = {3, 5, 1, 0, 3, 9, 3, 9, 2, 8};
    min_max(c, 10, &i, &j);
    assert((i==3) && (j==5));

    int d[] = {1, 2, 3, 4, 5, 6, 7};
    min_max(d, 7, &i, &j);
    assert((i==0) && (j==6));

    int f[] = {7,6,5,4,3};
    min_max(f, 5, &i, &j);
    assert((i==4) && (j==0));

    int g[] = {3,3,3,3};
    min_max(g, 4, &i, &j);
    assert((i==0) && (j==0));

    int h[] = {1};
    min_max(g, 1, &i, &j);
    assert((i==0) && (j==0));

    printf("min_max: tutti i test passati con successo\n");
}
