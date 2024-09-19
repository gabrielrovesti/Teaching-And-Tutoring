#include <advanced/lista.h>
#include <stdlib.h>
#include <stdio.h>

struct nodo* filter(struct nodo* ptr, int thres){
    struct nodo* list = NULL;

    int val;
    for(int i=0; i<lung(ptr); i++){
        val = get(ptr, i);
        if(val>=thres) suf_insert(&list, val);
    }
    return list;
}
// Data una lista di partenza, restituire una nuova lista con tutti e soli gli elementi maggiori o uguali di una certa soglia (nello stesso ordine) 

int main(){
	struct nodo* list = NULL;

    int len;
    scanf("%d", &len);

    int val;
    for(int i=0; i<len; i++){
        scanf("%d", &val);
        suf_insert(&list, val);
    }
    print_list(list);

    int thres;
    scanf("%d", &thres);
    struct nodo* nuova_lista = filter(list, thres);
    print_list(nuova_lista);
}
