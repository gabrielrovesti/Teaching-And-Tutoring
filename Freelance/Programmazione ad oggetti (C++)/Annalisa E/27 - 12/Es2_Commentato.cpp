#include <iostream>
#include <list>

class F: public D{
    private:
    std::list<int*> l;
    int& ref;
    double* p;

    public:
    
    //copia profonda standard
    F(const F& f): 
    D(f), l(f.l), ref(f.ref), p(f.p){}

    //assegnazione profonda standard
    F& operator=(const F& f){
        D::operator=(f);

        l = f.l;
        ref = f.ref;
        p = f.p;

        return *this;
    }


};