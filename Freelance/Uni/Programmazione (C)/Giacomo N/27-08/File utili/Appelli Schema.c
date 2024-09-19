#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Strutture dati utilizzate in vari esercizi

struct nodo {
    int valore;
    struct nodo *nextPtr;
};

typedef struct nodo Lista;

struct btree {
    int valore;
    struct btree *leftPtr;
    struct btree *rightPtr;
};

typedef struct btree BST;

// Esercizi su array e matrici

void rimuovi_triple(int *A, int *dim) {
    int i = 1, j;
    while (i < *dim - 1) {
        if ((A[i] == A[i-1]) && (A[i] == A[i+1])) {
            for (j = i; j < *dim - 1; j++)
                A[j] = A[j+1];
            *dim -= 1;
        } else {
            i += 1;
        }
    }
}

void somma_prodotti_inversi(int *X, int dim, int *somma) {
    *somma = 0;
    for (int i = 0, j = dim - 1; i <= j; i++, j--) {
        *somma += X[i] * X[j];
    }
}

void min_max(int *A, int dim, int *i, int *j) {
    *i = 0;
    *j = 0;
    for (int k = 0; k < dim; k++) {
        if (A[k] < A[*i])
            *i = k;
        if (A[k] >= A[*j])
            *j = k;
    }
    if (dim == 0) {
        *i = -1;
        *j = -1;
    }
}

void rimuovi_non_ordinati(int *A, int *dim) {
    int i, j;
    if (*dim <= 1)
        return;
    for (i = 1; i < *dim; i++) {
        if ((A[i] < A[i-1]) && (i < *dim-1)) {
            for (j = i; j < *dim; j++)
                A[j] = A[j+1];
            *dim -= 1;
            i -= 1;
        }
    }
}

// Esercizi su stringhe

void shuffle(char* s1, char* s2, char* r) {
    if (*s1 == '\0' && *s2 == '\0') {
        *r = '\0';
        return;
    }
    if (*s1 != '\0') {
        *r = *s1;
        shuffle(s1 + 1, s2, r + 1);
    }
    if (*s2 != '\0') {
        *r = *s2;
        shuffle(s1, s2 + 1, r + 1);
    }
}

void intToString(int n, char* s) {
    if (n == 0) {
        *s = '0';
        *(s+1) = '\0';
        return;
    }
    int i = 0;
    while (n > 0) {
        s[i++] = (n % 10) + '0';
        n /= 10;
    }
    s[i] = '\0';
    // Reverse the string
    for (int j = 0; j < i/2; j++) {
        char temp = s[j];
        s[j] = s[i-j-1];
        s[i-j-1] = temp;
    }
}

void copia_stringa(char *s1, char *s2) {
    *s1 = *s2;
    if (*s2 != '\0')
        copia_stringa(s1+1, s2+1);
}

// Esercizi su liste

void suf_insert(Lista **ptrPtr, int val) {
    while(*ptrPtr != NULL) {
        ptrPtr = &((*ptrPtr)->nextPtr);
    }
    Lista *tmpPtr = *ptrPtr;
    *ptrPtr = malloc(sizeof(Lista));
    (*ptrPtr)->valore = val;
    (*ptrPtr)->nextPtr = tmpPtr;
}

void clone_list(Lista *srcPtr, Lista **destPtr) {
    if (srcPtr == NULL) {
        *destPtr = NULL;
        return;
    }
    *destPtr = malloc(sizeof(Lista));
    (*destPtr)->valore = srcPtr->valore;
    clone_list(srcPtr->nextPtr, &((*destPtr)->nextPtr));
}

void clone_invlist(Lista *srcPtr, Lista **destPtr) {
    if (srcPtr == NULL) {
        *destPtr = NULL;
        return;
    }
    clone_invlist(srcPtr->nextPtr, destPtr);
    Lista *newNode = malloc(sizeof(Lista));
    newNode->valore = srcPtr->valore;
    newNode->nextPtr = *destPtr;
    *destPtr = newNode;
}

Lista* first_odd(Lista *srcPtr) {
    while (srcPtr != NULL) {
        if (srcPtr->valore % 2 != 0) {
            return srcPtr;
        }
        srcPtr = srcPtr->nextPtr;
    }
    return NULL;
}

void print_list(Lista *ptr) {
    while(ptr != NULL) {
        printf("%d ", ptr->valore);
        ptr = ptr->nextPtr;
    }
    printf("\n");
}

// Versione ricorsiva di print_list in ordine inverso
void print_list_reverse(Lista *ptr) {
    if (ptr == NULL) {
        return;
    }
    print_list_reverse(ptr->nextPtr);
    printf("%d ", ptr->valore);
}

// Esercizi su alberi binari di ricerca

