#include <iostream>

using namespace std;

class Orario{
    private:
    int minuti; //information hiding - nascondo i dati privati

    public:
    int getMinuti() const{
        return minuti;
    }
    //const - non ci sono modifiche all'oggetto di invocazione

    //costruttori - overloading (stesso nome diversi parametri)

    Orario(); //default - può essere omesso

    //tutti questi metodi sono inline = scrivo il metodo e il corpo tutto qui
    //altrimenti posso
    // (1) scrivere il file .h con definizioni dei metodi e nel file .cpp includere il .h e definire i metodi
    // con tipodiritorno classe::nomemetodo(parametri)
    // (2) scrivere i metodi qui e richiamarli con scoping fuori dalla classe

    //lista di inizializzazione - dopo i due punti, costruisco tutti i campi nello stesso ordine previsto
    // con le tonde = costruire di copia --> sintassi: variabile locale(variabile)
    Orario(int m): minuti(m) {}

    Orario(const Orario& o) //copia - con riferimento costante per non condividere memoria

    Orario operator=(const Orario& o) //assegnazione - creo un nuovo oggetto per salvare lo spazio
    // assegno tutti i campi

    // "static" - oggetto che viene deallocato per ultimo e resta per tutta la durata del programma
    // Esempio di campo statico: costo fisso, tassa, tariffa
    static double tariffa_mensile;
};
//lo dichiaro come valore al di fuori della classe (nelle modellazioni)
double Orario::tariffa_mensile = 10;

// Compilazione delle classi con "g++"
// Make - tutto in uno per eseguibile
// g++ (classi.cpp - se una, prendere quella dove sta il main - nome eseguibile)
g++ orario.cpp orario.o
./eseguibile

//Template = tipo T (segnaposto)
//che viene "rimpiazzato" dal tipo che ti serve
template<class T>
class Lista{
    //friend = permette alla classe di vedere i campi privati
    //normalmente, viene fatto per le classi iteratore (più piccole)
    //per vederne i campi privati

    private:
    class Nodo{

    };

    public:
    Nodo* head;

    // tipi di amicizie:
    // friend void stampa(); - amicizia associata 

    //Normalmente (con template):
    friend ostream& operator<<(ostream&, const Lista&);

    //Operazioni profonde - su tutti i campi

    //Copia profonda
    Lista(const Lista& l){
        l.head = head;
    }
    //Versione "stringata" - dopo la lista di inizializzazione
    Lista(const Lista& l): head(l.head) {}

    //Assegnazione profonda - ha questa struttura logica "fissa"
    Lista& operator=(const Lista& l){
        //controllo che non ci sia interferenza in memoria
        if(this != &l){
            // cancello le cose vecchie - delete l;
            // copio tutti gli oggetti
            l.head = head;
        }
        return *this; 
        //ritorno il puntatore al riferimento (Lista&)
    }

    // distruzione profonda = distruggo tutti i campi
    // Struttura: Esiste? Allora cancello
    ~Lista(){
        if(head) delete head;
    }
};

//Esempi di utilizzo template: Lista<int> l; Lista<double> l1;

//Se un oggetto è parte di template, lo dichiaro (se definito esternamente)
template<class T>
ostream& Lista::operator<<(ostream& os, const Lista&){

}

// Senso di uso dei template e dei friend:
// - creare delle classi contenitore/iteratore
// - usare i contenitori standard

template<class T>
class Vettore{
    private:
    class Iteratore{
        //ha una serie di operazioni previste
        //costruttori 
        //overloading operatori ==, ++, *, ->
    };

};

// Esempio utile di classe di questo tipo
// Smartp

// Contenitori standard
// Dentro al namespace std;

// Ci concentriamo o su vector o su list - ma usiamo vector
// (seguendo la teoria del corso) perché è più efficiente

// se includiamo std

#include <vector>
vector<int> v;

// usare vector - attraversamento/inserire dati/cancellazione

// per scorrere il vettore usiamo gli iteratori
// quando io includo vector, ci sono già anche gli iteratori
for(vector<int>::iterator it = v.begin(); it != v.end(); ++it){
    //inserire dentro a vector (in modo efficiente)
    v.push_back(5);
    //cancellare un elemento da un vector
    // (1) it = v.erase(5);
    // (2) v.erase(x);

    // l'iteratore è già posizionato dopo la cancellazione
    // se voglio salvarmi dove è stato eliminato o fare copie dell'oggetto
    // allora riposiziono it (it--);
}
// Alternativa = inferenza di tipo automatica (deduce il tipo da solo - auto (da C++ 11))
for(auto it = v.begin(); it != v.end(); ++it){

}

//se usi list

#include <list>
list<int> l;

// tutte le operazioni previste sopra discusse per vector valgono
// in modo equivalente anche per "list"

// quando noi puntiamo ad oggetti costanti
vector<const int*> v;

// logica = const "in mezzo" - punto ad oggetti costanti
for(vector<const int*>::const_iterator cit = v.begin(); cit != v.end(); ++cit){
    // viene fatto per garantire che l'oggetto sottostante rimanga immutabile
    // (aka no modifiche all'oggetto di invocazionw = side effects)

}

// Conversioni o casting

// const_cast = serve a togliere il const
const int* v;
int* i = const_cast<int*>(v); //stiamo togliendo il const a const int* e convertiamo a "int"

//Sintassi: const_cast<tipo a cui converto>(oggetto da convertire)

// static_cast
double d;
int s = static_cast<int>(d); 
// converto a un tipo qualsiasi (se la conversione è possibile)
//ma lo fa per tipi statici (noti subito prima della compilazione)

//Sintassi: static_cast<tipo a cui converto>(oggetto da convertire)

// dynamic_cast

// Ereditarietà

class Animale {};

// Classe: modificatore di visibilità (si usa sempre public) e classe da cui discendo
class Cane: public Animale{

};

// Polimorfismo - usare virtual

class A{
    public:
    virtual void stampa();
};

class B: public A{
    public:
    virtual void stampa(); // overriding - stessa firma - se definito "virtual", "posso andare giù"
};

class C: public B{
    public:
    virtual void stampa();
};

// Tipo statico (prima dell'uguale - noto subito)
// Tipo dinamico (dopo l'uguale - se i virtual me lo permettono, ci posso arrivare)
A* a = new C();

B* b = dynamic_cast<B*>(a);
// Sintassi: 
// dynamic_cast<tipo a cui convertire>(variabile da convertire)

// Normalmente, si usa per downcasting (da superclasse a sottoclasse): 
// dynamic_cast<sottotipo>(supertipo)