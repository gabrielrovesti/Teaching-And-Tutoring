#include <iostream>
using namespace std;

class A{
public:
    virtual ~A() {};
};

class B: public A {};
class C: public A {};

class D: public C {};

template <class T>
A* Fun(T* pt) {
    bool b = false;
    try {throw pt;}
    catch(B*) {cout << "B"; b=true;}
    catch(C*) {cout << "C"; b=true;}
    catch(D*) {cout << "D"; b=true;} // Exception of type 'D *' will be caught by earlier handler
    catch(A*) {cout << "A"; b=true;}
    if(!b) cout << "NO";
    return dynamic_cast<C*>(pt) != nullptr ? static_cast<A*>(pt):new D;
}

int main(){
    B b; C c; D d; A* pa1 = &b; A* pa2 = &d; B* pb1 = dynamic_cast<B*>(pa1); B* pb2 = dynamic_cast<B*>(pa2);
    
    Fun(&c); cout << endl; // "C"
    Fun(&d); cout << endl; // "C"
    Fun(pa1); cout << endl; // "A"
    Fun(pa2); cout << endl; // "A"
    Fun(pb1); cout << endl; // "B"
    Fun(pb2); cout << endl; // "B"
    Fun<A>(pb1); cout << endl; // "A"
    Fun<A>(pa2); cout << endl; // "A"
    Fun<B>(pb1); cout << endl; // "B"
  //Fun<C>(pa2); no matching function
    Fun<C>(&d); cout << endl; // "C"
  //Fun<D>(pa2); no matching function
    Fun(Fun(pa2)); cout << endl; // "AA"
    Fun(Fun(pb2)); cout << endl; // "BA"
    Fun(Fun(pb1)); cout << endl; // "BA"
}
