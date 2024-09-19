// Catalogo libri

// 1) Operazioni vettori = inserimento/ricerca/cancellazione
// 2) Previo (prima) ordinamento dei vettori stessi
// (questo perché rende le operazioni di cui sopra più efficienti)
// 3) Metodi in più = statistiche/stampa

#include <iostream>

// Catalogo?
    // (1) Struct
    // (2) Vettore di stringhe

// Variabili globali
    // Se metto qui la variabile tutti la vedono
    // problema -> pesa di più in memoria

// prende il tipo definito dall'utente e ne stampa tutte le info
struct Libro {
    std::string titolo;
    std::string autore;
    int annoP;
    double prezzo;
};

// funzione di stampa
// = stampa "personalizzata" = prendo il tipo di dati

void ordinaCatalogo(Libro catalogo[], int scelta) {
    // insertion sort (1)
    // selection sort (2)
    // bubble sort (3)

    // if(scelta == 1) // bubbleSort
    //    ...
}

// logica swap = scambio

// int temp = arr[i]
// arr[i] = arr[j]
// arr[j] = temp

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Ordina gli elementi "j" usando "i"
        // muovendosi a coppie come le bolle
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Confronti l'elemento attuale con il successivo
        // e verifichi per ognuno se è maggiore
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n)
{
    // Muove uno ad uno gli elementi non ordinati
    for (int i = 0; i < n - 1; i++)
    {
        // Trova il minimo
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }

        // Scambia il minimo trovato
        if (min != i)
            std::swap(arr[min], arr[i]);
    }
}

void stampaCatalogo(const Libro catalogo[]) {

    for(int i = 0; i < 3; i++) {    // for(int i: n)
        // o da 0 a 2 - o da 1 a 3 a livello di posizioni
        std::cout << "Titolo " << catalogo[i].titolo << ", Autore"
        << catalogo[i].titolo << std::endl;
    }
}

// ricerche

// dicotomica = detta anche binaria
int binarySearch(Libro catalogo[], std::string autore) {
    // metà sx e dx
    int sx = 0;
    int dx = 2;
    // 3 elementi ma partiamo a contare da 0 = fine effettiva
    // = cioè non vai fuori dai confini dell'array

    while(sx <= dx) {
        int pivot = sx + (dx - sx) / 2;
        // elemento medio
        if(catalogo[pivot].autore == autore) {
            return pivot;
        }
        if(catalogo[pivot].autore < autore) {
            sx = pivot + 1;
        }
        if(catalogo[pivot].autore > autore) {
            dx = pivot + 1;
        }
    }
}

// ricerca lineare = classica
int linearSearch(Libro catalogo[], std::string autore) {
    for(Libro libro: catalogo) {
        if(libro.autore == autore) {
            return 0;
            break;
        }
    }
    return -1;
}

// cancellazione

int main() {

// Variabili locali
    // lascio che lo vedano solo le funzioni che mi servono
    // in questo modo, all'uscita di quella funzione, le cancelliamo
    Libro catalogo[3] = {
        {"Il nome della rosa", "Umberto Eco", 1980, 12.99},
        {"1984", "Orwell", 1949, 10.99},
        {"Cent'anni di solitudine", "G. G. Marquez", 1967, 14.99},
    };
    int scelta;

    do {
        std::cout << "\n --- Gestione Catalogo Libri ---" << std::endl;
        std::cout << "1. Visualizza catalogo" << std::endl;
        std::cout << "2. Aggiungi libro" << std::endl;
        std::cout << "3. Ordina catalogo" << std::endl;
        std::cout << "4. Cerca libro per autore" << std::endl;
        std::cout << "5. Calcola statistiche" << std::endl;

        std::cin >> scelta;

        switch(scelta) {
            case 1: // if scelta == 1
                stampaCatalogo(catalogo);
                break;
            case 0:
                std::cout << "Grazie per aver usato il sistema" << std::endl;
            default:
                std::cout << "Scelta non valida. Riprova" << std::endl;
        }

    } while(scelta != 0);

    return 0;
}
