#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

template<class T>
class C{
    private:
        vector<ios*> v;
        int dim;
    public:

    int getDim() const{
        return dim;
    }

    C(int k){
        if(k > 0){
            dim = k;
        }
        else{
            dim = 0;
        }
    }

    void insert(ios& s){
        if (v.size() < dim && dynamic_cast<ios*>(&s) && dynamic_cast<fstream*>(&s) && dynamic_cast<stringstream*>(&s)){
            v.push_back(&s);
        }
    }
};

template<class T>
int conta(T& t){
    int cont = 0;
    for(auto it = v.begin(); it != v.end(); ++it){
        if(dynamic_cast<T*>(it)){
            cont ++;
        }
    }
    return cont;
}



int main() {

}