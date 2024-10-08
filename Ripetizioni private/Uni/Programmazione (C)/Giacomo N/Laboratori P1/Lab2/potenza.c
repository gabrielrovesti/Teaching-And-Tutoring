#include <stdio.h>

/* 
    Definire una funzione che, dati due 
    interi: base ed esponente, restituisce 
    base elevata ad esponente. Il prototipo della
    funzione è il seguente: 

    int potenza(int base, int esponente);

    La funzione deve soddisfare le seguenti PRE e POST:
    PRE: base è un intero positivo (>=1) ed esponente un intero positivo o nullo.
    POST: la funzione restituisce base^esponente. 

    Es. se l'input è: "2 3" stampa 
    8
 */



/* 
    PRE: base>=1, esponente>=0 
    POST: restituisce base^esponente
*/
int potenza(int base, int esponente);



int main (void) {

    int base, esp;
    //fornire due interi separati da spazio e seguiti da Invio
    scanf("%d %d", &base, &esp);

    printf("%d\n", potenza(base, esp));

}


int potenza(int base, int esponente) {
    /* moltiplica base*base*...*base esponente volte */
    int risultato=1;
    while (esponente > 0) {
        risultato = risultato * base;
        esponente = esponente-1;
    }
    return risultato; 
}
