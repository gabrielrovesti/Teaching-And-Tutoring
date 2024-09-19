#include <iostream>
#include <string>

// Struct = struttura dati con caratteristiche (informazioni)
// fatte apposta

using namespace std;

struct Libro{
    // insieme di titoli (1)
    // insieme di autori (2)
    // anno di pubblicazione (3)

    char titolo[50];
    char autore[50];
    int anno;
};

// Firma/prototipo funzione = nome/tipo/parametri
void bubbleSort(Libro libri[], int n){
    // due cicli prendendo dal vettore "libri" l'anno
    // ordina a coppie gli elementi usando scambio ("swap")
    // es. [[1 5] 3 2 4 

    for(int i = 0; i < n; i++){
        for(int j = 0; i < n; i++){
            if(libri[j].anno > libri[j+1].anno){
                // salvo la posizione interna "j"
                Libro temp = libri[j];
                libri[j] = libri[j+1];
                libri[j+1] = temp;
            }
        }
    }
    return;
}

// Pseudocodifica (versione abbozzata)

/*
funzione bubbleSort(void bubbleSort(Libro libri[], int n))

    Libro temp;

    for i = 1 ad n
        for j = 1 ad n
            se libri[j].anno > libri[j+1].anno allora

            temp <- libri[j]
            ....
fine
*/

/*

        --- Tabella di traccia ---

Libri       0   1   2
n           2

/// 1954 > 1949?
/// Allora scambio!

*/

// C'è o non c'è l'elemento?
int ricercaLineare(Libro libri[], int n, int anno){

    for(int i = 0; i < n; i++){
        if(libri[i].anno == anno){
            return 1;
        }
    }
    return -1;
}

// Cose in più
// PRE (precondizioni = cose note prima)
// n >=0, libri con almeno un elemento, anno >=0

int ricercaDicotomica(Libro libri[], int n, int anno){
    // uso la metà
    // e rispetto ad essa ordino inizio e fine

    // ritorno l'indice trovato a metà oppure -1

    // Inizio? --> 0
    // Fine? --> n

    int inizio = 0;
    int fine = n;

    while(inizio < fine){
        int meta = (inizio + fine) / 2;

        // es. 5 2 [3] 4 1 0

        // o abbiamo fortuna di beccarlo subito a metà

        if(libri[meta].anno == anno){
            return meta;
        }

        // o andiamo avanti
        if(libri[meta].anno < anno){
            inizio = meta + 1;
        }
        else{
            fine = meta - 1;
        }

        // o andiamo indietro
    }
}

// POST (postcondizioni = risultati/output)

// ritorna un indice != nullo che è la nostra metà nell'array ordinato

// parametri formali = questi sono per firma, questi rimangono - quelli che la funzione utilizza al suo interno

double calcolaAnnoMedio(Libro libri[], int n){
    // somma di tutti gli elementi

    int somma = 0;

    for(int i = 0; i < n; i++){
        somma += libri[i].anno;
    }

    return somma / n;

    // ritorno la media come sonna / numero di elementi    
}

// Funzioni di comodo/utilità

// Scambio = utile per ordinamento / usa riferimenti
void scambia(Libro& a, Libro &b){
    Libro temp = a;
    a = b;
    b = temp;
}
// Riferimento (detto anche alias) - ripercuote gli effetti dentro la memoria delle modifiche

// const = non faccio modifiche (rimane non toccata la memoria)

// Stampa = uso classico di parametro per riferimento (costante)
void stampaLibro(const Libro& libro){
    cout << "Titolo" << libro.titolo << ", Autore: " << libro.autore << ", Anno: " << libro.anno << endl;
}

int main(){
    return 0;

    Libro biblioteca[2] = {
        {"Il Signore degli Anelli", "J.R.R.Tolkien", 1954}, // tuple = dati formattati in modo fisso
        {"1984", "George Orwell", 1949}
    };
    int n = 2;

    int anno = 1950;

    bubbleSort(biblioteca, n);
    // attuali = noti al momento della chiamata di funzione

    ricercaLineare(biblioteca, n, anno);
    ricercaDicotomica(biblioteca, n, anno);

    calcolaAnnoMedio(biblioteca, n);
}