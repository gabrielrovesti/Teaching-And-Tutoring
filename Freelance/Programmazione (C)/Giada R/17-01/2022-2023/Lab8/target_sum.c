#include <stdio.h>
#include <assert.h>

/*
    Definire una funzione ricorsiva che, dato un array X di interi positivi ed un intero target, determini se esiste un sequenza di elementi di X (ottenuta eventualmente considerando più volte lo stesso elemento) la cui somma dia target. 
    La funzione restituisce 1 se esiste almeno una di tali sequenze, 0 altrimenti. 
    Ad esempio se X={4,5,3,6,1} e target=7 la funzione resituisce 1 poiché 4+3=7 oppure perché 3+3+1=7.
 */


int target_sum(int *X, int dim, int target);
void test_target_sum();
void consegna_moodle_target_sum();
void leggi_array(int* A, int dim);
 

int main(void) {

    test_target_sum();
    //consegna_moodle_target_sum();

}


/* 
    PRE: 0<=i<dim. X[i]>0
    POST: Resituisce 
            1 se esiste almeno una sequenza di indici j_1,..,j_k (dove un indice può comparire più volte) tali che X[j_1]+...+X[j_k]=target
            0 altrimenti
*/
int target_sum(int *X, int dim, int target) {

    if (target<0)
        return 0;
    if(target==0)
        return 1; 
    for(int i=0; i<dim; i+=1)
        if(target_sum(X, dim, target-X[i]))
            return 1;
    return 0;

}


void test_target_sum() {

    int X1[]={3,4,6,8,9};
    assert(target_sum(X1, 5, 7)==1);
    assert(target_sum(X1, 5, 2)==0);
    printf("test_target_sum: tutti i test passati con successo\n");

}


void consegna_moodle_target_sum() {

    int dim, target;
    scanf("%d", &target);
    scanf("%d", &dim);
    int X[dim];
    leggi_array(X, dim);

    printf("%d\n", target_sum(X, dim, target));
}


void leggi_array(int* A, int dim){
    for(int i =0; i<dim; i++){
        scanf("%d", A+i);
    }
}
