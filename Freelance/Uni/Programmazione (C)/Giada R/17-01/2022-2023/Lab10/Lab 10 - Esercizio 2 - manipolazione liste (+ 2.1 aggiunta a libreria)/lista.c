#include <stdlib.h>
#include <stdio.h>

struct nodo{
    int info;
    struct nodo *next;
};

struct nodo* new_nodo(int val);
// POST: return di un puntatore ad un nuovo nodo (allocato dentro la funzione) con campo info == val

/* Fatte in classe */
// PRE: ptr è un puntatore ad una lista (possibilmente vuota)
int isempty(struct nodo* ptr);
// POST: return 1 se la lista è vuota, 0 altrimenti

// PRE: ptr è un puntatore ad una lista (possibilmente vuota)
void print_list(struct nodo* ptr);
// POST: stampa il contenuto della lista (i campi info), "Vuota" se non ci sono elementi

// PRE: pptr è un puntatore ad una lista (possibilmente vuota) passato per riferimento
void pre_insert(struct nodo** pptr, int val);
// POST: la lista puntata da pptr è quella originale con un nodo aggiunto "in testa" (inizio lista) avente campo info == val

// PRE: pptr è un puntatore ad una lista (possibilmente vuota) passato per riferimento
void suf_insert(struct nodo** pptr, int val);
// POST: la lista puntata da pptr è quella originale con un nodo aggiunto "in coda" (fine lista) avente campo info == val

/* Nuove funzioni */
// PRE:  ptr è un puntatore ad una lista (possibilmente vuota)
int lung(struct nodo* ptr);
// POST: return il numero di nodi
// NOTA: è un one-liner se usate la ricorsione

// PRE: ptr è un puntatore ad una lista (possibilmente vuota), pos è una posizione valida (tra 0 e lung(ptr)-1)
int get(struct nodo* ptr, int pos);
// POST: return del campo info del nodo pos-esimo

// PRE: ptr è un puntatore ad una lista (possibilmente vuota) passata per riferimento, pos è una posizione valida (tra 0 e lung(ptr)-1)
void modifica(struct nodo** ptr, int pos, int val);
// POST: la lista puntata da ptr è uguale a quella originale ma il nodo in posizione pos ha campo info == val


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

    //raddoppio ogni elemento della lista (codice qui)
    print_list(list);
}

/*

Soluzioni:

struct nodo* new_nodo(int val) {
  struct nodo* newNode = malloc(sizeof(struct nodo));
  if(newNode == NULL) {
      printf("Memoria esaurita.\n");
      exit(EXIT_FAILURE);
  }
  newNode->info = val;
  newNode->next = NULL;
  return newNode;
}

int lung(struct nodo* ptr) {
  int count = 0;
  struct nodo* current = ptr;
  while(current != NULL) {
      count++;
      current = current->next;
  }
  return count;
}

int get(struct nodo* ptr, int pos) {
  struct nodo* current = ptr;
  for(int i = 0; i < pos; i++) {
      if(current == NULL) {
          printf("Posizione non valida.\n");
          exit(EXIT_FAILURE);
      }
      current = current->next;
  }
  if(current == NULL) {
      printf("Posizione non valida.\n");
      exit(EXIT_FAILURE);
  }
  return current->info;
}

void modifica(struct nodo** ptr, int pos, int val) {
  struct nodo* current = *ptr;
  for(int i = 0; i < pos; i++) {
      if(current == NULL) {
          printf("Posizione non valida.\n");
          exit(EXIT_FAILURE);
      }
      current = current->next;
  }
  if(current == NULL) {
      printf("Posizione non valida.\n");
      exit(EXIT_FAILURE);
  }
  current->info = val;

  for(int i = 0; i < lung(list); i++) {
   int info = get(list, i);
   modifica(&list, i, info * 2);
}

}




*/