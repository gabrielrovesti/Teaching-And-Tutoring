#include <iostream>
#include <fstream>
#include <sstream>
#include <typeinfo> 
#include <list>
#include <vector>

using namespace std;

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

        // (Approccio 1) - Il for con gli elementi "i"

        for(int i = 0; i < v.size(); i++){
            fstream* f = dynamic_cast<fstream*>(*v[i]);
            if(f && !f->good()){
                f = nullptr;
            }
            stringstream* s = dynamic_cast<fstream*>(*v[i]);
            if(s && s->good()){
                l.push_back(s);
            }
        }
    
        if(l.empty()) throw T();
        else            return l;

    // Approccio 2: iteratori e basta (simple for real)

    for(vector<ostream*>::iterator it = v.begin(); it != v.end(); ++it){
        fstream* f = dynamic_cast<fstream*>(*it);
        if(f && !f->good()){
            f = nullptr;
        }
        stringstream* s = dynamic_cast<fstream*>(*it);
        if(s && s->good()){
            l.push_back(s);
        }
    }

    if(l.empty()) throw T();
    else            return l;
};

int main(){
    return 0;
}