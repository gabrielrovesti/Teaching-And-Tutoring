#include <iostream>
#include <list>
#include <vector>

using namespace std;

class SIM{
    private:
        int tot_tempo;
        double traffico_dati;
    public:
        static double costo_tel;
        static double costo_dati;

        virtual double costoMeseCorrente() const = 0;

        virtual ~SIM() {}

        int get_tempo() const{
            return tot_tempo;
        }

        double get_traffico_dati() const{
            return traffico_dati;
        }

        SIM(int t, double tr):
        tot_tempo(t), traffico_dati(tr)
        {}
};

double SIM::costo_tel = 0.03;
double SIM::costo_dati = 0.04;

class Tel: public SIM{
    private:
        double costo_mensile;
    public:
        virtual double costoMeseCorrente() const{
            return ( costo_mensile +
                get_traffico_dati() * SIM::costo_dati);
        }

        Tel(int t, double tr, double c):
        SIM(t, tr), costo_mensile(c) {}

        double get_costo_mensile() const{
            return costo_mensile;
        }
};

class Dati: public SIM{
    public:
        static double costo_sim_dati;

        virtual double costoMeseCorrente() const{
            return ((SIM::costo_tel * get_tempo()) + Dati::costo_sim_dati);
        }
};

double Dati::costo_sim_dati = 13.99;

class PAO{
    private:
        list<const SIM*> vez;
    public:
        vector<Dati> fun1(double x){
            vector<Dati> v;
            for(auto it = vez.begin(); it != vez.end(); ++it){
                //const Dati *d = dynamic_cast<const Dati*>(*it);
                Dati *d = dynamic_cast<Dati*>(const_cast<SIM*>(*it));
                if(d && d->get_traffico_dati() >= x){
                    v.push_back(*d);
                }
            }
            return v;
        }

        list<Tel*> fun2(){
            list<Tel*> l;
            for(auto it = vez.begin(); it != vez.end(); ++it){
                Tel *t = dynamic_cast<Tel*>(const_cast<SIM*>(*it));
                if(t && t->get_costo_mensile() > 2 * t->costoMeseCorrente()){
                    l.push_back(t);
                }
            }
            return l;
        }
};