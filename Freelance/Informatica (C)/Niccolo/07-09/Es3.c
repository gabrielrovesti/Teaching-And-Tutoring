#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numPiloti, lunghezzaPista;
    
    printf("Benvenuto nella gara automobilistica!\n");
    
    // Chiedi all'utente il numero di piloti e la lunghezza della pista
    printf("Inserisci il numero di piloti: ");
    scanf("%d", &numPiloti);
    printf("Inserisci la lunghezza della pista (in chilometri): ");
    scanf("%d", &lunghezzaPista);
    
    srand(time(NULL)); // Inizializza il generatore di numeri casuali
    
    int velocita[numPiloti];
    int distanza[numPiloti];
    int tempo[numPiloti];
    
    // Inizializza le variabili
    for (int i = 0; i < numPiloti; i++) {
        velocita[i] = rand() % 100 + 100; // Velocità casuale tra 100 e 199 km/h
        distanza[i] = 0;
        tempo[i] = 0;
    }
    
    int vincitore = -1;
    
    while (vincitore == -1) {
        for (int i = 0; i < numPiloti; i++) {
            int spostamento = velocita[i] / 3600; // Spostamento in km al secondo
            distanza[i] += spostamento;
            tempo[i]++;
            
            // Verifica se il pilota ha attraversato il traguardo
            if (distanza[i] >= lunghezzaPista) {
                vincitore = i;
                break;
            }
        }
    }
    
    // Stampa il vincitore e il tempo impiegato
    printf("Il pilota %d ha vinto la gara in %d secondi!\n", vincitore + 1, tempo[vincitore]);
    
    // Stampa il tempo di tutti i piloti
    printf("Tempi di tutti i piloti:\n");
    for (int i = 0; i < numPiloti; i++) {
        printf("Pilota %d: %d secondi\n", i + 1, tempo[i]);
    }
    
    return 0;
}
