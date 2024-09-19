// esercizi_03_09.c

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Strutture dati
typedef struct BST {
    int value;
    struct BST* left;
    struct BST* right;
    int height;
} BST;

typedef struct List {
    int data;
    struct List* next;
} List;

// Esercizio 1: crea_bst_da_array
BST* create_node(int value) {
    BST* node = (BST*)malloc(sizeof(BST));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

BST* crea_bst_da_array_helper(int* arr, int start, int end) {
    if (start > end) return NULL;

    int mid = (start + end) / 2;
    BST* root = create_node(arr[mid]);

    root->left = crea_bst_da_array_helper(arr, start, mid - 1);
    root->right = crea_bst_da_array_helper(arr, mid + 1, end);

    return root;
}

BST* crea_bst_da_array(int* arr, int size) {
    return crea_bst_da_array_helper(arr, 0, size - 1);
}

// Esercizio 2: updateHeight
int updateHeight(BST* List) {
    if (List == NULL) return -1;
    int leftHeight = updateHeight(List->left);
    int rightHeight = updateHeight(List->right);
    List->height = 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    return List->height;
}

// Esercizio 3: f
void f(List** head) {
    List *slow = *head, *fast = *head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // Operazione con slow
}

// Esercizio 6: merge_sorted_lists
List* merge_sorted_lists(List* l1, List* l2) {
    List dummy;
    List* tail = &dummy;
    
    while (l1 && l2) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

// Esercizio 7: func
void func(int *p, int *q) {
    if (p != q) {
        int tmp = *p;
        *p = *q;
        *q = tmp;
    }
}

// Esercizio 8: pathSum
void pathSum(BST* root, int targetSum, int* currentPath, int pathSize, int** result, int* resultSize) {
    if (!root) return;

    currentPath[pathSize] = root->value;
    pathSize++;

    if (!root->left && !root->right && targetSum == root->value) {
        result[*resultSize] = (int*)malloc(pathSize * sizeof(int));
        for (int i = 0; i < pathSize; i++) {
            result[*resultSize][i] = currentPath[i];
        }
        (*resultSize)++;
    }

    pathSum(root->left, targetSum - root->value, currentPath, pathSize, result, resultSize);
    pathSum(root->right, targetSum - root->value, currentPath, pathSize, result, resultSize);
}

// Esercizio 9: isSymmetric
bool isMirror(BST* left, BST* right) {
    if (!left && !right) return true;
    if (!left || !right) return false;
    return (left->value == right->value) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

bool isSymmetric(BST* root) {
    if (!root) return true;
    return isMirror(root->left, root->right);
}

// Esercizio 10: hasCycle
bool hasCycle(List* head) {
    if (!head || !head->next) return false;
    
    List *slow = head, *fast = head->next;
    
    while (slow != fast) {
        if (!fast || !fast->next) return false;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return true;
}

// Esercizio 11: oddEvenList
List* oddEvenList(List* head) {
    if (!head || !head->next) return head;
    
    List *odd = head, *even = head->next, *evenHead = even;
    
    while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    
    odd->next = evenHead;
    return head;
}

int main() {
    // Test per crea_bst_da_array
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    BST* root = crea_bst_da_array(arr, size);

    // Test per func
    int a[2] = {1, 2};
    func(a, a+1);
    printf("Dopo func: %d %d\n", a[0], a[1]);

    // Altri test possono essere aggiunti qui per le altre funzioni

    return 0;
}