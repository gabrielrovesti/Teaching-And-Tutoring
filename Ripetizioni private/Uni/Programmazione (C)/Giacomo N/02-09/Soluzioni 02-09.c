// Teoria

/*
Data la seguente dichiarazione di array bidimensionale:
int A[4][6];
Utilizzando l'aritmetica dei puntatori, scrivere la formula per ottenere l'indirizzo dell'elemento A[2][4]

Soluzione:
La formula per ottenere l'indirizzo dell'elemento A[2][4] utilizzando l'aritmetica dei puntatori è:
*(A + 2*6 + 4) oppure *(*(A + 2) + 4)
*/

/*
Scrivere la PRE e la POST della seguente funzione:
int conta_pari(int *arr, int size);
che, dato un array di interi `arr` di dimensione `size`, conti il numero di elementi pari presenti nell'array

PRE: arr è un array di interi di dimensione size
POST: la funzione restituisce il numero di elementi pari presenti in arr
*/

/*
Scrivere la PRE e la POST della seguente funzione:
void elimina_multipli(int *arr, int *size, int k);
che, dato un array di interi `arr` di dimensione `*size` e un intero `k`, elimini dall'array tutti i multipli di `k`. La funzione deve aggiornare il valore di `*size` con la nuova dimensione dell'array dopo l'eliminazione dei multipli.

PRE: arr è un array di interi di dimensione *size, k è un intero positivo
POST: arr contiene solo gli elementi non multipli di k, *size contiene la nuova dimensione dell'array
*/

/*
Considerata la seguente struttura:
struct punto {
    int x: 4;
    int y: 4;
    int z: 8;
};
Quanto vale `3*sizeof(struct punto)-2`?

Soluzione:
sizeof(struct punto) = 2 byte (4+4+8 = 16 bit = 2 byte)
3*sizeof(struct punto)-2 = 3*2-2 = 4
*/

/*
Data la seguente funzione ricorsiva:
int f(int n) {
    if (n <= 0) return 0;
    return n + f(n-3);
}

- Qual è il parametro su cui viene fatta la ricorsione?
  Il parametro su cui viene fatta la ricorsione è n.

- Qual è la misura di complessità del problema?
  La misura di complessità del problema è n.

- Spiegare perché questa misura decresce ad ogni chiamata ricorsiva.
  Questa misura decresce ad ogni chiamata ricorsiva perché n viene decrementato di 3 ad ogni chiamata ricorsiva.

- Determinare il fattore minimo di decrescita della misura di complessità ad ogni chiamata ricorsiva.
  Il fattore minimo di decrescita della misura di complessità ad ogni chiamata ricorsiva è 3.
*/

/*
Data la seguente dichiarazione:
int (*f)(int, int);
Cosa rappresenta f? Come si potrebbe assegnare una funzione a questo puntatore?

Soluzione:
f è un puntatore a una funzione che prende due parametri interi e restituisce un intero.
Per assegnare una funzione a questo puntatore, si può utilizzare la seguente sintassi:
int somma(int a, int b) { return a + b; }
f = somma;
*/

/*
Dato il seguente codice:
int x = 5;

void func(int *p) {
    int x = 10;
    *p = x;
}

int main(void) {
    int *p = &x;
    func(p);
    printf("%d\n", x);
}
Cosa stampa il programma? Spiegare il concetto di passaggio per riferimento e il suo effetto sulle variabili.

Soluzione:
Il programma stampa 10.
Il passaggio per riferimento avviene quando viene passato l'indirizzo di una variabile come parametro a una funzione. Questo permette alla funzione di modificare direttamente il valore della variabile originale. Nel codice dato, la funzione func modifica il valore di x tramite il puntatore p, che punta all'indirizzo di x. Quindi, quando viene stampato il valore di x nel main, il valore è stato modificato a 10.
*/

