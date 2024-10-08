#include <stdio.h>
#include <stdlib.h>

/*
 * Scrivete la funzione delete_node che effettui la cancellazione 
 * del primo nodo trovato con valore pari a "val" da un BST. 
 * La funzione, per essere considerata corretta, deve garantire che l'albero risultante sia ancora un BST.
 *
 * Nota: si tenga conto del codice e delle funzioni fornite. 
 * Inoltre, la funzione dovrà restituire NULL se l'albero è vuoto, 
 * o se lo diventa a valle della cancellazione del nodo.
 */

struct btree {
    int valore;
    struct btree *leftPtr;
    struct btree *rightPtr;
};

typedef struct btree BST;

void stampa_ricorsiva(BST *ptr);
void ordinsert(BST **ptrPtr, int val);
BST* remove_node(BST* root, int val);
BST* nodo_valore_minimo(BST* node);

int main(void) {
    BST *albero = NULL;
    
    ordinsert(&albero, 7);
    ordinsert(&albero, 3);
    ordinsert(&albero, 9);
    ordinsert(&albero, 1);
    ordinsert(&albero, 5);
    ordinsert(&albero, 8);
    ordinsert(&albero, 0);
    ordinsert(&albero, 2);
    ordinsert(&albero, 4);
    ordinsert(&albero, 6);
    
    stampa_ricorsiva(albero);
    printf("\n");
    
    // esempio di cancellazione
    albero = remove_node(albero, 6);
    
    stampa_ricorsiva(albero);
    printf("\n");
    
    return 0;
}

void stampa_ricorsiva(BST *ptr) {
    if(ptr != NULL) {
        stampa_ricorsiva(ptr->leftPtr);
        printf("%d ", ptr->valore);
        stampa_ricorsiva(ptr->rightPtr);
    }
}

void ordinsert(BST **ptrPtr, int val) {
    if((*ptrPtr) == NULL) {
        *ptrPtr = (BST*)malloc(sizeof(BST));
        (*ptrPtr)->valore = val;
        (*ptrPtr)->leftPtr = NULL;
        (*ptrPtr)->rightPtr = NULL;
    } else {
        if(val < (*ptrPtr)->valore)
            ordinsert(&((*ptrPtr)->leftPtr), val);
        else
            ordinsert(&((*ptrPtr)->rightPtr), val);
    }
}

BST* remove_node(BST* root, int val) {
    if (root == NULL) return root;

    if (val < root->valore)
        root->leftPtr = remove_node(root->leftPtr, val);
    else if (val > root->valore)
        root->rightPtr = remove_node(root->rightPtr, val);
    else {
        // Nodo con un solo figlio o nessun figlio
        if (root->leftPtr == NULL) {
            BST* temp = root->rightPtr;
            free(root);
            return temp;
        } else if (root->rightPtr == NULL) {
            BST* temp = root->leftPtr;
            free(root);
            return temp;
        }

        // Nodo con due figli
        BST* temp = nodo_valore_minimo(root->rightPtr);
        root->valore = temp->valore;
        root->rightPtr = remove_node(root->rightPtr, temp->valore);
    }
    return root;
}

BST* nodo_valore_minimo(BST* node) {
    BST* corrente = node;
    while (corrente && corrente->leftPtr != NULL)
        corrente = corrente->leftPtr;
    return corrente;
}