#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definizioni delle strutture dati necessarie

struct nodo {
    int valore;
    struct nodo *next;
};
typedef struct nodo Lista;

struct btree {
    int valore;
    struct btree *left;
    struct btree *right;
};
typedef struct btree BTree;

// Soluzioni teoria

// 1. Accesso all'elemento A[2][3] usando l'aritmetica dei puntatori
// Soluzione: *(*(A+2)+3)

// 2. Analisi della funzione ricorsiva f(n)
// - Parametro di ricorsione: n
// - Misura di complessità: n
// - La misura decresce perché ad ogni chiamata ricorsiva n viene diminuito di 2
// - Fattore minimo di decrescita: 2

// 3. sizeof(struct punto)
// Soluzione: 12 byte

// 4. Output del codice con array bidimensionale
// Soluzione: 7

// 5. Calcolo di T(5) e complessità
// T(5) = 11
// Complessità: O(n)

// 6. Accesso all'elemento 'F' in str
// Soluzione: *(*(str+1)+2)

// 7. sizeof(struct packet)
// Soluzione: 4 byte

// 8. Output e valori dopo l'esecuzione della macro MAX
// Output: 10
// x = 6, y = 11

// 9. Descrizione della funzione f
// La funzione scambia il primo elemento con l'ultimo elemento valido dell'array

// 10. Dichiarazione del puntatore a funzione f
// f è un puntatore a una funzione che prende un int e un char* come parametri e restituisce un int
// Assegnazione: f = &nome_funzione;

// 11. Chiamata della funzione operate
// Addizione: operate(add, x, y);
// Sottrazione: operate(subtract, x, y);

// Implementazioni degli esercizi pratici

void riordina_lista_pivot(Lista **head, int pivot) {
    Lista *minore = NULL, *uguale = NULL, *maggiore = NULL;
    Lista *curr = *head, *next;

    while (curr) {
        next = curr->next;
        curr->next = NULL;

        if (curr->valore < pivot) {
            curr->next = minore;
            minore = curr;
        } else if (curr->valore == pivot) {
            curr->next = uguale;
            uguale = curr;
        } else {
            curr->next = maggiore;
            maggiore = curr;
        }
        curr = next;
    }

    // Ricostruisco la lista
    *head = minore;
    Lista *tail = NULL;

    // Funzione ausiliaria per aggiungere una sottolista alla fine
    void append(Lista **list, Lista *sublist) {
        if (!*list) {
            *list = sublist;
        } else {
            tail->next = sublist;
        }
        if (sublist) {
            while (sublist->next) sublist = sublist->next;
            tail = sublist;
        }
    }

    append(head, uguale);
    append(head, maggiore);
}

// PRE: arr è un array di interi di dimensione size >= 0
// POST: restituisce la somma dei quadrati dei numeri pari in arr
int somma_quadrati_pari(int arr[], int size) {
    if (size == 0) return 0;
    int resto = somma_quadrati_pari(arr + 1, size - 1);
    if (arr[0] % 2 == 0) {
        return arr[0] * arr[0] + resto;
    }
    return resto;
}

// Funzioni ausiliarie per la serializzazione/deserializzazione
int readInt(char **str) {
    int num = 0;
    while (**str >= '0' && **str <= '9') {
        num = num * 10 + (**str - '0');
        (*str)++;
    }
    return num;
}

BTree* deserialize_helper(char **str) {
    if (**str == '\0' || **str == ')') return NULL;

    if (**str == '(') {
        (*str)++;
        int val = readInt(str);
        BTree *node = (BTree*)malloc(sizeof(BTree));
        node->valore = val;
        node->left = deserialize_helper(str);
        if (**str == ',') (*str)++;
        node->right = deserialize_helper(str);
        if (**str == ')') (*str)++;
        return node;
    }
    return NULL;
}

BTree* deserialize(char* str) {
    return deserialize_helper(&str);
}

void serialize_helper(BTree* root, char* str) {
    if (!root) {
        strcat(str, "()");
        return;
    }
    char temp[20];
    sprintf(temp, "(%d", root->valore);
    strcat(str, temp);
    serialize_helper(root->left, str);
    if (root->right) strcat(str, ",");
    serialize_helper(root->right, str);
    strcat(str, ")");
}

char* serialize(BTree* root) {
    char* str = (char*)malloc(1000 * sizeof(char));  // Assumiamo una dimensione massima
    str[0] = '\0';
    serialize_helper(root, str);
    return str;
}

void mirror(BTree* root) {
    if (root == NULL) return;
    
    BTree* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    mirror(root->left);
    mirror(root->right);
}

void min_max(int *A, int dim, int *i, int *j) {
    *i = 0;
    *j = 0;
    
    for (int k = 1; k < dim; k++) {
        if (A[k] < A[*i]) {
            *i = k;
        }
        if (A[k] > A[*j]) {
            *j = k;
        }
    }
}

void mossa_alfiere(int m[][8], int x, int y) {
    // Inizializza tutte le posizioni a 0
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            m[i][j] = 0;
        }
    }
    
    // Marca le posizioni raggiungibili dall'alfiere
    int i, j;
    
    // Diagonale in alto a sinistra
    i = x - 1;
    j = y - 1;
    while (i >= 0 && j >= 0) {
        m[i][j] = 1;
        i--;
        j--;
    }
    
    // Diagonale in alto a destra
    i = x - 1;
    j = y + 1;
    while (i >= 0 && j < 8) {
        m[i][j] = 1;
        i--;
        j++;
    }
    
    // Diagonale in basso a sinistra
    i = x + 1;
    j = y - 1;
    while (i < 8 && j >= 0) {
        m[i][j] = 1;
        i++;
        j--;
    }
    
    // Diagonale in basso a destra
    i = x + 1;
    j = y + 1;
    while (i < 8 && j < 8) {
        m[i][j] = 1;
        i++;
        j++;
    }
    
    // Marca la posizione corrente dell'alfiere
    m[x][y] = 1;
}

// Funzione main per test
int main() {
    // Test per riordina_lista_pivot
    Lista *head = NULL;
    int values[] = {3, 5, 8, 2, 1, 9, 4, 5, 7};
    for (int i = 8; i >= 0; i--) {
        Lista *new_node = (Lista*)malloc(sizeof(Lista));
        new_node->valore = values[i];
        new_node->next = head;
        head = new_node;
    }

    printf("Lista originale: ");
    for (Lista *curr = head; curr; curr = curr->next) {
        printf("%d ", curr->valore);
    }
    printf("\n");

    riordina_lista_pivot(&head, 5);

    printf("Lista riordinata: ");
    for (Lista *curr = head; curr; curr = curr->next) {
        printf("%d ", curr->valore);
    }
    printf("\n");

    // Test per somma_quadrati_pari
    int arr[] = {1, 2, 3, 4, 5};
    printf("Somma quadrati pari: %d\n", somma_quadrati_pari(arr, 5));

    // Test per serializzazione/deserializzazione
    char *str = "(1,(2),((3,(4),(5))))";
    BTree *root = deserialize(str);
    char *serialized = serialize(root);
    printf("Albero serializzato: %s\n", serialized);

    free(serialized);
    // Liberare la memoria allocata per l'albero e la lista

    return 0;
}