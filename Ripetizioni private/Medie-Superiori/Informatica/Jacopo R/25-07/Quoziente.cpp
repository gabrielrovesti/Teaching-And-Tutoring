#include <iostream>

// Funzione per calcolare il quoziente usando il metodo iterativo
int calcolaQuozienteIterativo(int dividendo, int divisore) {
    // Controllo per la divisione per zero
    if (divisore == 0) {
        throw std::runtime_error("Errore: divisione per zero.");
    }

    // Gestione del segno del risultato
    int segno = 1;
    if (dividendo < 0) {
        dividendo = -dividendo;  // Rendiamo positivo il dividendo
        segno = -segno;          // Invertiamo il segno del risultato
    }
    if (divisore < 0) {
        divisore = -divisore;    // Rendiamo positivo il divisore
        segno = -segno;          // Invertiamo nuovamente il segno del risultato
    }

    // Inizializziamo il quoziente a 0
    int quoziente = 0;

    // Ciclo principale dell'algoritmo
    while (dividendo >= divisore) {
        dividendo -= divisore;   // Sottraiamo il divisore dal dividendo
        quoziente++;             // Incrementiamo il quoziente
    }

    // Restituiamo il quoziente con il segno corretto
    return segno * quoziente;
}

int main() {
    int dividendo, divisore;
    
    // Input del dividendo
    std::cout << "Inserisci il dividendo: ";
    std::cin >> dividendo;
    
    // Input del divisore
    std::cout << "Inserisci il divisore: ";
    std::cin >> divisore;
    
    try {
        // Chiamata alla funzione e stampa del risultato
        int risultato = calcolaQuozienteIterativo(dividendo, divisore);
        std::cout << "Il quoziente di " << dividendo << " diviso " << divisore << " è: " << risultato << std::endl;
    } catch (const std::exception& e) {
        // Gestione dell'eccezione in caso di divisione per zero
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}