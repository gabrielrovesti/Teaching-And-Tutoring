#include <stdio.h>

/*
 * Data una costante intera SOGLIA, stampare il più piccolo numero
 * maggiore di SOGLIA che non sia divisibile per i seguenti numeri: 2, 3, 5.
 * Es. se SOGLIA = 4, il programma stampa
 * 7
 *
 * Per la consegna, utilizzare SOGLIA = 63
 *
 */


int main () {

    int SOGLIA = 63;
    //inizializzare a SOGLIA + 1 (il numero deve essere strettamente più grande di soglia)
    int x = SOGLIA + 1;

    //se x è divisibile per 2 o per 3 o per 5, aumentiamo x di uno
    while ((x % 2 == 0) || (x % 3 == 0) || (x % 5 == 0)){
        x++;
    }
    //usciamo dal ciclo solo quando x non è divisibile per nessuno dei 3 numeri

    printf("%d\n", x);

}
