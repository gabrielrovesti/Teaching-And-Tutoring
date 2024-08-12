#include <stdio.h>
#include <stdlib.h>

int array_stesso_ordine(int A[], int B[], int N, int index) {
    // Caso base: abbiamo controllato tutti gli elementi
    if (index == N) {
        return 1;
    }
    
    // Cerchiamo l'elemento corrispondente in B
    int found = 0;
    for (int i = 0; i < N; i++) {
        if (abs(B[i]) == abs(A[index])) {
            found = 1;
            // Controlliamo se il segno è lo stesso o opposto
            if ((A[index] > 0 && B[i] > 0) || (A[index] < 0 && B[i] < 0)) {
                // Segno uguale, continuiamo con il prossimo elemento
                return array_stesso_ordine(A, B, N, index + 1);
            } else {
                // Segno opposto, continuiamo con il prossimo elemento
                return array_stesso_ordine(A, B, N, index + 1);
            }
        }
    }
    
    // Se non troviamo l'elemento corrispondente, restituiamo 0
    if (!found) {
        return 0;
    }
    
    // Questo punto non dovrebbe mai essere raggiunto
    return 0;
}

/*
Per quanto riguarda PRE e POST della funzione implementata:

- PRE:

    A e B sono array di interi di dimensione N
    N è un intero positivo che rappresenta la dimensione degli array
    index è un intero non negativo che rappresenta l'indice corrente in A

- POST:

    La funzione restituisce 1 se tutti i valori di A sono presenti in B nello stesso ordine 
    (con lo stesso segno o con segno opposto)
    La funzione restituisce 0 altrimenti

*/

int main(void) {
    int N;
    
    // Leggiamo la dimensione degli array
    scanf("%d", &N);
    
    int A[N], B[N];
    
    // Leggiamo gli elementi dell'array A
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    
    // Leggiamo gli elementi dell'array B
    for (int i = 0; i < N; i++) {
        scanf("%d", &B[i]);
    }
    
    // Chiamiamo la funzione ricorsiva e stampiamo il risultato
    printf("%d\n", array_stesso_ordine(A, B, N, 0));
    
    return 0;
}