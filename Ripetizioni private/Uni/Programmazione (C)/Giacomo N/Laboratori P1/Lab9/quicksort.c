#include <stdio.h>
#include <basic/array.h>

/*
* Implementare l'algoritmo di quick sort per ordinare un array di interi.
* Quick Sort è un algoritmo divide-et-impera che divide iterativamente
* l'array di input in due sottoarray rispetto ad un elemento detto pivot.
* Tale procedura ricorsiva viene chiamata partition: scelto il pivot si pongono a sinistra
* tutti gli elementi minori e a destra tutti i maggiori formando così i due sottoarray.
* L'operazione viene reiterata ricorsivamente sui sottoarray fino all'ordinamento completo. 
*
* Potete trovare una spiegazione più dettagliata al seguente link: https://ifif.altervista.org/quicksort-come-funziona-esempio/ 
*
* Stampare l'array ordinato usando la funzione stampa_array in libreria.
*/

void scambia(int *a, int *b);
int partition(int A[], int low, int high);
void quickSort(int A[], int low, int high);

/*
* PRE: a e b puntatori a interi
* POST: scambia i valori degli oggetti puntati
*/
void scambia(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}


/*
* PRE: A array di interi, low e high sono rispettivamente indice più piccolo e più grande
* POST: restituisce l'indice di partizione
*/
int partition(int A[], int low, int high) {
    int pivot = A[high]; //seleziona l'utlimo elemento
    int i = (low - 1); // indice all'elemento maggiore del pivot

    // scorre l'array e confronta i valori con il pivot
    for (int j = low; j < high; j++) {
        // se trova un elemento minore del pivot lo scambia con il maggiore puntato da i
        if (A[j] <= pivot) {
            i++;
            scambia(&A[i], &A[j]);
        }
    }

    // scambia l'elemento del pivot con il maggiore puntato da i
    scambia(&A[i+1], &A[high]);
    //ritorna l'indice di partizione
    return (i + 1);
}


/*
* PRE: A array di interi, low e high sono rispettivamente indice più piccolo e più grande
* POST: restituisce A ordinato in modo crescente
*/
void quickSort(int A[], int low, int high) {
    if (low < high) {
        /*
          Trova il pivot t.c.
          gli elementi più piccoli del pivot sono alla sua sinistra
          gli elementi più grandi del pivot sono alla sua destra
        */
        int pivot = partition(A, low, high);
        
        // chiamata ricorsiva al sottoarrray sinistro e destro del pivot
        quickSort(A, low, pivot - 1);
        quickSort(A, pivot + 1, high);
    }
}


int main() {

    /* Per velocizzare i vostri test potete usare le seguenti istruzioni*/
    /*int size = 8;
    int A[8] = {5, 8, 7, 2, 4, 0, 9, 6};*/

    /* Da commentare se si usano le istruzioni precedenti, necessarie per
       la consegna su Moodle*/
    int size;
    scanf("%d", &size);
    int A[size];
    leggi_array(A, size);

    // ordina array 
    quickSort(A, 0, size - 1);
    // stampa array
    stampa_array(A, size);
}
