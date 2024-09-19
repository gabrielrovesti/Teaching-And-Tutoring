#include <stdio.h>

int main() {
    int N;

    do {
        printf("Inserisci il numero di elementi (minore di 20): ");
        scanf("%d", &N);
    } while (N <= 0 || N >= 20);

    int vettore[N];
    int occorrenze[N];
    int num_presenti = 0;

    printf("Inserisci %d numeri interi:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &vettore[i]);
    }

    // Inizializziamo il vettore delle occorrenze a 0
    for (int i = 0; i < N; i++) {
        occorrenze[i] = 0;
    }

    // Calcoliamo le occorrenze
    for (int i = 0; i < N; i++) {
        int num = vettore[i];
        int presente = 0;

        for (int j = 0; j < num_presenti; j++) {
            if (num == occorrenze[j]) {
                presente = 1;
                break;
            }
        }

        if (!presente) {
            occorrenze[num_presenti] = num;
            num_presenti++;
            int conteggio = 1;

            for (int j = i + 1; j < N; j++) {
                if (vettore[j] == num) {
                    conteggio++;
                }
            }

            printf("numero %d occorrenze %d\n", num, conteggio);
        }
    }

    return 0;
}
