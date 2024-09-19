#include<stdio.h>

/*
 * Dato un array di interi di lunghezza N, scrivere un programma che stampa
 * "Array palindromo" se l'array è palindromo o "Array non palindromo" se non lo è.
 * Un array è definito palindromo se invertendolo rimane uguale (es. [1, 2, 3, 2, 1] è palindromo)
 * ATTENZIONE: l'input non è più fisso, la dimensione N e i valori dell'array saranno forniti come input. 
*/


/* 
   PRE: array ha dimensione n
   POST: restituisce 1 se l'array è palindromo, ovvero se per 0<=j<n, array[j]==array[n-1-j].
                     0 altrimenti.
*/
int palindromo(int array[], int n) {

    for(int i = 0; i<n/2; i+=1){
        if(array[i] != array[n-1-i]){
            return 0;
        }
    }
    return 1;
}


int main(){
    int N;
    //leggere da input grandezza array
    scanf("%d", &N);

    int array[N];

    //leggere da input dati array
    for(int i = 0; i < N; i++){
        scanf("%d", array+i);
    }

    if(palindromo(array, N) == 1){
        printf("Array palindromo\n");
    } else printf("Array non palindromo\n");
    
}
