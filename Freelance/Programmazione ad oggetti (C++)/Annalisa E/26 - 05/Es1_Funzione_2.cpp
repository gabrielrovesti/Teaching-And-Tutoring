#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <string>
#include <stdexcept>
#include <type_traits>

using namespace std;

template <class T>
list<const iostream*> compare(vector<ostream*>& v, vector<const T*>& w) {
    if (v.size() != w.size()) {
        throw string("");  // Solleva un'eccezione con stringa vuota se le dimensioni sono diverse
    }

    list<const iostream*> result;

    for (size_t i = 0; i < v.size(); ++i) {
        // Controlliamo se *v[i] è di tipo fstream
        if (dynamic_cast<fstream*>(v[i]) && typeid(*v[i]) == typeid(*w[i])) {
            // Caso 2(a): *v[i] è un fstream e dello stesso tipo di *w[i]
            result.push_back(v[i]);
            v.erase(v.begin() + i);
            w.erase(w.begin() + i);
            --i; // decrementiamo l'indice per compensare la rimozione
        } else if (dynamic_cast<stringstream*>(w[i]) && w[i]->good() && typeid(*v[i]) != typeid(*w[i])) {
            // Caso 2(b): *w[i] è un stringstream in stato good e *v[i] e *w[i] sono di tipo diverso
            result.push_back(w[i]);
        }
    }

    return result;
}

int main() {
    vector<ostream*> v;
    vector<const iostream*> w;

    // Esempio di utilizzo della funzione compare
    // Creiamo alcuni stream di esempio
    fstream fs1, fs2;
    stringstream ss1, ss2;

    // Popoliamo i vettori
    v.push_back(&fs1);
    v.push_back(&fs2);
    v.push_back(&ss1);

    w.push_back(&fs1);
    w.push_back(&ss1);
    w.push_back(&ss2);

    try {
        list<const iostream*> result = compare(v, w);

        // Stampa il risultato
        for (const auto& elem : result) {
            cout << elem << " ";
        }
        cout << endl;
    } catch (const string& e) {
        cout << "Eccezione catturata: " << e << endl;
    }

    return 0;
}
