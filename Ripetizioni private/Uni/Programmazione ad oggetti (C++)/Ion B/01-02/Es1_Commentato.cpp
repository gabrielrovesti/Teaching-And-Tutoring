// classe polimorfa

// ha un metodo virtuale oppure
// distruttore virtuale

class A{
    public:
    virtual ~A();
};

class B: public A{
    public:
    virtual void metodo() = 0;
    // astratto = virtuale = 0
};

class C: public B{
    public:
    virtual void metodo(){ // concreto = ridefinisco il metodo
        return;
    }
};

class D{
    private:
        int x;
    protected: // non lo vedono all'esterno, lo vedono solo le sottoclassi
        D(int x1): x(x1) {}
};

class E: virtual public D{
    private:
        int number;
    public:
        // assegnazione standard = uso le superclassi
        E& operator=(const E& e){
            D::operator=(e);
            number = e.number;
            return *this;
        }

        //copia standard
        E(const E& e): D(e), number(e.number) {}
};

