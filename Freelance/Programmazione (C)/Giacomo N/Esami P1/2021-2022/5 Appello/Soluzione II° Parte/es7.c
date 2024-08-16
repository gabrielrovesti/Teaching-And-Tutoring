#include <stdio.h>
#include <stdlib.h>

struct btree {
    int valore;
    struct btree *leftPtr;
    struct btree *rightPtr;
};

typedef struct btree BTree;

int search(BTree *ptr, int val) {
    return (ptr != NULL) ? (ptr->valore == val || search(ptr->leftPtr, val) || search(ptr->rightPtr, val)) : 0;
}