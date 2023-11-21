#include <iostream>

using namespace std;

class Orario{
    private:
    int secondi;
    int minuti;
    public:
    virtual void ora(); //guardo la classe sopra come metodo se non ha virtual o non è ridefinito
};

// ereditarietà diretta = dataora è un orario
class dataora: public Orario{
    // sottotipo = tutti i dati di Orario + cose tue che aggiungi
    // subtyping = sono un sottotipo
    private:
        int giorno;
        int mese;
        int anno;
    public:
        // public dataora() - costruire con cose che vengono da sopra
    protected: //nascondo gli oggetti pubblici ma li rendo visibili solo alle sottoclassi
        int data_nascita;
    public:
    virtual void ora(); //overriding - ridefinizione del metodo con stessa firma e stessi parametri
    // parametri diversi = funzioni diverse aka no overriding - sovrascrittura
    void ora() override; //keyword override = meglio usare il metodo della classe derivata "Se possibile"
};

// tipi statici - dinamici
int* variabile[10]; //statico - sappiamo "prima = a tempo di esecuzione" che tipo è

Orario o; dataora d;

Orario *o1 = &d;

A* a1 = &c; // A - B - C gerarchia con ereditarietà (se statico, mi rimane in A; se dinamico, "può" andare fino a C)
B* b1 = c; // B - C

class Macchina{
    private:
    string motore;
    public:
    virtual void accendi() = 0; //virtuale puro - astratto
};

class Ferrari{
    public:
    int cavalli;
    virtual void accendi() { //classe concreta
        return cavalli;
    }
};

Macchina m* = nullptr;
m = &f;
m->accendi(); // macchina

Ferrari* f = nullptr;
f->accendi();

// chiamo esplicitamente
E::f(); //so per certo che sto chiamando il metodo di quella classe = il cosa stampa prende quel metodo lì
// name hiding rule = nascondo altre implementazioni a favore di quella chiamata

// Costruttori della classe derivata
// Prima chiamo la base (o le basi in ordine)
// poi la sottoclasse

// Dalla clase base riusciamo tendenzialmente ad andare verso la classe derivata per ereditarietà

class C{
    private:
        int x;
};

class D: public C{
    public:
        double dou;
        string s;

    // copia standard
    D(const D& d): C(d), dou(d.dou), s(d.s) {}

    // assegnazione standard
    D& operator=(const D& d){
        C::operator=(d);
        dou = d.dou;
        s = d.s;
        return *this;
    }
};