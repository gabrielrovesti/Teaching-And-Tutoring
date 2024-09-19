#include <stdio.h>

/*
* Scrivete un programma che trovi l'indice del minimo e
* del il massimo valore di un array di interi non vuota.
*
* Il programma deve stampare i valori trovati. Utilizzare:
* printf("Valore minimo: array[%d] -> %d\n", min_indice, array[min_indice]);
* printf("valore massimo: array[%d] -> %d", max_indice, array[max_indice]);
*
*/

int main(void)
{
    /* Per comodità potete usare il codice sottostante 
    invece che leggere gli input da tastiera, è da commentare prima 
    di consegnare */ 
    
    /*const int N = 10;
    int array[] = {3, 5, 1, 7, 0, 9, 4, 6, 2, 8};*/

    /* da commentare se si usano le istruzioni sopra */

    int N;
    //leggere da input grandezza array
    scanf("%d", &N);

    int array[N];
    //leggere da input dati array
    for(int i = 0; i < N; i++){
        scanf("%d", array+i);
    }
    
    /*
        Utilizziamo un ciclo for che passa attraverso tutti gli elementi
        dell'array. Per ogni elemento controlla se questo sia minore del
        più piccolo elemento trovato o maggiore del più grande elemento
        trovato. Notate che stiamo assumendo di seguito
        che l'array non sia vuoto (altrimenti la stampa di
        array[max_indice] e array[min_indice] genererebbe un errore). 
    */
    
    int min_indice = 0, max_indice = 0; 
    for (int i = 0; i < N; i += 1){
        if (array[i] < array[min_indice]){
            min_indice = i;
        }
        else if (array[i] > array[max_indice]){
            max_indice = i;
        }
    }
    
    /*
        Terminiamo con la stampa.
    */
    printf("Valore minimo: array[%d] -> %d\n", min_indice, array[min_indice]); 
    printf("valore massimo: array[%d] -> %d", max_indice, array[max_indice]);
    
    return 0;
}
