// Si considerino le seguenti definizioni, la cui compilazione non provoca errori.

class C {
public:
static void f(const C& x) {}
};
class D {
public:
D(C x = C()) {}
void g() const {}
};
class E {
public:
E(D x = D()) {}
operator C() const {return C();}
static void h(const E& x) {C::f(x);}
void i() const {C::f(*this);}
};
C c; D d; E e;

// Delle seguenti istruzioni, quali compilano e quali no?

// E::h(c);  
// c.g(); 
// E::h(d); 
// e.i(); 
// C::f(d); 
// C::f(e); 
// d.i(); 
// E e1(c); 
// D d1(c); 
// C c1(e); 
// C c2(d); 