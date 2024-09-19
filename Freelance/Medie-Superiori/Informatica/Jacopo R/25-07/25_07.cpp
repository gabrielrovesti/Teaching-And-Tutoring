#include <iostream>

// Ricerca dicotomica
// = guardi da due parti dell'array

// Partiamo dalla ricerca normale
// = diamo un vettore/array e poi verifichiamo se c'è o meno l'elemento

bool ricercaArray(int* array, int num) {
    bool result = false;
    if (array == nullptr || num == 0) return false; // array o numero vuoto

    for(int i = 0; i < 10; i++) {
        // Cerchiamo
        if (array[i] == num) {
            // Appena trovato, usciamo
            result = true;
            break;  // Uscita forzata, ce l'abbiamo fatta
        }

    }
    return result;
}

// Ordinamento

// Bubble sort
// = confronto tra coppie adiacenti di elementi
// = utile per scambio di coppie nell'array

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                // swap = scambio (può essere una funzione)
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Selection sort
// = divide l'input in due parti (ordinata / non-ordinata)
// = trova minimo nella parte non ordinata e lo sposta in quella ordinata

void selectionSort(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        // Salviamo l'indice attuale che sarà il minimo
        int min = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
            // swap = scambio (può essere una funzione)
            int temp = arr[min];
            arr[min] = arr[j];
            arr[j] = temp;
        }
    }
}

void insertionSort(int arr[], int n){
    // due cicli
    // salviamo l'elemento attuale
    // scambiamo con la parte non ordinata
    for(int i = 1; i < n; i++) {
        int key = arr[i]; // salvo il pivot = elemento che mi serve per ordinare
        int j = i - 1; // indice precedente per ordinare
        while(j >= 0 && arr[j] > key) { // se ancora da ordinare
            arr[j + 1] = arr[j];    // salviamo nella parte ordinata
            j = j - 1;  // salvato l'elemento e la modifica, continuiamo
        }
        arr[j + 1] = key;
    }
}

// Simple sort (insertion sort)
// = prende un elemento dalla parte non ordinata e lo sposta nella parte ordinata nella pos. corretta

// Dicotomica = divisioni successive dell'array
// = fisso un centro e guardo a dx (destra) e sx (sinistra)

/*
Si divide l’insieme dei dati su cui ricercare esattamente a metà
e si considera la parte che interessa. La parte rimasta viene ancora divisa a metà e così via.

Se scartiamo la parte a sinistra, la metà diventa il nuovo estremo sinistro della ricerca; se
scartiamo la parte a destra, la metà diventa il nuovo estremo destro della ricerca.

La divisionea metà dell’intervallo di ricerca continua finché l’elemento viene trovato e in questo caso si
ottiene come risultato la posizione dell’elemento nell’array, oppure finché l’intervallo di ricerca
si riduce a due elementi consecutivi dell’array e viene visualizzato un messaggio di “elemento non trovato”.
 */

// https://www.edatlas.it/scarica/SIA_3/Capitolo8/MaterialiOnLine/3RicercaDicotomica.pdf

// Esempio pratico "alla tabella di traccia"

/*
5 2 4 1

output -> intero
input -> int array[], int dim, int num

1)  Elemento 1: 5
Medio = 2;
Sinistra = 5;
Destra 1;
*/

// Riferimento utile: https://www.edatlas.it/scarica/informatica/InfoTic/Capitolo8/MaterialiOnLine/4TabellaTraccia.pdf

int ricercaDicotomica(int array[], int dim, int num) {

    int sinistra = 0;
    int destra = dim - 1;

    while(sinistra <= destra) {
        // Elemento medio (pivot)
        int medio = sinistra + (destra - sinistra) / 2;
        // destra è più grande di sx, così sei sicuro sull'elemento medio

        // Elemento trovato
        if(array[medio] == num) {
            return num;
        }

        // Se l'elemento è più grande, ignora la parte destra
        if(array[medio] > num) {
            destra = medio - 1;
        }

        // Se l'elemento è più piccolo, ignora la parte sinistra
        if(array[medio] < num) {
            sinistra = medio + 1;
        }
    }

    return -1;
}

int calcoloQuoziente(int dividendo, int divisore) {
    // Controllo se divisione per zero

    // Quoziente 8/4 = 2
    // Dividendo = 4
    // Divisore = 8

    // NaN = Not a Number --> so' cazzi in memoria

    if (divisore == 0)
        throw std::runtime_error("Errore: divisione per zero");
    // Eccezione = lancio (throw) un comportamento strano

    // Gestiamo il risultato
    int segno = 1;
    if(dividendo < 0) {
        dividendo = -dividendo; // Rendiamo positivo il dividendo per risultato positivo
        segno = -segno;
    }
    if(divisore < 0) {
        divisore = -divisore; // Rendiamo positivo il divisore per risultato positivo
        segno = -segno;
    }

    int quoziente = 0;

    while(dividendo >= divisore) {
        dividendo -= divisore; // divisione effettuata come sottrazione = aka un certo numero di volte
        quoziente ++; // incremento quoziente e do valore al risultato
    }

    // Ritorno quoziente (sia esso positivo o negativo)
    return segno * quoziente;
}

int main() {

    int array[10];

    const int dim = 10;
    int array1[dim] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    // sizeof = dimensione dell'array
    int dimensione = sizeof(array1); // 10;

    // Ricerca (normale) in un array

    int num = 0;

    std::cout << "Inserisci un numero da cercare: ";
    std::cin >> num;

    bool result = false;

    result = ricercaArray(array1, num);
    std::cout << "Numero trovato: " << result << std::endl;

    // Ricerca dicotomica in un array

    int risultato = ricercaDicotomica(array1, dim, num);

    std::cout << "Ricerca dicotomica con risultato: " << risultato << std::endl;

    int dividendo = 0, divisore = 0;

    std::cout << "Inserisci il dividendo: ";
    std::cin >> dividendo;

    std::cout << "Inserisci il divisore: ";
    std::cin >> divisore;

    int quoziente = calcoloQuoziente(dividendo, divisore);
    std::cout << "Quoziente: " << quoziente << std::endl;

    return 0;
}

