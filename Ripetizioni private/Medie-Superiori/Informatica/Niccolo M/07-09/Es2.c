#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int saldo = 1000; // Saldo iniziale del giocatore
    int scommessa;
    int lancio1, lancio2, somma;
    char risposta;

    srand(time(NULL)); // Inizializza il generatore di numeri casuali

    printf("Benvenuto al gioco Craps!\n");

    while (saldo > 0) {
        printf("Il tuo saldo attuale è: $%d\n", saldo);
        printf("Quanto vuoi scommettere? $");
        scanf("%d", &scommessa);

        if (scommessa <= saldo) {
            lancio1 = rand() % 6 + 1;
            lancio2 = rand() % 6 + 1;
            somma = lancio1 + lancio2;

            printf("Hai lanciato i dadi: %d + %d = %d\n", lancio1, lancio2, somma);

            if (somma == 7 || somma == 11) {
                saldo += scommessa;
                printf("Hai vinto! Il tuo nuovo saldo è: $%d\n", saldo);
            } else if (somma == 2 || somma == 3 || somma == 12) {
                saldo -= scommessa;
                printf("Hai perso! Il tuo nuovo saldo è: $%d\n", saldo);
            } else {
                printf("Il gioco continua...\n");
                do {
                    lancio1 = rand() % 6 + 1;
                    lancio2 = rand() % 6 + 1;
                    somma = lancio1 + lancio2;
                    printf("Hai lanciato i dadi: %d + %d = %d\n", lancio1, lancio2, somma);
                } while (somma != 7 && somma != scommessa);

                if (somma == 7) {
                    saldo -= scommessa;
                    printf("Hai perso! Il tuo nuovo saldo è: $%d\n", saldo);
                } else {
                    saldo += scommessa;
                    printf("Hai vinto! Il tuo nuovo saldo è: $%d\n", saldo);
                }
            }
        } else {
            printf("Non hai abbastanza denaro per scommettere $%d\n", scommessa);
        }

        printf("Vuoi continuare a giocare? (S/N): ");
        scanf(" %c", &risposta);
        if (risposta != 'S' && risposta != 's') {
            printf("Grazie per aver giocato! Il tuo saldo finale è: $%d\n", saldo);
            break;
        }
    }

    return 0;
}
