#include <iostream>

using namespace std;

// dynamic_cast - Usato per fare conversioni dinamiche (verso il basso)
class Base{
public:
    virtual void print(){
        cout << "Base" << endl;
    }
};
class Derived : public Base{
public:
    virtual void print(){
        cout << "Derived" << endl;
    }
};
// da base vado sempre di solito verso la derivata (se c'è un virtual/polimorfismo)
// dynamic_cast fa conversioni dinamiche a prescindere
// tipo statico = superclasse che "può" andare verso le sottoclassi
// tipo dinamico = insieme di sottotipi verso cui possiamo andare

Base *b = dynamic_cast<Base*>(new Derived()); // scrittura normale della cosa

A* a = new C; //da A (TS) a C (TD)
a = dynamic_cast<B*>(a); // da A (TS) a B (TD)

// typeid

#include <typeinfo> // per typeid

// confronti dinamici di tipo
// tendenzialmente non serve a convertire, ma solo a vedere di che tipo dinamico è
if(typeid(A) == typeid(B) && typeid(*p1) == typeid(p2))

// override

class Base{
public:
    virtual void print(){
        cout << "Base" << endl;
    }
};

class Derived : public Base{
public:
    // se c'è override, nelle conversioni sei portata a vedere il tipo dinamico (la classe derivata)
    virtual void print() override{ // serve per dire esplicitamente che la classe derivata ridefinisce il metodo
        cout << "Derived" << endl;
    }
};


int main(){

}