int isbst(BST *ptr) {
    if (ptr == NULL)
        return 1;
    
    if (ptr->leftPtr != NULL && ptr->leftPtr->valore > ptr->valore)
        return 0;
    
    if (ptr->rightPtr != NULL && ptr->rightPtr->valore < ptr->valore)
        return 0;
    
    if (!isbst(ptr->leftPtr) || !isbst(ptr->rightPtr))
        return 0;
    
    return 1;
}

int search(BST *ptr, int val) {
    if (ptr == NULL)
        return 0;
    if (ptr->valore == val)
        return 1;
    if (val < ptr->valore)
        return search(ptr->leftPtr, val);
    else
        return search(ptr->rightPtr, val);
}

void ord_insert(BST **ptrPtr, int val) {
    if (*ptrPtr == NULL) {
        *ptrPtr = malloc(sizeof(BST));
        (*ptrPtr)->valore = val;
        (*ptrPtr)->leftPtr = NULL;
        (*ptrPtr)->rightPtr = NULL;
    } else if (val <= (*ptrPtr)->valore) {
        ord_insert(&((*ptrPtr)->leftPtr), val);
    } else {
        ord_insert(&((*ptrPtr)->rightPtr), val);
    }
}

void delete_node(BST **ptrPtr) {
    BST *temp;
    if ((*ptrPtr)->leftPtr == NULL) {
        temp = *ptrPtr;
        *ptrPtr = (*ptrPtr)->rightPtr;
        free(temp);
    } else if ((*ptrPtr)->rightPtr == NULL) {
        temp = *ptrPtr;
        *ptrPtr = (*ptrPtr)->leftPtr;
        free(temp);
    } else {
        BST **successor = &((*ptrPtr)->rightPtr);
        while ((*successor)->leftPtr != NULL) {
            successor = &((*successor)->leftPtr);
        }
        (*ptrPtr)->valore = (*successor)->valore;
        delete_node(successor);
    }
}

// Funzioni matematiche e ricorsive

int f(int n, int m) {
    if (n == m)
        return n;
    else
        return n * f(n-1, m);
}

int tartagliaRec(int x, int y) {
    if (x == 0 && y == 0)
        return 1;
    else if (y < 0 || x < 0 || y > x)
        return 0;
    else
        return tartagliaRec(x-1, y) + tartagliaRec(x-1, y-1);
}

int array_stesso_ordine(int *A, int sizeA, int *B, int sizeB) {
    if (sizeA <= 0)
        return 1;
    if (sizeB <= 0)
        return 0;
    if (*A == *B || *A == -*B)
        return array_stesso_ordine(A+1, sizeA-1, B+1, sizeB-1);
    else
        return array_stesso_ordine(A, sizeA, B+1, sizeB-1);
}

// Esercizio sulla scacchiera e l'alfiere
#define DIM_X 5
#define DIM_Y 5

int mossa(int campo[DIM_X][DIM_Y], int pos_x, int pos_y) {
    if ((pos_x < 0) || (pos_x > DIM_X-1) || (pos_y < 0) || (pos_y > DIM_Y-1))
        return 0;
    if (campo[pos_x][pos_y] == 0)
        return 0;
    if (pos_x == 0)
        return 1;
    return mossa(campo, pos_x-1, pos_y) + mossa(campo, pos_x, pos_y+1);
}

void mossa_alfiere(int m[8][8], int x, int y) {
    void inizializza(int m[8][8]) {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                m[i][j] = 0;
    }

    int mossa(int m[8][8], int x, int y) {
        if (x >= 0 && x < 8 && y >= 0 && y < 8) {
            m[x][y] = 1;
            return 1;
        }
        return 0;
    }

    int i;
    inizializza(m);
    for (i = 0; mossa(m, x+i, y+i); i++);
    for (i = 0; mossa(m, x-i, y-i); i++);
    for (i = 0; mossa(m, x+i, y-i); i++);
    for (i = 0; mossa(m, x-i, y+i); i++);
}

// Esercizi con enum
enum giorni {Lun, Mar, Mer, Gio, Ven, Sab, Dom};
enum appelli {Gen, Feb, Giu, Lug, Set};

// Funzione per GCD (massimo comun divisore)
int gcd(int p, int q) {
    if (q == 0) return p;
    return gcd(q, p % q);
}

// Funzione per ridurre una frazione ai minimi termini
void minimi_termini(int *num, int *den) {
    int divisore = gcd(*num, *den);
    *num /= divisore;
    *den /= divisore;
}

// Funzione per ruotare un array
void ruota_array(int *arr, int n, int dim) {
    n = n % dim;  // Normalizza n
    int temp[n];
    // Salva i primi n elementi
    for (int i = 0; i < n; i++)
        temp[i] = arr[i];
    // Sposta gli elementi rimanenti
    for (int i = n; i < dim; i++)
        arr[i-n] = arr[i];
    // Inserisce gli elementi salvati alla fine
    for (int i = 0; i < n; i++)
        arr[dim-n+i] = temp[i];
}

