// Classe "container" - lista/pila (strutture dati)

// Fornisco operazioni del tipo:
// - Aggiungo_uno
// - Rimuove_uno
// - Sostituisci

// Bolletta = Campo in memoria [info] e puntatore al dato successivo [next]

class Bolletta{
    //classe annidata - classe dentro un'altra 

    bool Vuota() const;
    //void Aggiungi_Telefonata(const telefonata&);
    //void Togli_Telefonata(const telefonata&);

    // Assegnazione profonda
    // Assegnare tutti i valori (sia di bolletta che di nodo) tramite l'uguale
    Bolletta& operator=(const Bolletta& b);
    // attenzione solo ad avere il riferimento costante

    // Assegnazione normale
    // Copia solo il valore (se sei una bolletta, "potrei perdermi dei nodi per strada")
    // Bolletta b;
    // b = c;  // Esiste già il valore e assegno tutti i suoi campi

    // Distruzione profonda 
    // Cancello tutti i campi e i sottocampi
    ~Bolletta(){if(first) {delete first;};

    // Senso "intuitivo" di una distruzione profonda
    /*
        ~Distruttore(){
            if(pointer){
                delete p; //cancello
                node *n = n->next; //scorro alla fine
            }
            return n;
        }
    */

    // Copia profonda
    // Copia (costruttore di copia = usare le parentesi tonde) per prendere tutti i sottocampi
    // Bolletta d(e); // Non esiste già il campo e copio tutti i suoi campi

    private: 
    class Nodo{
        // Telefonata info;
        Nodo* next;

    };
    Nodo* first; //puntatore o al primo o all'ultimo campo (di solito viene messa qui fuori)
};

// Garbage collection - Caratteristica di C++
// Quando io uso i puntatori, "non si cancellano da soli"
// Per questo motivo usiamo le operazioni profonde, cioè "per essere sicuri
// di assegnare/copia/cancellare tutti i campi"

 