/*
Data la funzione:
void reverse_string(char *str, int start, int end) {
    if (start >= end) return;
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    reverse_string(str, start+1, end-1);
}
- Scrivere le pre e post condizioni della funzione.
- Spiegare il funzionamento della funzione e dimostrarne la correttezza usando l'induzione

PRE: str è una stringa valida, start e end sono indici validi della stringa con start <= end
POST: str contiene la stringa invertita

Funzionamento:
La funzione reverse_string inverte ricorsivamente la stringa str scambiando i caratteri alle posizioni start ed end, e poi chiamando se stessa con start+1 ed end-1 fino a quando start >= end.

Dimostrazione di correttezza usando l'induzione:
Caso base: se start >= end, la stringa è vuota o contiene un solo carattere, quindi è già invertita.
Passo induttivo: assumiamo che la funzione inverta correttamente la sottostringa str[start+1...end-1]. Scambiando i caratteri str[start] e str[end], e combinandoli con la sottostringa invertita str[start+1...end-1], otteniamo l'intera stringa str[start...end] invertita.
*/

/*
Considerando il seguente codice:
#define MULTIPLY(a, b) a * b
int x = 5, y = 10;
int result = MULTIPLY(x+2, y+3);
printf("%d", result);
Cosa viene stampato? Spiegare il problema di precedenza degli operatori nelle macro e come risolverlo

Soluzione:
Viene stampato 23.
Il problema di precedenza degli operatori nelle macro si verifica quando la macro contiene espressioni complesse senza parentesi. In questo caso, MULTIPLY(x+2, y+3) si espande in x+2 * y+3, che viene valutato come (x+2) * y+3 a causa della precedenza degli operatori. Per risolvere questo problema, è necessario racchiudere ogni parametro della macro tra parentesi, ad esempio #define MULTIPLY(a, b) ((a) * (b)).
*/

/*
Considerando il seguente codice:
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }

int compute(int (*op[])(int, int), int n, int x, int y) {
    return op[n](x, y);
}
Come si chiamerebbe la funzione `compute` per eseguire un'operazione specifica (ad esempio, addizione, sottrazione, moltiplicazione, divisione) passando l'indice dell'operazione desiderata?

Soluzione:
Per eseguire un'operazione specifica utilizzando la funzione compute, si può creare un array di puntatori a funzione e passarlo come parametro insieme all'indice dell'operazione desiderata. Ad esempio:
int (*operations[])(int, int) = {add, subtract, multiply, divide};
int result = compute(operations, 0, 5, 3); // Esegue l'addizione: 5 + 3
int result = compute(operations, 1, 10, 4); // Esegue la sottrazione: 10 - 4
int result = compute(operations, 2, 6, 7); // Esegue la moltiplicazione: 6 * 7
int result = compute(operations, 3, 20, 5); // Esegue la divisione: 20 / 5
*/

/*
Dato il seguente codice:
int arr[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
int *p = (int *)arr;
printf("%d", *(p+5));
Cosa viene stampato? Spiegare come funziona l'aritmetica dei puntatori con gli array multidimensionali

Soluzione:
Viene stampato 6.
In C, un array bidimensionale viene memorizzato in memoria come un array monodimensionale contiguo. Quando si cast un array bidimensionale a un puntatore a int, il puntatore punta al primo elemento dell'array. L'aritmetica dei puntatori con gli array multidimensionali funziona considerando l'array come un array monodimensionale. Quindi, *(p+5) accede al sesto elemento dell'array monodimensionale, che corrisponde all'elemento arr[1][1], ovvero 6.

*/



// Pratica

ListNode* alterna_liste(ListNode *l1, ListNode *l2) {
    ListNode dummy(0);
    ListNode *tail = &dummy;
    
    while (l1 || l2) {
        if (l1) {
            tail->next = l1;
            tail = tail->next;
            l1 = l1->next;
        }
        if (l2) {
            tail->next = l2;
            tail = tail->next;
            l2 = l2->next;
        }
    }
    
    return dummy.next;
}

