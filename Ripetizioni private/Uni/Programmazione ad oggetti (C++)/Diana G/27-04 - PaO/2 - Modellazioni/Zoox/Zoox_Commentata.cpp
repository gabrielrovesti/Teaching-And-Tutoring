#include <iostream>
#include <vector>

using namespace std;

class Capo{
    private:
        string designer;
        int taglia;
    public:
        // default
        Capo(string d = "", int t = 0): designer(d), taglia(t){}

        // copia
        Capo(const Capo& c): designer(c.designer), taglia(c.taglia) {}

        string getDesigner() const{
            return designer;
        }

        int getTaglia() const{
            return taglia;
        }

        // operatore di uguaglianza
        virtual bool operator==(const Capo& c) const{
            return designer == c.designer && taglia == c.taglia;
        }

        // clone
        virtual Capo* clone() const{
            return new Capo(*this);
        }

        // distruzione polimorfa
        virtual ~Capo() {}
};

class TShirt: public Capo{
    private:
        bool manica;
    public:
    
    TShirt(string d = "", int t = 0, bool m): Capo(d, t), manica(m) {}

    bool isManicaLunga() const{
        return manica;
    }

    virtual bool operator==(const Capo& c) const{
        return typeid(const TShirt&) == typeid(c) && Capo::operator==(c);
    }
};

class Jeans: public Capo{
    private:
        unsigned int larghezza;
    public:
        Jeans(string d = "", int t = 0, unsigned int l): Capo(d, t), larghezza(l) {}

        unsigned int getLarghezza(){
            return larghezza;
        }
};

class Articolo{
    friend class Zoox;
    private:
        Capo* c;
        unsigned int q;
    public:
        Articolo(Capo* capo = 0, unsigned int quant): c(capo), q(quant) {}
        unsigned int getQuantita() const{
            return q;
        }
};

class Exc{
    private:
        string msg;
    public:
        Exc(string m): msg(m){};
        string getException() const{ return msg; }
};

class Zoox{
    private:
        // innestiamolo in una classe a parte che punta ai Capi polimorfi e alla loro quantità
        vector<Articolo> magazzino;
    public:
        int giacenza(const Capo& c){
            int n_articoli = 0;

            // per ogni articolo nel magazzino, prendo quantità
            for(int i = 0; i < magazzino.size(); ++i){
                //if(c == magazzino[i].c){
                    //n_articoli += magazzino[i].q;
                //}
            }

            return n_articoli;
        }

        // Versione corretta (per overloading ==)
        int giacenza(const Capo& c){
            int n_articoli=0;
            for(auto it = magazzino.begin(); it != magazzino.end(); ++it){
                if(*it->c == c){
                    n_articoli += it->q;
                }
            }
            return n_articoli;
        }

        vector<Jeans> getJeans(string marca, int size, double x){
            vector<Jeans> ret;

            for(auto it = magazzino.begin(); it != magazzino.end(); ++it){
                Jeans* j = dynamic_cast<Jeans*>(it->c);

                if(j && j->getDesigner() == marca && j->getTaglia() == size && j->getLarghezza() >= x){
                    ret.push_back(*j);
                }
            }
            return ret;
        }

        void scarica(const TShirt* pt){
            for(auto it = magazzino.begin(); it != magazzino.end(); ++it){
                TShirt* t = dynamic_cast<TShirt*>(it->c);
                if(t && *pt == *t){
                    if(it->q > 1){
                        magazzino.erase(it);
                    }
                    else{
                        throw Exc("assente");
                    }
                }
            }
        }

        void insert(const TShirt& t, int num){
            for(auto it = magazzino.begin(); it != magazzino.end(); ++it){
                TShirt *ts = dynamic_cast<TShirt*>(it->c);
                if(ts && !ts->isManicaLunga() && ts->getDesigner() == t.getDesigner()){
                    magazzino.push_back(Articolo(new TShirt(t), num));
                }
                else{
                    throw Exc("presente");
                }
            }
        }
};

int main(){
    return 0;
}