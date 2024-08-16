#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *nextPtr;
};
typedef struct node Lista;

struct btree{
    int value;
    struct btree *leftPtr;
    struct btree *rightPtr;
};
typedef struct btree BTree;

//La funzione first_odd, ricevuta una lista collegata
//con puntatore, restituisce il puntatore al minimo elemento
//nella lista il cui valore è dispari
Lista* first_odd(Lista *srcPtr){
    Lista *minPtr = NULL;
    Lista *currPtr = srcPtr;
    int min = 0;
    while(currPtr != NULL){
        if(currPtr->value % 2 != 0){
            if(minPtr == NULL){
                minPtr = currPtr;
                min = currPtr->value;
            }else{
                if(currPtr->value < min){
                    minPtr = currPtr;
                    min = currPtr->value;
                }
            }
        }
        currPtr = currPtr->nextPtr;
    }
    return minPtr;
}

//Ora, la stessa funzione, ma ricorsiva
Lista* first_odd_rec(Lista *srcPtr){
    if(srcPtr == NULL){
        return NULL;
    }else{
        if(srcPtr->value % 2 != 0){
            return srcPtr;
        }else{
            return first_odd_rec(srcPtr->nextPtr);
        }
    }
}

//La funzione delete_node effettua la cancellazione mantenendo l'ordine
//e garantendo che l'albero sia effettivamente un BST.
void delete_node(BTree **ptrPtr){
    BTree *currPtr = *ptrPtr;
    BTree *prevPtr = NULL;
    BTree *tempPtr = NULL;
    if(currPtr->leftPtr == NULL && currPtr->rightPtr == NULL){
        free(currPtr);
        *ptrPtr = NULL;
    }else{
        if(currPtr->leftPtr == NULL){
            *ptrPtr = currPtr->rightPtr;
            free(currPtr);
        }else{
            if(currPtr->rightPtr == NULL){
                *ptrPtr = currPtr->leftPtr;
                free(currPtr);
            }else{
                prevPtr = currPtr;
                tempPtr = currPtr->rightPtr;
                while(tempPtr->leftPtr != NULL){
                    prevPtr = tempPtr;
                    tempPtr = tempPtr->leftPtr;
                }
                currPtr->value = tempPtr->value;
                if(prevPtr == currPtr){
                    prevPtr->rightPtr = tempPtr->rightPtr;
                }else{
                    prevPtr->leftPtr = tempPtr->rightPtr;
                }
                free(tempPtr);
            }
        }
    }
}

void delete_node_rec(BTree **ptrPtr){
    BTree *currPtr = *ptrPtr;
    BTree *tempPtr = NULL;
    if(currPtr->leftPtr == NULL && currPtr->rightPtr == NULL){
        free(currPtr);
        *ptrPtr = NULL;
    }else{
        if(currPtr->leftPtr == NULL){
            *ptrPtr = currPtr->rightPtr;
            free(currPtr);
        }else{
            if(currPtr->rightPtr == NULL){
                *ptrPtr = currPtr->leftPtr;
                free(currPtr);
            }else{
                tempPtr = currPtr->rightPtr;
                while(tempPtr->leftPtr != NULL){
                    tempPtr = tempPtr->leftPtr;
                }
                currPtr->value = tempPtr->value;
                delete_node_rec(&(currPtr->rightPtr));
            }
        }
    }
}

int main(int argc, char *argv[]){

}