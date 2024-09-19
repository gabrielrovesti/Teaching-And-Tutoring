#include <stdio.h>
#include <stdlib.h>

struct nodo{
    float nodo;
    struct nodo *nextptr;
};

struct btree{
    int valore;
    struct btree *leftPtr;
    struct btree *rightPtr;
};

typedef struct btree BTree;
typedef struct nodo Lista;

void clone_list(Lista *srcPtr, Lista **destPtr){
    Lista *newPtr;
    Lista *lastPtr;
    Lista *currentPtr;
    Lista *tempPtr;
    newPtr = (Lista *)malloc(sizeof(Lista));
    newPtr->nodo = srcPtr->nodo;
    newPtr->nextptr = NULL;
    lastPtr = newPtr;
    currentPtr = srcPtr->nextptr;
    while(currentPtr != NULL){
        tempPtr = (Lista *)malloc(sizeof(Lista));
        tempPtr->nodo = currentPtr->nodo;
        tempPtr->nextptr = NULL;
        lastPtr->nextptr = tempPtr;
        lastPtr = tempPtr;
        currentPtr = currentPtr->nextptr;
    }
    *destPtr = newPtr;
}

void clone_list (Lista *scrPtr, Lista **destPtr) { 
    if (scrPtr == NULL) *destPtr = NULL; 
    else { 
    (*destPtr) = init(scrPtr->info, scrPtr->next); 
    clone_list (scrPtr->next, &(*destPtr)->next); 
    } 
}

int search(BTree *ptr, int val){
    if(ptr == NULL){
        return 0;
    }
    if(ptr->valore == val){
        return 1;
    }
    if(ptr->valore > val){
        return search(ptr->leftPtr, val);
    }
    else{
        return search(ptr->rightPtr, val);
    }
}

int main(){
    
}