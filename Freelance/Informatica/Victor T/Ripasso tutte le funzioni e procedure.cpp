#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

// Funzione che calcola il prezzo da pagare
double calcolaPrezzoPagare(double prezzoListino, double scontoPercentuale) {
    double scontoValore = prezzoListino * (scontoPercentuale / 100);
    double prezzoPagare = prezzoListino - scontoValore;
    return prezzoPagare;
}

// Funzione che calcola la potenza
int calcolaPotenza(int base, int esponente) {
    return pow(base, esponente);
}

// Funzione che calcola il perimetro e l'area di un cerchio
void calcolaCirconferenza(double raggio, double& perimetro, double& area) {
    const double PI = 3.14159265358979323846;
    perimetro = 2 * PI * raggio;
    area = PI * raggio * raggio;
}

// Funzione che calcola le radici di un'equazione di secondo grado
void calcolaRadiciEquazione(double a, double b, double c, double& x1, double& x2) {
    double discriminante = b * b - 4 * a * c;
    if (discriminante < 0) {
        cout << "L'equazione non ha soluzioni reali." << endl;
    } else if (discriminante == 0) {
        x1 = x2 = -b / (2 * a);
    } else {
        x1 = (-b + sqrt(discriminante)) / (2 * a);
        x2 = (-b - sqrt(discriminante)) / (2 * a);
    }
}

// Funzione che ordina tre numeri in senso crescente
void ordinaNumeri(int& n1, int& n2, int& n3) {
    int temp;
    if (n1 > n2) {
        temp = n1;
        n1 = n2;
        n2 = temp;
    }
    if (n1 > n3) {
        temp = n1;
        n1 = n3;
        n3 = temp;
    }
    if (n2 > n3) {
        temp = n2;
        n2 = n3;
        n3 = temp;
    }
}

// Procedura che conta elementi positivi e negativi in un vettore
void contaPositiviNegativi(int vettore[], int dimensione, int& positivi, int& negativi) {
    positivi = 0;
    negativi = 0;
    for (int i = 0; i < dimensione; i++) {
        if (vettore[i] >= 0) {
            positivi++;
        } else {
            negativi++;
        }
    }
}

// Procedura che riempie un vettore di interi casuali
void riempiVettoreCasuale(int vettore[], int dimensione) {
    for (int i = 0; i < dimensione; i++) {
        vettore[i] = rand() % 100; // Numeri casuali tra 0 e 99
    }
}

// Procedura che acquisisce valori in un vettore di dimensione fissa
void acquisciVettore(int vettore[], int dimensione) {
    cout << "Inserisci " << dimensione << " valori interi:" << endl;
    for (int i = 0; i < dimensione; i++) {
        cin >> vettore[i];
    }
}

// Funzione che calcola il perimetro di un quadrilatero
int calcolaPerimetroQuadrilatero(int lati[4]) {
    int perimetro = 0;
    for (int i = 0; i < 4; i++) {
        perimetro += lati[i];
    }
    return perimetro;
}

int main() {
    // Esempio di utilizzo delle funzioni
    double prezzoListino, scontoPercentuale, prezzoPagare;
    cout << "Inserisci il prezzo di listino: ";
    cin >> prezzoListino;
    cout << "Inserisci la percentuale di sconto: ";
    cin >> scontoPercentuale;
    prezzoPagare = calcolaPrezzoPagare(prezzoListino, scontoPercentuale);
    cout << "Il prezzo da pagare e': " << prezzoPagare << endl;

    int base, esponente, risultatoPotenza;
    cout << "Inserisci la base: ";
    cin >> base;
    cout << "Inserisci l'esponente: ";
    cin >> esponente;
    risultatoPotenza = calcolaPotenza(base, esponente);
    cout << base << " elevato a " << esponente << " e': " << risultatoPotenza << endl;

    double raggio, perimetroCirconferenza, areaCirconferenza;
    cout << "Inserisci il raggio della circonferenza: ";
    cin >> raggio;
    calcolaCirconferenza(raggio, perimetroCirconferenza, areaCirconferenza);
    cout << "Il perimetro della circonferenza e': " << perimetroCirconferenza << endl;
    cout << "L'area della circonferenza e': " << areaCirconferenza << endl;

    double a, b, c, x1, x2;
    cout << "Inserisci i coefficienti a, b e c dell'equazione di secondo grado:" << endl;
    cin >> a >> b >> c;
    calcolaRadiciEquazione(a, b, c, x1, x2);
    cout << "Le radici dell'equazione sono: x1 = " << x1 << ", x2 = " << x2 << endl;

    int n1, n2, n3;
    cout << "Inserisci tre numeri interi: ";
    cin >> n1 >> n2 >> n3;
    ordinaNumeri(n1, n2, n3);
    cout << "I numeri ordinati in senso crescente sono: " << n1 << ", " << n2 << ", " << n3 << endl;

    const int DIMENSIONE = 5;
    int vettore[DIMENSIONE];
    int positivi, negativi;
    acquisciVettore(vettore, DIMENSIONE);
    contaPositiviNegativi(vettore, DIMENSIONE, positivi, negativi);
    cout << "Nel vettore ci sono " << positivi << " elementi positivi e " << negativi << " elementi negativi." << endl;

    const int DIMENSIONE_CASUALE = 8;
    int vettoreCasuale[DIMENSIONE_CASUALE];
    riempiVettoreCasuale(vettoreCasuale, DIMENSIONE_CASUALE);
    cout << "Il vettore riempito con numeri casuali e': ";
    for (int i = 0; i < DIMENSIONE_CASUALE; i++) {
        cout << vettoreCasuale[i] << " ";
    }
    cout << endl;

    int latiQuadrilatero[4] = {5, 7, 5, 7};
    int perimetroQuadrilatero = calcolaPerimetroQuadrilatero(latiQuadrilatero);
    cout << "Il perimetro del quadrilatero e': " << perimetroQuadrilatero << endl;

    return 0;
}