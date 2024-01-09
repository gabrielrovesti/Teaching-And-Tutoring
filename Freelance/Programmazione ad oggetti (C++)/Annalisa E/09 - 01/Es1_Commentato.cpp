#include <iostream>
#include <vector>
using namespace std;

class Workout{
    private:
        int minuti;
    public:
        virtual ~Workout();

        virtual Workout* clone() const = 0;
        virtual int calorie() const = 0;

        Workout(int m): minuti(m) {}

        int getMinuti() const{
            return minuti;
        }
};

class Corsa: public Workout{
    private:
        int distanza;
    public:
        virtual Workout* clone() const{
            return new Corsa(*this);
        } 

        virtual int calorie() const{
            return 500 * (distanza * distanza) / getMinuti();
        }

        Corsa(int m, int d): 
        Workout(m), distanza(d) {}
};

class Nuoto: public Workout{
    private:
        unsigned int numVasche;
    public:
        Nuoto(int m, int nv): 
        Workout(m), numVasche(nv) {}

        unsigned int getnumVasche() const{
            return numVasche;
        }
};

class StileLibero: public Nuoto{
    public:
        virtual StileLibero* clone() const{
            return new StileLibero(*this);
        } 

        virtual int calorie() const{
           if(getMinuti() < 10)
           return 35 * getnumVasche();
                else
           return 40 * getnumVasche();
        }
};

class Dorso: public Nuoto{
    public:
        virtual Workout* clone() const{
            return new Dorso(*this);
        } 

        virtual int calorie() const{
           if(getMinuti() < 15)
           return 30 * getnumVasche();
                else
           return 35 * getnumVasche();
        }
};

class Rana: public Nuoto{
    public:
        Workout* clone() const {return new Rana(*this);}
        int calorie() const {return 25 * getnumVasche();}
};

class InForma{
    private:
        vector<const Workout*> vec;
    public:
        vector<Nuoto*> vasche(int v){
            vector<Nuoto*> ve;
            for(auto it = vec.begin(); it != vec.end(); ++it){
                const Nuoto *n = dynamic_cast<const Nuoto*>(*it);
                //auto n = dynamic_cast<Nuoto*>(const_cast<Workout*>(*it));
                if(n && n->getnumVasche() > v){
                    ve.push_back(dynamic_cast<Nuoto*>(n->clone()));
                }
            }
            return ve;
        }

        vector<Workout*> calorie(int x){
            vector<Workout*> ve;
            for(auto it = vec.begin(); it != vec.end(); ++it){
                Workout *w = const_cast<Workout*>(*it);
                Rana *r = dynamic_cast<Rana*>(const_cast<Workout*>(*it));
                if(w->calorie() > x && !r){
                    ve.push_back(w->clone());
                }
            }
            return ve;
        }

        void removeNuoto(){
            int max=0;
            for(auto it = vec.begin(); it != vec.end(); ++it){
                Nuoto *n = dynamic_cast<Nuoto*>(const_cast<Workout*>(*it));
                if(n->calorie() > max){
                    max = n->calorie();
                }
            }
            for(auto it = vec.begin(); it != vec.end(); ++it){
                if(max == 0) throw string("NoRemove");
                Nuoto *n = dynamic_cast<Nuoto*>(const_cast<Workout*>(*it));
                else if (max == n->calorie()) it = vec.erase(it);
            }
        }
};