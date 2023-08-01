#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int giocatore1 = 0, giocatore2 = 0;
    srand(time(NULL)); // Inizializzazione del generatore di numeri casuali con il seed del tempo attuale

    printf("Benvenuti al Gioco dei Dadi Avanzato!\n\n");

    // Loop per i dieci round del gioco
    for (int round = 1; round <= 10; round++) {
        printf("Round %d:\n", round);

        // Lancio dei due dadi per il giocatore 1
        int dado1_giocatore1 = rand() % 6 + 1; // Valore casuale tra 1 e 6 per il primo dado
        int dado2_giocatore1 = rand() % 6 + 1; // Valore casuale tra 1 e 6 per il secondo dado
        printf("Giocatore 1 ha ottenuto: %d e %d\n", dado1_giocatore1, dado2_giocatore1);
        giocatore1 += dado1_giocatore1 + dado2_giocatore1;

        // Lancio dei due dadi per il giocatore 2
        int dado1_giocatore2 = rand() % 6 + 1;
        int dado2_giocatore2 = rand() % 6 + 1;
        printf("Giocatore 2 ha ottenuto: %d e %d\n", dado1_giocatore2, dado2_giocatore2);
        giocatore2 += dado1_giocatore2 + dado2_giocatore2;

        printf("Punteggio parziale:\n");
        printf("Giocatore 1: %d\n", giocatore1);
        printf("Giocatore 2: %d\n", giocatore2);
        printf("\n");
    }

    // Dichiarazione del vincitore
    printf("Punteggio finale:\n");
    printf("Giocatore 1: %d\n", giocatore1);
    printf("Giocatore 2: %d\n", giocatore2);
    printf("\n");

    if (giocatore1 > giocatore2) {
        printf("Giocatore 1 vince!\n");
    } else if (giocatore2 > giocatore1) {
        printf("Giocatore 2 vince!\n");
    } else {
        printf("Parità! Nessun vincitore in questa partita.\n");
    }

    return 0;
}
