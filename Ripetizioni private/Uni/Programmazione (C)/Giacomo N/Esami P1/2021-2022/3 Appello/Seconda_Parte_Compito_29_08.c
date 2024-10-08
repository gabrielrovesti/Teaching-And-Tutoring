#include <stdio.h>
#include <stdlib.h>

struct nodo{
    float value;
    struct nodo *nextPtr;
}

typedef struct nodo Lista;

//Esercizio 4
void clone_list(Lista *srcPtr, Lista **destPtr){
    Lista *newPtr;
    Lista *precPtr;
    Lista *currPtr;
    Lista *nextPtr;
    newPtr = (Lista *)malloc(sizeof(Lista));
    newPtr->value = srcPtr->value;
    newPtr->nextPtr = NULL;
    precPtr = newPtr;
    currPtr = srcPtr->nextPtr;
    while(currPtr != NULL){
        nextPtr = (Lista *)malloc(sizeof(Lista));
        nextPtr->value = currPtr->value;
        nextPtr->nextPtr = NULL;
        precPtr->nextPtr = nextPtr;
        precPtr = nextPtr;
        currPtr = currPtr->nextPtr;
    }
    *destPtr = newPtr;
}
//Alternativamente
//(inizializzando a parte la lista)
void clone_list (Lista *scrPtr, Lista **destPtr) { 
    if (scrPtr == NULL) *destPtr = NULL; 
    else { 
    (*destPtr) = init(scrPtr->info, scrPtr->next); 
    clone_list (scrPtr->next, &(*destPtr)->next); 
    } 
}

//Esercizio 5
//Scrivere in modo chiaro ed esaustivo la definizione di albero binario di ricerca. Si riporti inoltre un esempio
//concreto che soddisfi tale definizione.

/*
L'albero binario di ricerca  è una struttura di dati ad albero binario basata su nodi che presenta le seguenti proprietà:

Il sottoalbero sinistro di un nodo contiene solo nodi con chiavi inferiori alla chiave del nodo.
Il sottoalbero destro di un nodo contiene solo nodi con chiavi maggiori della chiave del nodo.
I sottoalberi sinistro e destro devono essere anch'essi un albero binario di ricerca.

Esempio utile (spiegato in questo modo):
https://www.javatpoint.com/binary-search-tree 
*/

//Esercizio 6
struct btree{
    int value;
    struct btree *left;
    struct btree *right;
}

typedef struct btree BTree;

void ord_insert(BTree **ptrPtr, int val){
    BTree *newPtr;
    BTree *currPtr;
    BTree *precPtr;
    newPtr = (BTree *)malloc(sizeof(BTree));
    newPtr->value = val;
    newPtr->left = NULL;
    newPtr->right = NULL;
    precPtr = NULL;
    currPtr = *ptrPtr;
    while(currPtr != NULL){
        if(val < currPtr->value){
            precPtr = currPtr;
            currPtr = currPtr->left;
        }
        else{
            precPtr = currPtr;
            currPtr = currPtr->right;
        }
    }
    if(precPtr == NULL){
        *ptrPtr = newPtr;
    }
    else if(val < precPtr->value){
        precPtr->left = newPtr;
    }
    else{
        precPtr->right = newPtr;
    }
}