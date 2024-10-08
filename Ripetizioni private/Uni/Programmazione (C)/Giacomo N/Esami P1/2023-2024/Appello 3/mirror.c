#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define COUNT 8

struct btree {
    int valore;
    struct btree *leftPtr;
    struct btree *rightPtr;
};

typedef struct btree BST;

void init(BST **ptrPtr);
void mirror(BST *srcPtr, struct btree **destPtr);

void print_rec(BST *ptr);
void ordinsert_rec(BST **ptrPtr, int val);

void print_bst2D_uil(BST *root, int space);
void print_bst2D(BST *root);

int main(void) {
    BST *albero;
    init(&albero);
    
    // creazione di un BST
    ordinsert_rec(&albero, 5);
    ordinsert_rec(&albero, 3);
    ordinsert_rec(&albero, 7);
    ordinsert_rec(&albero, 1);
    ordinsert_rec(&albero, 4);
    print_rec(albero);
    //print_bst2D(albero);
    
    
    return 0;
}

void init(BST **ptrPtr) {
    *ptrPtr = NULL;
}

// funzione di copia/duplicazione a specchio dell'albero in ingresso
void mirror(BST *srcPtr, struct btree **destPtr) {
    // SCRIVETE QUA LA VOSTRA IMPLEMENTAZIONE
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

// inserimento in ordine (con ricorsione) 
void ordinsert_rec(BST **ptrPtr, int val) {
    if((*ptrPtr) != NULL) {
        if(val<=(*ptrPtr)->valore)
            ordinsert_rec(&((*ptrPtr)->leftPtr), val);
        else
            ordinsert_rec(&((*ptrPtr)->rightPtr), val);
    }    
    else {
        (*ptrPtr) = (BST*)malloc(sizeof(BST));
        (*ptrPtr)->valore = val;
        (*ptrPtr)->leftPtr = NULL;
        (*ptrPtr)->rightPtr = NULL;
    }  
}

// funzione di stampa/visualizzazione dell'albero
void print_bst2D_util(BST *root, int space){
    
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print_bst2D_util(root->rightPtr, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->valore);
 
    // Process left child
    print_bst2D_util(root->leftPtr, space);
}

void print_bst2D(BST *root){
    // Pass initial space count as 0
    print_bst2D_util(root, 0);
}