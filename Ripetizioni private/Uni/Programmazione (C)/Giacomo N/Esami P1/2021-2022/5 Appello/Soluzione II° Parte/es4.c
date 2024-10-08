#include <stdio.h>
#include <stdlib.h>

struct nodo {
    float value; 
    struct nodo *nextPtr;
};

typedef struct nodo Lista;

void pre_insert(Lista **ptr, float val) {
    Lista *tmp = *ptr;
    *ptr = malloc(sizeof(Lista));
    (*ptr)->value = val;
    (*ptr)->nextPtr = tmp;
}

void suf_insert(Lista **ptr, float val) {
    while (*ptr != NULL)
        ptr = &((*ptr)->nextPtr);
    pre_insert(ptr, val);
}

void clone_list_iter(Lista *srcPtr, Lista **destPtr) {
    while (srcPtr != NULL) {
        suf_insert(destPtr, srcPtr->value);
        srcPtr = srcPtr->nextPtr;
    }
}

void clone_list_rec(Lista *srcPtr, Lista **destPtr) {
    if (srcPtr != NULL) {
        suf_insert(destPtr, srcPtr->value);
        clone_list_rec(srcPtr->nextPtr, destPtr);
    }
}