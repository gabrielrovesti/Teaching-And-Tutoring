#include <iostream>
using namespace std;

class Z{
    public:
    Z() {cout << "Z0 ";}
    Z(double d) {cout << "Z1 ";}
};

class C{
    private:
    int x;
    Z w;
    public:
    C(): w(6.28), x(8) {cout << x << "C0 ";}
    C(int z): x(z) {cout << x << "C1 ";}
};

class D: public C{
    private:
    int y;
    Z z;
    public:
    D(): y(0) {cout << "D0 ";}
    D(int z): y(a), z(3.14), C(a) {cout << y << "D1 ";}
};

int main(){
    D d; cout << "UNO\n";
    D e(4); cout << "DUE\n";
}

/*
Z1 8 C0 Z0 D0 UNO
Z0 4 C1 Z1 D1 DUE
*/