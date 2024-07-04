#include <iostream>
#include <typeinfo>
using namespace std;
class Studente{
    protected:
    std::string nome;
    std::string corso_l;
    int n_esami_previsti;
    int n_esami_sostenuti;
    int n_anni;
    double media;
    public:
    Studente(string n, string c): nome(n), corso_l(c) {}
    virtual ~Studente() {};
};

class StudenteIC: public Studente{
    private:
    int anno_corso;
    double reddito_f;
    public:
    int classeDiReddito(){
        if(reddito_f <= 15000 && anno_corso==n_anni) return 0;
        if(reddito_f <= 15000 && anno_corso<n_anni) return 1;
        if(reddito_f > 15000 && reddito_f <=30000) return 2;
        if(reddito_f > 30000) return 3;
    }
};

class StudenteFC: public Studente{
    private:
    int anni_f;
    public:
    int getanni_f() const{return anni_f;}
    bool bonus(){
        if(n_esami_previsti < 5) return true;
    }
};

class Tasse{
    private:
    int importo_base;
    int penale;
    int bonus;
    public:
    int getib() const{return importo_base; }
    int getpen() const{return penale;}
    int getbonus() const{return bonus;}
    static int calcolaTasse(Studente& s){
        Tasse *t;
        StudenteIC *i=static_cast<StudenteIC*>(&s);
        if(i){
            return t->getib() + t->getpen() * i->classeDiReddito();
        }
        else{
            StudenteFC *f=static_cast<StudenteFC*>(&s);
            if(f){
                if(t->getbonus())
                return (t->getib() + 3*t->getpen() * f->getanni_f()) - t->getbonus();
                else
                return t->getib() + 3*t->getpen() * f->getanni_f();
            }
            else return 0;
        }
    }
};

int main(){

}