int cammino_somma(int *mat, int r, int c, int sum, int x, int y) {
    if (x == r - 1 && y == c - 1) {
        return sum == mat[x * c + y];
    }
    
    if (x >= r || y >= c) {
        return 0;
    }
    
    return cammino_somma(mat, r, c, sum - mat[x * c + y], x + 1, y) ||
           cammino_somma(mat, r, c, sum - mat[x * c + y], x, y + 1);
}

void elimina_dispari(TreeNode **root) {
    if (*root == NULL) {
        return;
    }
    
    elimina_dispari(&((*root)->left));
    elimina_dispari(&((*root)->right));
    
    if ((*root)->val % 2 != 0) {
        TreeNode *temp = *root;
        if ((*root)->left == NULL) {
            *root = (*root)->right;
        } else if ((*root)->right == NULL) {
            *root = (*root)->left;
        } else {
            TreeNode *succ = (*root)->right;
            while (succ->left != NULL) {
                succ = succ->left;
            }
            (*root)->val = succ->val;
            elimina_dispari(&((*root)->right));
        }
        delete temp;
    }
}

int somma_nodi(ListNode *head, int k, int &i) {
    if (head == NULL) {
        return 0;
    }
    
    int sum = somma_nodi(head->next, k, i);
    
    if (++i == k) {
        sum += head->val;
    }
    
    return sum;
}

int somma_nodi(ListNode *head, int k) {
    int i = 0;
    return somma_nodi(head, k, i);
}

void zigzag_stampa_helper(TreeNode *root, int level, bool leftToRight) {
    if (root == NULL) {
        return;
    }
    
    if (level == 1) {
        cout << root->val << " ";
    } else if (level > 1) {
        if (leftToRight) {
            zigzag_stampa_helper(root->left, level - 1, leftToRight);
            zigzag_stampa_helper(root->right, level - 1, leftToRight);
        } else {
            zigzag_stampa_helper(root->right, level - 1, leftToRight);
            zigzag_stampa_helper(root->left, level - 1, leftToRight);
        }
    }
}

void zigzag_stampa(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    
    int height = 0;
    TreeNode *temp = root;
    while (temp != NULL) {
        height++;
        temp = temp->left;
    }
    
    bool leftToRight = true;
    for (int i = 1; i <= height; i++) {
        zigzag_stampa_helper(root, i, leftToRight);
        leftToRight = !leftToRight;
        cout << endl;
    }
}

int cerca_sottostringa(char *str, char *sub) {
    int len1 = strlen(str);
    int len2 = strlen(sub);
    
    if (len2 > len1) {
        return 0;
    }
    
    for (int i = 0; i <= len1 - len2; i++) {
        int j;
        for (j = 0; j < len2; j++) {
            if (str[i + j] != sub[j]) {
                break;
            }
        }
        if (j == len2) {
            return 1;
        }
    }
    
    return 0;
}

int verifica_anagramma(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    if (len1 != len2) {
        return 0;
    }
    
    int count[256] = {0};
    
    for (int i = 0; i < len1; i++) {
        count[str1[i]]++;
        count[str2[i]]--;
    }
    
    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
            return 0;
        }
    }
    
    return 1;
}

int verifica_bst(TreeNode *root, int min, int max) {
    if (root == NULL) {
        return 1;
    }
    
    if (root->val <= min || root->val >= max) {
        return 0;
    }
    
    return verifica_bst(root->left, min, root->val) &&
           verifica_bst(root->right, root->val, max);
}

int is_bst(TreeNode *root) {
    return verifica_bst(root, INT_MIN, INT_MAX);
}

int conta_nodi_livello(TreeNode *root, int level) {
    if (root == NULL) {
        return 0;
    }
    
    if (level == 1) {
        return 1;
    }
    
    return conta_nodi_livello(root->left, level - 1) +
           conta_nodi_livello(root->right, level - 1);
}