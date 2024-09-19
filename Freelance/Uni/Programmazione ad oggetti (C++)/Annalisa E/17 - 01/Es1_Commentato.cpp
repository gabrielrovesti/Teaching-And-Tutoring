#include <iostream>
#include <vector>
using namespace std;

class Capo{
    private:
        string designer;
        int taglia;
    public:
        Capo(string d="", int t=0):
        designer(d), taglia(t) {};

        virtual ~Capo() = 0;

        virtual bool operator==(const Capo& c) const{
            return designer == c.designer &&
            taglia == c.taglia;
        }

        //clonazione
        virtual Capo* clone() = 0;

        string getDesigner() const{
            return designer;
        }

        int getTaglia() const{
            return taglia;
        }
};

class TShirt: public Capo{
    private:
        bool manicaLunga;
    public:
        TShirt(string m="", int t=0, 
        bool ma): Capo(m,t), manicaLunga(ma) {};

        virtual bool operator==(const Capo& c) const{
            return typeid(const TShirt&) == typeid(c) && Capo::operator==(c);
        }

        virtual Capo* clone(){
            return new TShirt(*this);
        }

        bool isManicaLunga() const{
            return manicaLunga;
        }
};

class Jeans: public Capo{
    private:
        int larghezza;
    public:
        Jeans(string m="", int t=0, double l=0):
        Capo(m,t), larghezza(l) {}
        int getLarghezza() const{
            return larghezza;
        }
        virtual bool operator==(const Capo& c) const{
            return typeid(const Jeans&) == typeid(c) && Capo::operator==(c) &&
            larghezza == (static_cast<const Jeans&>(c)).larghezza;
        }
};

class Articolo{
    private:
        unsigned int quantità;
    public:
        Capo* c;
        Articolo(Capo *capo = 0, unsigned int q):
        c(capo), quantità(q) {}
        unsigned int getQuantità() const{
            return quantità;
        }
        void setQuantità(int q) {
            quantità = q;
        }
};

//esempio di classe eccezione
class Exc{
    private:
        string messaggio;
    public:
        Exc(string m): messaggio(m) {};
};

class Zoox{
    private:
        vector<Articolo> magazzino;
    public:
        int giacenza(const Capo& c){
            int n_articoli = 0;
            for(auto it = magazzino.begin(); it != magazzino.end(); ++it){
                if(*it->c == c){
                    n_articoli += it->getQuantità();
                }
            }
        }

        vector<Jeans> getJeans(string marca, int size, double x){
            vector<Jeans> vez;
            for(auto it = magazzino.begin(); it != magazzino.end(); ++it){
                Jeans *j = dynamic_cast<Jeans*>(it->c);
                if(j && j->getDesigner() == marca && j->getTaglia() == size && j->getLarghezza() > x){
                    vez.push_back(*j);
                }
                // dynamic_cast<Tipo*>(*it) // star dentro a un ciclo
                // Punto ad un metodo di un puntatore/iteratore: it-> / p->
                // Punto ad un campo di un puntatore/iteratore: it. / p.

                //vector<Tipo> - push_back(*p)
                //vector<Tipo*> - push_back(p)
            }
            return vez;
        }

        void scarica(const TShirt* pt){
            for(auto it = magazzino.begin(); it != magazzino.end(); ++it){
                TShirt *t = dynamic_cast<TShirt*>(it->c);

                if(t && *t == *pt){
                    if(it->getQuantità() != 0){
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

                if(ts && ts->isManicaLunga() && ts->getDesigner() == t.getDesigner()){
                    it->setQuantità(num);
                    magazzino.push_back(*it);
                }
                else{
                    throw Exc("Presente");
                }
            }
        }
};