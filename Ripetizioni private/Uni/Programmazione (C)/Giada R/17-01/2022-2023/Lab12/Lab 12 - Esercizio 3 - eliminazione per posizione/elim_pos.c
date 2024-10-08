#include <advanced/tree.h>
#include <stdio.h>
#include <stdlib.h>

//PRE: albero non vuoto passato per riferimento, pos posizione valida al suo interno
void delete_pos(BST **ptrPtr, unsigned pos){
}
//POST: elimina nodo in posizione data, il risultato deve essere sempre un BST

int main(){
    BST *albero;
    init(&albero);

    //Da decommentare per la consegna su Moodle
    /*int n_el, val;
    scanf("%d", &n_el);
    for(int i=0; i<n_el; i++){
        scanf("%d", &val);
        ordinsert_rec(&albero, val);
    }*/
    
    //Da commentare per la consegna su Moodle
    /*Le seguenti istruzioni sono per i test in locale, per evitare di dover inserire i valori ogni volta.
    Modificate a piacere*/
    int values[] = {2,1,0,2,6,6,9,5};
    for(int i=0; i<8; i++){
        ordinsert_rec(&albero, values[i]);
    }

    //Da decommentare per la consegna su Moodle
    /*int pos;
    scanf("%d", &n_el);
    for(int i=0; i<n_el; i++){
        scanf("%d", &pos);
        delete_pos(&albero, pos);
    }*/
    
    //Da commentare per la consegna su Moodle
    /*Le seguenti istruzioni sono per i test in locale, per evitare di dover inserire i valori ogni volta.
    Modificate a piacere*/
    delete_pos(&albero,1);
    delete_pos(&albero,5);

    if(albero != NULL) print_scheme(albero);
    return 0;
}

/*

Soluzioni:

void delete_pos(BST **ptrPtr, unsigned pos) {
 if(*ptrPtr == NULL) {
    return;
 }
 if(pos == 0) {
    BST* temp = *ptrPtr;
    if(temp->left == NULL && temp->right == NULL) {
        *ptrPtr = NULL;
        free(temp);
    }
    else if(temp->left != NULL && temp->right == NULL) {
        *ptrPtr = temp->left;
        free(temp);
    }
    else if(temp->left == NULL && temp->right != NULL) {
        *ptrPtr = temp->right;
        free(temp);
    }
    else {
        BST* minRight = temp->right;
        while(minRight->left != NULL) {
            minRight = minRight->left;
        }
        temp->data = minRight->data;
        delete_pos(&(temp->right), pos);
    }
 }
 else if(pos > 0) {
    delete_pos(&((*ptrPtr)->right), pos - 1);
 }
 else {
    delete_pos(&((*ptrPtr)->left), pos + 1);
 }
}

int main(){
  BST *albero;
  init(&albero);

  int values[] = {2,1,0,2,6,6,9,5};
  for(int i=0; i<8; i++){
      ordinsert_rec(&albero, values[i]);
  }

  delete_pos(&albero,1);
  delete_pos(&albero,5);

  if(albero != NULL) print_scheme(albero);
  return 0;
}



*/