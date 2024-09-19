#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Inizializza il generatore di numeri casuali con il tempo attuale

    int ossigeno = rand() % 1000 + 500; // Quantità iniziale di ossigeno (tra 500 e 1500)
    int cibo = rand() % 1000 + 500;     // Quantità iniziale di cibo (tra 500 e 1500)
    int carburante = rand() % 1000 + 500; // Quantità iniziale di carburante (tra 500 e 1500)

    int giorniSimulazione;
    printf("Inserisci il numero di giorni di simulazione: ");
    scanf("%d", &giorniSimulazione);

    for (int giorno = 1; giorno <= giorniSimulazione; giorno++) {
        printf("\nGiorno %d:\n", giorno);
        
        int consumoOssigeno = rand() % 50 + 20;      // Consumo casuale di ossigeno (tra 20 e 70)
        int consumoCibo = rand() % 40 + 10;         // Consumo casuale di cibo (tra 10 e 50)
        int consumoCarburante = rand() % 100 + 50;  // Consumo casuale di carburante (tra 50 e 150)

        ossigeno -= consumoOssigeno;
        cibo -= consumoCibo;
        carburante -= consumoCarburante;

        int guastoTecnico = rand() % 3 ;  // Possibilità di guasto tecnico: 0, 1 o 2

        if (guastoTecnico == 1) {
            int risorseNecessarie = rand() % 30 + 10;  // Risorse necessarie per la riparazione (tra 10 e 40)
            printf("Guasto tecnico! Risorse necessarie per la riparazione: %d cibo.\n", risorseNecessarie);
            cibo -= risorseNecessarie;
        } else if (guastoTecnico == 2) {
            int risorseNecessarie = rand() % 50 + 20;  // Risorse necessarie per la riparazione (tra 20 e 70)
            printf("Guasto tecnico! Risorse necessarie per la riparazione: %d carburante.\n", risorseNecessarie);
            carburante -= risorseNecessarie;
        }

        printf("Stato delle risorse:\n");
        printf("Ossigeno: %d\n", ossigeno);
        printf("Cibo: %d\n", cibo);
        printf("Carburante: %d\n", carburante);

        if (ossigeno < 100 || cibo < 100 || carburante < 100) {
            printf("\n*** SITUAZIONE DI EMERGENZA! RISOLVI PRIMA DI CONTINUARE ***\n");
        }
    }

    printf("\nSimulazione conclusa.\n");
    printf("Risorse rimanenti:\n");
    printf("Ossigeno: %d\n", ossigeno);
    printf("Cibo: %d\n", cibo);
    printf("Carburante: %d\n", carburante);

    return 0;
}
