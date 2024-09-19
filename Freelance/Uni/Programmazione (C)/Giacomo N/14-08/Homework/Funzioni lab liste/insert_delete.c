#include <advanced/list.h>
#include <stdlib.h>
#include <stdio.h>
/*Il seguente esercizio si divide in 2 parti:
1) Usando la struttura nodo e le funzioni scritte durante il laboratorio precedente, scrivere le seguenti funzioni:
    -struct nodo* insert(struct nodo* ptr, int pos, int info), per aggiungere un nodo in una posizione generica della lista.
	Bisogna procedere nel seguente modo:
		1- verificare se la lista è vuota, in tal caso allocare e restituire un nuovo nodo con valore info.
		2- se la lista non è vuota, verificare se il nodo va inserito nella posizione iniziale. Se si, allocare un nuovo nodo con valore info, assegnare al campo next del nuovo nodo la lista originale e restiuire il nodo appena allocato.
		3- se la posizione non è quella iniziale, percorrere la lista fino al nodo pos-1 e poi:
			3.1- allocare un nuovo nodo con valore info.
			3.2- assegnare al campo next del nuovo nodo il nodo che correntemente è in posizione pos.
			3.3- assegnare al campo next del nodo a pos-1 il nuovo nodo.
			3.4- restituire il nodo iniziale della lista.
    -struct nodo* delete(struct nodo* ptr, int pos), per eliminare un nodo in una posizione generica della lista.
	Bisogna procedere nel seguente modo:
		1- verificare se la lista è vuota, in tal caso restituire il nodo corrente (niente da eliminare).
		2- se la lista non è vuota, verificare se il nodo da eliminare è nella posizione iniziale. Se si, creare un puntatore al secondo nodo, eliminare il nodo iniziale e restituire il secondo nodo della lista originale.
		3- se la posizione non è quella iniziale, percorrere la lista fino al nodo pos-1 e poi:
			3.1- creare un puntatore al nodo in posizione pos+1.
			3.2- eliminare il nodo in posizione pos.
			3.3- assegnare al campo next del nodo a pos-1 il nodo che precedentemente era in posizione pos+1.
			3.4- restituire il nodo iniziale della lista.

2) Aggiungere le funzioni alla libreria nella cartella advanced/list

NB: rispettare le PRE e POST che sono indicate ne codice.
*/

//PRE: ptr è il primo nodo di una lista (possibilmente vuota) passato per valore, pos è una posizione valida (tra 0 e lung(ptr)-1)
struct nodo* insert(struct nodo* ptr, int pos, int info);
//POST: restituisce il primo nodo della lista, che è quella originale, con un nodo aggiunto in posizione pos avente campo info == val

//PRE: ptr è il primo nodo di una lista (possibilmente vuota) passato per valore, pos è una posizione valida (tra 0 e lung(ptr)-1)
struct nodo* delete(struct nodo* ptr, int pos);
//POST: restituisce il primo nodo della lista che è quella originale senza il nodo in posizione pos, che è stato eliminato

int main(){
    struct nodo *list = NULL;

    int len;
    scanf("%d", &len);

    int val;
    for(int i=0; i<len; i++){
        scanf("%d", &val);
        list = insert(list, i, val);
    }
    print_list(list);
    
    for(int i=1; i<len; i++){
        list = delete(list, i);
        len -=1;
    }
    print_list(list);
}