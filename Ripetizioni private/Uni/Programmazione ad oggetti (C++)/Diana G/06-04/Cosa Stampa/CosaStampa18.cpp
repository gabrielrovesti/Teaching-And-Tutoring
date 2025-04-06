#include <iostream>
using namespace std;

class A {
protected:
    virtual void j() { cout << " A::j "; }
public:
    virtual void g() const { cout << " A::g "; }
    virtual void f() { cout << " A::f "; g(); j(); }
    void m() { cout << " A::m "; g(); j(); }
    virtual void k() { cout << " A::k "; j(); m(); }
    virtual A* n() { cout << " A::n "; return this; }
};

class B: public A {
public:
    virtual void g() const override { cout << " B::g "; }
    virtual void m() { cout << " B::m "; g(); j(); }
    void k() { cout << " B::k "; A::n(); }
    A* n() override { cout << " B::n "; return this; }
};

class C: public A {
private:
    void j() { cout << " C::j "; }
public:
    virtual void g() { cout << " C::g "; }
    void m() { cout << " C::m "; g(); j(); }
    void k() const { cout << " C::k "; k(); }
};

class D: public B {
protected:
    void j() { cout << " D::j "; }
public:
    B* n() final { cout << " D::n "; return this; }
    void m() { cout << " D::m "; g(); j(); }
};

int main() {
    A* p1 = new D(); 
    A* p2 = new B(); 
    A* p3 = new C(); 
    B* p4 = new D(); 
    const A* p5 = new C();
    
    // Per testare il codice, aggiungiamo delle chiamate alle funzioni
    cout << "Test p1 (A* -> D):" << endl;
    p1->g();
    cout << endl;
    p1->f();
    cout << endl;
    p1->m();
    cout << endl;
    p1->k();
    cout << endl;
    p1->n();
    cout << endl << endl;
    
    cout << "Test p2 (A* -> B):" << endl;
    p2->g();
    cout << endl;
    p2->f();
    cout << endl;
    p2->m();
    cout << endl;
    p2->k();
    cout << endl;
    p2->n();
    cout << endl << endl;
    
    cout << "Test p3 (A* -> C):" << endl;
    p3->g();
    cout << endl;
    p3->f();
    cout << endl;
    p3->m();
    cout << endl;
    p3->k();
    cout << endl;
    p3->n();
    cout << endl << endl;
    
    cout << "Test p4 (B* -> D):" << endl;
    p4->g();
    cout << endl;
    p4->m();
    cout << endl;
    p4->k();
    cout << endl;
    p4->n();
    cout << endl << endl;
    
    cout << "Test p5 (const A* -> C):" << endl;
    p5->g();
    cout << endl;
    // p5->f() non può essere chiamato perché p5 è const
    // p5->m() non può essere chiamato perché p5 è const
    // p5->k() non può essere chiamato perché p5 è const
    // p5->n() non può essere chiamato perché p5 è const
    
    // Liberiamo la memoria
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
    
    return 0;
}