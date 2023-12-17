class E: virtual public B{
    public: 
    Z ez;

    // (1) ridefinizione assegnazione standard

    // scrivere la firma dell'assegnazione standard
    // richiamiamo l'assegnazione delle classi dirette
    // ritorniamo il puntatore al contesto
    E& operator=(const E& e){
        // da superclassi
        B::operator=(e);
        // assegno tutti i campi
        ez = e.ez;
        // ritorno al puntatore di contesto
        return *this;
    }
}
// B D E F
class F: public D, public E{
    private:
    Z* fz;

    public:
    // (2) copia profonda
    F(const F& f): B(f), D(f), E(f),
    fz(f.fz != nullptr ? 
    new Z(*f.fz): nullptr) {}

    // (3) distruttore profondo
    ~F() {delete fz;}

    // (4) clonazione polimorfa
    virtual F* clone() const {
        return new F(*this);
    }
};
    