// Funzioni con effetti collaterali o che modificano variabili globali
int x = 10;

int fun(int y) {
    static int x = 1;
    x += y;
    return x;
}

// Main di esempio con test e dimostrazioni
int main() {
    // Test per rimuovi_triple
    int arr[] = {1,1,1,2,6,5};
    int dim = 6;
    rimuovi_triple(arr, &dim);
    printf("Dopo rimuovi_triple: ");
    for (int i = 0; i < dim; i++) printf("%d ", arr[i]);
    printf("\n");

    // Test per shuffle
    char s1[] = "abba";
    char s2[] = "ciao";
    char r[9];
    shuffle(s1, s2, r);
    printf("Shuffle result: %s\n", r);

    // Test per clone_list e print_list
    Lista *mylist = NULL;
    suf_insert(&mylist, 24);
    suf_insert(&mylist, 13);
    suf_insert(&mylist, 5);
    suf_insert(&mylist, 29);
    printf("Original list: ");
    print_list(mylist);
    
    Lista *cloned_list = NULL;
    clone_list(mylist, &cloned_list);
    printf("Cloned list: ");
    print_list(cloned_list);

    // Test per BST
    BST *tree = NULL;
    ord_insert(&tree, 5);
    ord_insert(&tree, 3);
    ord_insert(&tree, 7);
    ord_insert(&tree, 1);
    ord_insert(&tree, 9);
    printf("Is BST: %d\n", isbst(tree));
    printf("Search for 7: %d\n", search(tree, 7));

    // Test per funzione matematica
    printf("f(5,2) = %d\n", f(5,2));

    // Test per mossa_alfiere
    int scacchiera[8][8];
    mossa_alfiere(scacchiera, 2, 3);
    printf("Mosse dell'alfiere da (2,3):\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
            printf("%d ", scacchiera[i][j]);
        printf("\n");
    }

    // Test per enum
    enum giorni oggi = Mar;
    printf("Oggi è il giorno numero: %d\n", oggi);

    // Test per minimi_termini
    int num = 24, den = 36;
    minimi_termini(&num, &den);
    printf("Frazione ridotta: %d/%d\n", num, den);

    // Test per ruota_array
    int arr_rotate[] = {1,2,3,4,5};
    ruota_array(arr_rotate, 2, 5);
    printf("Array ruotato: ");
    for (int i = 0; i < 5; i++) printf("%d ", arr_rotate[i]);
    printf("\n");

// Test per funzione con effetti collaterali
    printf("fun(2) = %d\n", fun(2));
    printf("fun(3) = %d\n", fun(3));
    printf("x globale = %d\n", x);

    return 0;
}

// Spiegazioni teoriche e analisi del codice (in forma di commenti)

/*
Pregi e difetti della ricorsione:

Pregi:
1. Eleganza e leggibilità del codice per problemi naturalmente ricorsivi.
2. Semplificazione di algoritmi complessi.
3. Facilità di verifica della correttezza tramite induzione matematica.

Difetti:
1. Maggior consumo di memoria a causa dello stack di chiamate.
2. Possibile inefficienza per problemi con molte chiamate ricorsive.
3. Rischio di stack overflow per ricorsioni profonde.
4. Può essere meno intuitiva per programmatori meno esperti.

Analisi di codice:

Esempio 1:
int x = 10;

int main(void) {
    int y = 2;
    {
        int y = 4;
        if (y>2) {
            int x = 2;
            x += 8;
            printf("%d\n", x/4*2);
        }
        printf("%d %d\n", x, y);
    }
    printf("%d\n", *p);
}

Analisi:
- Alla riga con printf("%d\n", x/4*2), verrà stampato 5 (10/4*2 = 2*2 = 4).
- Alla riga con printf("%d %d\n", x, y), verrà stampato "10 4". La x si riferisce alla variabile globale, mentre y è la variabile locale con valore 4.
- L'ultima printf causerà un errore di compilazione poiché p non è definito.

Esempio 2:
float x = 3.3;

int main(void) {
    int y = 4;
    {
        if (x<3)
            if (y>4)
                printf("%d", y);
            else
                printf("%f", x);
        int y = 5;
        {
            int z = x * 3;
            printf("%d", z);
        }
    }
}

Analisi:
- Il codice stamperà 9. La condizione x<3 è falsa, quindi il blocco if-else viene saltato.
- Nella riga int z = x * 3, il risultato 9.9 viene convertito in intero, diventando 9.

Definizione di Albero Binario di Ricerca (BST):
Un albero binario di ricerca è una struttura dati ad albero binario con le seguenti proprietà:
1. Il sottoalbero sinistro di un nodo contiene solo nodi con chiavi minori della chiave del nodo.
2. Il sottoalbero destro di un nodo contiene solo nodi con chiavi maggiori della chiave del nodo.
3. Entrambi i sottoalberi sinistro e destro devono essere anch'essi alberi binari di ricerca.
4. Non ci sono nodi duplicati.

Esempio di BST:
     5
   /   \
  3     7
 / \   / \
1   4 6   9

Spiegazione dell'aritmetica dei puntatori:
Per accedere all'elemento A[i][j] di un array bidimensionale A[m][n], usando l'aritmetica dei puntatori:
*(A + i*n + j)

Esempio: Per A[5][4] in un array A[6][8], l'espressione sarebbe:
*(A + 5*8 + 4)

Questo funziona perché in memoria, gli elementi dell'array sono disposti in ordine di riga.
*/

