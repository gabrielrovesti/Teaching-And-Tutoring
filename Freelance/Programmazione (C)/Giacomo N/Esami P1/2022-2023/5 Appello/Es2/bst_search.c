#include <stdio.h>
#include <stdlib.h>

struct btree {
    int valore;
    struct btree *leftPtr;
    struct btree *rightPtr;
};

typedef struct btree BST;

void print_rec(BST *ptr);
void ordinsert(BST **ptrPtr, int val);
int search(BST *ptr, int val);

int main(void) {
    BST *albero = NULL;
    
    ordinsert(&albero, 2);
    ordinsert(&albero, 1);
    ordinsert(&albero, 0);
    ordinsert(&albero, 2);
    ordinsert(&albero, 7);
    ordinsert(&albero, 6);
    ordinsert(&albero, 9);
    ordinsert(&albero, 5);
    ordinsert(&albero, 2);
    print_rec(albero);
    
    int target = 9;
    printf("\nL'albero contiene %d? %d\n", target, search(albero, target));
    
    return 0;
}

// visita ricorsiva
void print_rec(BST *ptr) {
    if(ptr!=NULL) {
        //printf("%d ", ptr->valore); // visita in pre-ordine
        print_rec(ptr->leftPtr);
        //printf("%d ", ptr->valore); // visita simmetrica (in ordine)
        print_rec(ptr->rightPtr);
        printf("%d ", ptr->valore); // visita in post-ordine (in profondità / "depth-first")
    }
}

// inserimento in ordine 
void ordinsert(BST **ptrPtr, int val) {
    if((*ptrPtr) != NULL) {
        if(val<=(*ptrPtr)->valore)
            ordinsert(&((*ptrPtr)->leftPtr), val);
        else
            ordinsert(&((*ptrPtr)->rightPtr), val);
    }    
    else {
        (*ptrPtr) = (BST*)malloc(sizeof(BST));
        (*ptrPtr)->valore = val;
        (*ptrPtr)->leftPtr = NULL;
        (*ptrPtr)->rightPtr = NULL;
    }
}

// restituisce 1 se l'albero contiene l'elemento val, 0 altrimenti
int search(BST *ptr, int val) {
    // SCRIVETE QUA LA VOSTRA IMPLEMENTAZIONE
}