#include <iostream>
#include <vector>
#include <list>

using namespace std;

// classe eccezione
class Anomalia{
    private:
        char codice;
    public:
        Anomalia(char c): codice(c) {}
        char getCodice() const{
            return codice;
        }
};

// classe base astratta
class Scheda{
    private:
        string numTel;
        unsigned int credito;
        unsigned int costoSMS;
    public:
        // metodi virtuali puri
        virtual void telefonata(unsigned int) = 0;
        virtual void connessione(double) = 0;

        string getNumTel() const {
            return numTel;
        }
        
        double getCredito() const {
            return credito;
        }
        
        double getCostoSMS() const {
            return costoSMS;
        }

    // default
    Scheda(string nT = "", unsigned int cr = 0, unsigned int cS = 0): numTel(nT), credito(cr), costoSMS(cS) {}

    // copia
    Scheda(const Scheda& s): numTel(s.numTel), credito(s.credito), costoSMS(s.costoSMS) {}

    // assegnazione
    Scheda& operator=(const Scheda& s){
        if(this != &s){
            numTel = s.numTel;
            credito = s.credito;
            costoSMS = s.costoSMS;
        }
        return *this;
    }

    // messaggioSMS
    void messaggioSMS(unsigned int k){
        if(credito < (k * costoSMS)){
            throw Anomalia('s');
        }
        else{
            credito -= k * costoSMS;
        }
    }

    virtual ~Scheda() = default;

    // addebito
    void addebita(double c){
        credito -= c;
    }
};

class Consymo: public Scheda {
    private:
        unsigned int costoSecTel;
        unsigned int costoMB;

    public:
        // default

        Consumo(string nT = "0", unsigned int cr = 0, unsigned int cs = 2, unsigned int cST = 100, unsigned int cM = 10): 

        Scheda(nT, cr, cs), costoSecTel(cST), costoMB(cM) {};

        virtual void telefonata(unsigned int n){
            if((n * costoSecTel) <= getCredito()){
                addebita(n * costoSecTel);
            }
            else{
                throw Anomalia('v');
            }
        }

        virtual void connessione(double k) {
        if((k * costoMB) <= getCredito()){
                addebita(n * costoMB);
            }
            else{
                throw Anomalia('d');
            }
        }
        
};

class Mensile: public Scheda {
    private:
        unsigned int sogliaVoce;
        unsigned int trafficoVoce;
        unsigned int sogliaMB;
        unsigned int trafficoMB;
        unsigned int costoMensile;

    public:
        // default

        Mensile(string nT = "0", unsigned int cr = 0, unsigned int cs = 1, unsigned int tV = 60000, unsigned int sM = 2096): 

        Scheda(nT, cr, cs), trafficoVoce(tV), sogliaMB(sM) {};

        virtual void telefonata(unsigned int n){
            if((n + trafficoVoce) <= sogliaVoce){
                trafficoVoce += n;
            }
            else{
                throw Anomalia('v');
            }
        }

        virtual void connessione(unsigned int n){
            if((n + trafficoMB) <= sogliaMB){
                trafficoMB += n;
            }
            else{
                throw Anomalia('d');
            }
        }
};

class P2{
    private:
        list<Scheda*> l;
    public:
        Consumo* cambioPiano(string num){
            bool trovato = false;

            for(auto it = l.begin(); it != l.end(); ++it){
                if((*it)->getNumTel() == num){
                    trovato = true;
                    Consumo *c = *it;
                }
            }

            if(trovato){
                Consumo * ret =
                new Consumo(c->getNumTel(), c->getCredito());
                delete c;
                return ret;
            }
        }

vector<Consumo> rimuoviConsumoZero(){
    vector<Consumo> aux;
    for(auto it = l.begin(); it != l.end(); ++it){
        if((*it)->getCredito() == 0){
            // copia dell'oggetto

        Consumo* c = dynamic_cast<Consumo*>(*it);

            if(c){
                aux.push_back(*c);
                delete c;
                it = l.erase(it);
            }
        }
    }
    return aux;
}

double contabilizza(){

    double totprima = 0, totdopo = 0;

    for(auto it = l.begin(); it != l.end(); ++it){
        // it -> Scheda* s 

        totprima += (*it)->getCredito();

        (*it)->telefonata(1);
        (*it)->messaggioSMS(1);
        (*it)->connessione(1);

        totdopo += (*it)->getCredito();
    }

    return totprima - totdopo;
}

};

int main(){
    return 0;
}