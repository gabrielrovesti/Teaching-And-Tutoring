#include <iostream>

using namespace std;

class C{
    private:
    int x;
    public:
    C() {cout << "C0 "; x = 0;}
    C(int k) {cout << "C1 "; x = k;}
};

class D{
    private:
    C c;
    public:
    D() {cout << "D0 "; c = C(3);}
};

class E{
    private:
    char c;
    C c1;
    public:
    D d;
    C c2;
};

int main(){
    D y; cout << endl;
    E x; cout << endl;
    E* p = &x; cout << endl;
    D& a = y; cout << endl;
}