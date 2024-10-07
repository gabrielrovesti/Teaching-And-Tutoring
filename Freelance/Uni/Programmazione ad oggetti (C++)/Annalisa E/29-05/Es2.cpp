#include <iostream> 
#include <fstream>
#include <vector>

using namespace std;

vector<fstream*> Fun(const vector<const ios*>& s){
    vector<fstream*> v;

    for(auto i = s.begin(); i != s.end(); ++i) {
        istream* input = dynamic_cast<istream*>(const_cast<ios*>(*i));
        ostream* output = dynamic_cast<ostream*>(const_cast<ios*>(*i));

        if(input && output){
            if(input->tellg() > output->tellp()){
                input->setstate(2);
            }
        }

        fstream* file = dynamic_cast<fstream*>(const_cast<ios*>(*i));

        if(file && file->rdstate() == 0 && file->is_open()){
            file->close();
            v.push_back(file);
        }
        else throw std::exception();
    }

    return v;
}