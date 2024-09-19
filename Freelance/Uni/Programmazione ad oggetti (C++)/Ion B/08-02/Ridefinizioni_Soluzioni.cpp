class E: virtual public B{
    public: 
        Z ez;
        // assegnazione standard
        E& operator=(const E& e){
            // non serve il controllo
            // su *this
            B::operator=(e);
            ez = e.ez;
            return *this;
        }
};

class F: public D, public E{
    private:
        Z* fz;
    public:
        // copia profonda
        F(const F& f):
        D(f), E(f), fz(f.fz)

        // copia profonda
        // senza lista di inizializzazione
        F(const F& f){
            D(f);
            E(f);
            if(f.fz == nullptr)
                fz = nullptr;
            else
                fz = new Z(*f.fz);
        }

        // Per farla bene
        // fz(f.fz!=nullptr ? new Z(*f.fz) : nullptr) {}
        // condizione ? vero : falso

        // clonazione polimorfa
        // Idea base
        virtual classe* clone() const{
            return new classe(*this);
        }

        // Per l'esercizio
        virtual F* clone() const{
            return new F(*this);
        }

        // virtual D/E va bene = per superclassi, va bene

        // distruttore profondo
        ~F(){
           if(fz) delete fz;
        } 
};