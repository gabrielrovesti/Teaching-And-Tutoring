#include <iostream>

using namespace std;
#include <list>

// Definire un template di funzione
//template<class T> list<const iostream*> fun(vector<ostream*>&) con il seguente comportamento:
// (1) - se p non è nullo e *p è un fstream che non è nello stato good 
// (ovvero stato 0, con tutti i bit di errore spenti), allora p diventa nullo;
// (2) - se p è nullo e *p è uno stringstream, allora p viene inserito nella lista che la funzione
// deve ritornare;
// (3) se la lista che la funzione deve ritornare è vuota, allora la funzione solleva un'eccezione di tipo T,
// altrimenti la funzione ritorna la lista.

template<class T>
list<const iostream*> fun(vector<ostream*>& v){
    list<const iostream*> l;
    for(auto p : v){
        if(p != nullptr && dynamic_cast<fstream*>(*p) && !dynamic_cast<fstream*>(*p)->good()){
            p = nullptr;
        }
        else if(p == nullptr && dynamic_cast<stringstream*>(*p)){
            l.push_back( dynamic_cast<iostream*>(*p));
        }
    }
    if(l.empty()){
        throw T();
    }
    return l;
};