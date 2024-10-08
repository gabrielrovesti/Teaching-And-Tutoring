#include <iostream>
#include <vector>

using namespace std;

class Anomalia{
    private:
        char codice;
    public:
        Anomalia(char c): codice(c)  {}
};

class Scheda{
    private:
        string num;
        unsigned int credito;
        unsigned int costo;
    public:
        virtual void telefonata(unsigned int) =0;
        virtual void connessione(double) =0;

        Scheda(string n, int cr, int co): num(n), credito(cr), costo(co){};

        void messaggioSMS(unsigned int k){
            if(credito >= (k * costo)){
                credito -= (k * costo);
            }
            else throw Anomalia('s');
        }

        string getNum() const {
            return num;
        }
        
        unsigned int getCredito() const {
            return credito;
        }
        
        unsigned int getCosto() const {
            return costo;
        }

        void addebita(double c){
            credito -= c;
        }
};

class Mensile: public Scheda{
    private:
        int sogliaTel;
        int trafficoTel;
        double sogliaMB;
        double trafficoMB;
        double costoMensile;
    public:
        Mensile(string nt = "0", 
        unsigned int cred = 0, 
        unsigned int costo = 0.1,
        int sogliaC = 60000,
        int sogliaM = 2096):
        Scheda(nt, cred, costo), sogliaTel(sogliaC),
        sogliaMB(sogliaM) {};

        virtual void telefonata(unsigned int n){
            if(n + trafficoTel <= sogliaTel){
                trafficoTel += n;
            }
            else throw Anomalia('v');
        }

        virtual void connessione(double k){
            if(k + trafficoMB <= sogliaMB){
                trafficoMB += k;
            }
            else throw Anomalia('d');
        }

        int getSogliaTel() const{
            return sogliaTel;
        }

        int getTrafficoTel() const{
            return trafficoTel;
        }

        double getSogliaMB() const{
            return sogliaMB;
        }

        double getTrafficoMB() const{
            return trafficoMB;
        }

        double getCostoMensile() const{
            return costoMensile;
        }
};

class Consumo: public Scheda{
    private:
        double costoSecTel;
        double costoMB;
    public:
        Consumo(string nt = "0", 
        unsigned int cred = 0, 
        unsigned int costo = 0.2,
        double costoSec = 0.01,
        double costoM = 0.1):
        Scheda(nt, cred, costo),
        costoSecTel(costoSec),
        costoMB(costoM) {}

        virtual void telefonata(unsigned int n){
            if(n * costoSecTel <= getCredito()){
                addebita(n * costoSecTel);
            }
            else throw Anomalia('v');
        }

        virtual void connessione(unsigned int k){
            if(k * costoMB <= getCredito()){
                addebita(k * costoMB);
            }
            else throw Anomalia('v');
        }
};

class P2{
    private:
        vector<Scheda*> v;
    public:
        Consumo* cambioPiano(string num) {
            Consumo *c;
            for(auto it = v.begin(); it != v.end(); ++it){
                if(dynamic_cast<Mensile*>(*it)){
                    Consumo *c = new Consumo((*it).getNum(), (*it).getCredito());
                    delete *it;
                    return c;
                }
                else return nullptr;
            }

            return c;
        }

        vector<Consumo> rimuoviConsumoZero(){
            vector<Consumo> vec;

            for(auto it = v.begin(); it != v.end(); ++it){
                if(dynamic_cast<Consumo*>(*it) && dynamic_cast<Consumo*>(*it)->getCredito() == 0){
                    vec.push_back(dynamic_cast<Consumo>(*it));
                    it = v.erase(it);
                }
            }

            return vec;
        }

        double contabilizza() {
            double totprima = 0, totdopo = 0;

            for(auto it = v.begin(); it != v.end(); ++it){
                totprima += (*it)->getCredito();

                (*it)->telefonata(1);
                (*it)->messaggioSMS(1);
                (*it)->connessione(1);

                totdopo += (*it)->getCredito();
            }
            return totprima - totdopo;
        } 
};