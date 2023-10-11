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

E::h(c); // NON COMPILA -> h chiede const &;
        // non c'è nessun convertitore di tipo da classe C ad E
c.g(); // NON COMPILA -> La classe C non c'è nessun metodo g
E::h(d); // COMPILA -> Nonostante il convertitore di tipo ci sia, la conversione viene fatta
        // in maniera implicita
e.i(); // COMPILA -> This dereferenziato viene convertito da E in C (r.15)
C::f(d); // NON COMPILA -> Viene invocata D ma al suo interno non c'è un covertitore da D a C (r.9)
C::f(e); // COMPILA -> Per via del convertitore di tipo (r.5 into r.14)
d.i(); // NON COMPILA -> La classe D non ha il metodo i
E e1(c); // COMPILA -> Oggetto tipo C convertito in D (r.9) poi convertito in E (r.14)
D d1(c); // COMPILA -> Oggetto tipo C convertito in D (r.9)
C c1(e); // COMPILA -> Non c'è un costruttore abile a fare conversione C>E, però lo fa operator
C c2(d); // NON COMPILA -> Perchè in classe C nessun convertitore D>C