class F: public D, public E{
    private:
        Z* pz;
    public:

        // Costruzione con lista
        // di inizializzazione
        F(const F& f):
        D(f), E(f), pz(f.pz) {}

        // Costruzione dentro le graffe
        F(const F& f){
            D(f);
            E(f);
            pz = f.pz;
        }

        // Assegnazione standard
        F& operator=(const F& f){
            D::operator=(f);
            E::operator=(f);

            pz = f.pz;

            return *this;
        }

        // Struttura standard
        F& operator=(const F& f){
            if(this != f){
                D::operator=(f);
                E::operator=(f);

                delete pz;

                Z* z = new Z();
                z = f.pz;
            }
            return this;
        }

        // Metodo di clonazione polimorfa
        virtual F* clone(){
            return new F(*this);
        }
};