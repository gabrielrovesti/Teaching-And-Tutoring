#include <stdlib.h>
#include <stdio.h>

struct nodo{
    int info;
    struct nodo *next;
};

struct nodo* new_nodo(int info){
    struct nodo *temp =  (struct nodo*)malloc(sizeof(struct nodo));
    temp->info = info;
    temp->next = NULL;
    return temp;
}
// POST: return di un puntatore ad un nuovo nodo (allocato dentro la funzione) con campo info

/* Fatte in classe */
// PRE: ptr è un puntatore ad una lista (possibilmente vuota)
int isempty(struct nodo* ptr){
    return ptr==NULL? 1: 0;
}
// POST: return 1 se la lista è vuota, 0 altrimenti

// PRE: ptr è un puntatore ad una lista (possibilmente vuota)
void print_list(struct nodo* ptr){
    if(isempty(ptr)==1){
        printf("Vuota\n");
    }
    else{
        while(isempty(ptr)==0){
            printf("%d ", ptr->info);
            ptr = ptr->next;
        }
        printf("\n");
    }
}
// POST: stampa il contenuto della lista (i campi info), "Vuota" se non ci sono elementi

// PRE: pptr è un puntatore ad una lista (possibilmente vuota) passato per riferimento
void pre_insert(struct nodo** pptr, int val){
    struct nodo* nuovo = new_nodo(val);
    nuovo->next = *pptr;
    *pptr = nuovo;
}
// POST: la lista puntata da pptr è quella originale con un nodo aggiunto "in testa" (inizio lista) avente campo info == val

// PRE: pptr è un puntatore ad una lista (possibilmente vuota) passato per riferimento
void suf_insert(struct nodo** pptr, int val){
    struct nodo* nuovo = new_nodo(val);
    while(isempty(*pptr)==0){
        pptr = &((*pptr)->next);
    }
    *pptr = nuovo;
}
// POST: la lista puntata da pptr è quella originale con un nodo aggiunto "in coda" (fine lista) avente campo info == val

/* Nuove funzioni */
// PRE:  ptr è un puntatore ad una lista (possibilmente vuota)
int lung(struct nodo* ptr){
    return (isempty(ptr)==1)? 0 : 1+lung(ptr->next);
}
// POST: return il numero di nodi
// NOTA: è un one-liner se usate la ricorsione

// PRE: ptr è un puntatore ad una lista (possibilmente vuota), pos è una posizione valida (tra 0 e lung(ptr)-1)
int get(struct nodo* ptr, int pos){
    while(pos!=0){
        ptr = ptr->next;
        pos--;
    }
    return ptr->info;
}
// POST: return del campo info del nodo pos-esimo

// PRE: ptr è un puntatore ad una lista (possibilmente vuota) passata per riferimento, pos è una posizione valida (tra 0 e lung(ptr)-1)
void modifica(struct nodo** ptr, int pos, int val){
    while(pos!=0){
        ptr = &((*ptr)->next);
        pos--;
    }
    (*ptr)->info = val;
}
// POST: la lista puntata da ptr è uguale a quella originale ma il nodo in posizione pos ha info == val


int main(){
    struct nodo *list = NULL;

    int len;
    scanf("%d", &len);

    int val;
    for(int i=0; i<len; i++){
        scanf("%d", &val);
        if(i%2==0){
            pre_insert(&list, val);
        }
        else suf_insert(&list, val);
    }
    print_list(list);

    //raddoppio ogni elemento della lista
    for(int i=0; i<lung(list); i++){
        modifica(&list, i, 2*get(list, i));
    }
    print_list(list);
}
