#include <stdio.h>

int main() {
    int N1, N2;

    do {
        printf("Inserisci la lunghezza del primo vettore (N1, minore di 20): ");
        scanf("%d", &N1);
    } while (N1 <= 0 || N1 >= 20);

    int vettore1[N1];

    printf("Inserisci %d numeri interi in ordine crescente per il primo vettore:\n", N1);
    for (int i = 0; i < N1; i++) {
        scanf("%d", &vettore1[i]);
    }

    do {
        printf("Inserisci la lunghezza del secondo vettore (N2, minore di 20): ");
        scanf("%d", &N2);
    } while (N2 <= 0 || N2 >= 20);

    int vettore2[N2];

    printf("Inserisci %d numeri interi in ordine crescente per il secondo vettore:\n", N2);
    for (int i = 0; i < N2; i++) {
        scanf("%d", &vettore2[i]);
    }

    int vettoreFusione[N1 + N2];

    int index1 = 0; // Puntatore per il vettore1
    int index2 = 0; // Puntatore per il vettore2
    int indexFusione = 0; // Puntatore per il vettoreFusione

    // Fusioniamo i due vettori ordinati in modo crescente
    while (index1 < N1 && index2 < N2) {
        if (vettore1[index1] < vettore2[index2]) {
            vettoreFusione[indexFusione] = vettore1[index1];
            index1++;
        } else {
            vettoreFusione[indexFusione] = vettore2[index2];
            index2++;
        }
        indexFusione++;
    }

    // Se ci sono elementi rimanenti nel vettore1, li aggiungiamo al vettoreFusione
    while (index1 < N1) {
        vettoreFusione[indexFusione] = vettore1[index1];
        index1++;
        indexFusione++;
    }

    // Se ci sono elementi rimanenti nel vettore2, li aggiungiamo al vettoreFusione
    while (index2 < N2) {
        vettoreFusione[indexFusione] = vettore2[index2];
        index2++;
        indexFusione++;
    }

    // Stampiamo il vettoreFusione
    printf("Il vettore risultante della fusione è:\n");
    for (int i = 0; i < N1 + N2; i++) {
        printf("%d ", vettoreFusione[i]);
    }
    printf("\n");

    return 0;
}
