// Scambia valori

#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5, y = 10;
    cout << "Prima dello scambio: x = " << x << ", y = " << y << endl;
    swap(x, y);
    cout << "Dopo lo scambio: x = " << x << ", y = " << y << endl;
    return 0;
}

// Calcola il massimo

#include <iostream>
#include <string>
using namespace std;

void invertiStringa(string &str) {
    int n = str.length();
    for (int i = 0; i < n / 2; i++) {
        swap(str[i], str[n - i - 1]);
    }
}

int main() {
    string parola = "ciao";
    cout << "Stringa originale: " << parola << endl;
    invertiStringa(parola);
    cout << "Stringa invertita: " << parola << endl;
    return 0;
}

// Inverti stringa

#include <iostream>
#include <string>
using namespace std;

void invertiStringa(string &str) {
    int n = str.length();
    for (int i = 0; i < n / 2; i++) {
        swap(str[i], str[n - i - 1]);
    }
}

int main() {
    string parola = "ciao";
    cout << "Stringa originale: " << parola << endl;
    invertiStringa(parola);
    cout << "Stringa invertita: " << parola << endl;
    return 0;
}

// Calcola l'area del rettangolo

#include <iostream>
using namespace std;

void calcolaAreaRettangolo(int lunghezza, int larghezza) {
    int area = lunghezza * larghezza;
    cout << "L'area del rettangolo e': " << area << endl;
}

int main() {
    int l = 5, w = 3;
    calcolaAreaRettangolo(l, w);
    return 0;
}

// Verifica se un numero è primo

#include <iostream>
using namespace std;

bool isPrimo(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int numero = 17;
    if (isPrimo(numero)) {
        cout << numero << " e' un numero primo." << endl;
    } else {
        cout << numero << " non e' un numero primo." << endl;
    }
    return 0;
}

// Somma degli elementi di un array

#include <iostream>
using namespace std;

int sommaArray(int arr[], int size) {
    int somma = 0;
    for (int i = 0; i < size; i++) {
        somma += arr[i];
    }
    return somma;
}

int main() {
    int numeri[] = {3, 5, 2, 8, 1};
    int dimensione = sizeof(numeri) / sizeof(numeri[0]);
    int risultato = sommaArray(numeri, dimensione);
    cout << "La somma degli elementi dell'array e': " << risultato << endl;
    return 0;
}

// Conta occorrenze di un carattere in una stringa

#include <iostream>
#include <string>
using namespace std;

int contaOccorrenze(string &str, char c) {
    int count = 0;
    for (char x : str) {
        if (x == c) {
            count++;
        }
    }
    return count;
}

int main() {
    string parola = "banana";
    char carattere = 'a';
    int occorrenze = contaOccorrenze(parola, carattere);
    cout << "Il carattere '" << carattere << "' appare " << occorrenze << " volte nella stringa '" << parola << "'." << endl;
    return 0;
}

// Calcola la potenza

#include <iostream>
using namespace std;

int calcolaPotenza(int base, int esponente) {
    int risultato = 1;
    for (int i = 0; i < esponente; i++) {
        risultato *= base;
    }
    return risultato;
}

int main() {
    int b = 2, e = 3;
    int potenza = calcolaPotenza(b, e);
    cout << b << " elevato a " << e << " e' uguale a " << potenza << endl;
    return 0;
}

// Ordina un array

#include <iostream>
using namespace std;

void ordinaArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int numeri[] = {5, 2, 8, 1, 9};
    int dimensione = sizeof(numeri) / sizeof(numeri[0]);
    cout << "Array originale: ";
    for (int i = 0; i < dimensione; i++) {
        cout << numeri[i] << " ";
    }
    cout << endl;
    ordinaArray(numeri, dimensione);
    cout << "Array ordinato: ";
    for (int i = 0; i < dimensione; i++) {
        cout << numeri[i] << " ";
    }
    cout << endl;
    return 0;
}

// Conversione in maiuscolo

#include <iostream>
#include <string>
using namespace std;

void convertiInMaiuscolo(string &str) {
    for (char &c : str) {
        c = toupper(c);
    }
}

int main() {
    string parola = "ciao";
    cout << "Stringa originale: " << parola << endl;
    convertiInMaiuscolo(parola);
    cout << "Stringa in maiuscolo: " << parola << endl;
    return 0;
}