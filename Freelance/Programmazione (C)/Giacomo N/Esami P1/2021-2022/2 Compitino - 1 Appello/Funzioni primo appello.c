#include <stdio.h>
#include <stdlib.h>

struct nodoLista{
    int valore;
    struct nodoLista *nextPtr;
};

typedef struct nodoLista Lista;

void print_list(Lista* ptr){
    while(ptr != NULL){
        printf("%d ", ptr->valore);
        ptr = ptr->nextPtr;
    }
    printf("\n");
}

void ord_insert(Lista **ptr, int val){
    Lista *newPtr;
    Lista *currentPtr;
    Lista *previousPtr;
    newPtr = (Lista *)malloc(sizeof(Lista));
    newPtr->valore = val;
    newPtr->nextPtr = NULL;
    currentPtr = *ptr;
    previousPtr = NULL;
    while(currentPtr != NULL && currentPtr->valore < val){
        previousPtr = currentPtr;
        currentPtr = currentPtr->nextPtr;
    }
    if(previousPtr == NULL){
        newPtr->nextPtr = *ptr;
        *ptr = newPtr;
    }
    else{
        previousPtr->nextPtr = newPtr;
        newPtr->nextPtr = currentPtr;
    }
}

int main(){
    
}