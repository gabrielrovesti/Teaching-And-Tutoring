#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Strutture dati
typedef struct nodo {
    int info;
    struct nodo* left;
    struct nodo* right;
} nodo;

typedef struct Lista {
    int info;
    struct Lista* next;
} nodo_lista;

// Funzioni per l'esercizio del cammino da radice a foglia
bool cerca_cam(nodo* r, int k, int y, int* C) {
    if (!r) return false;
    
    if (r->info == y) k--;
    
    if (!r->left && !r->right) {
        if (k == 0) {
            *C = -1;
            return true;
        }
        return false;
    }
    
    if (cerca_cam(r->left, k, y, C+1)) {
        *C = 0;
        return true;
    }
    
    if (cerca_cam(r->right, k, y, C+1)) {
        *C = 1;
        return true;
    }
    
    return false;
}

// Funzioni per l'esercizio di pattern matching su liste
nodo_lista* match_aux(nodo_lista* n, int* P, int dimP, int index) {
    if (!n || index == dimP) return n;
    if (n->info != P[index]) return NULL;
    return match_aux(n->next, P, dimP, index + 1);
}

nodo_lista* match(nodo_lista** n, int* P, int dimP) {
    if (!*n) return NULL;
    
    nodo_lista* result = match_aux(*n, P, dimP, 0);
    if (result) {
        nodo_lista* match_start = *n;
        for (int i = 0; i < dimP - 1; i++) {
            match_start = match_start->next;
        }
        *n = result;
        match_start->next = NULL;
        return match_start;
    }
    
    nodo_lista* next_match = match(&((*n)->next), P, dimP);
    if (next_match) return next_match;
    
    return NULL;
}

// Funzioni di utilità
nodo* create_node(int value) {
    nodo* new_node = (nodo*)malloc(sizeof(nodo));
    new_node->info = value;
    new_node->left = new_node->right = NULL;
    return new_node;
}

nodo_lista* create_list_node(int value) {
    nodo_lista* new_node = (nodo_lista*)malloc(sizeof(nodo_lista));
    new_node->info = value;
    new_node->next = NULL;
    return new_node;
}

void print_tree(nodo* root) {
    if (root) {
        printf("%d ", root->info);
        print_tree(root->left);
        print_tree(root->right);
    }
}

void print_list(nodo_lista* head) {
    while (head) {
        printf("%d -> ", head->info);
        head = head->next;
    }
    printf("NULL\n");
}

void print_path(int* C) {
    int i = 0;
    while (C[i] != -1) {
        printf("%d", C[i]);
        i++;
    }
    printf("-1\n");
}

int main() {
    // Test per cerca_cam
    nodo* root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(1);
    root->left->left = create_node(1);
    root->left->right = create_node(1);
    root->right->left = create_node(2);
    
    printf("Albero: ");
    print_tree(root);
    printf("\n");
    
    int C[100];
    int k = 2, y = 1;
    
    bool result = cerca_cam(root, k, y, C);
    if (result) {
        printf("Cammino trovato: ");
        print_path(C);
    } else {
        printf("Nessun cammino trovato\n");
    }
    
    // Test per match
    nodo_lista* list = create_list_node(3);
    list->next = create_list_node(2);
    list->next->next = create_list_node(1);
    list->next->next->next = create_list_node(3);
    list->next->next->next->next = create_list_node(0);
    list->next->next->next->next->next = create_list_node(0);
    list->next->next->next->next->next->next = create_list_node(1);
    
    printf("Lista originale: ");
    print_list(list);
    
    int P[] = {3, 0, 0};
    int dimP = 3;
    
    nodo_lista* matched = match(&list, P, dimP);
    
    if (matched) {
        printf("Pattern trovato: ");
        print_list(matched);
        printf("Resto della lista: ");
        print_list(list);
    } else {
        printf("Pattern non trovato\n");
    }
    
    return 0;
}