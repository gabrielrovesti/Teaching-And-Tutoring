#include <iostream>
#include <vector>

using namespace std;

class B{
    public:
    int x;
    B(int z=1): x(z) {}
    virtual void f() const{cout << x << " B::f()"; }
};

class D: virtual public B{
    public:
        virtual void f() const{cout << "D::f()";}
};

class C: virtual public B{
    public:
        virtual void g() const {cout << "C::g() ";}
        virtual void h() const {cout << "C::h() ";}
};

class E: public C{
    public:
        virtual void f() const {cout << "E::f() ";}
        virtual void h() const {cout << "E::h() ";}
};

class F: public E, public D{
    public:
        F(): B(3) {}
        virtual void f() const {cout << x << " F::f() ";}
        virtual void g() const {cout << "F::g() ";}
};

void Fun(const vector<B*>& v) {
    auto it1 = v.begin();
    vector<B*>::const_iterator it2;
    C* q;
    for(int i=1 ; it1 != v.end(); ++it1, ++i) {
        std::cout << "#" << i << " ";
        (*it1)->f();
        it2 = it1 + 1;
        if(it2 != v.end() && typeid(**it1) == typeid(**it2)) (*it2)->f();
            q = dynamic_cast<C*>(*it1);
        if(q) {static_cast<C*>(q)->g(); q->h();}
        cout << endl;
    }
}

int main(){
    B b; C c; D d; E e; F f;
    vector<B*> v = { &d, &d, &e, &e, &b, &b, &f, &f, &e, &f, &c, &c };
    Fun(v);
}

/*
#1 D::f()D::f()
#2 D::f()
#3 E::f() E::f() C::g() E::h()
#4 E::f() C::g() E::h()
#5 1 B::f()1 B::f()
#6 1 B::f()
#7 3 F::f() 3 F::f() F::g() E::h()
#8 3 F::f() F::g() E::h() 
#9 E::f() C::g() E::h()
#10 3 F::f() F::g() E::h()
#11 1 B::f()1 B::f()C::g() C::h() 
#12 1 B::f()C::g() C::h()
*/