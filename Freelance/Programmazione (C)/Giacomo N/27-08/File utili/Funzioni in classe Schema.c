#include <stdio.h>
#include <stdlib.h>

// Strutture dati
struct nodo {
    int info;
    struct nodo *next;
};

struct nodoD {
    int info;
    struct nodoD* prev;
    struct nodoD* next;
};

// ---- LISTE ----

struct nodo* new_nodo(int info) {
    struct nodo *temp = (struct nodo*)malloc(sizeof(struct nodo));
    temp->info = info;
    temp->next = NULL;
    return temp;
}

int isempty(struct nodo* ptr) {
    return ptr == NULL ? 1 : 0;
}

void print_list(struct nodo* ptr) {
    if (isempty(ptr) == 1) {
        printf("Vuota\n");
    } else {
        while (isempty(ptr) == 0) {
            printf("%d ", ptr->info);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void pre_insert(struct nodo** pptr, int val) {
    struct nodo* nuovo = new_nodo(val);
    nuovo->next = *pptr;
    *pptr = nuovo;
}

void suf_insert(struct nodo** pptr, int val) {
    struct nodo* nuovo = new_nodo(val);
    while (isempty(*pptr) == 0) {
        pptr = &((*pptr)->next);
    }
    *pptr = nuovo;
}

int lung(struct nodo* ptr) {
    return (isempty(ptr) == 1) ? 0 : 1 + lung(ptr->next);
}

int get(struct nodo* ptr, int pos) {
    while (pos != 0) {
        ptr = ptr->next;
        pos--;
    }
    return ptr->info;
}

void modifica(struct nodo** ptr, int pos, int val) {
    while (pos != 0) {
        ptr = &((*ptr)->next);
        pos--;
    }
    (*ptr)->info = val;
}

struct nodo* insert(struct nodo* ptr, int pos, int info) {
    struct nodo* nodo = new_nodo(info);
    if (ptr == NULL) return nodo;
    if (pos == 0) {
        nodo->next = ptr;
        return nodo;
    }
    struct nodo* current = ptr;
    while (pos != 1) {
        current = current->next;
        pos--;
    }
    nodo->next = current->next;
    current->next = nodo;
    return ptr;
}

struct nodo* delete(struct nodo* ptr, int pos) {
    if (ptr == NULL) return ptr;
    if (pos == 0) {
        struct nodo* next = ptr->next;
        free(ptr);
        return next;
    }
    struct nodo* current = ptr;
    while (pos != 1) {
        current = current->next;
        pos--;
    }
    struct nodo* next = current->next->next;
    free(current->next);
    current->next = next;
    return ptr;
}

struct nodo* filter(struct nodo* ptr, int thres) {
    struct nodo* list = NULL;
    int val;
    for (int i = 0; i < lung(ptr); i++) {
        val = get(ptr, i);
        if (val >= thres) suf_insert(&list, val);
    }
    return list;
}

void reverse_list(struct nodo **ptr) {
    if (*ptr != NULL && (*ptr)->next != NULL) {
        struct nodo* old_first = (*ptr)->next;
        reverse_list(&((*ptr)->next));
        old_first->next = *ptr;
        *ptr = (*ptr)->next;
        old_first->next->next = NULL;
    }
}

// ---- LISTE DOPPIAMENTE CONCATENATE ----

void insert_dlist(struct nodoD **first, struct nodoD **last, int pos, int info) {
    if (pos == 0) {
        struct nodoD* tmp = malloc(sizeof(struct nodoD));
        tmp->info = info;
        tmp->prev = NULL;
        tmp->next = *first;
        if (*first != NULL) {
            (*first)->prev = tmp;
        } else *last = tmp;
        *first = tmp;
    } else {
        insert_dlist(&((*first)->next), last, pos-1, info);
        (*first)->next->prev = (*first);
    }
}

void print_forward(struct nodoD* first) {
    if (first == NULL) printf("Vuota\n");
    else {
        while (first != NULL) {
            printf("%d ", first->info);
            first = first->next;
        }
        printf("\n");
    }
}

void print_backward(struct nodoD* last) {
    if (last == NULL) printf("Vuota\n");
    else {
        while (last != NULL) {
            printf("%d ", last->info);
            last = last->prev;
        }
        printf("\n");
    }
}

void reverse_dlist(struct nodoD **first, struct nodoD **last) {
    struct nodoD *ptr = *first;
    while (ptr != NULL) {
        struct nodoD *tmp = ptr->next;
        ptr->next = ptr->prev;
        ptr->prev = tmp;
        ptr = tmp;
    }
    struct nodoD *tmp = *first;
    *first = *last;
    *last = tmp;
}

// ---- ARRAY E MATRICI ----

int confronta_array(int *X, int *Y, int dim) {
    for (int i = 0; i < dim; i++) {
        if (X[i] != Y[i]) return 0;
    }
    return 1;
}

void inverti(int *A, int dim) {
    int tmp;
    for (int i = 0; i < dim/2; i++) {
        tmp = A[i];
        A[i] = A[dim-1-i];
        A[dim-1-i] = tmp;
    }
}

void min_max(int *A, int dim, int *i, int *j) {
    *i = 0, *j = 0; 
    for (int k = 1; k < dim; k++) {
        if (A[k] < A[*i]) *i = k;
        if (A[k] > A[*j]) *j = k;
    }
}

void incrementa_array(int* A, int length, int x, int pos) {
    for (int i = length-1; i > pos; i--) {
        A[i] = A[i-1];
    }
    A[pos] = x;
}

void somma_prodotti_inversi(int *X, int dim, int *somma) {
    *somma = 0;
    for (int i = 0; i < dim/2; i++) {
        *somma += X[i] * X[dim-1-i];
    }
    if ((dim % 2) == 1) 
        *somma += X[dim/2] * X[dim/2];
}

int confronta_matrici_double(double *Matrice1, double* Matrice2, int righe1, int colonne1, int righe2, int colonne2, double toll) {
    if(righe1 != righe2 || colonne1 != colonne2)
        return 0;
    else
        return confronta_array_double(Matrice1, Matrice2, righe1*colonne1, toll);
}

void moltiplica_matrici(int dim, int *mat1, int *mat2, int *matRisultato) {
    for(int i = 0; i < dim; i++) {
        for(int j = 0; j < dim; j++) {
            int scalare = 0;
            for(int k = 0; k < dim; k++) {
                scalare += (*((mat1+i*dim)+k)) * (*((mat2+k*dim)+j));
            }
            *(matRisultato+i*dim+j) = scalare;
        }
    }
}

// ---- ALGORITMI DI ORDINAMENTO E RICERCA ----

int partition(int A[], int low, int high) {
    int pivot = A[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (A[j] <= pivot) {
            i++;
            int t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }
    int t = A[i+1];
    A[i+1] = A[high];
    A[high] = t;
    return (i + 1);
}

void quickSort(int A[], int low, int high) {
    if (low < high) {
        int pi = partition(A, low, high);
        quickSort(A, low, pi - 1);
        quickSort(A, pi + 1, high);
    }
}

// ---- CONVERSIONI NUMERICHE ----

unsigned int dec2base_k(unsigned int n) {
    unsigned int base_k = 0; 
    unsigned int power = 1;
    while (n > 0) {
        base_k += power * (n % 2);  // Assumiamo base 2 per semplicità
        power *= 10;
        n = n / 2;
    }
    return base_k;
}

void converti_binario(int n) {
    if(n == 0)
        printf("0");
    else
        converti_binario_ric(n);
}

void converti_binario_ric(int n) {
    if (n > 0) {
        converti_binario_ric(n/2);
        printf("%d", n%2);
    }
}

// ---- FUNZIONI MATEMATICHE ----

int fattore_primo(int n, int p) {
    int e = 0;
    while (n % p == 0) {
        e++;
        n = n / p;
    }
    return e;
}

int potenza(int base, int esponente) {
    int risultato = 1;
    for (int i = 0; i < esponente; i++) {
        risultato = risultato * base;
    }
    return risultato;
}

int mcm(int n1, int n2, int n3) {
    int risultato = 1;
    int f = 2;
    while (n1 > 1 || n2 > 1 || n3 > 1) {
        if (verifica_primo(f)) {
            int e_n1 = fattore_primo(n1, f);
            n1 = n1 / potenza(f, e_n1);
            int e_n2 = fattore_primo(n2, f);
            n2 = n2 / potenza(f, e_n2);
            int e_n3 = fattore_primo(n3, f);
            n3 = n3 / potenza(f, e_n3);
            int max_e = max(e_n1, e_n2, e_n3);
            risultato = risultato * (potenza(f, max_e));
        }
        f++;
    }
    return risultato;
}

float notazione_scientifica(float x, int *n) {
    *n = 0;
    while (x < 1 || x >= 10) {
        if(x < 1) {
            x *= 10.0;
            *n += 1;
        } else {
            x /= 10.0;
            *n += -1;
        }
    }
    return x;
}

// ---- STRINGHE ----

int lunghezza_stringa(char *p) {
    if (*p == '\0')
        return 0;
    else
        return 1 + lunghezza_stringa(p+1);
}

int confronta_stringhe(char *s1, char *s2) {
    if (*s1 == '\0' && *s2 == '\0')
        return 0;
    if (*s1 == '\0' || *s1 < *s2)
        return -1;
    if (*s2 == '\0' || *s2 < *s1)
        return 1;
    return confronta_stringhe(s1+1, s2+1);
}

void concatenaStringhe(char* S1, char* S2) {
    while(*S1 != '\0')
        S1 += 1;
    while(*S2 != '\0') {
        *S1 = *S2;
        S2 += 1;
        S1 += 1;
    }
    *S1 = '\0';
}

// ---- ALTRE FUNZIONI SPECIFICHE ----

int palindromo(int array[], int n) {
    for (int i = 0; i < n/2; i++) {
        if (array[i] != array[n-1-i]) {
            return 0;
        }
    }
    return 1;
}

int magico(int x, int y) {
    if ((x == 0) && (y == 0))
        return 1;
    else if ((y < 0) || (x < 0) || (y > x))
        return 0;
    else
        return magico(x-1, y) + magico(x-1, y-1);
}

int mossa(int dim_x, int dim_y, int campo[dim_x][dim_y], int pos_x, int pos_y) {
    if ((pos_x < 0) || (pos_y < 0) || (pos_y > dim_y-1) || (pos_x > dim_x-1)) {
        return 0;
    }
    if (campo[pos_x][pos_y] == 0)
        return 0;
    if (pos_x == 0)
        return 1;
    return (mossa(dim_x, dim_y, campo, pos_x-1, pos_y)) || (mossa(dim_x, dim_y, campo, pos_x, pos_y+1));
}

int golbach_sequenza(int n) {
    int x, y, res;
    int goldbach_fallita = 0;
    for (int i = 4; i <= n && goldbach_fallita == 0; i += 2) {
        res = goldbach_singolo(i, &x, &y);
        if (!res) goldbach_fallita = i;
        else printf("%d=%d+%d\n", i, x, y);
    }
    return goldbach_fallita;
}

int goldbach_singolo(int n, int *x, int *y) {
    int i;
    for (i = 2; i <= n/2; i++) {
        if (primo(i) && primo(n-i)) {
            *x = i;
            *y = n-i;
            return 1;
        }
    }
    return 0;
}

int primo(int n) {
    int i;
    for (i = 2; i <= n/2; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

int verifica_primo(int n) {
    int primo = 1;
    if (n > 1) {
        int f = 2;
        while (f < n && primo) {
            if (n % f == 0) primo = 0;
            f++;
        }
    }
    return primo;
}

int max(int n1, int n2, int n3) {
    int max = n1;
    if (n2 > max) max = n2;
    if (n3 > max) max = n3;
    return max;
}

// Funzione di supporto per confrontare array di double
int confronta_array_double(double *X, double *Y, int dim, double toll) {
    for (int i = 0; i < dim; i++) {
        if (fabs(X[i] - Y[i]) > toll) return 0;
    }
    return 1;
}

// Main di esempio
int main() {
    printf("Questo file contiene tutte le funzioni implementate durante il corso.\n");
    printf("Per utilizzare una funzione specifica, chiamarla all'interno del main.\n");
    return 0;
}