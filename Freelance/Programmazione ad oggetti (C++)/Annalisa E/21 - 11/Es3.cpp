#include <iostream>
using namespace std;

class Z{
    public:
    int x;
    Z(): x(0) {cout << "Z0 ";}
    Z(const Z& x) {cout << "Zc ";}
    Z& operator=(const Z& x) {cout << "Z= "; return *this;}
};

class C{
    public:
    Z w;
    C() {cout << "C0 ";}
    C(const C& x): w(x.w) {cout << "Cc ";}
    C& operator=(const C& x) { w = x.w; cout << "C= ";return *this;}
};

class D: public C{
    public:
    Z z;
    D() {cout << "D0 ";}
    D(const D& x): C(x), z(x.z) {cout << "Dc ";}
    D& operator=(const D& x) {C::operator=(x); z = x.z; cout << "D= "; return *this;}
};

int main(){
    D d; d.w.x = 3; cout << "UNO\n";
    D e; e.w.x = 5; cout << "DUE\n";
    e = d; cout << "TRE\n";
    cout << e.w.x << ' ' << d.w.x << " QUATTRO\n";
}