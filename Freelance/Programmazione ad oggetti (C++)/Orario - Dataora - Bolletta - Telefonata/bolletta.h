#ifndef BOLLETTA_H
#define BOLLETTA_H
#include "telefonata.h"

class bolletta
{
    friend class iteratore;
private:
    class nodo;

    class smartp
    {
    public:
        nodo* punt;
        smartp& operator=(const smartp&);
        nodo& operator*() const;
        nodo* operator->() const;
        bool operator==(const smartp&) const;
        bool operator!=(const smartp&) const;
    };

    class nodo
    {
        public:
            nodo();
            telefonata info;
            int riferimenti;
    };

public:
    bolletta(): first(0) {}
    bolletta(const bolletta&);
    bool Vuota() const;
    void Aggiungi_Telefonata(telefonata);
    void Togli_Telefonata(telefonata);
    void Sostituisci(const telefonata& t1, const telefonata& t2);
    telefonata Estrai_Una();
    bolletta& operator=(const bolletta&);
    static nodo* copia(nodo*);
    static void distruggi(nodo*);
    friend ostream& operator<<(ostream&, const bolletta&);


};

orario Somma_Durate(bolletta b);
bolletta Chiamate_A(int num, bolletta& b);
#endif // BOLLETTA_H
