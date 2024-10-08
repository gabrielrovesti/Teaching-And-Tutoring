#include <iostream>

using namespace std;

class A{
    public:
        virtual ~A() = default;
};

class D: public A {};

class C: public A{};

class B: public D {};

template <class X, class Y>
X* fun(X* p) { return dynamic_cast<Y*>(p);}

int main(){
    C c; fun<A,B>(&c);
    if(fun<A,B>(new C())==0) cout << "Bjarne ";
    if(dynamic_cast<C*>(new B()) == 0) cout << "Stroustrop";
    A* p = fun<D, B>(new D());
}

/*

A <= B
A <= C
A <= D
B <= A
B <= C
B <= D
C <= A
C <= B
C <= D
D <= A
D <= B
D <= C

*/