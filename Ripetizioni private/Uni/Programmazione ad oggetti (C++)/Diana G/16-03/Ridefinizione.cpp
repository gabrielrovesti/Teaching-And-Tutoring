#include <iostream>

using namespace std;

class F: public D{
    private:
        list<int*> l;
        // list = classe container

        // Noi mettiamo lo * e abbiamo una serie di oggetti (iterator) che puntano a quello che c'è dentro

        // <int> = template = costruzione standard (modello)

        int& ref;
        double *p;

    // profondo = copia di tutti gli oggetti e sottooggetti

    // lista di inizializzazione (:)
    // noi andiamo a mettere in ordine sparso tutti i campi del tipo classe 
    // la roba standard (questo tipo di es.) ti "impone" di chiamare D(f)

    // comportamento standard 
    // derivo da D, chiamo il suo c. di copia
    F(const F& f): D(f), l(f.l), ref(f.ref), p(f.p) {}

    // Attenzione: "p" è un puntatore -> occhio a gestire il caso nullo!
    // nullptr / 0 (std)

    // Caso 1: dentro le graffe
    F(const F& f): D(f), l(f.l), ref(f.ref) {
        if(f.p == nullptr){
            p = new F(f.p); // new = allocazione dinamica (heap)
        }
        else{
            p = nullptr;
        }
    }

    // Caso 2: operatore ternario
    // Sintassi -> condizione ? vero : falso
    F(const F& f): D(f), l(f.l), ref(f.ref), 
    p(f.p != nullptr) ? new F(f.p) : nullptr {}

    // Clonazione (polimorfa)
    virtual F* clone() const {
        return new F(*this);
    }

    // const = Assicura che non ci siano side effects -> Immutabilità


    // Distruzione
    // Normalmente la fai solo se la classe prevede un campo di tipo puntatore (in questo caso "p")
    ~F(){
        if(p) delete p; // se esiste, cancello
    }

    // delete = deallocazione di un puntatore
    // OCCHIO: diverso da
    // erase = esercizi di tipo funzione (vector)


};