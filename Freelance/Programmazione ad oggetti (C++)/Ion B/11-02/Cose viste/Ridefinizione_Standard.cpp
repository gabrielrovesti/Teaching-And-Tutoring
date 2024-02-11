#include <iostream>

class F: public D, public E{
    private:
        Z *pz;
    public:
        //ridefinisci il costuttore di copia in modo standard
        F(const F& f):
        pz(f.pz), D(f), E(f) {}

        // (1) Standard
        // --> D(f), E(f)
        // (2) "Profondo" = tutti i campi
        // --> pz(f.pz)

        // profondo = assegno tutto
        // (tutti i campi)
        // standard = uso ereditarietà
        // = prendo anche le superclassi

        // assegnazione standard
        F& operator=(const F& f){
            //Standard
            D::operator(f);
            E::operator(f);

            pz = f.pz;

            return *this;
        }

        //distruzione standard
        ~F(){
            if(pz) delete pz;
        }

        //clonazione polimorfa
        virtual F* clone const(){
            return new F(*this);
        }

        // come si fa completamente (logica)
        /*
        operator=(&ref){
            if(this != ref){ //questo non serve nella standard
                delete
                F qualcosa = new F()
                campo = ref.campo;
            }
            return *this;
        }
        */
};