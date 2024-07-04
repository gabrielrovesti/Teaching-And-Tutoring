#include<iostream>
#include <vector>
using namespace std;
class Auto{
    private:
        static double cavalli;
        static double tassa_cv;
    protected:
        Auto(int);
        virtual ~Auto();
    public:
        static double getTassa() {return tassa_cv;}
        static double getCavalli() {return cavalli;}
        virtual double tassa() const =0;
};
double Auto::tassa_cv=5;

class Benzina: public Auto{
    private:
    static double bonus;
    bool euro4;
    public:
        Benzina(int x, bool b=true): Auto(x), euro4(b) {};
        virtual double tassa() const;
};

    double Benzina::tassa() const{
        if(euro4){
            return getCavalli()*getTassa()-bonus;
        }
        return getCavalli()*getTassa();
    }


class Diesel: public Auto{
    static double tassaD;
    public:
        Diesel(int x): Auto(x) {}
        virtual double tassa() const;
};
double Diesel::tassa() const{
    return getCavalli() * getTassa() + tassaD;
}

class ACI{
    private:
        vector<Auto*> v;
    public:
        void aggiungiAuto(const Auto &);
        double incassaBolli() const;
};
    void ACI::aggiungiAuto(const Auto &a){
            Auto &b=const_cast<Auto&>(a);
            v.push_back(&b);
    }
    double ACI::incassaBolli() const{
            double tot=0;
            vector<Auto*>::const_iterator it;
            for(it=v.begin(); it != v.end(); it++){
                tot+=(*it)->tassa();
            }
            return tot;
    }

int main(){
    Benzina fiat(60, false), lancia(60, true);
    Diesel bmw(90), audi(80);
    ACI a;
    a.aggiungiAuto(fiat); a.aggiungiAuto(lancia);
    a.aggiungiAuto(bmw); a.aggiungiAuto(audi);
    cout<<a.incassaBolli()<<endl;
}