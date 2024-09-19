#include <iostream> 
#include <fstream>

using namespace std;

class Fallimento{
    private:
        string errore;
    public:
        Fallimento(string e): errore(e) {}
};

long Fun(const ios& s){
    if(s.fail()) throw Fallimento("Fuck"); //(1)

    if(!dynamic_cast<ifstream*>(const_cast<ios*>(&s))){
        return -2;
    }
    /* non costante
    else if(dynamic_cast<ifstream*>(const_cast<ios*>(&s)) && dynamic_cast<ifstream*>(const_cast<ios*>(&s))->is_open()){

    }
    */
    // tenendo il const
    else if((dynamic_cast<const ifstream*>(&s)) && (dynamic_cast<const ifstream*>(&s)->is_open())){
        return -1;
    }
    else {
        // return dynamic_cast<const ifstream*>(&s)->tellg();
    }
}

/*
Usando lo star:

long Fun(const ios* s){
    if(s->fail()) throw Fallimento("Fuck"); //(1)

    if(!dynamic_cast<ifstream*>(const_cast<ios*>(s))){

    }
}
*/