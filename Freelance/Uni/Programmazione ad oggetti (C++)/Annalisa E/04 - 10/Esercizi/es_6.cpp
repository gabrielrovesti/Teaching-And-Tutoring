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
    D x;
    cout << endl;
    D y(x);
    cout << endl;

    D2 xx;
    cout << endl;
    D2 yy(xx);
    cout << endl;
}