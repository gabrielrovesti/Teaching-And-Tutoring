using namespace std;
#include <iostream>
#include <fstream> // va inclusa per fstream
#include <sstream> // va inclusa per stringstream
#include <vector>

//Ios è la base (virtuale)

//istream - stream di input
//ostream - stream di output
//iostream
//fstream

vector<fstream*> Fun (const vector<const ios*>& v){
    vector<fstream*> res;
    for(auto it = v.begin(); it != v.end(); ++it){
        // punto (a)
        // a tutti gli stream di input/output
        istream *i = dynamic_cast<istream*>(const_cast<ios*>(*it));
        ostream *o = dynamic_cast<ostream*>(const_cast<ios*>(*it));
        // tellg - posizione testina input
        // tellp - posizione testina output
        if(i && o){
            //setstate
            if(i->tellg() > o->tellp()){
                i->setstate(2);
            }
        }
        // punto (b)
        fstream *f = dynamic_cast<fstream*>(const_cast<ios*>(*it));
        if(f && f->rdstate() != 0 && f->is_open()){
            f->close();
            res.push_back(f);
        }
        else throw std::exception();
    }
    return res;
}