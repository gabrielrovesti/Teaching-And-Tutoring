#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<fstream*> Fun(const vector<const ios*> &v){
    vector<fstream*> ret;
    for(auto it = v.begin(); it != v.end(); ++it){
        //posizione della testina di input
        //const istream* i = dynamic_cast<const istream*>(*it);
        istream* i = dynamic_cast<istream*>(const_cast<ios*>(*it));
        //posizione della testina di output
        //const ostream* i = dynamic_cast<const istream*>(*it);
        ostream* o = dynamic_cast<ostream*>(const_cast<ios*>(*it));
        
        if(i && o){
            if(i->tellg() > o->tellp()){
                i->setState(2);
            }
        }
        fstream* f = dynamic_cast<fstream*>(const_cast<ios*>(*it));

        if(f && f->rdstate() == 0 && f->isOpen()){
            ret.push_back(f);
        }
        if(f->rdstate()==0 && f->isOpen()){
            throw std::exception();
        }
    }
    return ret;
}