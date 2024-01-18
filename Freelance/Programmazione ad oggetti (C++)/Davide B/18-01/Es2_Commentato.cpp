#include <iostream>

using namespace std;

class Fallimento{
    private:
        string msg;
    public:
        Fallimento(string m): msg(m) {};
};

long Fun(const ios& s){
    if(s.fail()){
        throw Fallimento("Errore");
    }
    else{
        // const ifstream *i = dynamic_cast<const istream*>(s);
        ifstream *i = dynamic_cast<ifstream*>(const_cast<ios*>(s));
        if(!i) return -2;
        if(!i->isOpen()) return -1;
        if(i->isOpen()) return i->tellg();
    }
}