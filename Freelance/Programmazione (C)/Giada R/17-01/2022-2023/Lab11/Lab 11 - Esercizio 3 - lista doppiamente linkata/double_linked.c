#include <advanced/list.h>
#include <stdlib.h>
#include <stdio.h>

/*In questo esercizio lavoreremo su liste normali e liste doppiamente linkate. A differenza delle liste su cui avete lavorato fino ad adesso, 
che hanno solo un puntatore al nodo successivo, le liste doppiamente linkate hanno anche un puntatore al nodo precendente.
Vi viene data la struttura nodoD che corrisponde ad un nodo di una lista doppiamente linkata e una funzione insert_dlist per inserire un dopo 
in una posizione generica di una lista doppiamente linkata.

Vi chiediamo di scrivere 3 funzioni per le liste doppiamente linkate:
1- reverse_dlist, che inverte la posizione dei nodi della lista originale
2- print_forward, per stampare la lista dal primo nodo all'ultimo
3- print_backward, per stampare la lista dall' ultimo nodo al primo

Inoltre, vi chiediamo di scrivere 1 funzione per le liste normali:
1- reverse_list, che inverte la posizione dei nodi della lista originale

Le PRE e POST delle funzioni, così come le loro firme, sono riportate nel codice e devono essere rispettate.
Attenzione: le stampe hanno tutte uno spazio dopo un numero, anche quello finale.*/

//Lista doppiamente linkata: un puntatore al nodo successivo e uno a quello precedente
struct nodoD{
    int info;
    struct nodoD* prev;
    struct nodoD* next;
};

//PRE: first e last sono riferimenti ai puntatori iniziali e finali di una DList, pos una posizione valida (0..lung -1)
void insert_dlist(struct nodoD **first, struct nodoD **last, int pos, int info){
    if(pos == 0){
        struct nodoD* tmp = malloc(sizeof(struct nodoD));
        tmp->info = info;
        tmp->prev = NULL;
        tmp->next = *first;
        if(*first != NULL){
            (*first)->prev = tmp;
        }
        else *last = tmp;
        *first = tmp;
    }
    else{
        insert_dlist(&((*first)->next), last, pos-1, info);
        (*first)->next->prev = (*first);
    }
}
//POST: inserisce un nuovo nodo in posizione pos con campo dati == info

//POST: stampa la DList dato il puntatore al nodo iniziale first
void print_forward(struct nodoD* first);

//POST: stampa la DList al contrario dato il puntatore all'ultimo elemento
void print_backward(struct nodoD* last);

/*double linked vs single linked*/
//PRE: first e last sono riferimenti ai puntatori iniziali e finali di una DList
void reverse_dlist(struct nodoD **first, struct nodoD **last);
//POST: la DList identificata da first e last è la lista originale ma al contrario
// ESEMPIO: 1-2-4 diventa 4-2-1

//PRE: ptr è un riferimento al puntatori iniziale della lista normale
void reverse_list(struct nodo **ptr);
//POST: l'ordine degli elementi della lista è stato invertito
// ESEMPIO: 1-2-4 diventa 4-2-1


int main(){
    struct nodoD* dlist_start = NULL;
    struct nodoD* dlist_end = NULL;

    struct nodo* list = NULL;

    int n_entries;
    scanf("%d", &n_entries);

    for(int i=0; i<n_entries; i++){
        pre_insert(&list, i);
        insert_dlist(&dlist_start, &dlist_end, 0, i);
    }

    //normale print, da libreria
    printf("Lista:\n");
    print_list(list);

    //print in un senso e nell'altro
    printf("DLista in avanti:\n");
    print_forward(dlist_start);
    printf("DLista all'indietro:\n");
    print_backward(dlist_end);

    //reversing
    reverse_list(&list);
    reverse_dlist(&dlist_start, &dlist_end);

    printf("Lista reversed:\n");
    print_list(list);

    //print in un senso e nell'altro
    printf("DLista reversed (entrambi i sensi):\n");
    print_forward(dlist_start);
    print_backward(dlist_end);    
}

/*

Soluzioni

void reverse_dlist(struct nodoD **first, struct nodoD **last) {
   struct nodoD* current = *first;
   struct nodoD* prev = NULL;
   struct nodoD* next = NULL;
   while(current != NULL) {
       next = current->next;
       current->next = prev;
       current->prev = next;
       prev = current;
       current = next;
   }
   *first = prev;
}

void print_forward(struct nodoD* first) {
   struct nodoD* current = first;
   while(current != NULL) {
       printf("%d ", current->info);
       current = current->next;
   }
   printf("\n");
}

void print_backward(struct nodoD* last) {
   struct nodoD* current = last;
   while(current != NULL) {
       printf("%d ", current->info);
       current = current->prev;
   }
   printf("\n");
}

void reverse_list(struct nodo **ptr) {
   struct nodo* prev = NULL;
   struct nodo* current = *ptr;
   struct nodo* next = NULL;
   while(current != NULL) {
       next = current->next;
       current->next = prev;
       prev = current;
       current = next;
   }
   *ptr = prev;
}

int main(){
   struct nodoD* dlist_start = NULL;
   struct nodoD* dlist_end = NULL;

   struct nodo* list = NULL;

   int n_entries;
   scanf("%d", &n_entries);

   for(int i=0; i<n_entries; i++){
       pre_insert(&list, i);
       insert_dlist(&dlist_start, &dlist_end, 0, i);
   }

   printf("Lista:\n");
   print_list(list);

   printf("DLista in avanti:\n");
   print_forward(dlist_start);
   printf("DLista all'indietro:\n");
   print_backward(dlist_end);

   reverse_list(&list);
   reverse_dlist(&dlist_start, &dlist_end);

   printf("Lista reversed:\n");
   print_list(list);

   printf("DLista reversed (entrambi i sensi):\n");
   print_forward(dlist_start);
   print_backward(dlist_end);   
}



*/