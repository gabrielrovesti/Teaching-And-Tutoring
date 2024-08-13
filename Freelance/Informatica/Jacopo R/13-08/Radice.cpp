#include <iostream>
using namespace std; // operazioni I/O

// Calcolo iterativo radice

// libreria per funzioni matematiche
#include <cmath>
// libreria per setw
#include <iomanip> // manipolazione I/O

double calcoloRadiceQuadrata(int num, int maxIt, double precisione) {
    // prima di far la radice, controllo se il numero è valido

    if (num < 0) {
        cout << "Errore: impossibile calcolare la radice" << endl;
        // modo normale = "lanciare eccezione" - messaggio d'avvertimento
        // throw error(5);
    }

    // Calcolo effettivo radice
    // Iterativa = ciclo (while) finché non ho raggiunto massimo numero di iterazioni
    // Ad ogni passaggio, stimi come operare sul numero e continuare ad arrotondarlo
    int it = 0;
    int stima = num; // il numero attuale rappresenta cosa arrotondo all'inizio

    while(it < maxIt) {
        // prendo il numero
        // eseguo una divisione (di solito per 2/ in base al valore della radice)
        // arrotondo sul numero precedente

        double stimaPr = stima;
        stima = (stima + num / stima) / 2;
        int diff = abs(stima - stimaPr);

        // se la differenza non riesce ad essere arrotondata
        // = non puoi passare a una roba con più decimali
        if(diff < precisione) {
            break;  // esci anticipatamente dal ciclo/dalle iterazioni in caso di problemi
        }

        // setw = dice quanto spazio dedichi alla memoria dell'output/dell'input
        cout << setw(12) << it + 1
        << setw << stima << diff;

        // 4
        // stima = 2
        // 4 / 2 = 2
        // differenza = 2 - 2 = 0
        // se la divisione dà resto 0, allora hai trovato la radice (2)

        // abs = valore assoluto (prende il valore negativo e lo mette sempre positivo)
        // |-15| = 15

        it++;
    }

}

int main()
{
    // chiamata funzione
    // calcolo radice --> input/output

    int num = 0, maxIt;
    cout << "Inserisci un numero" << endl;
    cin >> num;
    // se non includo std, le cose di std (cout, cin, endl, etc.)
    // usi std::cin (scoping/"prendo"/"miro" le cose che mi serve)

    cout << "Inserisci il numero di iterazioni" << endl;
    cin >> maxIt;

    double precisione = 1e-6;

    // risultato = double (numero con la virgola)
    double radice = calcoloRadiceQuadrata(num, maxIt, precisione);

    if(radice >= 0) {
        cout << "Il risultato è: " << radice << endl;
    }

    return 0;
}

// Esempio classico

/*
#include <iostream>
#include <cmath>
double babylonianSquareRoot(double n, double epsilon = 1e-6) {
    if (n < 0) {
    std::cerr << "Cannot calculate the square root of a negative number." << std::endl;
    return -1.0; // Error code or throw an exception
    }

    if (n == 0.0) {
        return 0.0; // Square root of 0 is 0
    }

    double guess = n / 2.0; // Initial guess

    while (std::abs(guess * guess - n) > epsilon) {
        guess = 0.5 * (guess + n / guess); // Update guess using the Babylonian formula
    }

    return guess;
}

int main() {
    double number;

    std::cout << "Numero: ";
    std::cin >> number;

    double result = squareRoot(number);

    if (result != -1.0) {
    std::cout << "Square root of " << number << " is approximately: " << result << std::endl;
    }

    return 0;
}
*/