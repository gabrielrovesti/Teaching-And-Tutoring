#include <iostream>

using namespace std;

// Funzione = pezzo di codice che svolge una certa operazione
double radiceQuadrata(double n, double precisione) {
    if (n < 0) {
        cout << "Inserisci un numero postivo";
    }
    if (n == 1) {
        cout << "Radice quadrata è pari ad 1";
    }

    // double = numero con la virgola
    // a livello di algoritmo noi ne esaminiamo la precisione

    double x = n; // Approssimazione iniziale

    while((x * x - n) > precisione) {
        x = (x + n / x) / 2;
    }
    return x;
}

// Passaggio parametri valore - riferimento

// Parametro = Variabile passata ad una funzione

// Per valore = Variabile che viene passata localmente
// Gli effetti delle modifiche restano solo nella funzione

int somma(int num1, int num2) {
    num1 = 10;
    num2 = 20;
    return num1 + num2;
}

// Funzioni = ritorna dei valori o li modifica
// Procedure = servono a svolgere delle operazioni senza modifiche

// Per riferimento = Variabili passate vengono modificate opportunamente
// = passiamo degli alias (&) - riferimenti a zone di memoria
void modificaCattiva(int &num1) {
    num1 = 10;
}

int main() {

    // Vettori (oppure Array)

    // Contengono insiemi di elementi
    // O sai a priori quanti elementi vuoi

    int* vettore = new int[10];

    // Non sai a priori quanti elementi ci sono
    // Alloco dinamicamente la memoria
    // Uso "new" -> heap (alloca elementi quando vuoi quanti ne vuoi)

    // Lo (*) punta al primo elemento (all'inizio)
    // Partendo dall'elemento ad indice 0

    // Per scorrere/operare sul vettore ci servono i cicli

    // Attraversamento elementi del vettore
    for(int i = 0; i < 10; i++) {
        // Modifica elemento di un vettore
        vettore[i] = i;
        // accesso ad elemento i-esimo
        // [0] 1 2 3 4 5 6 7 8 9

        // i++
        // 0 [1] 2 3 4 5 6 7 8 9
        // ...

        // Eliminazione in un vettore
        vettore[i] = 0;

    }

    // for (int i = 1; i <= 10; i++){

    //}

    // Matrici / array multi-dimensionali

    int matrice[10];
    // modo corto per istanziare l'array

    int matrice1[5][5];
    // 5 righe per 5 colonne
    /*
    1 1 1 1 1
    1 1 1 1 1
    1 1 1 1 1
    1 1 1 1 1
    1 1 1 1 1
    */

    int matrice2[4][5];
    // 4 righe per 5 colonne
    /*
    1 1 1 1 1
    1 1 1 1 1
    1 1 1 1 1
    1 1 1 1 1
    */

    // Cicli sulle matrici
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {

        }
    }

    return 0;
}

// Altro caso (con vettori) di passaggio per riferimento
void modificaCattiva2_LaVendetta(int* vettore) {
    for (int i = 0; i < 10; i++) {
        vettore[i] = 0;
    }
}
// Riferimento = tutte le modifiche su tutti gli elementi dell'array

// Tabelle di traccia
// traccio passo per passo l'esecuzione di tutto il codice
// input/output, etc.

// MCD = Massimo Comun Divisore
// Algoritmo di Euclide

int mcd (int a, int b) {
    while(b != 0) {
        // return a % b;
        int ris = a % b;
        a = b;  // scambio per continuare a dividere
        b = ris; // continua a dividere partendo da dove sei arrivato
    }
}

