/* 
Definire un'unica gerarchia di classi che includa:

1) una classe base polimorfa A alla radice della gerarchia
2) una classe derivata astratta B
3) una sottoclasse C di B che sia concreta
4) una classe D che non permetta la costruzione pubblica
dei suoi oggetti, ma solamente la costruzione di oggetti di D
che siano sottooggetti
5) una classe E derivata direttamente da D e con l'assegnazione ridefinita
pubblicamente con comportamento identico a quello dell'assegnazione standard di E.*/

// virtual metodo = 0; //astratto - virtuale puro
// virtual metodo //con implementazioni // concreto

class A{
    public:
    virtual ~A(); //così rendo la classe polimorfa = distruggo i sottooggetti
};

class B: public A{ //classe derivata astratta
    public:
    virtual void metodo() = 0; 
};

class C: public B{
    public:
    virtual void metodo(){}; //concreto
};

class D{
    protected: 
    D d;
};

class E: public D{
    private: 
    int x;
    public:
    E& operator=(const E& e){
        D::operator(e);
        x = e.x;
        return *this; 
    }
};
