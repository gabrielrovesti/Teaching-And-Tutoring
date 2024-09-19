#include <iostream>

using namespace std;

class A{
    public:
        A() {cout << "A() ";}
        A(const A& x) {cout << "Ac ";};
        virtual ~A() {cout << "~A() ";}
        virtual const A* j() {cout << "A::j() "; return this;}
        virtual void k() {cout << "A::k() "; m();}
        void m() {cout << "A::m() "; j();}
};

class B: virtual public A{
    public:
        B() {cout << "B() ";}
        virtual ~B() {cout << "~B() ";}
        virtual void g() const{cout << "B::g() ";}
        //void k() const {cout << "B::k() "; j(); m();}
        void m() {cout << "B::m() "; g(); j();}
        virtual A& n() {cout << "B::n() "; return *this;}
};

class C: virtual public B{
    public:
        C() {cout << "C() ";}
        ~C() {cout << "~C() ";}
        void g() const{cout << "C::g() ";}
        void k() override{cout << "C::k() "; B::n();}
        virtual void m() {cout << "C::m() "; g(); j();}
        B& n() override{cout << "C::n() "; return *this;}
};

class D: virtual public B{
    public:
        D() {cout << "D() ";}
        ~D() {cout << "~D() ";}
        virtual void g() {cout << "D::g() ";}
        const A* j() {cout << "D::j() "; return this;}
        void k() const {cout << "D::k() "; k();}
        void m() {cout << "D::m() "; g(); j();}
};

class E: public C, public D{
    public:
        E() {cout << "E() ";}
        ~E() {cout << "~E() ";}
        E(const E& x) {cout << "Ec ";}
        virtual void g() const {cout << "E::g() ";}
        const E* j() {cout << "E::j() "; return this;}
        void m() {cout << "E::m() "; g(); j();}
        D& n() final{cout << "E::n() "; return *this;}
};

A* p1 = new E(); B* p2 = new C(); A* p3 = new D(); B* p4 = new E(); 
const A* p5 = new D(); const B* p6 = new E(); const E* p7 = new E();

int main(){
    //(p1->j())->k(); cout << endl; 
    // error: passing 'const A' as 'this' argument discards qualifiers [-fpermissive]   
    // k() non è const in B

    // se io tolgo i const da tutti i J()
    // E::j C::k B::n
    cout << endl;
    //(dynamic_cast<const E*>(p1->j()))->g(); cout << endl;

    // (dynamic_cast<E*>(p1->j()))->g(); cout << endl;
    // no - dynamic_cast cannot cast away const or other type qualifiersC/C++(694)

    (dynamic_cast<const E*>(p1->j()))->g(); cout << endl; // E::j() E::g()

    // error: passing 'const E' as 'this' argument discards qualifiers [-fpermissive]  
    // togliamo il const da  virtual void g() {cout << "E::g() ";}

    cout << endl;
    p2->m(); // 

    cout << endl;
    p3->k();



}

// B::m() C::g() B::j() C::n()