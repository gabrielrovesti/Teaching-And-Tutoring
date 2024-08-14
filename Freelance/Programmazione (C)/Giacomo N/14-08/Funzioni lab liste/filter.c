#include <advanced/lista.h>
#include <stdlib.h>
#include <stdio.h>
/* Il seguente esercizio richiede la creazione di una funzione che filtra una lista creandone una nuova 
* con tutti e soli gli elementi, nello stesso ordine,che hanno un campo val maggiore o uguale a un certo 
* valore (la firma della funzione non è fornita).
*/

// filter(...)
/*Data una lista di partenza, restituire una nuova lista con tutti e soli gli elementi maggiori o uguali 
di una certa soglia (nello stesso ordine) */

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
    //filtra qui
    print_list(nuova_lista);
}
