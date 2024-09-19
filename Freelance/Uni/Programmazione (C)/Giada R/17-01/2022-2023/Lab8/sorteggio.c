#include<stdio.h>
#include<stdlib.h>

/*
    Siamo nel bel mezzo del torneo di Karate "All Valley KarateTournament". Il torneo è ad eliminazione diretta, ovvero, all'iniziodi ogni fase, che supponiamo avere un numero pari di squadre N,vengono selezionati casualmente N/2 accoppiamenti. Ogni coppia disquadre si affronta, il vincitore passa alla fase successiva, nellaquale si ripete lo stesso procedimento fino alla fine del torneo. 

    Dovete scrivere una funzione che effettui un sorteggio degli accoppiamenti per la fase successiva in modo casuale. 

    La lista delle squadre è rappresentata da un array di stringhe: squadre. 
    Al termine del sorteggio (rimescolamento degli elementi dell'array) gli accoppiamenti saranno i seguenti: 
    squadre[0] sfiderà squadre[1]
    squadre[2] sfiderà squadre[3]
    squadre[4] sfiderà squadre[5], e così via...

    L'esercizio non ha test perché esistono molti modi corretti di effettuare un sorteggio casuale. Caricate lo stesso l'esercizio su Moodle.  
*/

#define NUM_SQUADRE 8

void sorteggio(char *lista_squadre[], int dim);
void stampa_array(char **X, int size);
void scambia(char **p1, char **p2);


int main(void) {

    char *squadre[NUM_SQUADRE] = {"Cobra Kai Dojo", "Miyagi-Do Karate", 
                                "Locust Valley Karate Club", "Topanga Karate","Xtreme Martial Arts", "All Star Karate", "Krunch Karate", "Cutting Edge Karate"};
    
    srand(42);

    stampa_array(squadre, NUM_SQUADRE);
    sorteggio(squadre, NUM_SQUADRE);
    stampa_array(squadre, NUM_SQUADRE);

}


/* 
    PRE:  dim è pari e corrisponde al numero di elemento di lista_squadre
    POST: rimescolato l'array lista_squadre in modo casuale
*/
void sorteggio(char *lista_squadre[], int dim) {
    
    while (--dim>0) 
        scambia(&lista_squadre[dim], &lista_squadre[rand()%dim]); 

}


/* POST scambiati i valori di p1 e p2 */
void scambia(char **p1, char **p2) {
    char *t = *p1;
    *p1 = *p2;
    *p2 = t;
}


/*
    PRE: X è un puntatore ad un array di dimensione size 
    POST: stampati a video gli elementi di X a coppie, una coppia per ogni riga
*/
void stampa_array(char **X, int size) {

    for(int i=0; i<size; i+=2)
        printf("%s - %s\n", X[i], X[i+1]);
    printf("\n");

}
