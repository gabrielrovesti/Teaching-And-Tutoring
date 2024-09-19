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

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Soluzioni Teoria

// 1. Accesso all'elemento M[1][2] usando l'aritmetica dei puntatori
// Soluzione: *(*(M + 1) + 2)

// 2. Analisi della funzione ricorsiva g(n)
/*
   - Parametro di ricorsione: n
   - Misura di complessità: n
   - La misura decresce perché ad ogni chiamata ricorsiva, n viene diminuito
   - Fattore minimo di decrescita: 1 (nella chiamata g(n-1))
*/

// 3. Il codice stamperà: 5

// 4. Spiegazione della stampa e modifiche in memoria
/*
   printf("%d\n", ***r); stamperà il valore di x (inizialmente 10)
   printf("%p\n", **r); stamperà l'indirizzo di x
   printf("%p\n", *q); stamperà l'indirizzo di x

   Dopo *p = y;, x varrà 20 e printf("%d\n", x); stamperà 20
*/

// 5. Analisi del dangling pointer
/*
   a) Crea un dangling pointer perché restituisce l'indirizzo di una variabile locale
   b) Accesso a memoria non più valida, comportamento indefinito
   c) Allocare memoria dinamicamente e restituire un puntatore a quella
*/

// 6. Analisi del codice con free(p)
/*
   a) q diventa un dangling pointer
   b) Accesso a memoria liberata, comportamento indefinito
   c) Settare q a NULL dopo free(p) e controllare se è NULL prima di dereferenziarlo
*/

// 7. Il codice stamperà: 9

// Soluzioni Esercizi

// 1. Inversione ricorsiva di una lista concatenata
struct Node* reverse_list(struct Node* head) {
    if (head == NULL || head->next == NULL) return head;
    struct Node* rest = reverse_list(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

// 2. Trovare il cammino più lungo in un albero binario
int longest_path(BST* root) {
    if (root == NULL) return 0;
    int left_path = longest_path(root->left);
    int right_path = longest_path(root->right);
    return 1 + (left_path > right_path ? left_path : right_path);
}

// 3. Ricerca efficiente di pattern in un testo (KMP algorithm)
void computeLPSArray(const char* pattern, int M, int* lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int find_pattern(const char* text, const char* pattern) {
    int M = strlen(pattern);
    int N = strlen(text);
    int lps[M];
    computeLPSArray(pattern, M, lps);
    int i = 0, j = 0;
    while (i < N) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }
        if (j == M) {
            return i - j;
        } else if (i < N && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return -1;
}

// 4. Riorganizzazione di un BST sbilanciato
void storeInorder(BST* root, int* arr, int* index) {
    if (root == NULL) return;
    storeInorder(root->left, arr, index);
    arr[(*index)++] = root->value;
    storeInorder(root->right, arr, index);
}

BST* arrayToBST(int* arr, int start, int end) {
    if (start > end) return NULL;
    int mid = (start + end) / 2;
    BST* root = (BST*)malloc(sizeof(BST));
    root->value = arr[mid];
    root->left = arrayToBST(arr, start, mid - 1);
    root->right = arrayToBST(arr, mid + 1, end);
    return root;
}

BST* reorganize_bst(BST* root) {
    int node_count = 0;
    storeInorder(root, NULL, &node_count);
    int* arr = (int*)malloc(sizeof(int) * node_count);
    int index = 0;
    storeInorder(root, arr, &index);
    return arrayToBST(arr, 0, node_count - 1);
}

// 5. Percorso con somma massima in una matrice
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

// 6. Percorso radice-foglia con somma specificata
bool has_path_sum(TreeNode* root, int sum) {
    if (root == NULL) return false;
    if (root->left == NULL && root->right == NULL && root->val == sum)
        return true;
    return has_path_sum(root->left, sum - root->val) ||
           has_path_sum(root->right, sum - root->val);
}

// 7. Trovare il più basso antenato comune
BST* lowest_common_ancestor(BST* root, BST* p, BST* q) {
    if (root == NULL) return NULL;
    if (root == p || root == q) return root;
    BST* left = lowest_common_ancestor(root->left, p, q);
    BST* right = lowest_common_ancestor(root->right, p, q);
    if (left && right) return root;
    return left ? left : right;
}

int main() {
    // Il main è vuoto perché le funzioni sono state implementate come richiesto
    // senza un contesto specifico di esecuzione.
    return 0;
}