// Cosa stampa?
#include <iostream>
using namespace std;
class C {
    public:
    C() { cout << "CO ";}
    C(const C&) { cout << "Cc ";}
};
class D {
    public:
    C c;
    D() { cout << "DO ";}
};
class D2 {
    public:
    C c;
    D2 () { cout << "D0 ";}
    D2(const D&) { cout <<  "Dc ";}
};

int main() {
    D x; //1- CHIAMA COSTRUTTORE CLASSE D (R.17) 2- CHIAMERÀ COSTRUTTORE C PERCHÈ VA DEFINITO ELEMENTO (R.5)
    cout << endl; // C0 D0
    D y(x); // //1- CHIAMA COSTRUTTORE CLASSE D (R.17) 2- CHIAMERÀ COSTRUTTORE COPIA (R.6)
    cout << endl; // Cc

    D2 xx; // 1- CHIAMA COSTRUTTORE D2 (R.17) 2- CHIAMA COSTRUTTORE C (R.5)
    cout << endl; // C0 D0
    D2 yy(xx); // 1- CHIAMA COSTRUTTORE COPIA D2 (R.18)
    cout << endl; // C0 Dc
}