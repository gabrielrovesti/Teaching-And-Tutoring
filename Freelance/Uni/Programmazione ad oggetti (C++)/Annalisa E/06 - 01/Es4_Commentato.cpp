class F: public D{
    private:
        list<int*> l;
        int& ref;
        double* p;
    public:
        void m() const {}

        //ridefinizione copia standard
        F(const F& f):
        D(f), l(f.l), ref(l.ref), p(f.p) {}

        //ridefinizione assegnazione standard

        F& operator=(const F& f){
            D::operator=(f);

            l = f.l;
            ref = l.ref;
            p = f.p;

            return *this;
        }

        // metodo di clonazione polimorfa
        virtual D* clone(){
            return new D(*this);
        }

        // Va sempre fatto così! :D
        virtual Tipo* clone(){
            return new Tipo(*this);
        }

        // Questa logica va seguita nelle modellazioni e basta; qui, non è necessario
        /*
            if(this != &p){
                delete p;
                Classe *c = new C();
                c = campo.c;
            }
            return *this;
        */

};