// Funzioni aggiuntive per completezza

// Funzione ricorsiva per calcolare il fattoriale
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// Funzione per invertire una stringa ricorsivamente
void inverti_stringa(char *s, int dim) {
    if (dim <= 1) return;
    char temp = s[0];
    s[0] = s[dim-1];
    s[dim-1] = temp;
    inverti_stringa(s+1, dim-2);
}

// Funzione per trovare la somma di due elementi in un array ordinato
void trova_indici_somma(int A[], int dim, int x, int *i, int *j) {
    *i = 0;
    *j = dim - 1;
    while (*i < *j) {
        int somma = A[*i] + A[*j];
        if (somma == x) return;
        if (somma < x) (*i)++;
        else (*j)--;
    }
    *i = -1;
    *j = -1;
}

// Implementazione della funzione che verifica se un array è contenuto in un altro
int array_stesso_ordine(int *A, int sizeA, int *B, int sizeB) {
    if (sizeA == 0) return 1;
    if (sizeB == 0) return 0;
    if (*A == *B || *A == -*B)
        return array_stesso_ordine(A+1, sizeA-1, B+1, sizeB-1);
    return array_stesso_ordine(A, sizeA, B+1, sizeB-1);
}

// Funzione per la visita simmetrica di un BST
void inorder_traversal(BST *root) {
    if (root != NULL) {
        inorder_traversal(root->leftPtr);
        printf("%d ", root->valore);
        inorder_traversal(root->rightPtr);
    }
}

// Funzione per la visita anticipata di un BST
void preorder_traversal(BST *root) {
    if (root != NULL) {
        printf("%d ", root->valore);
        preorder_traversal(root->leftPtr);
        preorder_traversal(root->rightPtr);
    }
}

// Funzione per la visita posticipata di un BST
void postorder_traversal(BST *root) {
    if (root != NULL) {
        postorder_traversal(root->leftPtr);
        postorder_traversal(root->rightPtr);
        printf("%d ", root->valore);
    }
}

// Funzione per calcolare la profondità di un BST
int tree_depth(BST *root) {
    if (root == NULL) return 0;
    int left_depth = tree_depth(root->leftPtr);
    int right_depth = tree_depth(root->rightPtr);
    return (left_depth > right_depth ? left_depth : right_depth) + 1;
}

// Esempio di utilizzo di una struct più complessa
struct student {
    char name[50];
    int age;
    float gpa;
};

// Funzione per stampare i dettagli di uno studente
void print_student(struct student s) {
    printf("Nome: %s, Età: %d, Media: %.2f\n", s.name, s.age, s.gpa);
}

// Esempio di utilizzo nel main
int main() {
    // ... (codice precedente) ...

    // Test per factorial
    printf("Factorial of 5: %d\n", factorial(5));

    // Test per inverti_stringa
    char str[] = "Hello";
    inverti_stringa(str, 5);
    printf("Stringa invertita: %s\n", str);

    // Test per trova_indici_somma
    int arr_sum[] = {1, 3, 4, 5, 7, 9};
    int i, j;
    trova_indici_somma(arr_sum, 6, 10, &i, &j);
    if (i != -1 && j != -1)
        printf("Indici per somma 10: %d e %d\n", i, j);
    else
        printf("Nessuna coppia trovata per somma 10\n");

    // Test per array_stesso_ordine
    int A[] = {1, -3, 2};
    int B[] = {1, 9, 8, 3, 8, 6, 2, 7, 9};
    printf("A è contenuto in B nello stesso ordine: %d\n", array_stesso_ordine(A, 3, B, 9));

    // Test per le visite del BST
    printf("Visita simmetrica del BST: ");
    inorder_traversal(tree);
    printf("\n");

    printf("Visita anticipata del BST: ");
    preorder_traversal(tree);
    printf("\n");

    printf("Visita posticipata del BST: ");
    postorder_traversal(tree);
    printf("\n");

    printf("Profondità del BST: %d\n", tree_depth(tree));

    // Test per struct student
    struct student s1 = {"Mario Rossi", 20, 3.5};
    print_student(s1);

    return 0;
}