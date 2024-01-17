#include <stdio.h>

/*
* Scrivete un programma che ordini un array di numeri interi in ordine
* crescente.
*
* Il programma deve stampare l'array ordinato al termine dell'esecuzione.
* Utilizzare: printf("Array[%d] : %d\n", i, array[i]);
*
*/

/*
    Suggerimento: per ordinare l'array è possibile spostare i suoi
    elementi utilizzando due cicli for, uno interno all'altro. Il
    ciclo interno trova il valore minimo contenuto nell'array. Il
    ciclo esterno permette di spostare l'elemento minimo all'inizio
    dell'array.
*/

int main(void) {

    // Per comodità potete usare il codice sottostante 
    // invece che leggere gli input da tastiera, è da commentare prima 
    // di consegnare 

    /*
    const int N = 10;
    int array[] = {3, 5, 7, 1, 2, 9, 4, 6, 0, 8};
    */

    // da commentare se non si vuole immettere l'input da tastiera 
    int N;
    //leggere da input grandezza array
    scanf("%d", &N);

    int array[N];
    //leggere da input dati array
    for(int i = 0; i < N; i++){
        scanf("%d", array+i);
    }
    // fine blocco da commentare se non si vuole immettere l'input da tastiera


    // Il ciclo for esterno passa attraverso tutti gli indici dell'array.
    // Per ognuno di questi indici, il ciclo for interno cerca il valore minimo
    // a partire da quell'indice e lo scambia con il valore della posizione
    // attuale.
    //    
    //  1° ciclo. [|3| 5 4 1 2] -> [|1| 5 4 3 2]
    //  2° ciclo. [1 |5| 4 3 2] -> [1 |2| 4 3 5]
    //  ...
    //  5° ciclo. [1 2 3 4 |5|] -> [1 2 3 4 |5|]
    
    int supporto; // la usiamo per scambiare due valori dell'array
    int min_indice;
    for(int i = 0; i < N ; i += 1){
        min_indice = i;
        for(int j = i; j < N; j += 1){
            if (array[j] < array[min_indice]){
                min_indice = j;
            }
        }
        supporto = array[i];
        array[i] = array[min_indice];
        array[min_indice] = supporto;
    }
    
    // Terminiamo con la stampa.
    for(int i = 0 ; i < N ; i += 1){
        printf("Array[%d] : %d\n", i, array[i]);
    }
    
}
