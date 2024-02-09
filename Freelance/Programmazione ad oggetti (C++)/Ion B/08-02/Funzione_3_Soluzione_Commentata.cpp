// Off-topic
// Definisci una classe di eccezione Exc

class Exc{
    public:
        Exc();
};

class Exc{
    private:
        string msg;
    public:
        Exc(string m): msg(m) {}
};

// Metodi liste/vettori

/*

push_back (inserisce in una posizione al fondo del vettore)
erase (cancella in una posizione)

begin/end (inizio e fine = per iteratori)
*/

#include <typeinfo>
#include <list>

list<const D *const> fun(const vector<const B*>& v){
    list<const D *const> l;
    int count = 0;

    for(auto it = v.begin(); it != v.end(); ++it){
        const B* q = *it;

        if(q && typeid(*q) == typeid(C)){
            count++;

            it = v.erase(it);
            //v.erase(it);
            delete q;

            if(count > 2) throw C();
        }
        else{
            A* ptr = q->f();

            if(ptr == nullptr)  
                throw std::string("nullptr");
            else{
                if(dynamic_cast<const D* const>(ptr) 
                && !dynamic_cast<const E* const>(ptr))
                    l.push_back(dynamic_cast<const D *const>(ptr));
            }
        }
        return l;
    }

    for(auto it: v){
        
    }

    //for(const vector<const B*>& v::const_iterator cit)

    /*
    Alternativa:

    for(int i=0; i<n; i++)
        v[i]->metodo();
    */

    return l;
}
