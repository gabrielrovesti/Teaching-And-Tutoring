#include <stdio.h>
#include <stdlib.h>

// Definizione delle strutture dati

typedef struct BTree {
    int value;
    struct BTree* left;
    struct BTree* right;
} BTree;

typedef struct Lista {
    int value;
    struct Lista* next;
} Lista;

// 1. Potatura dell'albero

/* 
PRE: root è un puntatore valido a un albero binario (può essere NULL), k è un intero
POST: Restituisce un puntatore all'albero potato, dove tutti i nodi con valore < k sono stati rimossi
*/

// Versione ricorsiva
BTree* prune_tree_recursive(BTree* root, int k) {
    if (root == NULL) return NULL;
    
    root->left = prune_tree_recursive(root->left, k);
    root->right = prune_tree_recursive(root->right, k);
    
    if (root->value < k) {
        BTree* temp = root->right ? root->right : root->left;
        free(root);
        return temp;
    }
    
    return root;
}

// Versione iterativa
BTree* prune_tree_iterative(BTree* root, int k) {
    if (root == NULL) return NULL;
    
    BTree* dummy = malloc(sizeof(BTree));
    dummy->left = root;
    
    BTree* current = dummy;
    while (current) {
        if (current->left && current->left->value < k) {
            BTree* temp = current->left;
            current->left = temp->right ? temp->right : temp->left;
            free(temp);
        } else if (current->right && current->right->value < k) {
            BTree* temp = current->right;
            current->right = temp->right ? temp->right : temp->left;
            free(temp);
        } else {
            current = current->left ? current->left : current->right;
        }
    }
    
    BTree* result = dummy->left;
    free(dummy);
    return result;
}

// 2. Conteggio percorsi con somma data

/*
PRE: root è un puntatore valido a un albero binario (può essere NULL), sum è un intero
POST: Restituisce il numero di percorsi nell'albero la cui somma dei valori dei nodi è uguale a sum
*/

// Versione ricorsiva
int count_paths_recursive_helper(BTree* root, int sum, int current_sum) {
    if (root == NULL) return 0;
    
    current_sum += root->value;
    int count = (current_sum == sum) ? 1 : 0;
    
    count += count_paths_recursive_helper(root->left, sum, current_sum);
    count += count_paths_recursive_helper(root->right, sum, current_sum);
    
    return count;
}

int count_paths_with_sum_recursive(BTree* root, int sum) {
    if (root == NULL) return 0;
    
    return count_paths_recursive_helper(root, sum, 0) +
           count_paths_with_sum_recursive(root->left, sum) +
           count_paths_with_sum_recursive(root->right, sum);
}

// Versione iterativa (utilizzando una pila)
#define MAX_SIZE 1000

int count_paths_with_sum_iterative(BTree* root, int sum) {
    if (root == NULL) return 0;
    
    int count = 0;
    BTree* stack[MAX_SIZE];
    int top = -1;
    int sum_stack[MAX_SIZE];
    
    stack[++top] = root;
    sum_stack[top] = 0;
    
    while (top >= 0) {
        BTree* current = stack[top];
        int current_sum = sum_stack[top--];
        
        current_sum += current->value;
        if (current_sum == sum) count++;
        
        if (current->right) {
            stack[++top] = current->right;
            sum_stack[top] = current_sum;
        }
        if (current->left) {
            stack[++top] = current->left;
            sum_stack[top] = current_sum;
        }
    }
    
    return count;
}

// 3. Diametro dell'albero

/*
PRE: root è un puntatore valido a un albero binario (può essere NULL)
POST: Restituisce la lunghezza del percorso più lungo tra due foglie nell'albero
*/

// Versione ricorsiva
int height(BTree* node) {
    if (node == NULL) return 0;
    return 1 + max(height(node->left), height(node->right));
}

int diameter_of_tree_recursive(BTree* root) {
    if (root == NULL) return 0;
    
    int left_height = height(root->left);
    int right_height = height(root->right);
    
    int left_diameter = diameter_of_tree_recursive(root->left);
    int right_diameter = diameter_of_tree_recursive(root->right);
    
    return max(left_height + right_height + 1, max(left_diameter, right_diameter));
}

