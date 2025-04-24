#include <iostream>
#include <vector>
#include <list>

template <class T>
std::vector<const T*> filter(const std::list<ios*>& streams, const function<bool(const T*)>& predicate){
    vector<const T*> v;

    // (4)

    // (2)
    for(auto it = streams.begin(); it != streams.end(); ++it){
        T* t = dynamic_cast<const T*>(*it);
        if(predicate(t))
            v.push_back(*t);
        // (4)
        if(!dynamic_cast<ios*>(*t))
            throw std::logic_error("Tipo non compatibile");
    }

    // (3)
    if(v.empty())  throw ios_base::failure("No element found!");    
}

// Quando usare const_cast?
// Quando devo ritornare roba non const ma ho il puntatore delle condizioni const
std::vector<std::istream*> filter(std::list<const ios*>& l){
    vector<std::istream*> v:

    for(auto cit = l.begin(); cit != l.end(); ++cit){
        // cit = const_iterator

        // if condizione pushalo nel vector v
        // qua va tolto il const, perché il vector non è const
        istream* i = dynamic_cast<istream*>(const_cast<ios*>(*cit));
        if(i) v.push_back(i);
    }
}

int main(){
    return 0;
}