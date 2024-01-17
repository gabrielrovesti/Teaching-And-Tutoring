#include<stdio.h>

/*
 * Dato un array di interi di lunghezza N, scrivere un programma che stampa
 * "Array palindromo" se l'array è palindromo o "Array non palindromo" se non lo è.
 * Un array è definito palindromo se invertendolo rimane uguale (es. [1, 2, 3, 2, 1] è palindromo)
 * ATTENZIONE: l'input non è più fisso, la dimensione N e i valori dell'array saranno forniti come input. 
*/

int main(){

    // Per comodità potete usare il codice sottostante 
    // invece che leggere gli input da tastiera, è da commentare prima 
    // di consegnare 
    
    /*const int N = 10;
    int array[] = {3, 5, 1, 7, 0, 9, 4, 6, 2, 8};*/

    // inizio codice per leggere input da tastiera
    int N;
    //leggere da input grandezza array
    scanf("%d", &N);

    int array[N];
    //leggere da input dati array
    for(int i = 0; i < N; i++){
        scanf("%d", array+i);
    }
    // fine lettura input da tastiera

    //controllo l'array finchè non trovo un mismatch tra 2 valori "opposti"
    int ok = 1;
    for(int i = 0; i<N/2 && ok==1; i++){
        if(array[i] != array[N-1-i]){
            ok=0;
        }
    }

    //controllare se ho trovato mismatch
    if(ok == 1){
        printf("Array palindromo\n");
    } else printf("Array non palindromo\n");
    
}