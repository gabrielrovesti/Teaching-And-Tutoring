#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <fstream>
#include <typeinfo>

using namespace std;

template <class T>
std::list<const std::iostream*> compare(std::vector<std::ostream*>& v, const std::vector<const T*>& w) {
    if (v.size() != w.size()) {
        throw std::string("Vector sizes do not match.");
    }

    std::list<const std::iostream*> result;

    for (int i = 0; i < v.size(); i++) {
        if (dynamic_cast<fstream*>(v[i]) && typeid(*v[i]) == typeid(*w[i])) {
            result.push_back(dynamic_cast<const iostream*>(v[i]));

            ostream* temp = *v[i]; // not const, safe
            T* t = const_cast<T*>(*w[i]); // const, keep in mind

            v.erase(v.begin() + i);
            v.erase(t);

            delete temp; 
            delete t;

        }
        if (dynamic_cast<stringstream*>(v[i])->good() && typeid(*v[i]) != typeid(*w[i])){   
            result.push_back(dynamic_cast<const iostream*>(v[i]));
        } 
    }

    return result;
}

int main(){
    return 0;
}