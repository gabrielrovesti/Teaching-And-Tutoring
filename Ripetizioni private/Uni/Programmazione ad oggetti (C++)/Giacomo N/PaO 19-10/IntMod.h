#ifndef INTMOD_H
#define INTMOD_H
#include "IntMod.h"

#include <iostream>
using namespace std;

class IntMod{
    
    public:
        static int n;
        // set / get

        static void setModulo(int n);
        static int getModulo();

        // o metto
        // int getModulo() const;
        // oppure
        // static int getModulo(); 

        // operatori
        int operator+(int) const;
        int operator*(int) const;

        // convertitori di tipo
        operator int() const;
        // converto una variabile in int per fare in modo IntMod possa usarla  

        // costruttori = come fare i set (ma noi preferiamo i costruttori)
        IntMod(); // default (può essere omesso = quello a 0 parametri)
        IntMod(int); // default ad 1 parametro

        IntMod(const IntMod&); //costruttore di copia -> parametro un riferimento costante al tipo Classe (IntMod)

        // Esempi di uso dei costruttori

        // default --> IntMod i;
        // copia -> IntMod i1; i1(i2);

        // lista di inizializzazione (dai due punti)
        IntMod::IntMod(const IntMod& i): n(i.n){}
        // dopo i due punti, inizio a costruire

        // lo vedrai -> operatore di assegnazione (=)
        IntMod& operator=(const IntMod& i){
            n = i.n;
            return *this;
        }
};

int IntMod::n = 1; // lo statico richiede di fare lo scoping (::) della variabile e definire il valore fuori

// statico = dura sempre per tutto il programma e viene cancellato alla fine di tutto


// MakeFile