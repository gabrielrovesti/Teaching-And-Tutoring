#include <stdio.h>

/*
 * Stampare l'insieme dei divisori non banali 
 * di un numero x>0. Un divisore non banale è 
 * un divisore diverso da 1 e x. 
 * Inoltre, se x è primo, stampare 
 * "il numero x è primo".
 * 
 * Es. se x=5 stampa
 * Il numero 5 è primo
 * 
 * Es. se x=6 stampa
 * Il numero 6 è divisibile per 2
 * Il numero 6 è divisibile per 3
 * 
 * Per la consegna utilizzare x=63
 * 
 */

/*
 * Suggerimento: per determinare se un numero è
 * primo, utilizzare una variabile che conti il 
 * numero di divisori trovati fino a quel momento
 */

int main() {

    int x = 63;
    int candidato_div = 2; // non vogliamo controllare 1 come divisore
    int numero_divisori = 0; // conta il numero di divisori trovati

    while (candidato_div < x) { // non vogliamo controllare x come divisore

        if (x % candidato_div == 0) { // x divisibile per candidato_div
            printf("Il numero %d è divisibile per %d\n", x, candidato_div);
            numero_divisori = numero_divisori + 1;
        }
        candidato_div = candidato_div + 1; 
    } 

    if (numero_divisori == 0) {
        printf("il numero %d è primo\n", x);
    }

}

