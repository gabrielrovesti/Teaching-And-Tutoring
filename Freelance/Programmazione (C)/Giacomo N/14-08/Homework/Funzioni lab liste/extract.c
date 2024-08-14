#include <advanced/list.h>
#include <stdlib.h>
#include <stdio.h>

/*In questo esercizio vi chiediamo di scrivere una funzione extract che, data una lista di interi e due interi lim1 e lim2,
restituisca una lista con tutti i nodi compresi tra il nodo con campo dati == lim1 e il nodo con campo dati == lim2 se presenti all'interno della lista.
La funzione deve rispettare le PRE e POST riportate nel codice.
La lista al termine della funzione non deve più contenere i nodi tra lim1 e lim2 compresi.
Il valore lim1 è assunto essere l'inizio dell'intervallo e lim2 la fine.

ESEMPIO : lista=1 2 3 4 5 6 e lim1=2, lim2=4 -> lista=1 5 6, return=2 3 4

La firma della funzione deve essere struct nodo* extract(struct nodo** orig, int lim1, int lim2).*/

//PRE: orig è un riferimento ad una lista concatenata, lim1 e lim2 due interi
struct nodo* extract(struct nodo** orig, int lim1, int lim2);
//POST: se la lista contiene, in qualche posizione i e j con i<=j, l'intero lim1 in i e lim2 in j, 
// ritornare la lista di nodi compresa tra i e j e modificare orig in modo
// che tale sottolista non sia più inclusa. Altrimenti ritornare NULL e lasciare orig invariato   
// Possibilmente non allocare o eliminare nessun nodo, modificate solo i puntatori

int main(){
    struct nodo *lista = NULL;

    int n_elem;
    scanf("%d", &n_elem);

    for(int i=1; i<=n_elem; i++){
        suf_insert(&lista, i);
    }
    print_list(lista);

    int lim1, lim2;
    scanf("%d %d", &lim1, &lim2);

    struct nodo* extracted = extract(&lista, lim1, lim2);

    print_list(lista);
    print_list(extracted);
}