// Versione iterativa
int diameter_of_tree_iterative(BTree* root) {
    if (root == NULL) return 0;
    
    int max_diameter = 0;
    BTree* stack[MAX_SIZE];
    int heights[MAX_SIZE] = {0};
    int top = -1;
    
    stack[++top] = root;
    
    while (top >= 0) {
        BTree* current = stack[top];
        
        if (current->left && heights[top * 2 + 1] == 0) {
            stack[++top] = current->left;
            continue;
        }
        
        if (current->right && heights[top * 2 + 2] == 0) {
            stack[++top] = current->right;
            continue;
        }
        
        int left_height = current->left ? heights[top * 2 + 1] : 0;
        int right_height = current->right ? heights[top * 2 + 2] : 0;
        
        heights[top] = 1 + max(left_height, right_height);
        max_diameter = max(max_diameter, left_height + right_height + 1);
        
        top--;
    }
    
    return max_diameter;
}

// 4. Rotazione della matrice

/*
PRE: m è una matrice quadrata NxN, n è la dimensione della matrice
POST: La matrice m è ruotata di 90 gradi in senso orario
*/

// Versione ricorsiva
void rotate_matrix_recursive_helper(int m[][N], int start, int end) {
    if (start >= end) return;
    
    for (int i = 0; i < end - start; i++) {
        int temp = m[start][start + i];
        m[start][start + i] = m[end - i][start];
        m[end - i][start] = m[end][end - i];
        m[end][end - i] = m[start + i][end];
        m[start + i][end] = temp;
    }
    
    rotate_matrix_recursive_helper(m, start + 1, end - 1);
}

void rotate_matrix_recursive(int m[][N], int n) {
    rotate_matrix_recursive_helper(m, 0, n - 1);
}

// Versione iterativa
void rotate_matrix_iterative(int m[][N], int n) {
    for (int layer = 0; layer < n / 2; layer++) {
        int first = layer;
        int last = n - 1 - layer;
        for (int i = first; i < last; i++) {
            int offset = i - first;
            int top = m[first][i];
            m[first][i] = m[last - offset][first];
            m[last - offset][first] = m[last][last - offset];
            m[last][last - offset] = m[i][last];
            m[i][last] = top;
        }
    }
}

// 5. Ordine spirale

/*
PRE: m è una matrice rows x cols, result è un array di dimensione rows * cols
POST: result contiene gli elementi di m in ordine spirale
*/

void spiral_order(int m[][N], int rows, int cols, int result[]) {
    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
    int index = 0;
    
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++)
            result[index++] = m[top][i];
        top++;
        
        for (int i = top; i <= bottom; i++)
            result[index++] = m[i][right];
        right--;
        
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                result[index++] = m[bottom][i];
            bottom--;
        }
        
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                result[index++] = m[i][left];
            left++;
        }
    }
}

// 6. Conteggio isole

/*
PRE: matrix è una matrice binaria rows x cols
POST: Restituisce il numero di isole nella matrice
*/

// Versione ricorsiva
void dfs_recursive(int matrix[][N], int rows, int cols, int i, int j) {
    if (i < 0 || i >= rows || j < 0 || j >= cols || matrix[i][j] == 0)
        return;
    
    matrix[i][j] = 0;
    
    dfs_recursive(matrix, rows, cols, i - 1, j);
    dfs_recursive(matrix, rows, cols, i + 1, j);
    dfs_recursive(matrix, rows, cols, i, j - 1);
    dfs_recursive(matrix, rows, cols, i, j + 1);
}

int count_islands_recursive(int matrix[][N], int rows, int cols) {
    int count = 0;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 1) {
                count++;
                dfs_recursive(matrix, rows, cols, i, j);
            }
        }
    }
    
    return count;
}

// Versione iterativa
int count_islands_iterative(int matrix[][N], int rows, int cols) {
    int count = 0;
    int stack[MAX_SIZE][2];
    int top = -1;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 1) {
                count++;
                stack[++top][0] = i;
                stack[top][1] = j;
                
                while (top >= 0) {
                    int x = stack[top][0];
                    int y = stack[top--][1];
                    
                    if (x < 0 || x >= rows || y < 0 || y >= cols || matrix[x][y] == 0)
                        continue;
                    
                    matrix[x][y] = 0;
                    
                    stack[++top][0] = x - 1; stack[top][1] = y;
                    stack[++top][0] = x + 1; stack[top][1] = y;
                    stack[++top][0] = x; stack[top][1] = y - 1;
                    stack[++top][0] = x; stack[top][1] = y + 1;
                }
            }
        }
    }
    
    return count;
}

// 7. Segregazione pari/dispari

/*
PRE: head è un puntatore a un puntatore alla testa di una lista concatenata
POST: La lista è riordinata in modo che tutti i nodi pari vengano prima dei nodi dispari, mantenendo l'ordine relativo originale
*/

