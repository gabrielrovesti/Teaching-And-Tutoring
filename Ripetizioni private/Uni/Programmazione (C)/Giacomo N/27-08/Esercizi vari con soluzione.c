int sotto_array_somma_massima(int* array, int lunghezza, int* inizio, int* fine) {
    int somma_massima = array[0];
    int somma_corrente = 0;
    int inizio_temp = 0;
    *inizio = *fine = 0;

    for (int i = 0; i < lunghezza; i++) {
        somma_corrente += array[i];
        
        if (somma_corrente > somma_massima) {
            somma_massima = somma_corrente;
            *inizio = inizio_temp;
            *fine = i;
        }
        
        if (somma_corrente < 0) {
            somma_corrente = 0;
            inizio_temp = i + 1;
        }
    }

    return somma_massima;
}

/******************* Trova massimo in BST ************************/

// Ricorsiva
int findMax(Node* root)
{
    // Base case
    if (root == NULL)
        return INT_MIN;
 
    // Return maximum of 3 values:
    // 1) Root's data 2) Max in Left Subtree
    // 3) Max in right subtree
    int res = root->data;
    int lres = findMax(root->left);
    int rres = findMax(root->right);
    if (lres > res)
        res = lres;
    if (rres > res)
        res = rres;
    return res;
}

// Iterativa
int maxValue(struct node* node)
{   
    /* loop down to find the rightmost leaf */
    struct node* current = node;
    while (current->right != NULL) 
        current = current->right;
     
    return (current->data);
}

// Successore del nodo

Node* findSuccessor(Node* root, Node* succ, int key)
{
    // base case
    if (root == nullptr) {
        return succ;
    }
 
    // if a node with the desired value is found, the successor is the minimum value
    // node in its right subtree (if any)
    if (root->data == key)
    {
        if (root->right != nullptr) {
            return findMinimum(root->right);
        }
    }
    // if the given key is less than the root node, recur for the left subtree
    else if (key < root->data)
    {
        // update successor to the current node before recursing in the left subtree
        succ = root;
        return findSuccessor(root->left, succ, key);
    }
 
    // if the given key is more than the root node, recur for the right subtree
    else {
        return findSuccessor(root->right, succ, key);
    }
 
    return succ;
}
 
// https://www.techiedelight.com/find-inorder-successor-given-key-bst/