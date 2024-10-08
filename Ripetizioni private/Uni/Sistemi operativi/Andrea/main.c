#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "procedure.h"

#define QUANTITA_INIZIALE 500
#define VALORE_INIZIALE 100

void *aggiornatore(void *arg);
void *azionista(void *arg);

int main() {
    pthread_t thread_aggiornatore;
    pthread_t thread_azionisti[3];
    MonitorPortafoglio m[3];

    // Inizializza i portafogli
    for (int i = 0; i < 3; i++) {
        inizializza(&m[i], QUANTITA_INIZIALE, VALORE_INIZIALE);
    }

    // Crea il thread aggiornatore
    pthread_create(&thread_aggiornatore, NULL, aggiornatore, (void *)m);

    // Crea i thread azionisti
    for (int i = 0; i < 3; i++) {
        pthread_create(&thread_azionisti[i], NULL, azionista, (void *)&m[i]);
    }

    // Attende la terminazione del thread aggiornatore
    pthread_join(thread_aggiornatore, NULL);

    // Attende la terminazione dei thread azionisti
    for (int i = 0; i < 3; i++) {
        pthread_join(thread_azionisti[i], NULL);
        termina(&m[i]);
    }

    return 0;
}

void *aggiornatore(void *arg) {
    MonitorPortafoglio *m = (MonitorPortafoglio *)arg;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) {
            int valore = 100 + (rand() % 21 - 10);
            printf("[AGGIORNATORE] Aggiornamento titolo %d, valore %d\n", j, valore);
            aggiorna(&m[j], valore);
        }
        sleep(1);
    }

    for (int j = 0; j < 3; j++) {
        aggiorna(&m[j], 200);
        sleep(1);
        aggiorna(&m[j], 0);
    }

    return NULL;
}

void *azionista(void *arg) {
    MonitorPortafoglio *m = (MonitorPortafoglio *)arg;

    printf("[AZIONISTA] Richiesta di vendita azioni, prezzo offerto 105\n");
    vendita(m, 50, 105);
    int valore = leggi(m);
    printf("[AZIONISTA] Vendita effettuata, valore attuale %d\n", valore);

    printf("[AZIONISTA] Richiesta di acquisto azioni, prezzo offerto 95\n");
    acquisto(m, 50, 95);
    valore = leggi(m);
    printf("[AZIONISTA] Acquisto effettuato, valore attuale %d\n", valore);

    return NULL;
}
