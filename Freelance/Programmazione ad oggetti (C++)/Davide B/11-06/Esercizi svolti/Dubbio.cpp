// Buongiorno, dato questo esercizio, nella prima stampa (&d, &f), quando viene chiamato v[k]->f(), in cui abbiamo un oggetto B/D, nel momento in cui non trova il metodo in D(), lo va a prendere in B. 

#include <iostream>
#include <vector>
using namespace std;

class B {

public:
  int x;
  B(int z=1):x(z){}
  virtual void f() const {cout << x <<"B::f  ";}
  virtual bool operator<=(const B& r) const {return true;}

};

class C: virtual public B {

public:
    virtual void f() const {cout <<"C::f  ";}
     virtual bool operator<=(const B& r) const {return dynamic_cast<const C*>(&r) != 0 ? true : false;}
};

class D: virtual public B{

public:
    virtual void g() const {cout <<"D::g  ";}
    virtual void h() const {cout <<"D::h  "; g();}
    virtual bool operator<=(const B& r) const {return dynamic_cast<const D*>(&r) != 0 ? true : false;}
};

class E: public D{

public:
    virtual void f() const {cout <<"E::f  ";}
    virtual void h() const {cout <<"E::h  ";}
    virtual bool operator<=(const B& r) const {return dynamic_cast<const E*>(&r) != 0 ? true : false;}
};

class F:public C,public E{

public:
    F():B(2){}
    virtual void f() const {cout <<x<<"F::f  ";}
    virtual void g() const {cout <<"F::g  "; D::g();}
    virtual bool operator<=(const B& r) const {return dynamic_cast<const F*>(&r) != 0 ? true : false;}
};

void fun(const vector<B*>& v){
    D* p;
    for(int k=0;k!=v.size();++k){
        v[k]->f();
        if(k+1< v.size() && *v[k] <=*v[k+1]) 
            v[k+1]->f();
        p=dynamic_cast<E*>(v[k]);
        if(p){
            static_cast<E*>(p)->g();
            p->h();
        }
        cout<<"   **" << k << endl;

    }

}

int main() {
  B b;
  C c;
  D d;
  E e;
  F f;
  vector<B*> v;
  v.push_back(&d);
  v.push_back(&f);

  fun(v);
}


// In quest'altro esercizio

#include <iostream>
using namespace std;

class A {
public:
    virtual void f() const {cout <<" A::f ";}
    virtual void g() {cout <<" A::g "; m(); }
    virtual void h() {cout <<" A::h "; f();}
    void m() {cout <<" A::m "; f();}
    virtual A* n() {cout <<" A::n "; return this;}
};

class B: public A {
public:
    virtual void f() const {cout <<" B::f ";}
    void g() {cout <<" B::g "; A::n();}
    virtual void m() {cout <<" B::m "; f();}
    A* n() {cout <<" B::n "; return this;}
};

class D: public B {
public:
    B* n() {cout <<" D::n "; return this;}
protected:
    void r() {cout <<" D::r ";}
public:
    void m() {cout <<" D::m "; f(); r();}
};

class C: public A {
public:
    virtual void f() {cout <<" C::f ";}
    void g() const {cout <<" C::g "; g();}
    void m() {cout <<" C::m "; g(); f();}
};

int main() {
    A* q1 = new D(); 
    A* q2 = new B(); 
    A* q3 = new C(); 
    B* q4 = new D(); 
    const A* q5 = new C();

    //q1->f();
    //q1->g();
    //q2->h();
    //q2->m();
    //q3->g();
    //q3->h();
    //q4->m();
    //q4->g();
    //(q3->n())->m();
    //(q3->n())->n()->f();
    //(q4->n())->m();
    (q5->n())->f();
    //(dynamic_cast<B*>(q1))->m();
    //(static_cast<C*>(q2))->g();
    //(static_cast<B*>(q3->n()))->f();

    return 0;
}

/*

Nella stampa (q5->n())->f(), il principale errore è dato dal const A* in cui non viene selezionato un metodo nei sottotipi in quanto rimane const A* e si aspetta di trovare nel sottotipo il metodo const. Se togliessimo il const, stamperebbe A::n() A:f().
Perché qui non compila dato che il metodo nella classe base c’è? Sarebbe dovuto allo *this?


*/