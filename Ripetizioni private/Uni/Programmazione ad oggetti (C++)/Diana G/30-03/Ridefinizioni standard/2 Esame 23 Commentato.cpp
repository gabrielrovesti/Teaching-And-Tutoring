class E: public D{
    private:
        std::vector<double*> v;
        int *p;
        int &ref;
    public:
        E(): p(new int(0)), ref(*p); // default

        // Copia profonda
        // = Tutti i campi e sottocampi
        E(const E& e): D(e), 
        v(e.v), p(e.p), ref(e.ref){}
        
        // Assegnazione profonda

        E& operator=(const E& e){
            //if(this != e)
            // NO perchè gia fatto per ereditarietà, ma nelle classi normali ci va
            D::operator=(e);
            // Richiamo l'operator= con lo scoping di D

            v = e.v;
            p = e.p;
            ref = e.ref;

            return *this;
        }
};

// Commenti:
// Non condividi memoria -> riferimento costante
// Default (keyword nel testo) -> C++ 17 in avanti (ultima parte corso)

// Ogni puntatore NON VIENE automaticamente cancellato, dobbiamo farlo noi -> distruttori (profondi) con ereditarietà

// All'atto pratico, vado a cancellare le cose create dinamicamente (new = nello heap -> garbage collection)
/*
*p, *...
delete
*/

//Riferimento per questi esercizi - 2 Esame 2021