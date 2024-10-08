#include<iostream>
using namespace std;

class A {
protected:
    int k;
    A(int x=1): k(x) {}
    virtual ~A() {}
public:
    virtual void m() {cout << k << " A::m() ";}
    virtual void m(int x) {k=x; cout << k << " A::m(int) ";}
};

class B: virtual public A {
    public:
        virtual void m(double y) {cout << k << " B::m(double) ";}
        virtual void m(int x) {cout << k << " B::m(int) ";}
};

class C: virtual public A {
    public:
        C(int x = 2): A(x) {}
        virtual void m(int x) {cout << "C::m(int) ";}
};

class D: public B {
    public:
        D(int x=3): A(x) {}
        virtual void m(double y) {cout << "D::m(double) ";}
        virtual void m() {cout << "D::m() ";}
};

class E: public D, public C {
    public:
        E(int x=4): C(x) {}
        virtual void m() {cout << "E::m() ";}
        virtual void m(int x) {cout << "E::m(int) ";}
        virtual void m(double y) {cout << "E::m(double) ";}
};

int main() {
    A* a[7] = {new B(),new C(),new D(),new E()};
    for(int i=0; i<4; ++i) {
        a[i]->m();
        a[i]->m(i);
        a[i]->m(3.14);
        cout << " *** " << i << endl;
    }
}