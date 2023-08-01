#include <stdio.h>

int main() {
    int numeri[100];
    int input, conteggio = 0;

    // Chiedi all'utente di inserire i numeri
    printf("Inserisci una serie di numeri interi positivi (max 100), separati da spazi o nuove righe. Inserisci un numero negativo per terminare:\n");

    // Leggi gli input dell'utente e salvali in un vettore
    while (input >= 0 && conteggio < 100) {
        numeri[conteggio++] = input;
    }

    // Calcola la media dei numeri inseriti
    int somma = 0;
    for (int i = 0; i < conteggio; i++) {
        somma += numeri[i];
    }
    float media = (float)somma / conteggio;

    // Calcola la mediana dei numeri inseriti
    int temp;
    for (int i = 0; i < conteggio - 1; i++) {
        for (int j = i + 1; j < conteggio; j++) {
            if (numeri[i] > numeri[j]) {
                temp = numeri[i];
                numeri[i] = numeri[j];
                numeri[j] = temp;
            }
        }
    }
    float mediana;
    if (conteggio % 2 == 0) {
        mediana = (float)(numeri[conteggio / 2 - 1] + numeri[conteggio / 2]) / 2;
    } else {
        mediana = numeri[conteggio / 2];
    }

    // Calcola la moda dei numeri inseriti
    int frequenzaMassima = 0, moda, frequenzaCorrente;
    for (int i = 0; i < conteggio; i++) {
        frequenzaCorrente = 0;
        for (int j = 0; j < conteggio; j++) {
            if (numeri[i] == numeri[j]) {
                frequenzaCorrente++;
            }
        }
        if (frequenzaCorrente > frequenzaMassima) {
            frequenzaMassima = frequenzaCorrente;
            moda = numeri[i];
        }
    }

    // Stampa i risultati
    printf("Media: %.2f\n", media);
    printf("Mediana: %.2f\n", mediana);
    printf("Moda: %d\n", moda);

    return 0;
}
