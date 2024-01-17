#include<stdio.h>

/* Dato un Array A di dimensione len, filtrare tutti gli elementi f.
 * Questo significa restituire l'array compattato composta da tutti gli elementi originali di A meno gli elementi uguali ad f.
 * ES: [1,24,3,4] 3 -> [1,24,4]
 * ES: [1,2,1,3,4,6] 1 -> [2,3,4,6]
*/

void leggi_array(int *X, int dim);

void filter(int *A, unsigned int *dim, int f){
    int *compat = A;
    unsigned int sz = *dim;

    for(int i=0; i<sz; i =i+1){
        if(*(A+i)!=f){
            *compat = *(A+i);
            compat=compat+1;
        }
        else *dim = *dim -1;
    }
}


int main(){

    unsigned int len;
    int f;
 
    //Per testare più velocemente il vostro algoritmo
    //potete usare le istruzioni fornite sotto. 
    //Quando siete pronti a consegnare potete ricommentare le seguenti righe.
         
    /*
    len = 10;
    f = 3;
    int A[] = {1,2,3,4,5,6,7,8,9,10};
    */
 
    // Decommentare le seguenti istruzioni per la consegna. 
    // leggi lunghezza array, inizializza e leggi array
    scanf("%2u", &len);
    int A[len];
    leggi_array(A, len);
    //leggi elemento da inserire
    scanf("%d", &f);


    filter(A, &len, f);

    printf("[");
    for (int i = 0; i<len; i+=1)
        printf(" %d",A[i]);
    printf(" ]\n");

}

void leggi_array(int *X, int dim) {
    for(int i=0; i<dim; i+=1)
        scanf("%d", &X[i]);
}
