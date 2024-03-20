#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numBiglie, turno, modoComputer;
    int mossa;
    srand(time(NULL));

    // Generiamo il numero iniziale di biglie (compreso fra 10 e 100)
    numBiglie = rand() % 100 + 1;

    // Generiamo il turno (0: il computer gioca per primo, 1: l'umano gioca per primo)
    turno = rand() % 2;

    // Generiamo la modalità del computer (0: stupido, 1: intelligente)
    modoComputer = rand() % 2;

    printf("Benvenuto nel gioco di Nim!\n");
    printf("Numero iniziale di biglie: %d\n", numBiglie);
    if (modoComputer) {
        printf("Il computer gioca in modo intelligente\n");
    } else {
        printf("Il computer gioca in modo stupido\n");
    }

    while (numBiglie > 0) {
        // Visualizza il turno corrente
        if (turno) {
            printf("\nTurno dell'umano.\n");
        } else {
            printf("\nTurno del computer.\n");
        }

        if (turno) {
            // Turno dell'umano
            printf("Quante biglie vuoi levare? ");
            scanf("%d", &mossa);

            while (mossa < 1 || mossa > numBiglie / 2 || (numBiglie == 1 && mossa != 1)) {
                if (numBiglie == 1) {
                    break;
                } else {
                    printf("Mossa non valida. Devi levare almeno 1 biglia e non piu' della meta'. Riprova: ");
                }
                scanf("%d", &mossa);
            }
        } else {
            // Turno del computer
            if (modoComputer) {
                // Modalità intelligente del computer
                int potenzaDiDue = 1;
                while (potenzaDiDue * 2 - 1 <= numBiglie) {
                    potenzaDiDue *= 2;
                }
                mossa = numBiglie - (potenzaDiDue - 1);
            } else {
                // Modalità stupida del computer
                if (numBiglie == 1) {
                    mossa = 1;
                } else {
                    mossa = rand() % (numBiglie / 2) + 1;
                }
            }
            printf("Il computer ha levato %d biglie.\n", mossa);
        }

        numBiglie -= mossa;
        printf("Numero di biglie rimanenti: %d\n", numBiglie);
        
        // Cambio del turno dopo aver scelto la mossa e aggiornato il numero di biglie
        if(turno == 0){
            turno = 1;
        } else {
            turno = 0;
        }
    }

    // Stabiliamo il vincitore
    if (!turno) {
        printf("\nHa vinto l'umano!\n");
    } else {
        printf("\nHa vinto il computer!\n");
    }

    return 0;
}
