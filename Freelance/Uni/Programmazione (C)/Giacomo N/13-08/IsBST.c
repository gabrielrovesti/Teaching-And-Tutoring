int isbst (BST* ptr){
    if(ptr == NULL) return NULL;
    if(ptr != NULL){
        BST* temp = ptr;
        if(ptr->left){
            // iterativa
            while(ptr->left){
                if(ptr->left <= temp->valore)
                    temp = ptr;
                    ptr = ptr->left;
            }           
        }
        if(ptr->right){
            while(ptr->right){
                if(ptr->right > temp->valore)
                    temp = ptr;
                    ptr = ptr->right;
            }
        }
        int ris = -1;
        // ricorsiva
        if(ptr->left){
            if(isbst(ptr->left) <= temp)
                ris = 1;
        }
        if(ptr->right){
            if(isbst(ptr->right) > temp)
                ris = 1;
        }
        ris = 0;
        return ris;
    }
}

/*

/// Alterantiva a livello logico

int is_bst(struct node* root)
{
    if (root)
    {
        if (!is_bst(root->left)) //moves towards the leftmost child of the tree and checks for the BST
            return 0;
        if (prev != NULL && root->data <= prev->data)
            return 0;
        prev = root;
        return is_bst(root->right);    //moves the corresponding right child of the tree and checks for the BST
    }
    return 1;
}
*/