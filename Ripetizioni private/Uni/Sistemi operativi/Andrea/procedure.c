#include <stdio.h>
#include <pthread.h>
#include "procedure.h"

void inizializza(MonitorPortafoglio *m, int quantita_iniziale, int valore_iniziale) {
    m->valore = valore_iniziale;
    m->quantita = quantita_iniziale;
    pthread_mutex_init(&m->mutex, NULL);          // Inizializza mutex
    pthread_cond_init(&m->cond_acquisto, NULL);   // Inizializza variabile condizione per acquisto
    pthread_cond_init(&m->cond_vendita, NULL);    // Inizializza variabile condizione per vendita
}

void termina(MonitorPortafoglio *m) {
    pthread_mutex_destroy(&m->mutex);             // Dealloca mutex
    pthread_cond_destroy(&m->cond_acquisto);      // Dealloca variabile condizione
    pthread_cond_destroy(&m->cond_vendita);
}

void acquisto(MonitorPortafoglio *m, int quantita, int prezzo) {
    pthread_mutex_lock(&m->mutex);
    while (prezzo < m->valore) {  // Condizione per sospensione
        pthread_cond_wait(&m->cond_acquisto, &m->mutex);
    }
    m->quantita += quantita;
    pthread_mutex_unlock(&m->mutex);
}

void vendita(MonitorPortafoglio *m, int quantita, int prezzo) {
    pthread_mutex_lock(&m->mutex);
    while (prezzo > m->valore || m->quantita < quantita) {  // Condizioni per sospensione
        pthread_cond_wait(&m->cond_vendita, &m->mutex);
    }
    m->quantita -= quantita;
    pthread_mutex_unlock(&m->mutex);
}

void aggiorna(MonitorPortafoglio *m, int valore) {
    pthread_mutex_lock(&m->mutex);
    m->valore = valore;
    pthread_cond_broadcast(&m->cond_acquisto);    // Riattiva tutti i thread in attesa
    pthread_cond_broadcast(&m->cond_vendita);     // Riattiva tutti i thread in attesa
    pthread_mutex_unlock(&m->mutex);
}

int leggi(MonitorPortafoglio *m) {
    pthread_mutex_lock(&m->mutex);
    int valore = m->valore;
    pthread_mutex_unlock(&m->mutex);
    return valore;
}
