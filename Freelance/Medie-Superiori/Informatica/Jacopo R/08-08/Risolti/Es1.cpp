#include <iostream>
#include <cstring>

struct Libro {
    char titolo[50];
    char autore[50];
    int anno;
};

void bubbleSort(Libro libri[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (libri[j].anno > libri[j + 1].anno) {
                Libro temp = libri[j];
                libri[j] = libri[j + 1];
                libri[j + 1] = temp;
            }
        }
    }
}

int ricercaDicotomica(Libro libri[], int n, int anno) {
    int inizio = 0;
    int fine = n - 1;

    while (inizio <= fine) {
        int meta = (inizio + fine) / 2;

        if (libri[meta].anno == anno) {
            return meta;
        }

        if (libri[meta].anno < anno) {
            inizio = meta + 1;
        } else {
            fine = meta - 1;
        }
    }

    return -1;
}

double calcolaAnnoMedio(Libro libri[], int n) {
    int somma = 0;
    for (int i = 0; i < n; i++) {
        somma += libri[i].anno;
    }
    return (double)somma / n;
}

void stampaLibro(const Libro& libro) {
    std::cout << "Titolo: " << libro.titolo << ", Autore: " << libro.autore << ", Anno: " << libro.anno << std::endl;
}

void scambiaLibri(Libro& a, Libro& b) {
    Libro temp = a;
    a = b;
    b = temp;
}

int main() {
    Libro biblioteca[5] = {
        {"Il signore degli anelli", "J.R.R. Tolkien", 1954},
        {"1984", "George Orwell", 1949},
        {"Il piccolo principe", "Antoine de Saint-Exupéry", 1943},
        {"Il nome della rosa", "Umberto Eco", 1980},
        {"Cronache marziane", "Ray Bradbury", 1950}
    };
    int n = 5;

    std::cout << "Biblioteca originale:" << std::endl;
    for (int i = 0; i < n; i++) {
        stampaLibro(biblioteca[i]);
    }

    bubbleSort(biblioteca, n);

    std::cout << "\nBiblioteca ordinata per anno:" << std::endl;
    for (int i = 0; i < n; i++) {
        stampaLibro(biblioteca[i]);
    }

    int annoRicerca = 1950;
    int indice = ricercaDicotomica(biblioteca, n, annoRicerca);
    if (indice != -1) {
        std::cout << "\nLibro del " << annoRicerca << " trovato:" << std::endl;
        stampaLibro(biblioteca[indice]);
    } else {
        std::cout << "\nNessun libro del " << annoRicerca << " trovato." << std::endl;
    }

    double annoMedio = calcolaAnnoMedio(biblioteca, n);
    std::cout << "\nAnno medio di pubblicazione: " << annoMedio << std::endl;

    // Dimostrazione del passaggio per riferimento
    std::cout << "\nScambio dei primi due libri:" << std::endl;
    scambiaLibri(biblioteca[0], biblioteca[1]);
    stampaLibro(biblioteca[0]);
    stampaLibro(biblioteca[1]);

    return 0;
}