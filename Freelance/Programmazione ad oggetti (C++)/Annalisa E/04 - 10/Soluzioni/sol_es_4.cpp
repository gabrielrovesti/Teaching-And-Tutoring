#include <iostream>
using namespace std;
//Definire un costruttore di default legale per la classe C.

class E {
    private:
        int x;
    public:
        E(int z=0): x(z) {}
};

class C {
    private:
        int z;
        E x;
        const E e; //ATTENZIONE AI CAMPI CONST E PUNTATORI CONST --> CAMPI DATI CONST DEVONO ESSERE INIZIALIZZATI CON COSTRUTTORE DI COPIA
        E& r;
        int* const p;
    public:
        // C() :r(x), p(nullptr) {}
};
int main() {
    C c;
}