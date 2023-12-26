#include <iostream> // per tutto il resto di ios
#include <vector> // vector/iterator/const_iterator
#include <typeinfo> // typeid 

#include <fstream>  // per gli fstream
#include <sstream>  // per gli stringstream

using namespace std;

class C{
    private:
        vector<ios*> v; 
        int dim;
    public:
        C(int k=10): dim(k){}
        void insert(ios& s){
            if(v.size() < dim &&
            typeid(s) != typeid(fstream)
            && typeid(s) != typeid(stringstream)){
                v.push_back(&s);
            }
        }

        template<class T>
        int conta(T& t){
            int x = 0;
            for(auto it = v.begin();
            it != v.end();
            ++it){
                if(dynamic_cast<T*>(*it))
                x++;
            }
            return x;
        }
};