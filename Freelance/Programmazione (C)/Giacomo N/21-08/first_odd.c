#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *nextPtr;
};

typedef struct node Lista;

Lista* first_odd(Lista *srcPtr) {
    Lista *minOdd = NULL;
    
    while (srcPtr != NULL) {
        if (srcPtr->value % 2 != 0) {  // Controllo se il valore è dispari
            if (minOdd == NULL || srcPtr->value < minOdd->value) {
                minOdd = srcPtr;
            }
        }
        srcPtr = srcPtr->nextPtr;
    }
    
    return minOdd;  // Restituisce NULL se non ci sono elementi dispari
}