/*
 * Fatti concernenti la libreria di I/O standard:
 * 
 * - `ios` è la classe base astratta e virtuale della gerarchia di tipi della libreria di I/O.
 * - La classe `istream` è derivata direttamente e virtualmente da `ios`.
 * - La classe `ifstream` è derivata direttamente da `istream`.
 * 
 * Comportamento delle classi:
 * 
 * - `ios`:
 *   - Rende disponibile un metodo costante e non virtuale `bool fail()`.
 *   - Comportamento di `fail()`: una invocazione `s.fail()` ritorna `true` se e solamente se lo stream `s` è in uno stato di fallimento (cioè, il `failbit` di `s` vale 1).
 * 
 * - `istream`:
 *   - Rende disponibile un metodo non costante e non virtuale `long tellg()`.
 *   - Comportamento di `tellg()`:
 *     1. Se `s` è in uno stato di fallimento, ritorna -1.
 *     2. Altrimenti, se `s` non è in uno stato di fallimento, ritorna la posizione della testina di input di `s`.
 * 
 * - `ifstream`:
 *   - Rende disponibile un metodo costante e non virtuale `bool is_open()`.
 *   - Comportamento di `is_open()`: una invocazione `s.is_open()` ritorna `true` se e solo se il file associato allo stream `s` è aperto.
 * 
 * Definire una funzione `long Fun(const ios&)` con il seguente comportamento:
 * 
 * - Una invocazione `Fun(s)`:
 *   1. Se `s` è in uno stato di fallimento, lancia una eccezione di tipo `Fallimento`, dove la classe `Fallimento` va esplicitamente definita.
 *   2. Se `s` non è in uno stato di fallimento allora:
 *      (a) Se `s` non è un `ifstream`, ritorna -2.
 *      (b) Se `s` è un `ifstream` ed il file associato non è aperto, ritorna -1.
 *      (c) Se `s` è un `ifstream` ed il file associato è aperto, ritorna la posizione della cella corrente di input di `s`.
 */


#include <iostream> //per prendere tutto il resto
#include <fstream> //per ofstream e ifstream
#include <string>

using namespace std;

class Fallimento{
    private:
    string errore;
    public:
    Fallimento(string e): errore(e) {}
};

long Fun(const ios& s){
    if(s.fail()) throw Fallimento("Errore");
    
    ifstream* i=dynamic_cast<ifstream*>(const_cast<ios*>(&s));
    if(!i) return -2; //non è un ifstream
    //Variante se ifstream fosse const (const ifstream)
    //if(!dynamic_cast<const ifstream*>(&s)) return -2;
    if(!i && !i->is_open()) return -1; //non è un ifstream e il file non è aperto
    if(i && i->is_open()) return i->tellg(); //i è istream e ritorna la posizione della cella corrente
    return 0;
}

int main(){
    
}