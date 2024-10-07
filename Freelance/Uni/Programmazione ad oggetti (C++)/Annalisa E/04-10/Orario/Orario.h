#include <iostream>

using namespace std;

class Orario{
    private:
    //information hiding
        int secondi;
        int ore;
        int minuti;
        int* topolino;
    public:
        int getSecondi() const;  
        // const - non faccio side-effects
        
        // faccio match al metodo che mi assomiglia di più
        
        // overloading - stesso metodo, con lo stesso tipo di ritorno
        // ma con parametri diversi
        // i metodi con "const" e senza (ma con stesso nome) sono metodi diversi
        int getSecondi(int x);

        //Saper usare i puntatori
        //this - puntatore del contesto di invocazione

        int metodo_bellissimo(){
            this->minuti;   //operatore di dereferenziazione
            (*this).minuti; //uso del puntatore come riferimento
        }

        // X esame (per quanto riguarda il this)
        // l'uso vero del this è con l'operator= (assegnazione)
        // l'ultima istruzione è sempre "return this" (non faccio interferenza in memoria)

        // overriding (avrò a che fare con i virtual)

        // scoping - prendo i dati da un namespace
        // std::cout

        // Quando separiamo i metodi (tra classe .h e .cpp)
        // allora usiamo lo scoping

        void inizializza(int secondi, int ore); //quando scoping è "separato"

        // esempio metodo inline
        void inizializza(int secondi, int ore){
            //facciamo cose qua dentro
        };

        // "static" - oggetto che viene deallocato per ultimo e resta per tutta la durata del programma
        // Esempio di campo statico: costo fisso, tassa, tariffa
        static double tariffa_mensile;

        // Costruttori - metodo con lo stesso nome della classe in cui è creato - serve ad inizializzare parametri
        Orario(); //costruttore di default/senza parametri (può essere omesso perché non ha parametri)
        Orario(int, int); //costruttore di default a più parametri/a più parametri

        // Lista di inizializzazione - metto i due punti e do dei valori ai parametri (si mette solo nel caso dei costruttori)
        Orario(int cosa1, int cosa2): secondi(cosa1), minuti(cosa2){} 

        //se ho un puntatore, nella lista di inizializzazione controllo se esiste (aka != nullptr)
        //condizione ternaria: (condizione) ? (caso positivo - yes) : (caso negativo - nope)
        Orario(int* punt, int cosa3): punt == nullptr ? punt = 0 : punt = 5;

        // inizializzazione dei parametri nei costruttori

        // Costruttore di copia - metodo con lo stesso nome della classe ma con parametro che è un rifer. costante
        Orario(const Orario&); 

        //232322323234 --> cella di memoria

        // esempio di costruttore di copia - uso le tonde per copiare un oggetto
        int i1, i2;
        i2(i1); //esempio di copia di un oggetto - stesso tipo
};
//lo dichiaro come valore al di fuori della classe (nelle modellazioni)
double Orario::tariffa_mensile = 10;

// Compilazione delle classi con "g++"
// Make - tutto in uno per eseguibile
// g++ (classi.cpp - se una, prendere quella dove sta il main - nome eseguibile)
g++ orario.cpp orario.o
./eseguibile