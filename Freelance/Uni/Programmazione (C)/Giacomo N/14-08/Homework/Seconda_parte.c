#include <stdio.h>
#include <stdlib.h>

// Definizioni delle strutture dati

struct nodo {
    float value;
    struct nodo *nextPtr;
};

typedef struct nodo Lista;

struct btree {
    int value;
    struct btree *leftPtr;
    struct btree *rightPtr;
};

typedef struct btree BTree;

// Esercizio 4: Funzione ricorsiva clone_list

void clone_list(Lista *srcPtr, Lista **destPtr) {
    if (srcPtr == NULL) {
        *destPtr = NULL;
        return;
    }
    
    *destPtr = (Lista*)malloc(sizeof(Lista));
    if (*destPtr == NULL) {
        // Gestione errore di allocazione
        exit(1);
    }
    
    (*destPtr)->value = srcPtr->value;
    clone_list(srcPtr->nextPtr, &((*destPtr)->nextPtr));
}

// Esercizio 5: Definizione di albero binario di ricerca

/*
Un albero binario di ricerca è una struttura dati ad albero binario che soddisfa le seguenti proprietà:

1. Il sottoalbero sinistro di un nodo contiene solo nodi con chiavi minori della chiave del nodo.
2. Il sottoalbero destro di un nodo contiene solo nodi con chiavi maggiori della chiave del nodo.
3. Entrambi i sottoalberi sinistro e destro devono essere anch'essi alberi binari di ricerca.
4. Non ci sono nodi con chiavi duplicate.

Esempio concreto:

       8
     /   \
    3    10
   / \     \
  1   6    14
     / \   /
    4   7 13

Questo è un albero binario di ricerca valido perché ogni nodo rispetta le proprietà sopra elencate.
*/

// Esercizio 6: Funzione ricorsiva ord_insert

void ord_insert(BTree **ptrPtr, int val) {
    if (*ptrPtr == NULL) {
        *ptrPtr = (BTree*)malloc(sizeof(BTree));
        if (*ptrPtr == NULL) {
            // Gestione errore di allocazione
            exit(1);
        }
        (*ptrPtr)->value = val;
        (*ptrPtr)->leftPtr = NULL;
        (*ptrPtr)->rightPtr = NULL;
    } else if (val < (*ptrPtr)->value) {
        ord_insert(&((*ptrPtr)->leftPtr), val);
    } else if (val > (*ptrPtr)->value) {
        ord_insert(&((*ptrPtr)->rightPtr), val);
    }
    // Se val è uguale al valore del nodo corrente, non facciamo nulla
    // per mantenere la proprietà di unicità delle chiavi
}

// Main di esempio per testare le funzioni

int main() {
    // Test clone_list
    Lista *original = NULL;
    Lista *clone = NULL;
    
    // Creazione lista originale
    // ...

    clone_list(original, &clone);

    // Test ord_insert
    BTree *root = NULL;
    ord_insert(&root, 8);
    ord_insert(&root, 3);
    ord_insert(&root, 10);
    ord_insert(&root, 1);
    ord_insert(&root, 6);
    ord_insert(&root, 14);
    ord_insert(&root, 4);
    ord_insert(&root, 7);
    ord_insert(&root, 13);

    return 0;
}