// Versione ricorsiva
void segregate_even_odd_recursive(Lista** head) {
    if (*head == NULL || (*head)->next == NULL) return;
    
    Lista* odd = NULL;
    Lista* even = NULL;
    Lista* odd_tail = NULL;
    Lista* even_tail = NULL;
    
    while (*head) {
        if ((*head)->value % 2 == 0) {
            if (even == NULL) {
                even = *head;
                even_tail = even;
            } else {
                even_tail->next = *head;
                even_tail = even_tail->next;
            }
        } else {
            if (odd == NULL) {
                odd = *head;
                odd_tail = odd;
            } else {
                odd_tail->next = *head;
                odd_tail = odd_tail->next;
            }
        }
        *head = (*head)->next;
    }
    
    if (even_tail) even_tail->next = odd;
    if (odd_tail) odd_tail->next = NULL;
    
    *head = even ? even : odd;
}

// Versione iterativa
void segregate_even_odd_iterative(Lista** head) {
    if (*head == NULL || (*head)->next == NULL) return;
    
    Lista* odd = NULL;
    Lista* even = NULL;
    Lista* odd_tail = NULL;
    Lista* even_tail = NULL;
    Lista* current = *head;
    
    while (current) {
        if (current->value % 2 == 0) {
            if (even == NULL) {
                even = current;
                even_tail = even;
            } else {
                even_tail->next = current;
                even_tail = even_tail->next;
            }
        } else {
            if (odd == NULL) {
                odd = current;
                odd_tail = odd;
            } else {
                odd_tail->next = current;
                odd_tail = odd_tail->next;
            }
        }
        current = current->next;
    }
    
    if (even_tail) even_tail->next = odd;
    if (odd_tail) odd_tail->next = NULL;
    
    *head = even ? even : odd;
}

// 8. Rendere palindroma una lista

/*
PRE: head è un puntatore a un puntatore alla testa di una lista concatenata
POST: La lista è riordinata in modo da essere palindroma
*/

// Funzioni di supporto
Lista* reverse_list(Lista* head) {
    Lista* prev = NULL;
    Lista* current = head;
    Lista* next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}

Lista* find_middle(Lista* head) {
    Lista* slow = head;
    Lista* fast = head;
    
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

// Continua da make_palindrome_recursive
void make_palindrome_recursive(Lista** head) {
    if (*head == NULL || (*head)->next == NULL) return;
    
    Lista* middle = find_middle(*head);
    Lista* second_half = middle->next;
    middle->next = NULL;
    
    second_half = reverse_list(second_half);
    
    Lista* first = *head;
    Lista* second = second_half;
    
    while (second != NULL) {
        Lista* temp = second->next;
        second->next = first->next;
        first->next = second;
        first = first->next->next;
        second = temp;
    }
}

// Versione iterativa
void make_palindrome_iterative(Lista** head) {
    if (*head == NULL || (*head)->next == NULL) return;
    
    Lista* middle = find_middle(*head);
    Lista* second_half = middle->next;
    middle->next = NULL;
    
    second_half = reverse_list(second_half);
    
    Lista* first = *head;
    Lista* second = second_half;
    
    while (second != NULL) {
        Lista* temp = first->next;
        first->next = second;
        second = second->next;
        first->next->next = temp;
        first = temp;
    }
}

// 9. Rimozione elementi in un intervallo

/*
PRE: head è un puntatore a un puntatore alla testa di una lista concatenata, start e end sono interi che definiscono l'intervallo (inclusi)
POST: Tutti gli elementi della lista con valori compresi tra start e end (inclusi) sono rimossi
*/

// Versione ricorsiva
void remove_range_recursive(Lista** head, int start, int end) {
    if (*head == NULL) return;
    
    if ((*head)->value >= start && (*head)->value <= end) {
        Lista* temp = *head;
        *head = (*head)->next;
        free(temp);
        remove_range_recursive(head, start, end);
    } else {
        remove_range_recursive(&((*head)->next), start, end);
    }
}

// Versione iterativa
void remove_range_iterative(Lista** head, int start, int end) {
    while (*head != NULL && (*head)->value >= start && (*head)->value <= end) {
        Lista* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    
    if (*head == NULL) return;
    
    Lista* current = *head;
    while (current->next != NULL) {
        if (current->next->value >= start && current->next->value <= end) {
            Lista* temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

// Funzione main per test
int main() {
    // Qui puoi inserire il codice per testare le funzioni implementate
    return 0;
}