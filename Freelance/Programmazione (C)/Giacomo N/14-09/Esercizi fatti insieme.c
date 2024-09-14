#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Strutture dati necessarie
struct Node {
    int data;
    struct Node* next;
};

typedef struct BST {
    int value;
    struct BST* left;
    struct BST* right;
} BST;

// PRE = head, puntatore al primo nodo di una lista
struct Node* reverse_list(struct Node* head){
    if(head == NULL)    return NULL;    // return head;
    if(!head->next)     return head;    // caso base: 1 solo elemento
    else{
        // [1] 2 3 4 5
        // 5 4 3 2 1 

        // 2 [1] 3 4 5
        // 2 1 [3] 4 5
        // ...
        // 2 3 4 5 [1]
        int cont = 0;
        while(head->next){
            head = head->next;
            cont++; // 5 elementi = lunghezza
        }
        struct Node* last = head;
        last = head;
        // salvo la fine
        int limite = cont / 2; // 5 / 2 = 2 (arrotondato per difetto per "int")
        // 1 2 [3] 4 5
        int lunghezza = cont;
        cont = 0;

        while (cont <= limite){
            struct Node* temp = head;
            head = last;
            last = temp;
            
            lunghezza--;
            while(cont < lunghezza){
                head = head->next;
            }      
            last = head;
            head = temp;   
            head = head->next;   
        }  
    }
}
// POST = la funzione ritorna la lista d'origine con i valori "info" invertiti rispetto all'ordine originale
// = da inizio a fine diventa da fine ad inizio
// 0 <= i <= list.length -- ordine inverso

// 30 per lo sforzo - accettiamo il nostro destino 

// Ricorsivo
struct Node* reverse_list(struct Node* head) {
    if (head == NULL || head->next == NULL) return head;
    struct Node* rest = reverse_list(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

// Iterativo
struct Node* reverse_list(struct Node* head) {
    if (head == NULL || head->next == NULL) return head;

    struct node* temp = head; 
    struct node* new_head = NULL;

    // crea un nuovo nodo e lo inserisci all'inizio
    while(temp != NULL){
        struct node* new_node = temp;
        new_node->next = new_head;
        new_head = new_node;
        temp = temp->next;
    }

    // aggiorniamo la testa con quella nuova
    head = new_head;
}

struct Node* reverseList(Node* head) {
    
    // Initialize three pointers: curr, prev and next
    Node *curr = head, *prev = nullptr, *next;

    // Traverse all the nodes of Linked List
    while (curr != nullptr) {
      
        // Store next
        next = curr->next;
      
        // Reverse current node's next pointer
        curr->next = prev;
      
        // Move pointers one position ahead
        prev = curr;
        curr = next;
    }
      
    // Return the head of reversed linked list
    return prev;
}

BST* lowest_common_ancestor(BST* root, BST* p, BST* q) {
    if (root == NULL || !p && !q) return NULL;
    if (root == p || root == q) return root;
    if(p && q) {
        BST* left = lowest_common_ancestor(root->left, p, q);
        BST* right = lowest_common_ancestor(root->right, p, q);
        if(left)    return right;
        if(right)   return left;
        if(left && right) return root;
    }
}

int max_path_sum(int** matrix, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(matrix[i][j+1] > matrix[i+1][j]){
                matrix[i][j] = matrix[i][j+1];
            }
            if(matrix[i+1][j] > matrix[i][j+1]){
                matrix[i][j] = matrix[i+1][j];
            }
        }
    }
    
    return matrix[rows][cols];
}

// Prog. dinamica --> Ho una matrice, in cui posiziono delle celle per salvarmi dentro i risultati
// Ottimizzo salvando la soluzione solo quando mi serve dopo aver inizializzato le celle
// che non andrò a toccare

int max_path_sum(int** matrix, int rows, int cols) {
    int dp[rows][cols];
    dp[0][0] = matrix[0][0];

    for (int i = 1; i < rows; i++)
        dp[i][0] = dp[i-1][0] + matrix[i][0];
    for (int j = 1; j < cols; j++)
        dp[0][j] = dp[0][j-1] + matrix[0][j];

    for (int i = 1; i < rows; i++)
        for (int j = 1; j < cols; j++)
            dp[i][j] = matrix[i][j] + (dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1]);
    
    return dp[rows-1][cols-1];
}

// text = SABBATICO
// pattern = ABBA (da indice 1 a indice 5)

int find_pattern(const char* text, const char* pattern){
    int text_length = strlen(text);
    int pattern_length = strlen(pattern);

    int i = 0, j = 0;
    int pos = 0;
    while(i < text_length && j < pattern_length){
        if(pattern[j] == text[pos]) {
            i++;
            j++;
        }
        else{
            j = 0;
            pos++;
            i = 0;  
        }
        if(j == pattern_length) return pos;
    }
    return -1;
}