#include <iostream>

using namespace std;

class A{
    public:
        A() {cout << "A() ";}
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
        virtual const B* j() {cout << "B::j() "; n(); return this;}
        void k() {cout << "B::k() "; j(); m();}
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
        const B* j() {cout << "D::j() "; return this;}
        void k() const {cout << "D::k() "; k();}
        void m() {cout << "D::m() "; g(); j();}
};

class E: public C, public D{
    public:
        E() {cout << "E() ";}
        ~E() {cout << "~E() ";}
        E(const E& x) {cout << "Ec ";}
        virtual void g() const{cout << "E::g() ";}
        const E* j() {cout << "E::j() "; return this;}
        void m() {cout << "E::m() "; g(); j();}
        D& n() final{cout << "E::n() "; return *this;}
};

A* p1 = new E(); B* p2 = new C(); A* p3 = new D(); B* p4 = new E(); 
const A* p5 = new D(); const B* p6 = new E(); const E* p7 = new E();

int main(){
    p2->m(); cout << endl;
    (p2->j())->g(); cout << endl;
    p3->k(); cout << endl;
    (p4->n()).m(); cout << endl;
    ((dynamic_cast<D*>(p4))->n()).k(); cout << endl;
    //(dynamic_cast<E*>(p5))->j(); cout << endl;
    //(p1->j())->k(); cout << endl;  
    (dynamic_cast<const E*>(p1->j()))->g(); cout << endl;
    (dynamic_cast<E*>(const_cast<B*>(p6))->k()); cout << endl;
    new E(*p7); cout << endl;
    delete p1; cout << endl;
    delete p4; cout << endl;
}

/*
1) B::m() C::g() B::j() C::n()
2) B::j() C::n() C::g()
3) B::k() D::j() B::m() B::g() D::j()
4) E::n() A::m() E::j()
5) E::n() C::k() B::n()
6) non compila
7) non compila
8) E::j() E::g()
9) non compila - sia con static che con dynamic dà errore e non compila (non sa quale scegliere)
10) A() B() C() D() Ec
11) ~A() - perché non c'è il virtual in A (sennò li chiamerebbe tutti, fino alla sottoclasse)
12) ~E() ~D() ~C() ~B() ~A() (chiama anche A essendo "virtual public A")
*/