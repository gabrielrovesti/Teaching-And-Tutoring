#include <stdio.h>
#include <stdlib.h>

/*
 * Scrivete la funzione ord_insert che effettui l'inserimento di un nuovo nodo in una lista - 
 * con valore pari a "val" - mantenendo gli elementi ordinati (in ordine decrescente) per valore.
 */

struct nodoLista {
    int valore;
    struct nodoLista *nextPtr;
};

typedef struct nodoLista Lista;

void stampa_lista(Lista *ptr);
void ord_insert(Lista **ptrPtr, int val);

int main() {
    Lista *miaLista = NULL;
    
    ord_insert(&miaLista, 29);
    ord_insert(&miaLista, 5);
    ord_insert(&miaLista, 11);
    ord_insert(&miaLista, 24);
    ord_insert(&miaLista, 71);
    
    stampa_lista(miaLista);
    
    return 0;
}

void stampa_lista(Lista *ptr) {
    while(ptr != NULL) {
        printf("%d ", ptr->valore);
        ptr = ptr->nextPtr;
    }
    printf("\n");
}

void ord_insert(Lista **ptrPtr, int val) {
    Lista *nuovoNodo = malloc(sizeof(Lista));
    nuovoNodo->valore = val;
    nuovoNodo->nextPtr = NULL;

    if (*ptrPtr == NULL || val > (*ptrPtr)->valore) {
        nuovoNodo->nextPtr = *ptrPtr;
        *ptrPtr = nuovoNodo;
    } else {
        Lista *corrente = *ptrPtr;
        while (corrente->nextPtr != NULL && corrente->nextPtr->valore > val) {
            corrente = corrente->nextPtr;
        }
        nuovoNodo->nextPtr = corrente->nextPtr;
        corrente->nextPtr = nuovoNodo;
    }
}