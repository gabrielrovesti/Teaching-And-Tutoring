#include<stdio.h>
#include<stdlib.h>
#include<basic/array.h>

//PRE: v è un vettore passato per riferimento
void init_vector(int** v);
//POST: inizializza il vettore con capacity 1 e senza nessun elemento.

//PRE: il vettore è inizializzato e pos è un numero tra 0 e size -1 compreso
void insert_element(int** v, int data, unsigned int pos, unsigned int *size, unsigned int *capacity);
//POST: aggiunge un elemento data in posizione pos. Se necessario, la capacity del vettore viene raddoppiata

//PRE: v1 è un riferimento a un vettore inizializzato, con size = s e capacity = c, v2 è un vettore o un array di size n_elem
void concat_vectors(int** v1, int* v2, unsigned int n_elem, unsigned int *s, unsigned int *c);
//POST: v1 contiene il risultato della concatenazione tra v1 e v2

int main(){
    int *vector;
    int n_elem;

    //inizializzazione del vettore
    init_vector(&vector);
    // variabili che tengono traccia di size e capacity
    unsigned int size = 0, capacity = 1;

    scanf("%d", &n_elem);

    //inserimento di n_elem da standard input
    int elem;
    for(int i=0; i<n_elem; i+=1){
        scanf("%d", &elem);
        insert_element(&vector, elem, i, &size, &capacity);
    }

    //lettura di un secondo array, non dinamico
    scanf("%d", &n_elem);
    int second_vec[n_elem];
    leggi_array(second_vec, n_elem);

    //concatenazione tra vector e array
    concat_vectors(&vector, second_vec, n_elem, &size, &capacity);

    stampa_array(vector, size);
    printf("\n");
    printf("%d", capacity);
}

void init_vector(int** v){
    *v = malloc(sizeof(int));
}

void insert_element(int** v, int data, unsigned int pos, unsigned int *size, unsigned int *capacity){
    if(*size==*capacity){
        *v = realloc(*v, 2*(*capacity)*sizeof(int));
        *capacity *= 2;
    }

    for(int i = *size; i>pos; i-=1){
        *v[i] = *v[i-1];
    }
    (*v)[pos] = data;
    *size += 1;
}

void concat_vectors(int** v1, int* v2, unsigned int n_elem, unsigned int *s, unsigned int *c){
    while(*s+n_elem>*c){
        *v1 = realloc(*v1, (*c)*2*sizeof(int));
        *c *= 2;
    }

    for(int i=*s; i<*s+n_elem; i++){
        (*v1)[i] = v2[i-*s];
    }
    *s += n_elem;
}
