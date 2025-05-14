#include <iostream>
#include <list>
#include <typeinfo>

enum Laurea {Informatica,
Ingegneria, Altro};

using namespace std;

class ICTStaff{
    private:
        double fissoMensile;
        Laurea l;
        bool magistrale;
    public:
        // metodi virtuali puri 
        virtual ICTStaff* clone() const = 0;
        virtual double salary() const = 0;
        // se classe astratta, non istanziamo nulla dei nostri oggetti privati

        // getter
        Laurea getLaurea() const {return l;}
        bool isMaster() const {return magistrale;}
        double getFisso() const{return fissoMensile;}

        // polimorfa
        virtual ~ICTStaff() = default; // default = C++17 oltre per farti la costruzione standard
};

class SwEngineer: public ICTStaff{
    private:
        bool safety;
        // se l'extra rimane sempre 500 -> static
        // static double extra;
    public:
        // alternativa
        // virtual ICTStaff* clone() const - firma - classe base
        virtual SwEngineer* clone() const{
            return new SwEngineer(*this);
        }
        virtual double salary() const{
            // if this->safety() - volendo perché sei dentro la classe
            if(safety){
                return getFisso() + 500;
            }
            else{
                return getFisso();
            }
        }
        bool isSafety() const{
            return safety;
        }
};
// tipo Classe::campo = valore
// double SwEngineer::extra = 500.0;

class HwEngineer: public ICTStaff{
    private:
        unsigned int numTrasferte;
    public:
        virtual HwEngineer* clone() const{
            return new HwEngineer(*this);
        }
        virtual double salary() const{
            return getFisso() + numTrasferte * 300;
        }
};

class Amazonia{
    private:
        class SmartP{
        public:
        ICTStaff* p; // puntatore polimorfo - smart pointer (no condivisione memoria = clone)

        // default
        SmartP(ICTStaff* q): p(q != nullptr ? q->clone() : nullptr) {}

        // copia
        SmartP(const SmartP& s):
        p(s.p != nullptr ? (s.p)->clone() : nullptr) {}
         
        // assegnazione
        SmartP& operator=(const SmartP& s){
            // aliasing memoria
            if(this != &s) {
                // deallocazione
                delete p;
                // assegnazione
                p = s.p != nullptr ? (s.p)->clone() : nullptr;
            }
            // return
            return *this;
        }
        // p = ICTStaff
        // (p) = *p, &p

        // distruzione
        ~SmartP() {
            delete p;
        }

        ICTStaff* operator->() const{
            return p;
        }

        ICTStaff& operator*() const{
            return *p;
        }
                
        };

    list<SmartP*> lista;

    public:
        bool insert(SwEngineer* p, unsigned int k){
            int cont = 0;

            for(auto it = lista.begin(); it != lista.end(); ++it){
                SwEngineer* sw = dynamic_cast<SwEngineer*>(it->p);
                if(sw && sw->isSafety()) {
                    lista.push_back(sw->clone());
                    cont++;
                }
            }
            if(cont < k){
                return true;
            }
            else{
                return false;
            }
        }
        
        vector<HwEngineer> fire(double){
            vector<HwEngineer> v;

            for(auto it = lista.begin(); it != lista.end(); ++it){
                if((*it)->salary() > s){
                    HwEngineer* hw = dynamic_cast<HwEngineer*>(it->p);

                    if(hw)
                        v.push_back(*hw);
                    // no delete = esiste il distruttore profondo di Smartp
                    // basta fare erase

                    it = v.erase(it);
                }
            }

            return v;
        }

        vector<SwEngineer*> masterInf(){
            vector<SwEngineer*> v;

            for(auto it = lista.begin(); it != lista.end(); ++it){
                SwEngineer* sw = dynamic_cast<SwEngineer*>(it->p);

                if(sw && sw->getLaurea() == Informatica && sw->isMaster()) {
                    v.push_back(sw);
                }
            }
            
            return v;
        }
};

int main(){
    return 0;
}