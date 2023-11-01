#include <iostream>
using namespace std;

class Nodo {
private:
    Nodo(string st = "***", Nodo* s = nullptr, Nodo* d = nullptr) : info(st), sx(s), dx(d) {}
    string info;
    Nodo* sx;
    Nodo* dx;
};

class Tree {
public:
    Tree() : radice(nullptr) {}
    Tree(const Tree& other) {
        radice = copia(other.radice); // Chiamiamo la funzione copia per copia profonda
    }

private:
    Nodo* radice;

    // Funzione di copia profonda ricorsiva
    Nodo* copia(const Nodo* nodo) {
        if (nodo == nullptr) {
            return nullptr;
        }

        // Copia il nodo corrente
        Nodo* n = new Nodo(nodo->info);

        // Copia ricorsivamente i sottoalberi sinistro e destro
        n->sx = copia(nodo->sx);
        n->dx = copia(nodo->dx);

        return n;
    }
};
