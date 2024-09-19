#include <iostream>
#include <typeinfo>
#include <list>
#include <vector>
using namespace std;

list<const D* const> fun (const vector<const B*>& v){
    list<const D* const> l;
    //q = v.begin(); q != v.end(); q++
    int cont = 0;
    for(auto q: v){
        if(!q && typeid(*q) == typeid(C)){
            B* copy = const_cast<B*>(*q);
            v.erase(copy);
            cont++;
            if(cont > 2) throw C();
        }
        if(!q){
           A* ptr = q->f()
           if(ptr == nullptr){
                throw(std::string("nullptr"));
           }
           if(ptr != nullptr && dynamic_cast<D*>(*q) && !dynamic_cast<E*>(*q)){
                l.push_back(q);
           }
        }
    }
}

int main(){

}