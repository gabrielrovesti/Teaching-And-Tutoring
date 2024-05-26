#include <iostream>
#include <list>

using namespace std;

template <class T> list<const iostream*> compare(vector<ostream*>& v, vector<const T*>& w)
{
    list<const iostream*> l;

    vector<ostream*>& v1;
    v1 = v;
    vector<const T*>& w1;

    // (1)
    if(v.size() != w.size())
        throw std::string();
        // oppure std::string("Exc");

    // (2)

    // Sintassi per la maggior parte degli usi
    // Tipo *t = dynamic_cast<Tipo*>(v[i]);
    
    //for(auto i = v.begin(); i != v.end(); ++i)
    // = quando è iteratore

    for(auto i = 0; i < v.size(); ++i){ 
        // qui è intero

        if(dynamic_cast<fstream*>(v1[i]) && typeid(dynamic_cast<fstream*>(v1[i])) == typeid(dynamic_cast<stringstream*>(w1[i]))){

            // (a)

            // (i)
            l.push_back(v1[i]);
            // (ii)
            
            // delete = cancello tutto il puntatore
            // erase = cancella la posizione - oppure da first a list (inizio/fine)

            for(auto i = 0; i < v.size(); ++i){ 
                if(v[i] == v1[i]) {
                    v.erase(v[i]);
                }   
            }

            if(dynamic_cast<const stringstream*>(w1[i])->good() && typeid(*v1[i]) != typeid(*w1[i])){
                l.push_back(w1[i]);
            }

            return l;

            // good = metodo di iostream
            // puntatore->good();
            // oppure
            // controlli se uguale a 0

            /*
            std::fstream* f1 = dynamic_cast<std::fstream*>(v[i]);
            std::stringstream* w1 = dynamic_cast<std::stringstream*>(w[i]);

            if (f1 && typeid(*v[i]) == typeid(*w[i])) {
                result.push_back(v[i]);
                v.erase(v.begin() + i);
                w.erase(w.begin() + i);
                --i;

                /// Senso logico (| è dove siamo ora)
                /// 1 2 [3] 4 5
                ///      |
                /// 1 2 4 5
                ///   |
            }
            */
        }
    }
}

for(int i = 0; i < v.size(); ++i)
    if(dynamic_cast<fstream*>(v[i]) && typeid(*v[i] == typeid(*w[i])))

    // no insert

    // push_back (si)

    fstream* f = dynamic_cast<fstream*>(f[i]);

    if ...
    v.erase(f);

    // se c'è const sopra 
        // in cancellazione = se const, no party
        // = se sei oggetto const, non cancella

        // in inserimento
            // o converti al sottotipo togliendo const

            // = fstream* f = dynamic_cast<fstream*>(const_cast<iostream*>(v[i]));

            // oppure tieni il tipo costante

            // if(dynamic_cast<const stringstream*>(v[i]) ...
