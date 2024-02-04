

class Esempio{

    private:
        int campo; //information hiding
        int* puntatore;
    public:
        int getCampo() const{return campo;};
        // const alla fine = immutabilità (non cambia)

        Esempio(); //costruttore di default - Esempio e;

        Esempio(int c): campo(c) {}; // overloading - Esempio e = Esempio(5);

        // operazioni profonde - copiano/cancellano/assegnano tutti i campi

        Esempio(const Esempio& e) { //copia - non crea un nuovo oggetto per assegnare
                campo = e.campo; // assegno i campi (1)
                // se hai altri campi, assegni tutto (2)
            //}
        } 

        Esempio(const Esempio& e): campo(e.campo) {};

        Esempio& operator=(const Esempio& e){ //assegnazione - crea un nuovo oggetto
            if(this != &e){
                // pulisco la memoria (2)
                delete puntatore;
                int *p = new int();
                campo = e.campo; // assegno i campi (3)
                p = e.puntatore;
                // se hai altri campi, assegni tutto
            }
            return *this;
        }

        ~Esempio(){ //distruzione
            if(puntatore) delete puntatore; //cancellazione dei puntatori e degli oggetti puntati
        }

        // campi statici - esistono per tutta la durata del programma

        // variabili statiche = int campo; - sono "gestite" dal programma (uscendo si cancellano)
        // puntatori = stanno sullo heap e quindi devo cancellarli a mano (delete)
        
        // Rata fissa / prezzo fisso / Tariffa

        static double tariffa;

        // overloading degli operatori
        // definisco l'operazione "per la classe"

        // overloading operatore di uguaglianza
        bool operator==(const Esempio &e){
            return e.campo == campo && e.puntatore == puntatore; 
        }
};

double Esempio::tariffa = 1.5; // inizializzo il campo statico

// Template

template <class T> // T = tipo generico
class Classe{
    // friend = faccio vedere la parte privata di una classe
    friend class Vettore;
};

// Classe<int> / Classe<double> 

template <class T> 
class Vettore{
    friend class Classe;
    private:
        class Iteratore{

        };
};  

// Classi container/iteratore
#include <vector> //parte della libreria std
vector<int*> v;

// inserimento
for(auto it = v.begin(); it != v.end(); ++it){ //scorro con iteratori
    v.push_back(5);
}

// cancellazione
for(auto it = v.begin(); it != v.end(); ++it){ //scorro con iteratori
    it = v.erase(it);
}

// Iteratore dentro la classe vector
// vector<int*>::iterator it

const vector<const int*> v1;
// vector<int*>::const_iterator it

// se io ho dei const = lo gestisco senza const (const_cast)
// se ereditarietà = dynamic_cast

int v = const_cast<int*>(v1);

//static_cast = converto a qualcos'altro
double d = static_cast<double>(v);

// Ereditarietà
class Base{
    public:
        virtual int metodo();
};

class Derivata1: public Base{
    public:
        int metodo(); //overriding = metodo con stesso nome/stessi parametri/con virtual o meno
};

class Derivata2: public Base{
    
};

Base *b = new Derivata2(); //puntatore polimorfo = parto da un tipo e "posso" andare verso altri tipi
// tipo statico = quello a sinistra dell'uguale --> Base
// tipo dinamico = quello a destra dell'uguale --> quello che posso raggiungere

// dynamic_cast = conversione di tipi dinamica (verso altre classi)
// Downcasting = da sopra a sotto
Derivata2 *d = dynamic_cast<Derivata2*>(b);

// Ereditarietà multipla

class A{};

class B: public A{};

class C: public A{};

class D: public B, public C{};

// non sa chi scegliere, dà errore

// Si mette virtual public per assicurare la costruzione di un solo oggetto

class A{};

class B: virtual public A{};

class C: virtual public A{};

class D: public B, public C{};

// A B C D

// Astratto = Virtuale puro - virtual void metodo() = 0;
// Concreto = virtual void metodo();

// typeid = un tipo dinamico che deve essere esattamente uguale a un altro
// dynamic_cast = un tipo dinamico sottotipo proprio di qualcos'altro