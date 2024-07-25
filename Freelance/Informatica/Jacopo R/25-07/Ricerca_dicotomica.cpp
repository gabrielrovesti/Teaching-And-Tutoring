#include <iostream>

// Funzione per la ricerca dicotomica
int ricercaDicotomica(const int array[], int dimensione, int target) {
    int sinistra = 0;
    int destra = dimensione - 1;

    while (sinistra <= destra) {
        int medio = sinistra + (destra - sinistra) / 2;

        // Elemento trovato
        if (array[medio] == target) {
            return medio;
        }

        // Se l'elemento è più grande, ignora la metà destra
        if (array[medio] > target) {
            destra = medio - 1;
        }
        // Se l'elemento è più piccolo, ignora la metà sinistra
        else {
            sinistra = medio + 1;
        }
    }

    // Elemento non trovato
    return -1;
}

int main() {
    const int dimensione = 10;
    int array[dimensione] = {2, 3, 4, 10, 40, 50, 60, 70, 80, 90};
    int target;

    std::cout << "Array ordinato: ";
    for (int i = 0; i < dimensione; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Inserisci il numero da cercare: ";
    std::cin >> target;

    int risultato = ricercaDicotomica(array, dimensione, target);

    if (risultato != -1) {
        std::cout << "L'elemento " << target << " è presente all'indice " << risultato << std::endl;
    } else {
        std::cout << "L'elemento " << target << " non è presente nell'array" << std::endl;
    }

    return 0;
}