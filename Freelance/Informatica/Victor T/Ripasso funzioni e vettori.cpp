#include <iostream>

using namespace std;

// Funzioni

// Nome --> aggiungi
// Prototipo = Nome + parametri
// Tipo di ritorno = void - vuoto / int - intero / double = numeri con virgola

// Parametri = vanno nelle parentesi tonde
// per valore = copia locale
// per riferimento = puntatore per posizione dello specifico valore
// indirizzo di una certa variabile
int aggiungi(int val1, int& val2){
    return val1 + val2;  
}

// Funzione di sscambio tra due numeri ricevuti in ingresso
void scambia(int& val1, int& val2){
    int temp = val1; // copia del primo valore
    val1 = val2;    // il primo valore diventa il secondo
    val2 = temp;   // il secondo valore diventa il primo    
}

// Ricevuti in ingresso i parametri "a", "b" e "c" passati per valore
// ritorni i risultati su radici "x1" e "x2" per riferimento
void equazioneSecondoGrado(int a, int b, int c, int &x1, int &x2){
    double delta = (b * b) - (4 * a * c); // soluzione

    // Gestiamo i singoli casi
    if(delta > 0){
        x1 = -b + (sqrt(delta)/2 * a); // Calcolo delle soluzini
        x2 = -b - (sqrt(delta)/2 * a);
    }
    if(delta == 0){
        x1 = 0;
        x2 = 0;
    }
    if(delta < 0){
        cout << "Non esistono soluzioni reali";
    }
}

// Funzione che riceva in ingresso il prezzo di listino (prezzo > 0) e la percentuale di sconto,
// capendo il prezzo da pagare



// Funzione che riceve in ingresso i valori interi della base e dell'esponente e calcola la potenza



// Overloading funzioni



// Funzioni che legga tre diversi numeri tra di loro e li visualizza ordinati in senso
// crescente mediante una funzione



// Funzione che legge il raggio di circonferenza e calcola perimetro e area del cerchio

int main(){
    // & = referenziazione
    // * = dereferenziazione

    int a = 1;
    // Puntatore = accesso ad un'area specifica di memoria
    int *ptr = &a; // si legge: "assegna a ptr l'indirizzo di a"
    // * = accesso al primi lemento
    int b = *ptr; // si legge: "assegna a b il valore puntato da ptr"
    cout << "a: " << a << endl; // 1
    cout << "b: " << b << endl; // 1
    cout << "*ptr: " << *ptr << endl; // 1
    
    int array[10]; // vettore
    // si conta da 0 e si arriva fino a 9
    
    for(int i = 0; i < 10; i++){
        // accedo al singolo elemento dentro al ciclo
        // (elemento in posizione "i")
        array[i] = 3;

    }
}

// Funzione che calcola il prodotto di 100 numeri reali e ne salva il risultato
// in una struttura apposita
// Esempio di funzione che usa un vettore e assegna un valore

double prodotto_numeri(double numeri[]){
    double prodotto = 0;
    for(int i=0; i < 100; i++){
        // Uguale a fare prodotto = prodotto * ...
        prodotto *= numeri[i];
    }
}

// Matrice = gestire un ciclo per ognuna delle sue dimensioni

// int v[5][4] = 5 righe e 4 colonne
/*
    [][][][]
    [][][][]
    [][][][]
    [][][][]
    [][][][]
*/
// Come accedere ad una matrice
/*
    for(int i = 0; i < 5; i++){
        for(j = 0; j < 4; j++){
            
        }
    }
*/
