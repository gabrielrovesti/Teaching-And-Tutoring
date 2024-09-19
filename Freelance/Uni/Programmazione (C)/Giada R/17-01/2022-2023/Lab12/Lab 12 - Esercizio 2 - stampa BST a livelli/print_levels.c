#include <advanced/tree.h>
/*In questo esercizio vi chiediamo di scrivere una funzione per visualizzare un albero BST a livelli.
Esempio:
          2
         / \
        1   3
       / \   \
      0   2   5
             /
            4

La funzione deve restituire un array dinamico Darray, passato per riferimento, contenente i valori: 2 1 3 0 2 5 4

La firma della funzione è Darray print_level_order(BST *ptr), ed userà una funzione ausiliaria 
Darray print_level(BST *ptr, int level) per stampare i singoli livelli.

Trovate la definizione del Darray e le PRE e POST da rispettare nel codice. 
Potete usare le funzioni sugli alberi che trovate nella libreria advanced.*/

//Struttura array dinamico
struct darray{
    unsigned int size;
    unsigned int capacity;
    int *array;
};
typedef struct darray Darray;

//PRE: a è puntatore ad un Darray.
void init_darray(Darray* a){
    a->capacity = 1;
    a->size = 0;
    a->array = malloc(sizeof(int));
}
//POST: il Darray puntato da a è stato inizializzato. 
//La sua capacity è 1, la sua size (elementi correnti) è 0 ed è stata allocata la memoria per l'array.

//PRE: a è puntatore ad un Darray, data è un valore intero da aggiungere alla fine.
void insert_last_element_darray(Darray* a, int data){
    if(a->size==a->capacity){
        a->array = realloc(a->array, ((a->capacity) + 1)*sizeof(int));
        a->capacity += 1;
    }

    a->array[a->size] = data;
    a->size += 1;
}
//POST: data è stato aggiunto alla fine del Darray puntato da a. Size e capacity sono state aggiornate.

//PRE: a è puntatore ad un Darray.
void delete_darray(Darray* a){
    if (a->capacity > 0) {
        free(a->array);
        a->size = 0;
        a->capacity = 0;
    }    
}
//POST: i valori contenuti nel Darray sono stati deallocati, l'array è ora vuoto, la size è pari a 0 e la capacity è pari a 1.

//PRE: a è puntatore ad un Darray.
void print_darray(Darray* a){
    printf("Size: %d\n", a->size);
    printf("Capacity: %d\n", a->capacity);
    printf("Array: ");
    for(int i=0; i<a->size; i++){
        printf("%d ", a->array[i]);
    }
    printf("\n");
}
//POST: sono stampati size, capacity ed i valori contenuti nel Darray puntato da a.

//PRE: a1 è puntatore ad un Darray, a2 è puntatore ad un Darray.
void concat_darray(Darray* a1, Darray* a2){
    while((a1->size+a2->size)>a1->capacity){
        a1->array = realloc(a1->array, ((a1->capacity)+ a2->size)*sizeof(int));
        a1->capacity += a2->size;
    }

    for(int i=a1->size; i<a1->size+a2->size; i++){
        a1->array[i] = a2->array[i-a1->size];
    }
    a1->size += a2->size;
}
//POST: a1 contiene il risultato della concatenazione tra i valori di a1 e a2.

//PRE: ptr è la radice di un albero BST, level il livello dell'albero da restituire.
Darray print_level(BST *ptr, int level);
//POST: restituisce un Darray contenenti i valori di tutti i nodi per quel livello dell'albero, in ordine da sinistra a destra.
/*Esempio:
          2
         / \
        1   3
       / \   \
      0   2   5
             /
            4

Per il livello 2, il Darray restituito deve contenere i valori: 1 3
Un albero vuoto non ha nodi, quindi il suo livello sarà 0.
La radice dell'albero corrisponde al livello 1.
*/

//PRE: ptr è la radice di un albero BST.
Darray print_level_order(BST *ptr);
//POST: restituisce un Darray contenenti i valori dei livelli del BST, iniziando dal primo e concludendo con l'ultimo. 
/*Esempio:
          2
         / \
        1   3
       / \   \
      0   2   5
             /
            4

Il Darray restituito deve contenere i valori: 2 1 3 0 2 5 4*/

int main(void) {
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
    
    Darray array = print_level_order(albero);
    print_darray(&array);

    delete_darray(&array);
    delete_tree(albero);
    return 0;
}

/*

Soluzioni:

Darray print_level(BST *ptr, int level) {
   Darray result;
   init_darray(&result);
   if(ptr == NULL) {
       return result;
   }
   if(level == 1) {
       insert_last_element_darray(&result, ptr->data);
   }
   else {
       Darray left = print_level(ptr->left, level - 1);
       Darray right = print_level(ptr->right, level - 1);
       concat_darray(&result, &left);
       concat_darray(&result, &right);
       delete_darray(&left);
       delete_darray(&right);
   }
   return result;

}

Darray print_level_order(BST *ptr) {
   Darray result;
   init_darray(&result);
   int height = get_height(ptr);
   for(int i = 1; i <= height; i++) {
       Darray level = print_level(ptr, i);
       concat_darray(&result, &level);
       delete_darray(&level);
   }
   return result;
}

int main(void) {
  BST *albero;
  init(&albero);

  int values[] = {2,1,0,2,6,6,9,5};
  for(int i=0; i<8; i++){
      ordinsert_rec(&albero, values[i]);
  }

  Darray array = print_level_order(albero);
  print_darray(&array);

  delete_darray(&array);
  delete_tree(albero);
  return 0;
}



*/