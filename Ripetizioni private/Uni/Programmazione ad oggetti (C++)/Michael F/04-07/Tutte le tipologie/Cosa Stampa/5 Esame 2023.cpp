#include <iostream>

using namespace std;

class Z{
public:
    Z(int x){};
};

class A{
public:
    void f(int){cout << "A::f(int)";}
    virtual void f(bool){cout << "A::f(bool)";}
    virtual A* f(Z){cout << "A::f(Z)"; f(2); return this;}
    A(){cout << "A()";}
};

class B: virtual public A{
public:
    void f(const bool&){cout << "B::f(const bool&)";}
    virtual void f(const int&){cout << "B::f(const int&)";}
    virtual ~B(){cout << "~B()";}
    B(){cout << "B()";}
};

class C: public A{
public:
    C* f(Z){cout << "C::f(Z)"; return this;}
    C(){cout << "C()";}
};

class D: virtual public A{
public:
    virtual void f(bool) const {cout << "D::f(bool)";}
    ~D(){cout << "~D()";}
    D(){cout << "D()";}
};

class E: public C{
public:
    C* f(Z){cout << "E::f(Z)"; return this;}
    ~E(){cout << "~E()";}
    E(){cout << "E()";}
};

B* pb = new B;
C* pc = new C;
D* pd = new D;
E* pe = new E;


A* pa1 = pb, *pa2 = pc, *pa3 = pd, *pa4 = pe;

int main(){
    cout << "1. ";
    pa3->f(3);
    cout << endl;

    cout << "4. ";
    pa4->f(true);
    cout << endl;

    cout << "5. ";
    pa2->f(Z(2));
    cout << endl;

    cout << "7. ";
    pb->f(3);
    cout << endl;

    cout << "8. ";
    pc->f(3);
    cout << endl;

    cout << "9. ";
    (pa4->f(Z(3)))->f(4);
    cout << endl;

    cout << "10. ";
    (pc->f(Z(3)))->f(4);
    cout << endl;
}