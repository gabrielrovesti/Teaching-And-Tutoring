using namespace std;

#include <vector>

class Workout{
    private:
        int durata_minuti;
    public:
        virtual ~Workout() {}; //questo rende la classe base polimorfa

        //astratta = metodi virtuali puri
        virtual Workout* clone() const = 0;
        virtual int calorie() const = 0;

        // get dei campi privati
        int getDurata() const{
            return durata_minuti;
        }

        // costruttore
        Workout(int d): durata_minuti(d) {};
};

class Corsa: public Workout{
    private:
        int distanzaKm;
    public:
        Workout* clone() const {
            return new Corsa(*this);
        }

        virtual int calorie() const{
            int cal = 
            500 * (distanzaKm * distanzaKm) 
            / getDurata();

            return cal;
        }

        Corsa(int d, int dist): 
        Workout(d), distanzaKm(dist) {};

        double getDistanza() const{
            return distanzaKm;
        }
};

class Nuoto: public Workout{
    private:
    unsigned int numVasche;
    public:
        Nuoto(int t, unsigned int n): 
        Workout(t), numVasche(n){};

        unsigned int getVasche() const {
            return numVasche;
        }
};

class StileLibero: public Nuoto{
    public:
        virtual StileLibero* clone() const{
            return new StileLibero(*this);
        }

        virtual int calorie() const{
            if(getDurata() < 10){
                return 30 * getVasche();
            }
            else return 40 * getVasche();
        }
};

class Dorso: public Nuoto{
    public:
        virtual Dorso* clone() const{
            return new Dorso(*this);
        }

        virtual int calorie() const{
            if(getDurata() < 15){
                return 30 * getVasche();
            }
            else return 35 * getVasche();
        }
};

class Rana: public Nuoto{
    public:
        virtual Rana* clone() const{
            return new Rana(*this);
        }

        virtual int calorie() const{
            return 25 * getVasche();
        }
};

class InForma{
    private:
        vector<const Workout*> vec;
    public:
        vector<Nuoto*> vasche(int v){
            vector<Nuoto*> ve;
            for(auto it = vec.begin(); it != vec.end(); ++it){
                Nuoto* n = dynamic_cast<Nuoto*>(const_cast<Workout*>(*it)); // o tolgo il const
                // const Nuoto *n = dynamic_cast<const Nuoto*>(*it); // non tolgo il const
                if(n && n->getVasche() > v){
                    vec.push_back(dynamic_cast<Nuoto*>(n->clone()));
                }
            }
            return ve;
        }

        vector<Workout*> calorie(int x){
            vector<Workout*> ve;
            for(auto it = vec.begin(); it != vec.end(); ++it){
                Rana *r = dynamic_cast<Rana*>(const_cast<Workout*>(*it));

                const Workout* w = dynamic_cast<const Workout*>(*it);
                if(!r && w->calorie() > x){
                    ve.push_back(dynamic_cast<Rana*>(r->clone()));
                }
            }
            return ve;
        }
};