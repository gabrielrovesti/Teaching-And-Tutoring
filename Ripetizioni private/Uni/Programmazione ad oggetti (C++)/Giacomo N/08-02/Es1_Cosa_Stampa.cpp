#include <iostream>
using namespace std;

class A {
public:
    A() {cout << " A() ";}
    virtual ~A() {cout << " ~A() ";}
    virtual void f() {cout << " A::f "; h(); g();}
    virtual void g() const {cout << " A::g ";}
    virtual const A* h() {cout << " A::h "; return this;}
    virtual void k() {cout << " A::k "; m(); h();}
    void m() {cout << " A::m "; g(); h();}
    virtual A& n() {cout << " A::n "; return *this;}
};

class C: virtual public A {
public:
    C() {cout << " C() ";}
    ~C() {cout << " ~C() ";}
    virtual void g() const override {cout << " C::g ";}
    void k() override {cout << " C::k "; A::n();}
    virtual void m() {cout << " C::m "; h(); g();}
    A& n() override {cout << " C::n "; return *this;}
};

class D: virtual public A {
public:
    D() {cout << " D() ";}
    ~D() {cout << " ~D() ";}
    virtual void g() {cout << " D::g ";}
    const A* h() {cout << " D::h "; return this;}
    void k() const {cout << " D::k "; k();}
    void m() {cout << " D::m "; g(); h();}
};

class E: public C, public D {
public:
    E() {cout << " E() ";}
    ~E() {cout << " ~E() ";}
    virtual void g() const {cout << " E::g ";}
    const E* h() {cout << " E::h "; return this;}
    void m() {cout << " E::m "; h(); g();}
    D& n() final {cout << " E::n "; return *this;}
};

class F: public E {
public:
    F() {cout << " F() ";}
    ~F() {cout << " ~F() ";}
    F(const F& x): A(x) {cout << " Fc ";}
    void k() {cout << " F::k "; h();}
    void m() {cout << " F::m "; g();}
};

int main() {
    cout << "\nCreazione oggetti:\n";
    A* p1 = new E(); 
    A* p2 = new C(); 
    A* p3 = new D(); 
    C* p4 = new E();
    const A* p5 = new D(); 
    const A* p6 = new E(); 
    const A* p7 = new F(); 
    F f;

    cout << "\n\nTest delle chiamate:\n";
    
    cout << "\n1) (dynamic_cast<C*>(const_cast<A*>(p7)))->A::k();\n";
    (dynamic_cast<C*>(const_cast<A*>(p7)))->A::k();
    
    cout << "\n2) (dynamic_cast<E*>(p6))->h();\n";
    //(dynamic_cast<E*>(p6))->h();
    
    cout << "\n3) (p5->n()).g();\n";
    //(p5->n()).g();
    
    cout << "\n4) p4->f();\n";
    p4->f();
    
    cout << "\n5) p4->k();\n";
    p4->k();
    
    cout << "\n6) (p4->n()).m();\n";
    (p4->n()).m();
    
    cout << "\n7) p3->k();\n";
    p3->k();
    
    cout << "\n8) (dynamic_cast<D&>(p3->n())).g();\n";
    (dynamic_cast<D&>(p3->n())).g();
    
    cout << "\n9) (p3->n()).m();\n";
    (p3->n()).m();
    
    cout << "\n10) p2->m();\n";
    p2->m();
    
    cout << "\n11) (p2->h())->g();\n";
    (p2->h())->g();
    
    cout << "\n12) p1->m();\n";
    p1->m();
    
    cout << "\n13) (p1->h())->k();\n";
    //(p1->h())->k();
    
    cout << "\n14) (dynamic_cast<const F*>(p1->h()))->g();\n";
    (dynamic_cast<const F*>(p1->h()))->g();
    
    cout << "\n15) C* ptr = new F(f);\n";
    C* ptr = new F(f);
    
    cout << "\n16) delete p7;\n";
    delete p7;

    return 0;
}

/*

Test delle chiamate:

1) (dynamic_cast<C*>(const_cast<A*>(p7)))->A::k();
 A::k  A::m  E::g  E::h  E::h
2) (dynamic_cast<E*>(p6))->h();
NC -> dynamic_cast cannot cast away const or other type qualifiers
3) (p5->n()).g();
NC -> the object has type qualifiers that are not compatible with the member function "A::n"
n() non const in A mentre p5 si -> const correctness
4) p4->f();
 A::f  E::h  E::g
5) p4->k();
 C::k  A::n
6) (p4->n()).m();
 E::n  A::m  E::g  E::h
7) p3->k();
 A::k  A::m  A::g  D::h  D::h
8) (dynamic_cast<D&>(p3->n())).g();
 A::n  D::g
9) (p3->n()).m();
 A::n  A::m  A::g  D::h
10) p2->m();
 A::m  C::g  A::h
11) (p2->h())->g();
 A::h  C::g
12) p1->m();
 A::m  E::g  E::h
13) (p1->h())->k();
NC -> the object has type qualifiers that are not compatible with the member function "A::k"C/C++(1086)
p1 non const, h() in A è const -> const correctness
14) (dynamic_cast<const F*>(p1->h()))->g();
UB -> E::h (la stampa "ci pensa") poi dà errore e non compila il resto del programma
(this const quindi p1 originariamente non era const, se provo a chiamare errore - compilando stampa solo E::h per questo - this const e puntatore non const)
15) C* ptr = new F(f);
 C()  D()  E()  Fc
16) delete p7;
 ~F()  ~E()  ~D()  ~C()  ~A()

*/