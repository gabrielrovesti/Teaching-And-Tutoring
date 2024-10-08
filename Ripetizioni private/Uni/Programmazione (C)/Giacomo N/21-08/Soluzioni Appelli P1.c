#include <stdio.h>
#include <stdlib.h>

// Strutture dati necessarie
struct node {
    int value;
    struct node *nextPtr;
};
typedef struct node Lista;

struct btree {
    int valore;
    struct btree *leftPtr;
    struct btree *rightPtr;
};
typedef struct btree BTree;

// Esercizio 4 (12/9/2022): first_odd
Lista* first_odd(Lista* srcPtr) {
    while (srcPtr != NULL) {
        if (srcPtr->value % 2 != 0) {
            return srcPtr;
        }
        srcPtr = srcPtr->nextPtr;
    }
    return NULL;
}

// Esercizio 5 (12/9/2022): first_odd ricorsivo
Lista* first_odd_recursive(Lista* srcPtr) {
    if (srcPtr == NULL) {
        return NULL;
    }
    if (srcPtr->value % 2 != 0) {
        return srcPtr;
    }
    return first_odd_recursive(srcPtr->nextPtr);
}

// Esercizio 6 (12/9/2022): delete_node
void delete_node(BTree** ptrPtr) {
    BTree* nodeToDelete = *ptrPtr;
    
    // Caso 1: Nodo foglia
    if (nodeToDelete->leftPtr == NULL && nodeToDelete->rightPtr == NULL) {
        free(nodeToDelete);
        *ptrPtr = NULL;
    }
    // Caso 2: Nodo con un solo figlio
    else if (nodeToDelete->leftPtr == NULL) {
        *ptrPtr = nodeToDelete->rightPtr;
        free(nodeToDelete);
    }
    else if (nodeToDelete->rightPtr == NULL) {
        *ptrPtr = nodeToDelete->leftPtr;
        free(nodeToDelete);
    }
    // Caso 3: Nodo con due figli
    else {
        BTree* successor = nodeToDelete->rightPtr;
        BTree** successorPtr = &(nodeToDelete->rightPtr);
        while (successor->leftPtr != NULL) {
            successorPtr = &(successor->leftPtr);
            successor = successor->leftPtr;
        }
        nodeToDelete->valore = successor->valore;
        delete_node(successorPtr);
    }
}

// Esercizio 4 (1/2/2023): clone_list iterativo
void clone_list(Lista* srcPtr, Lista** destPtr) {
    *destPtr = NULL;
    Lista* tail = NULL;
    
    while (srcPtr != NULL) {
        Lista* newNode = (Lista*)malloc(sizeof(Lista));
        newNode->value = srcPtr->value;
        newNode->nextPtr = NULL;
        
        if (*destPtr == NULL) {
            *destPtr = newNode;
        } else {
            tail->nextPtr = newNode;
        }
        tail = newNode;
        srcPtr = srcPtr->nextPtr;
    }
}

// Esercizio 4 (1/2/2023): clone_list ricorsivo
void clone_list_recursive(Lista* srcPtr, Lista** destPtr) {
    if (srcPtr == NULL) {
        *destPtr = NULL;
        return;
    }
    
    *destPtr = (Lista*)malloc(sizeof(Lista));
    (*destPtr)->value = srcPtr->value;
    clone_list_recursive(srcPtr->nextPtr, &((*destPtr)->nextPtr));
}

// Esercizio 6 (1/2/2023): completare il codice per stampare 3
int main(void) {
    enum appelli {Gen, Feb, Giu, Lug, Set};
    printf("%d\n", Giu);
    return 0;
}

// Esercizio 7 (1/2/2023): search ricorsivo
int search(BTree* ptr, int val) {
    if (ptr == NULL) {
        return 0;
    }
    if (ptr->valore == val) {
        return 1;
    }
    if (val < ptr->valore) {
        return search(ptr->leftPtr, val);
    } else {
        return search(ptr->rightPtr, val);
    }
}

// Main function per test
int main() {
    // Test delle funzioni qui
    return 0;
}