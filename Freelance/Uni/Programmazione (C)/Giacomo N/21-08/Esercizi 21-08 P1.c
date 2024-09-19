#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Strutture dati necessarie
struct node {
    int value;
    struct node *nextPtr;
};
typedef struct node List;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define N 4
#define MAX 100

// 1. Esercizio sulle liste concatenate
List* remove_even(List *head) {
    if (head == NULL) return NULL;
    
    head->nextPtr = remove_even(head->nextPtr);
    
    if (head->value % 2 == 0) {
        List *temp = head->nextPtr;
        free(head);
        return temp;
    }
    
    return head;
}

// 3. Esercizio sulle matrici
void rotate_matrix(int matrix[N][N]) {
    // Trasponi la matrice
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    
    // Inverti ogni riga
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N/2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][N-1-j];
            matrix[i][N-1-j] = temp;
        }
    }
}

// 4. Esercizio sulla ricorsione
int find_path(int maze[MAX][MAX], int n, int m, int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m || maze[x][y] == 1) return 0;
    if (x == n-1 && y == m-1) return 1;
    
    maze[x][y] = 1;  // Marca come visitato
    
    int found = find_path(maze, n, m, x+1, y) || 
                find_path(maze, n, m, x-1, y) ||
                find_path(maze, n, m, x, y+1) || 
                find_path(maze, n, m, x, y-1);
    
    maze[x][y] = 0;  // Ripristina
    return found;
}

// 5. Esercizio sulle stringhe e puntatori
void reverse_words(char *str) {
    int len = strlen(str);
    
    // Inverti l'intera stringa
    for (int i = 0; i < len/2; i++) {
        char temp = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = temp;
    }
    
    // Inverti ogni parola
    char *start = str;
    for (char *end = str; *end; end++) {
        if (*end == ' ') {
            for (char *i = start, *j = end-1; i < j; i++, j--) {
                char temp = *i;
                *i = *j;
                *j = temp;
            }
            start = end + 1;
        }
    }
    
    // Inverti l'ultima parola
    for (char *i = start, *j = str+len-1; i < j; i++, j--) {
        char temp = *i;
        *i = *j;
        *j = temp;
    }
}

// 6. Esercizio sulla ricorsione e backtracking
void generate_parentheses(int n, char* current, int open, int close, int index) {
    if (index == 2*n) {
        current[index] = '\0';
        printf("%s\n", current);
        return;
    }
    
    if (open < n) {
        current[index] = '(';
        generate_parentheses(n, current, open+1, close, index+1);
    }
    
    if (close < open) {
        current[index] = ')';
        generate_parentheses(n, current, open, close+1, index+1);
    }
}

// 7. Esercizio su alberi binari
bool isMirror(struct TreeNode* left, struct TreeNode* right) {
    if (left == NULL && right == NULL) return true;
    if (left == NULL || right == NULL) return false;
    
    return (left->val == right->val) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

bool is_symmetric(struct TreeNode* root) {
    if (root == NULL) return true;
    return isMirror(root->left, root->right);
}

// 8. Esercizio su array e ordinamento
int* merge_sorted_arrays(int* arr1, int size1, int* arr2, int size2, int* result_size) {
    *result_size = size1 + size2;
    int* result = (int*)malloc(*result_size * sizeof(int));
    
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }
    
    while (i < size1) result[k++] = arr1[i++];
    while (j < size2) result[k++] = arr2[j++];
    
    return result;
}

// Main function per test
int main() {
    // Test delle funzioni qui
    return 0;
}