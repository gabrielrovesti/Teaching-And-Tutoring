#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int min, max, num, tentativo, tentativi;

    // Chiedi all'utente di inserire il valore minimo e massimo del range
    printf("Inserisci il valore minimo: ");
    scanf("%d", &min);

    printf("Inserisci il valore massimo: ");
    scanf("%d", &max);

    // Genera un numero casuale compreso tra min e max
    srand(time(NULL)); // Inizializza il generatore di numeri casuali con il tempo attuale
    num = rand() % (max - min + 1) + min;

    // Chiedi all'utente di inserire il numero di tentativi disponibili
    printf("Inserisci il numero di tentativi disponibili: ");
    scanf("%d", &tentativi);

    // Ciclo di gioco
    while (tentativi > 0) {
        printf("Tentativo rimasti: %d\n", tentativi);
        printf("Inserisci il tuo tentativo: ");
        scanf("%d", &tentativo);

        if (tentativo == num) {
            printf("Hai indovinato! Il numero era %d.\n", num);
            break;
        } else if (tentativo < num) {
            printf("Troppo piccolo. Prova ancora.\n");
        } else {
            printf("Troppo grande. Prova ancora.\n");
        }

        tentativi--;
    }

    // Verifica se l'utente ha finito i tentativi disponibili
    if (tentativi == 0) {
        printf("Hai esaurito i tentativi. Il numero da indovinare era %d.\n", num);
    }

    return 0;
}
