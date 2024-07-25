#include <iostream>
#include <cmath>

// 1. Quoziente iterativo
int quozienteIterativo(int dividendo, int divisore) {
    int quoziente = 0;
    while (dividendo >= divisore) {
        dividendo -= divisore;
        quoziente++;
    }
    return quoziente;
}

// 2. Calcolo iterativo della radice quadrata (metodo di Newton)
double radiceQuadrata(double numero, double precisione = 0.0001) {
    if (numero < 0) return -1;  // Errore per numeri negativi
    double stima = numero;
    while (fabs(stima * stima - numero) > precisione) {
        stima = (stima + numero / stima) / 2;
    }
    return stima;
}

// 3. Ricerca dicotomica in un array
int ricercaDicotomica(const int array[], int dimensione, int target) {
    int sinistra = 0, destra = dimensione - 1;
    while (sinistra <= destra) {
        int medio = sinistra + (destra - sinistra) / 2;
        if (array[medio] == target) return medio;
        if (array[medio] < target) sinistra = medio + 1;
        else destra = medio - 1;
    }
    return -1;  // Elemento non trovato
}

// 4. Funzione che modifica un array (passaggio per riferimento)
void raddoppiaElementi(int array[], int dimensione) {
    for (int i = 0; i < dimensione; i++) {
        array[i] *= 2;
    }
}

// 5. Funzione che stampa un array
void stampaArray(const int array[], int dimensione) {
    for (int i = 0; i < dimensione; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Esempio 1: Quoziente iterativo
    std::cout << "1. Calcolo del quoziente iterativo:" << std::endl;
    int dividendo = 20, divisore = 3;
    int quoziente = quozienteIterativo(dividendo, divisore);
    std::cout << dividendo << " / " << divisore << " = " << quoziente << std::endl;

    // Esempio 2: Calcolo della radice quadrata
    std::cout << "\n2. Calcolo iterativo della radice quadrata:" << std::endl;
    double numero = 16;
    std::cout << "Radice quadrata di " << numero << " = " << radiceQuadrata(numero) << std::endl;

    // Esempio 3: Uso di array e ricerca dicotomica
    std::cout << "\n3. Uso di array e ricerca dicotomica:" << std::endl;
    int array[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int dimensione = sizeof(array) / sizeof(array[0]);
    
    std::cout << "Array originale: ";
    stampaArray(array, dimensione);

    int target = 7;
    int posizione = ricercaDicotomica(array, dimensione, target);
    if (posizione != -1) {
        std::cout << "Elemento " << target << " trovato alla posizione " << posizione << std::endl;
    } else {
        std::cout << "Elemento " << target << " non trovato" << std::endl;
    }

    // Esempio 4: Modifica dell'array (passaggio per riferimento)
    std::cout << "\n4. Modifica dell'array (raddoppio degli elementi):" << std::endl;
    raddoppiaElementi(array, dimensione);
    std::cout << "Array dopo il raddoppio: ";
    stampaArray(array, dimensione);

    // Esempio 5: Tabella di traccia per il quoziente iterativo
    std::cout << "\n5. Tabella di traccia per il quoziente iterativo:" << std::endl;
    std::cout << "Dividendo  Divisore  Quoziente" << std::endl;
    int tempDividendo = dividendo;
    int tempQuoziente = 0;
    while (tempDividendo >= divisore) {
        std::cout << tempDividendo << "         " << divisore << "         " << tempQuoziente << std::endl;
        tempDividendo -= divisore;
        tempQuoziente++;
    }
    std::cout << tempDividendo << "         " << divisore << "         " << tempQuoziente << " (Risultato finale)" << std::endl;

    return 0;
}